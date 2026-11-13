unit Pix;

{ Cobrança Pix pela API Pix do Banco Central. A especificação é a mesma em todos os PSPs (bancos e instituições de
  pagamento que oferecem a API): OAuth2 com client_credentials, certificado de cliente (mTLS) e o recurso /cob, de
  cobrança imediata com QR Code dinâmico.

  As chamadas HTTPS vão pelo curl, que confere o certificado e o nome do servidor do PSP (o OpenSSL do FPC 3.2.2 não
  confere o nome). A configuração do curl, com o segredo, vai pela entrada padrão, para não aparecer na lista de
  processos. Esta unit não usa a LCL: as chamadas são bloqueantes e devem rodar fora da thread da tela. }

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils;

type

  TPixConfig = record
    Ativo: Boolean;
    { Endereço base da API Pix do PSP, sem a barra final (ex.: https://api.psp.com.br/api/v2). }
    UrlApi: string;
    { Endereço do OAuth2 do PSP (ex.: https://api.psp.com.br/oauth/token). }
    UrlToken: string;
    { Alguns PSPs pedem o grant_type em JSON em vez de formulário. }
    TokenEmJson: Boolean;
    ClientId: string;
    ClientSecret: string;
    Escopo: string;
    { Certificado e chave do cliente (PEM) que o PSP entrega. Vazios se o PSP não exigir mTLS. }
    Certificado: string;
    ChavePrivada: string;
    { Cadeia de certificados para conferir o PSP. Vazio usa a do sistema. }
    CertificadoCA: string;
    { Chave Pix que recebe (e-mail, telefone, CNPJ/CPF ou aleatória), cadastrada na conta do PSP. }
    Chave: string;
    { Valores em reais que a tela oferece. }
    Valores: array of Integer;
    { Validade do QR Code em segundos. }
    Expiracao: Integer;
    { Texto que aparece para quem paga. }
    Descricao: string;
    { Posição do botão PIX na tela principal; largura 0 usa o canto inferior direito. }
    BotaoX, BotaoY, BotaoLargura, BotaoAltura: Integer;
    { Código de tecla que também abre a tela do Pix; 0 = nenhuma. }
    Tecla: Integer;
    Curl: string;
  end;

  TPixStatus = (psAtiva, psConcluida, psRemovida, psDesconhecido);

  { TPixCliente }

  TPixCliente = class
  private
    FConfig: TPixConfig;
    FToken: string;
    FTokenValidade: TDateTime;
    FUltimoErro: string;
    function ChamaCurl(const Metodo, Url, Corpo, Autorizacao, TipoConteudo: string; out Resposta: string;
      out Codigo: Integer): Boolean;
    function ObtemToken: Boolean;
    function ChamaApi(const Metodo, Caminho, Corpo: string; out Resposta: string; out Codigo: Integer): Boolean;
  public
    constructor Create(const AConfig: TPixConfig);
    { Cria a cobrança imediata e devolve o texto do QR Code (Pix copia e cola). }
    function CriaCobranca(const Txid: string; Reais: Integer; out CopiaECola: string): Boolean;
    function Consulta(const Txid: string; out Status: TPixStatus): Boolean;
    { Remove a cobrança no PSP, para ela não poder mais ser paga. Falha se ela já tiver sido paga. }
    function Cancela(const Txid: string): Boolean;
    property UltimoErro: string read FUltimoErro;
  end;

{ Lê pix.txt (linhas chave=valor, # para comentário). Devolve False e o motivo se faltar algo obrigatório. }
function LeConfigPix(const Arquivo: string; out Config: TPixConfig; out Erro: string): Boolean;
{ Identificador da cobrança: 32 letras e dígitos, como a API pede (26 a 35). }
function NovoTxid: string;
function ValorPix(Reais: Integer): string;
function StatusPix(const Texto: string): TPixStatus;

implementation

uses
  Process, Pipes, base64, fpjson, jsonparser;

const
  ALFABETO_TXID = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';

function NovoTxid: string;
var
  Aleatorio: TFileStream;
  Bytes: array[0..31] of Byte;
  i: Integer;
begin
  FillChar(Bytes, SizeOf(Bytes), 0);
  try
    Aleatorio := TFileStream.Create('/dev/urandom', fmOpenRead or fmShareDenyNone);
    try
      Aleatorio.ReadBuffer(Bytes, SizeOf(Bytes));
    finally
      Aleatorio.Free;
    end;
  except
    Randomize;
    for i := 0 to High(Bytes) do
      Bytes[i] := Random(256);
  end;
  SetLength(Result, Length(Bytes));
  for i := 0 to High(Bytes) do
    Result[i + 1] := ALFABETO_TXID[(Bytes[i] mod Length(ALFABETO_TXID)) + 1];
end;

function ValorPix(Reais: Integer): string;
begin
  Result := IntToStr(Reais) + '.00';
end;

function StatusPix(const Texto: string): TPixStatus;
begin
  if Texto = 'ATIVA' then
    Result := psAtiva
  else if Texto = 'CONCLUIDA' then
    Result := psConcluida
  else if (Texto = 'REMOVIDA_PELO_USUARIO_RECEBEDOR') or (Texto = 'REMOVIDA_PELO_PSP') then
    Result := psRemovida
  else
    Result := psDesconhecido;
end;

function SimNao(const Texto: string): Boolean;
var
  T: string;
begin
  T := LowerCase(Trim(Texto));
  Result := (T = 'sim') or (T = '1') or (T = 's') or (T = 'true');
end;

function LeConfigPix(const Arquivo: string; out Config: TPixConfig; out Erro: string): Boolean;
var
  Linhas, Partes: TStringList;
  i, j, n, Igual: Integer;
  Linha, Nome, Valor: string;
begin
  Result := False;
  Erro := '';
  Config := Default(TPixConfig);
  Config.Ativo := True;
  Config.Escopo := 'cob.write cob.read';
  Config.Expiracao := 300;
  Config.Descricao := 'JukeLinux - creditos de musica';
  Config.Curl := 'curl';
  SetLength(Config.Valores, 0);

  if not FileExists(Arquivo) then
  begin
    Erro := 'arquivo ' + Arquivo + ' não existe';
    Exit;
  end;

  Linhas := TStringList.Create;
  Partes := TStringList.Create;
  try
    Linhas.LoadFromFile(Arquivo);
    for i := 0 to Linhas.Count - 1 do
    begin
      Linha := Trim(Linhas[i]);
      if (Linha = '') or (Linha[1] = '#') then
        Continue;
      Igual := Pos('=', Linha);
      if Igual = 0 then
        Continue;
      Nome := LowerCase(Trim(Copy(Linha, 1, Igual - 1)));
      Valor := Trim(Copy(Linha, Igual + 1, MaxInt));

      if Nome = 'ativo' then Config.Ativo := SimNao(Valor)
      else if Nome = 'url_api' then Config.UrlApi := Valor
      else if Nome = 'url_token' then Config.UrlToken := Valor
      else if Nome = 'token_json' then Config.TokenEmJson := SimNao(Valor)
      else if Nome = 'client_id' then Config.ClientId := Valor
      else if Nome = 'client_secret' then Config.ClientSecret := Valor
      else if Nome = 'escopo' then Config.Escopo := Valor
      else if Nome = 'certificado' then Config.Certificado := Valor
      else if Nome = 'chave_privada' then Config.ChavePrivada := Valor
      else if Nome = 'ca' then Config.CertificadoCA := Valor
      else if Nome = 'chave' then Config.Chave := Valor
      else if Nome = 'expiracao' then Config.Expiracao := StrToIntDef(Valor, 300)
      else if Nome = 'descricao' then Config.Descricao := Valor
      else if Nome = 'tecla' then Config.Tecla := StrToIntDef(Valor, 0)
      else if Nome = 'curl' then Config.Curl := Valor
      else if Nome = 'valores' then
      begin
        Partes.Clear;
        ExtractStrings([',', ';', ' '], [], PChar(Valor), Partes);
        SetLength(Config.Valores, 0);
        for j := 0 to Partes.Count - 1 do
        begin
          n := StrToIntDef(Partes[j], 0);
          if n > 0 then
          begin
            SetLength(Config.Valores, Length(Config.Valores) + 1);
            Config.Valores[High(Config.Valores)] := n;
          end;
        end;
      end
      else if Nome = 'botao' then
      begin
        Partes.Clear;
        ExtractStrings([',', ';', ' '], [], PChar(Valor), Partes);
        if Partes.Count = 4 then
        begin
          Config.BotaoX := StrToIntDef(Partes[0], 0);
          Config.BotaoY := StrToIntDef(Partes[1], 0);
          Config.BotaoLargura := StrToIntDef(Partes[2], 0);
          Config.BotaoAltura := StrToIntDef(Partes[3], 0);
        end;
      end;
    end;
  finally
    Partes.Free;
    Linhas.Free;
  end;

  if Config.UrlApi = '' then Erro := 'falta url_api'
  else if Config.UrlToken = '' then Erro := 'falta url_token'
  else if Config.ClientId = '' then Erro := 'falta client_id'
  else if Config.ClientSecret = '' then Erro := 'falta client_secret'
  else if Config.Chave = '' then Erro := 'falta chave'
  else if Length(Config.Valores) = 0 then Erro := 'falta valores'
  else if (Config.Expiracao < 60) or (Config.Expiracao > 3600) then Erro := 'expiracao deve ficar entre 60 e 3600';
  while (Config.UrlApi <> '') and (Config.UrlApi[Length(Config.UrlApi)] = '/') do
    SetLength(Config.UrlApi, Length(Config.UrlApi) - 1);
  Result := Erro = '';
end;

{ Texto entre aspas no formato do arquivo de configuração do curl. }
function AspasCurl(const Texto: string): string;
var
  i: Integer;
begin
  Result := '"';
  for i := 1 to Length(Texto) do
    case Texto[i] of
      '"', '\': Result := Result + '\' + Texto[i];
      #10: Result := Result + '\n';
      #13: Result := Result + '\r';
      #9: Result := Result + '\t';
    else
      Result := Result + Texto[i];
    end;
  Result := Result + '"';
end;

function CodificaUrl(const Texto: string): string;
var
  i: Integer;
begin
  Result := '';
  for i := 1 to Length(Texto) do
    if Texto[i] in ['A'..'Z', 'a'..'z', '0'..'9', '-', '_', '.', '~'] then
      Result := Result + Texto[i]
    else
      Result := Result + '%' + IntToHex(Ord(Texto[i]), 2);
end;

procedure LePipe(Fluxo: TStream; var Destino: string);
var
  Buffer: array[0..4095] of Char;
  Lidos: Integer;
  Pedaco: string;
begin
  FillChar(Buffer, SizeOf(Buffer), 0);
  while (Fluxo as TInputPipeStream).NumBytesAvailable > 0 do
  begin
    Lidos := Fluxo.Read(Buffer, SizeOf(Buffer));
    if Lidos <= 0 then
      Break;
    SetString(Pedaco, PChar(@Buffer[0]), Lidos);
    Destino := Destino + Pedaco;
  end;
end;

function TextoCurto(const Texto: string): string;
begin
  Result := StringReplace(Copy(Texto, 1, 200), #10, ' ', [rfReplaceAll]);
end;

{ TPixCliente }

constructor TPixCliente.Create(const AConfig: TPixConfig);
begin
  inherited Create;
  FConfig := AConfig;
end;

function TPixCliente.ChamaCurl(const Metodo, Url, Corpo, Autorizacao, TipoConteudo: string; out Resposta: string;
  out Codigo: Integer): Boolean;
var
  Processo: TProcess;
  Config, Saida, Erros: string;
  Fim: Integer;
begin
  Result := False;
  Resposta := '';
  Codigo := 0;

  Config := 'silent' + #10 + 'show-error' + #10 +
    'url = ' + AspasCurl(Url) + #10 +
    'request = ' + AspasCurl(Metodo) + #10 +
    'connect-timeout = 8' + #10 +
    'max-time = 20' + #10 +
    'write-out = ' + AspasCurl(#10 + '%{http_code}') + #10;
  if Autorizacao <> '' then
    Config := Config + 'header = ' + AspasCurl('Authorization: ' + Autorizacao) + #10;
  if TipoConteudo <> '' then
    Config := Config + 'header = ' + AspasCurl('Content-Type: ' + TipoConteudo) + #10;
  if Corpo <> '' then
    Config := Config + 'data-binary = ' + AspasCurl(Corpo) + #10;
  if FConfig.Certificado <> '' then
    Config := Config + 'cert = ' + AspasCurl(FConfig.Certificado) + #10;
  if FConfig.ChavePrivada <> '' then
    Config := Config + 'key = ' + AspasCurl(FConfig.ChavePrivada) + #10;
  if FConfig.CertificadoCA <> '' then
    Config := Config + 'cacert = ' + AspasCurl(FConfig.CertificadoCA) + #10;

  Saida := '';
  Erros := '';
  Processo := TProcess.Create(nil);
  try
    Processo.Executable := FConfig.Curl;
    Processo.Parameters.Add('--config');
    Processo.Parameters.Add('-');
    Processo.Options := [poUsePipes];
    try
      Processo.Execute;
    except
      on E: Exception do
      begin
        FUltimoErro := 'não consegui executar o curl: ' + E.Message;
        Exit;
      end;
    end;
    try
      Processo.Input.Write(Config[1], Length(Config));
    except
      { Se o curl morreu antes de ler, o erro aparece na saída de erro. }
    end;
    Processo.CloseInput;
    repeat
      LePipe(Processo.Output, Saida);
      LePipe(Processo.Stderr, Erros);
      if Processo.Running then
        Sleep(10);
    until not Processo.Running;
    LePipe(Processo.Output, Saida);
    LePipe(Processo.Stderr, Erros);

    if Processo.ExitCode <> 0 then
    begin
      FUltimoErro := 'curl (código ' + IntToStr(Processo.ExitCode) + '): ' + TextoCurto(Trim(Erros));
      Exit;
    end;
  finally
    Processo.Free;
  end;

  Fim := Length(Saida);
  while (Fim > 0) and (Saida[Fim] <> #10) do
    Dec(Fim);
  Codigo := StrToIntDef(Trim(Copy(Saida, Fim + 1, MaxInt)), 0);
  if Fim > 0 then
    Resposta := Copy(Saida, 1, Fim - 1)
  else
    Resposta := '';
  Result := True;
end;

function TPixCliente.ObtemToken: Boolean;
var
  Corpo, Tipo, Resposta: string;
  Codigo, Validade: Integer;
  Dados: TJSONData;
begin
  if (FToken <> '') and (Now < FTokenValidade) then
    Exit(True);
  Result := False;
  FToken := '';

  if FConfig.TokenEmJson then
  begin
    Corpo := '{"grant_type":"client_credentials"}';
    Tipo := 'application/json';
  end
  else
  begin
    Corpo := 'grant_type=client_credentials';
    if FConfig.Escopo <> '' then
      Corpo := Corpo + '&scope=' + CodificaUrl(FConfig.Escopo);
    Tipo := 'application/x-www-form-urlencoded';
  end;

  if not ChamaCurl('POST', FConfig.UrlToken, Corpo,
    'Basic ' + EncodeStringBase64(FConfig.ClientId + ':' + FConfig.ClientSecret), Tipo, Resposta, Codigo) then
    Exit;
  if (Codigo <> 200) and (Codigo <> 201) then
  begin
    FUltimoErro := 'token recusado (HTTP ' + IntToStr(Codigo) + '): ' + TextoCurto(Resposta);
    Exit;
  end;

  try
    Dados := GetJSON(Resposta);
    try
      FToken := (Dados as TJSONObject).Get('access_token', '');
      Validade := (Dados as TJSONObject).Get('expires_in', 300);
    finally
      Dados.Free;
    end;
  except
    on E: Exception do
    begin
      FUltimoErro := 'resposta do token não é JSON: ' + TextoCurto(Resposta);
      Exit;
    end;
  end;
  if FToken = '' then
  begin
    FUltimoErro := 'resposta do token sem access_token';
    Exit;
  end;
  if Validade < 60 then
    Validade := 60;
  FTokenValidade := Now + (Validade - 30) / SecsPerDay;
  Result := True;
end;

function TPixCliente.ChamaApi(const Metodo, Caminho, Corpo: string; out Resposta: string;
  out Codigo: Integer): Boolean;
var
  Tentativa: Integer;
begin
  Result := False;
  Resposta := '';
  Codigo := 0;
  for Tentativa := 1 to 2 do
  begin
    if not ObtemToken then
      Exit;
    if not ChamaCurl(Metodo, FConfig.UrlApi + Caminho, Corpo, 'Bearer ' + FToken, 'application/json',
      Resposta, Codigo) then
      Exit;
    { Token vencido antes da hora: pede outro uma vez. }
    if Codigo <> 401 then
      Break;
    FToken := '';
  end;
  Result := True;
end;

function TPixCliente.CriaCobranca(const Txid: string; Reais: Integer; out CopiaECola: string): Boolean;
var
  Pedido: TJSONObject;
  Dados: TJSONData;
  Corpo, Resposta: string;
  Codigo: Integer;
begin
  Result := False;
  FUltimoErro := '';
  CopiaECola := '';
  Pedido := TJSONObject.Create([
    'calendario', TJSONObject.Create(['expiracao', FConfig.Expiracao]),
    'valor', TJSONObject.Create(['original', ValorPix(Reais)]),
    'chave', FConfig.Chave,
    'solicitacaoPagador', FConfig.Descricao]);
  try
    Corpo := Pedido.AsJSON;
  finally
    Pedido.Free;
  end;

  if not ChamaApi('PUT', '/cob/' + Txid, Corpo, Resposta, Codigo) then
    Exit;
  if (Codigo <> 200) and (Codigo <> 201) then
  begin
    FUltimoErro := 'cobrança recusada (HTTP ' + IntToStr(Codigo) + '): ' + TextoCurto(Resposta);
    Exit;
  end;

  try
    Dados := GetJSON(Resposta);
    try
      CopiaECola := (Dados as TJSONObject).Get('pixCopiaECola', '');
    finally
      Dados.Free;
    end;
  except
    FUltimoErro := 'resposta da cobrança não é JSON: ' + TextoCurto(Resposta);
    Exit;
  end;
  if CopiaECola = '' then
  begin
    FUltimoErro := 'o PSP não devolveu pixCopiaECola (precisa da API Pix 2.x)';
    Exit;
  end;
  Result := True;
end;

function TPixCliente.Consulta(const Txid: string; out Status: TPixStatus): Boolean;
var
  Dados: TJSONData;
  Resposta: string;
  Codigo: Integer;
begin
  Result := False;
  FUltimoErro := '';
  Status := psDesconhecido;
  if not ChamaApi('GET', '/cob/' + Txid, '', Resposta, Codigo) then
    Exit;
  if Codigo <> 200 then
  begin
    FUltimoErro := 'consulta recusada (HTTP ' + IntToStr(Codigo) + '): ' + TextoCurto(Resposta);
    Exit;
  end;
  try
    Dados := GetJSON(Resposta);
    try
      Status := StatusPix((Dados as TJSONObject).Get('status', ''));
    finally
      Dados.Free;
    end;
  except
    FUltimoErro := 'resposta da consulta não é JSON: ' + TextoCurto(Resposta);
    Exit;
  end;
  Result := Status <> psDesconhecido;
  if not Result then
    FUltimoErro := 'status desconhecido: ' + TextoCurto(Resposta);
end;

function TPixCliente.Cancela(const Txid: string): Boolean;
var
  Resposta: string;
  Codigo: Integer;
begin
  Result := False;
  FUltimoErro := '';
  if not ChamaApi('PATCH', '/cob/' + Txid, '{"status":"REMOVIDA_PELO_USUARIO_RECEBEDOR"}', Resposta, Codigo) then
    Exit;
  if Codigo <> 200 then
  begin
    FUltimoErro := 'cancelamento recusado (HTTP ' + IntToStr(Codigo) + '): ' + TextoCurto(Resposta);
    Exit;
  end;
  Result := True;
end;

end.

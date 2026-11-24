unit Nuvem;

{ Conversa da jukebox com a nuvem da empresa (nuvem/ no repositório).

  A jukebox NÃO depende da internet: tudo o que acontece (dinheiro no noteiro, Pix, música pedida, fechamento do
  relógio) vai para uma fila em arquivo (nuvem-fila.txt) e é mandado quando der. A cada contato a nuvem devolve a
  licença da máquina assinada (licenca.pas); sem internet, vale a última licença guardada.

  - nuvem.txt (pasta da jukebox): "url = https://endereço-da-nuvem" (sem ele, nada é mandado). Opcional:
    "curl = /caminho/do/curl".
  - nuvem-segredo.txt: segredo sorteado no primeiro uso. A nuvem amarra o código da máquina a ele: outro aparelho
    com o mesmo código é recusado. Não copie este arquivo para outra máquina.
  - nuvem-fila.txt: um evento JSON por linha. Cada evento tem um id que não se repete (prefixo da instalação +
    sequência em nuvem-seq.txt): se a resposta se perder e a jukebox mandar de novo, a nuvem não conta duas vezes.
    Só sai da fila o que a nuvem confirmou.

  O contato roda numa thread (o curl pode demorar sem internet) e a fila só é mexida na thread principal (Tick).
  Sem LCL: usada pela jukebox e pelos testes. }

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpjson;

const
  ARQ_NUVEM = 'nuvem.txt';
  ARQ_NUVEM_FILA = 'nuvem-fila.txt';
  ARQ_NUVEM_SEGREDO = 'nuvem-segredo.txt';
  ARQ_NUVEM_SEQ = 'nuvem-seq.txt';
  NUVEM_MAX_EVENTOS = 500;
  NUVEM_MAX_FILA = 200000;   // a fila nunca passa disso (meses sem internet); os mais velhos saem
  NUVEM_JUNTA_PULSOS_S = 4;  // pulsos do noteiro com menos de 4 s entre eles viram uma nota só

type
  TRelogioNuvem = record
    Total, Parcial, PixParcial, PixTotal, PontoPct, Creditos: Int64;
  end;

  TSituacaoNuvem = (snDesligada, snSemContato, snPendente, snAtiva, snBloqueada, snRecusada);

  TNuvemTarefa = class(TThread)
  private
    FCurl, FUrl, FSegredo, FCorpo: string;
  public
    Resposta, Erro: string;
    Codigo: Integer;
    constructor Create(const ACurl, AUrl, ASegredo, ACorpo: string);
    procedure Execute; override;
  end;

  TLicencaRecebida = procedure(const Texto: string) of object;
  TRegistroNuvem = procedure(const Texto: string) of object;

  TNuvem = class
  private
    FPasta, FUrl, FCurl, FCodigo, FVersao, FSegredo, FPrefixo: string;
    FSeq: Int64;
    FTarefa: TNuvemTarefa;
    FProximo: TDateTime;
    FIntervalo: Integer;
    FFalhas: Integer;
    FPulsos: Integer;
    FPulsosDesde, FUltimoPulso: TDateTime;
    FEnviados: Integer;
    procedure Enfileira(Ev: TJSONObject; Quando: TDateTime);
    procedure JuntaPulsos(Agora: TDateTime; Forca: Boolean);
    function MontaCorpo(const Relogio: TRelogioNuvem; out Ids: Integer): string;
    procedure TrataResposta(T: TNuvemTarefa);
    procedure TiraDaFila(Recebidos: TJSONArray);
    procedure Registra(const Texto: string);
  public
    Situacao: TSituacaoNuvem;
    UltimoErro: string;
    UltimoContato: TDateTime;
    OnLicenca: TLicencaRecebida;
    OnRegistro: TRegistroNuvem;
    constructor Create(const APasta, ACodigo, AVersao: string);
    destructor Destroy; override;
    function Ligada: Boolean;
    { eventos (chamar na thread principal) }
    procedure Pulso(Agora: TDateTime);   // R$ 1 no noteiro (um pulso do relógio)
    procedure Credito(const Origem: string; Reais, Creditos: Integer; Agora: TDateTime);
    procedure Musica(const Cd, NomeMusica: string; Agora: TDateTime);
    procedure Fechamento(Parcial, Pix, Ponto: Int64; Agora: TDateTime);
    procedure Ligou(Agora: TDateTime);
    { chamar a cada segundo: junta os pulsos, começa um contato na hora certa e trata a resposta }
    procedure Tick(const Relogio: TRelogioNuvem; Agora: TDateTime);
    { espera o contato em andamento terminar (para os testes e ao fechar) }
    procedure Espera;
    function TamanhoDaFila: Integer;
    function DescreveSituacao: string;
    property Url: string read FUrl;
  end;

function LeConfigNuvem(const Arquivo: string; out Url, Curl: string): Boolean;
function SegundosUnix(Quando: TDateTime): Int64;

implementation

uses
  BaseUnix, process, pipes, jsonparser, DateUtils, base64;

function SegundosUnix(Quando: TDateTime): Int64;
begin
  Result := DateTimeToUnix(LocalTimeToUniversal(Quando));
end;

function LeConfigNuvem(const Arquivo: string; out Url, Curl: string): Boolean;
var
  L: TStringList;
  i, p: Integer;
  Linha, Nome, Valor: string;
begin
  Url := '';
  Curl := 'curl';
  Result := False;
  if not FileExists(Arquivo) then
    Exit;
  L := TStringList.Create;
  try
    try
      L.LoadFromFile(Arquivo);
    except
      Exit;
    end;
    for i := 0 to L.Count - 1 do
    begin
      Linha := Trim(L[i]);
      if (Linha = '') or (Linha[1] = '#') then
        Continue;
      p := Pos('=', Linha);
      if p = 0 then
      begin
        { só o endereço na linha também vale }
        if (Url = '') and ((Pos('https://', Linha) = 1) or (Pos('http://', Linha) = 1)) then
          Url := Linha;
        Continue;
      end;
      Nome := LowerCase(Trim(Copy(Linha, 1, p - 1)));
      Valor := Trim(Copy(Linha, p + 1, MaxInt));
      if Nome = 'url' then
        Url := Valor
      else if Nome = 'curl' then
        Curl := Valor;
    end;
  finally
    L.Free;
  end;
  while (Url <> '') and (Url[Length(Url)] = '/') do
    SetLength(Url, Length(Url) - 1);
  Result := (Pos('https://', Url) = 1) or (Pos('http://', Url) = 1);
  if not Result then
    Url := '';
end;

function LeTexto(const Arquivo: string): string;
var
  L: TStringList;
begin
  Result := '';
  if not FileExists(Arquivo) then
    Exit;
  L := TStringList.Create;
  try
    try
      L.LoadFromFile(Arquivo);
      if L.Count > 0 then
        Result := Trim(L[0]);
    except
      Result := '';
    end;
  finally
    L.Free;
  end;
end;

procedure GravaTexto(const Arquivo, Texto: string);
var
  F: TFileStream;
begin
  F := TFileStream.Create(Arquivo + '.novo', fmCreate);
  try
    if Texto <> '' then
      F.WriteBuffer(Texto[1], Length(Texto));
  finally
    F.Free;
  end;
  if FpRename(Arquivo + '.novo', Arquivo) <> 0 then
    raise EInOutError.Create('não consegui gravar ' + Arquivo);
end;

function NovoSegredo: string;
const
  LETRAS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_';
var
  F: TFileStream;
  Bytes: array[0..31] of Byte;
  i: Integer;
begin
  F := TFileStream.Create('/dev/urandom', fmOpenRead);
  try
    F.ReadBuffer(Bytes, SizeOf(Bytes));
  finally
    F.Free;
  end;
  Result := '';
  for i := 0 to High(Bytes) do
    Result := Result + LETRAS[(Bytes[i] and 63) + 1] + LETRAS[((Bytes[i] shr 2) and 63) + 1];
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

procedure LePipe(Fluxo: TStream; var Destino: string);
var
  Buffer: array[0..4095] of Char;
  Lidos: Integer;
  Pedaco: string;
begin
  while (Fluxo as TInputPipeStream).NumBytesAvailable > 0 do
  begin
    Lidos := Fluxo.Read(Buffer, SizeOf(Buffer));
    if Lidos <= 0 then
      Break;
    SetString(Pedaco, PChar(@Buffer[0]), Lidos);
    Destino := Destino + Pedaco;
  end;
end;

{ TNuvemTarefa }

constructor TNuvemTarefa.Create(const ACurl, AUrl, ASegredo, ACorpo: string);
begin
  FCurl := ACurl;
  FUrl := AUrl;
  FSegredo := ASegredo;
  FCorpo := ACorpo;
  FreeOnTerminate := False;
  inherited Create(False);
end;

procedure TNuvemTarefa.Execute;
var
  Processo: TProcess;
  Config, Saida, Erros: string;
  Fim: Integer;
begin
  { a configuração (com o segredo e o corpo) vai pela entrada padrão: não aparece na lista de processos }
  Config := 'silent' + #10 + 'show-error' + #10 +
    'url = ' + AspasCurl(FUrl + '/api/v1/contato') + #10 +
    'request = "POST"' + #10 +
    'connect-timeout = 10' + #10 +
    'max-time = 40' + #10 +
    'header = ' + AspasCurl('Authorization: Bearer ' + FSegredo) + #10 +
    'header = "Content-Type: application/json"' + #10 +
    'data-binary = ' + AspasCurl(FCorpo) + #10 +
    'write-out = ' + AspasCurl(#10 + '%{http_code}') + #10;
  Saida := '';
  Erros := '';
  Processo := TProcess.Create(nil);
  try
    Processo.Executable := FCurl;
    Processo.Parameters.Add('--config');
    Processo.Parameters.Add('-');
    Processo.Options := [poUsePipes];
    try
      Processo.Execute;
    except
      on E: Exception do
      begin
        Erro := 'não consegui executar o curl: ' + E.Message;
        Exit;
      end;
    end;
    try
      Processo.Input.Write(Config[1], Length(Config));
    except
      { se o curl morreu antes de ler, o erro aparece na saída de erro }
    end;
    Processo.CloseInput;
    repeat
      LePipe(Processo.Output, Saida);
      LePipe(Processo.Stderr, Erros);
      if Processo.Running then
        Sleep(20);
    until not Processo.Running;
    LePipe(Processo.Output, Saida);
    LePipe(Processo.Stderr, Erros);
    if Processo.ExitCode <> 0 then
    begin
      Erro := 'sem contato (curl ' + IntToStr(Processo.ExitCode) + ': ' +
        StringReplace(Copy(Trim(Erros), 1, 150), #10, ' ', [rfReplaceAll]) + ')';
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
    Resposta := Copy(Saida, 1, Fim - 1);
end;

{ TNuvem }

constructor TNuvem.Create(const APasta, ACodigo, AVersao: string);
var
  Ok: Boolean;
begin
  inherited Create;
  FPasta := IncludeTrailingPathDelimiter(APasta);
  FCodigo := ACodigo;
  FVersao := AVersao;
  FIntervalo := 60;
  Situacao := snDesligada;
  Ok := LeConfigNuvem(FPasta + ARQ_NUVEM, FUrl, FCurl);
  if Ok then
    Situacao := snSemContato;
  FSegredo := LeTexto(FPasta + ARQ_NUVEM_SEGREDO);
  if Length(FSegredo) < 32 then
  begin
    FSegredo := NovoSegredo;
    GravaTexto(FPasta + ARQ_NUVEM_SEGREDO, FSegredo + #10);
    FpChmod(FPasta + ARQ_NUVEM_SEGREDO, &600);
  end;
  { o prefixo dos ids é desta instalação: uma jukebox reinstalada não repete os ids da anterior }
  FPrefixo := Copy(FSegredo, 1, 8);
  FSeq := StrToInt64Def(LeTexto(FPasta + ARQ_NUVEM_SEQ), 0);
  FProximo := 0;
end;

destructor TNuvem.Destroy;
begin
  JuntaPulsos(Now, True);
  if FTarefa <> nil then
  begin
    FTarefa.WaitFor;
    FTarefa.Free;
  end;
  inherited Destroy;
end;

function TNuvem.Ligada: Boolean;
begin
  Result := FUrl <> '';
end;

procedure TNuvem.Registra(const Texto: string);
begin
  if Assigned(OnRegistro) then
    OnRegistro('Nuvem: ' + Texto);
end;

procedure TNuvem.Enfileira(Ev: TJSONObject; Quando: TDateTime);
var
  F: TextFile;
begin
  try
    Inc(FSeq);
    Ev.Add('id', FPrefixo + '-' + IntToStr(FSeq));
    Ev.Add('quando', SegundosUnix(Quando));
    try
      GravaTexto(FPasta + ARQ_NUVEM_SEQ, IntToStr(FSeq) + #10);
      AssignFile(F, FPasta + ARQ_NUVEM_FILA);
      if FileExists(FPasta + ARQ_NUVEM_FILA) then
        Append(F)
      else
        Rewrite(F);
      Writeln(F, Ev.AsJSON);
      CloseFile(F);
    except
      on E: Exception do
        Registra('nao gravei o evento na fila (' + E.Message + ')');
    end;
  finally
    Ev.Free;
  end;
end;

procedure TNuvem.JuntaPulsos(Agora: TDateTime; Forca: Boolean);
var
  Ev: TJSONObject;
begin
  if FPulsos = 0 then
    Exit;
  if not Forca and (SecondsBetween(Agora, FUltimoPulso) < NUVEM_JUNTA_PULSOS_S) then
    Exit;
  Ev := TJSONObject.Create(['tipo', 'credito', 'origem', 'noteiro', 'reais', FPulsos]);
  FPulsos := 0;
  Enfileira(Ev, FPulsosDesde);
end;

procedure TNuvem.Pulso(Agora: TDateTime);
begin
  if FPulsos = 0 then
    FPulsosDesde := Agora;
  Inc(FPulsos);
  FUltimoPulso := Agora;
end;

procedure TNuvem.Credito(const Origem: string; Reais, Creditos: Integer; Agora: TDateTime);
begin
  JuntaPulsos(Agora, True);
  Enfileira(TJSONObject.Create(['tipo', 'credito', 'origem', Origem, 'reais', Reais, 'creditos', Creditos]), Agora);
end;

procedure TNuvem.Musica(const Cd, NomeMusica: string; Agora: TDateTime);
begin
  Enfileira(TJSONObject.Create(['tipo', 'musica', 'cd', Cd, 'musica', NomeMusica]), Agora);
end;

procedure TNuvem.Fechamento(Parcial, Pix, Ponto: Int64; Agora: TDateTime);
begin
  JuntaPulsos(Agora, True);
  Enfileira(TJSONObject.Create(['tipo', 'fechamento', 'parcial', Parcial, 'pix', Pix, 'ponto', Ponto]), Agora);
end;

procedure TNuvem.Ligou(Agora: TDateTime);
begin
  Enfileira(TJSONObject.Create(['tipo', 'ligou', 'versao', FVersao]), Agora);
end;

function TNuvem.TamanhoDaFila: Integer;
var
  L: TStringList;
begin
  Result := 0;
  if not FileExists(FPasta + ARQ_NUVEM_FILA) then
    Exit;
  L := TStringList.Create;
  try
    L.LoadFromFile(FPasta + ARQ_NUVEM_FILA);
    Result := L.Count;
  finally
    L.Free;
  end;
end;

function TNuvem.MontaCorpo(const Relogio: TRelogioNuvem; out Ids: Integer): string;
var
  L: TStringList;
  Corpo, R: TJSONObject;
  Eventos: TJSONArray;
  Dado: TJSONData;
  i: Integer;
begin
  Ids := 0;
  Corpo := TJSONObject.Create(['codigo', FCodigo, 'versao', FVersao]);
  try
    R := TJSONObject.Create(['total', Relogio.Total, 'parcial', Relogio.Parcial, 'pix_parcial', Relogio.PixParcial,
      'pix_total', Relogio.PixTotal, 'ponto_pct', Relogio.PontoPct, 'creditos', Relogio.Creditos]);
    Corpo.Add('relogio', R);
    Eventos := TJSONArray.Create;
    Corpo.Add('eventos', Eventos);
    if FileExists(FPasta + ARQ_NUVEM_FILA) then
    begin
      L := TStringList.Create;
      try
        L.LoadFromFile(FPasta + ARQ_NUVEM_FILA);
        for i := 0 to L.Count - 1 do
        begin
          if Eventos.Count >= NUVEM_MAX_EVENTOS then
            Break;
          if Trim(L[i]) = '' then
            Continue;
          try
            Dado := GetJSON(L[i]);
          except
            Continue;  // linha estragada (falta de luz no meio da gravação): sai da fila no próximo TiraDaFila
          end;
          if Dado is TJSONObject then
            Eventos.Add(Dado)
          else
            Dado.Free;
        end;
      finally
        L.Free;
      end;
    end;
    Ids := Eventos.Count;
    Result := Corpo.AsJSON;
  finally
    Corpo.Free;
  end;
end;

procedure TNuvem.TiraDaFila(Recebidos: TJSONArray);
var
  L, Ficam: TStringList;
  Confirmados: TStringList;
  i: Integer;
  Dado: TJSONData;
  Id: string;
begin
  if not FileExists(FPasta + ARQ_NUVEM_FILA) then
    Exit;
  L := TStringList.Create;
  Ficam := TStringList.Create;
  Confirmados := TStringList.Create;
  try
    Confirmados.Sorted := True;
    Confirmados.Duplicates := dupIgnore;
    if Recebidos <> nil then
      for i := 0 to Recebidos.Count - 1 do
        Confirmados.Add(Recebidos.Strings[i]);
    L.LoadFromFile(FPasta + ARQ_NUVEM_FILA);
    for i := 0 to L.Count - 1 do
    begin
      if Trim(L[i]) = '' then
        Continue;
      Id := '';
      try
        Dado := GetJSON(L[i]);
        try
          if Dado is TJSONObject then
            Id := TJSONObject(Dado).Get('id', '');
        finally
          Dado.Free;
        end;
      except
        Continue;  // linha estragada sai da fila
      end;
      if (Id <> '') and (Confirmados.IndexOf(Id) < 0) then
        Ficam.Add(L[i]);
    end;
    { a fila não cresce para sempre: se passar do limite, ficam os mais novos }
    while Ficam.Count > NUVEM_MAX_FILA do
      Ficam.Delete(0);
    Ficam.LineBreak := #10;
    GravaTexto(FPasta + ARQ_NUVEM_FILA, Ficam.Text);
  finally
    Confirmados.Free;
    Ficam.Free;
    L.Free;
  end;
end;

procedure TNuvem.TrataResposta(T: TNuvemTarefa);
var
  Dado: TJSONData;
  R: TJSONObject;
  Sit, Licenca: string;
  Antes: Integer;
begin
  if T.Erro <> '' then
  begin
    UltimoErro := T.Erro;
    Inc(FFalhas);
    if FFalhas = 1 then
      Registra(T.Erro);
    if Situacao <> snRecusada then
      Situacao := snSemContato;
    Exit;
  end;
  Dado := nil;
  try
    try
      Dado := GetJSON(T.Resposta);
    except
      Dado := nil;
    end;
    if not (Dado is TJSONObject) then
    begin
      UltimoErro := 'resposta estranha da nuvem (HTTP ' + IntToStr(T.Codigo) + ')';
      Inc(FFalhas);
      if FFalhas = 1 then
        Registra(UltimoErro);
      Situacao := snSemContato;
      Exit;
    end;
    R := TJSONObject(Dado);
    if T.Codigo <> 200 then
    begin
      UltimoErro := 'HTTP ' + IntToStr(T.Codigo);
      if R.Find('erro') is TJSONString then
        UltimoErro := TJSONString(R.Find('erro')).AsString;
      Inc(FFalhas);
      if FFalhas = 1 then
        Registra('recusou o contato: ' + UltimoErro);
      if T.Codigo = 403 then
        Situacao := snRecusada
      else
        Situacao := snSemContato;
      Exit;
    end;
    if FFalhas > 0 then
      Registra('contato de volta');
    FFalhas := 0;
    UltimoErro := '';
    UltimoContato := Now;
    FIntervalo := R.Get('intervalo', 60);
    if (FIntervalo < 10) or (FIntervalo > 3600) then
      FIntervalo := 60;
    Antes := TamanhoDaFila;
    if R.Find('recebidos') is TJSONArray then
      TiraDaFila(TJSONArray(R.Find('recebidos')));
    Inc(FEnviados, Antes - TamanhoDaFila);
    Sit := '';
    if R.Find('situacao') is TJSONString then
      Sit := TJSONString(R.Find('situacao')).AsString;
    if Sit = 'pendente' then
      Situacao := snPendente
    else if Sit = 'ativa' then
      Situacao := snAtiva
    else if Sit = 'bloqueada' then
      Situacao := snBloqueada;
    { a licença vem em base64 (só ASCII): os bytes saem exatos, sem conversão de página de código do fpjson }
    if R.Find('licenca_b64') is TJSONString then
    begin
      try
        Licenca := DecodeStringBase64(TJSONString(R.Find('licenca_b64')).AsString, True);
      except
        Licenca := '';
      end;
      if (Licenca <> '') and Assigned(OnLicenca) then
        OnLicenca(Licenca);
    end;
  finally
    Dado.Free;
  end;
end;

procedure TNuvem.Tick(const Relogio: TRelogioNuvem; Agora: TDateTime);
var
  Corpo: string;
  Ids, Pausa: Integer;
begin
  JuntaPulsos(Agora, False);
  if not Ligada then
    Exit;
  if FTarefa <> nil then
  begin
    if not FTarefa.Finished then
      Exit;
    TrataResposta(FTarefa);
    FreeAndNil(FTarefa);
    if FFalhas > 0 then
    begin
      { sem internet, espera mais a cada falha (até 10 min), para não ficar chamando o curl à toa }
      Pausa := FIntervalo * FFalhas;
      if Pausa > 600 then
        Pausa := 600;
    end
    else if TamanhoDaFila > 0 then
      Pausa := 2  // ainda tem fila (mais de 500 eventos): o próximo contato vai logo
    else
      Pausa := FIntervalo;
    FProximo := Agora + Pausa / SecsPerDay;
    Exit;
  end;
  if Agora < FProximo then
    Exit;
  Corpo := MontaCorpo(Relogio, Ids);
  FTarefa := TNuvemTarefa.Create(FCurl, FUrl, FSegredo, Corpo);
end;

procedure TNuvem.Espera;
begin
  if FTarefa <> nil then
    FTarefa.WaitFor;
end;

function TNuvem.DescreveSituacao: string;
begin
  case Situacao of
    snDesligada: Result := 'nuvem desligada (sem nuvem.txt)';
    snSemContato: Result := 'sem contato com a nuvem';
    snPendente: Result := 'aguardando a licença da empresa';
    snAtiva: Result := 'liberada';
    snBloqueada: Result := 'bloqueada pela empresa';
    snRecusada: Result := 'recusada pela nuvem';
  end;
  if UltimoErro <> '' then
    Result := Result + ' (' + UltimoErro + ')';
end;

initialization
  { Os nomes de arquivo no Linux e o JSON da nuvem são UTF-8. A jukebox (LCL) já roda com UTF-8 como página de
    código padrão (LazUTF8); aqui garante o mesmo para os testes e ferramentas sem LCL. Sem isso o fpjson converte
    os textos e "ANUNCIAÇÃO" chega estragado na nuvem. }
  if DefaultSystemCodePage <> CP_UTF8 then
  begin
    DefaultSystemCodePage := CP_UTF8;
    DefaultFileSystemCodePage := CP_UTF8;
    DefaultRTLFileSystemCodePage := CP_UTF8;
  end;
end.

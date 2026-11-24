unit Licenca;

{ Licença da JukeLinux Nova, emitida pela nuvem (no lugar do pendrive-chave da original e da contra-senha).

  - Código da máquina: 16 dígitos (NNNN-NNNN-NNNN-NNNN) tirados do número de série do disco onde está o sistema
    (/dev/disk/by-id). Uma imagem do HD clonada para outra máquina tem outro código. Sem serial (máquina virtual),
    usa o /etc/machine-id. É ele que aparece no painel da nuvem.
  - licenca.txt: texto assinado pela nuvem com Ed25519 (formato em nuvem/src/licenca.js): código, situação
    (ativa/bloqueada), validade, prazo para falar com a nuvem e a data de emissão. A jukebox confere a assinatura com
    a chave pública embutida (licenca_publica.inc), sem internet: só a nuvem, que tem a chave privada, emite
    licença. Mexer em qualquer letra do arquivo invalida a assinatura.
  - A licença chega pela internet (nuvem.pas, a cada contato) ou num pendrive (licenca.txt baixado no painel).
    Uma licença só substitui outra mais nova ou igual (data de emissão), então não dá para voltar uma antiga.
  - licenca-dia.txt guarda o último dia visto: atrasar o relógio da máquina não estende a validade. O dia
    considerado também nunca é anterior ao da emissão da licença.

  A assinatura é conferida pela libcrypto do sistema (OpenSSL 3, que o Linux Mint já traz), carregada na hora.

  Sem LCL: usada pela jukebox e pelos testes. }

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils;

{ A chave pública de verdade fica em licenca_publica.inc. Os testes compilam com -dLICENCA_DESENVOLVIMENTO (modo
  "Teste" do jukelinux.lpi) para usar a de desenvolvimento, cuja privada está no git. }
{$IFDEF LICENCA_DESENVOLVIMENTO}
{$I licenca_publica.desenvolvimento.inc}
{$ELSE}
{$I licenca_publica.inc}
{$ENDIF}

const
  ARQ_LICENCA = 'licenca.txt';
  ARQ_LICENCA_DIA = 'licenca-dia.txt';
  CABECALHO_LICENCA = 'JUKELINUX NOVA LICENCA 1';

type
  TEstadoLicenca = (elValida, elSemLicenca, elOutraMaquina, elAssinaturaErrada, elVencida, elBloqueada,
    elSemContato, elSemOpenSSL);

  TLicenca = record
    Estado: TEstadoLicenca;
    Codigo: string;          // da máquina, com os tracinhos
    Validade: string;        // 'permanente' ou AAAA-MM-DD
    ContatoAte: string;      // 'nunca' ou AAAA-MM-DD
    Cliente: string;
    Emitida: Int64;          // segundos desde 1970 (UTC)
    Hoje: TDateTime;         // o dia considerado (nunca antes do último dia visto nem da emissão)
  end;

{ Texto que identifica a máquina (serial do disco do sistema ou machine-id). }
function IdentidadeDaMaquina: string;
{ Código de 16 dígitos mostrado na tela de ativação e no painel da nuvem. }
function CodigoDaMaquina(const Identidade: string): string;

{ Confere a assinatura Ed25519 (base64) de Mensagem com a chave pública da licença. }
function AssinaturaConfere(const Mensagem, AssinaturaBase64: string; const Chave: array of Byte): Boolean;
{ Confere um texto de licença para o código da máquina, no dia Hoje. Preenche L. }
function ConfereTextoLicenca(const Texto, Codigo: string; Hoje: TDateTime; out L: TLicenca): TEstadoLicenca;

{ Lê e confere o licenca.txt da pasta. }
function LeLicenca(const Pasta: string; Agora: TDateTime): TLicenca;
{ Instala uma licença nova (vinda da nuvem ou do pendrive) se a assinatura confere, é desta máquina e não é mais
  velha que a atual. Devolve o estado da licença nova (elAssinaturaErrada/elOutraMaquina quando recusada). }
function InstalaLicenca(const Pasta, Texto: string; Agora: TDateTime; out Instalou: Boolean): TEstadoLicenca;
{ Guarda o último dia visto (chamar com a licença válida). }
procedure GravaUltimoDia(const Pasta: string; Dia: TDateTime);

function SoDigitos(const Texto: string): string;
function DescreveEstado(E: TEstadoLicenca): string;
function DataDaLicenca(const Texto: string; out Data: TDateTime): Boolean;

implementation

uses
  BaseUnix, sha1, base64, dynlibs, ctypes, DateUtils;

function SoDigitos(const Texto: string): string;
var
  i: Integer;
begin
  Result := '';
  for i := 1 to Length(Texto) do
    if Texto[i] in ['0'..'9'] then
      Result := Result + Texto[i];
end;

function DescreveEstado(E: TEstadoLicenca): string;
begin
  case E of
    elValida: Result := 'válida';
    elSemLicenca: Result := 'sem licença';
    elOutraMaquina: Result := 'licença de outra máquina';
    elAssinaturaErrada: Result := 'licença com assinatura errada';
    elVencida: Result := 'licença vencida';
    elBloqueada: Result := 'máquina bloqueada pela empresa';
    elSemContato: Result := 'passou do prazo sem falar com a nuvem';
    elSemOpenSSL: Result := 'sem a libcrypto (OpenSSL) para conferir a licença';
  end;
end;

function LeArquivo(const Arquivo: string): string;
var
  F: TFileStream;
begin
  Result := '';
  if not FileExists(Arquivo) then
    Exit;
  try
    F := TFileStream.Create(Arquivo, fmOpenRead or fmShareDenyNone);
    try
      if F.Size > 65536 then
        Exit;
      SetLength(Result, F.Size);
      if F.Size > 0 then
        F.ReadBuffer(Result[1], F.Size);
    finally
      F.Free;
    end;
  except
    Result := '';
  end;
end;

function PrimeiraLinhaDe(const Arquivo: string): string;
var
  i: Integer;
begin
  Result := LeArquivo(Arquivo);
  i := Pos(#10, Result);
  if i > 0 then
    SetLength(Result, i - 1);
  Result := Trim(Result);
end;

{ Grava inteiro ou nada: escreve num .novo e troca pelo nome certo. }
procedure GravaArquivo(const Arquivo, Texto: string);
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

{ ------------------------------------------------------------------------------------------------------------
  Código da máquina }

function LeLink(const Caminho: string): string;
begin
  Result := fpReadLink(Caminho);
end;

function DiscoDoSistema: string;
var
  Montagens: TStringList;
  i: Integer;
  Partes: TStringArray;
  Dispositivo, Bloco, Pai: string;
begin
  Result := '';
  Montagens := TStringList.Create;
  try
    try
      Montagens.LoadFromFile('/proc/mounts');
    except
      Exit;
    end;
    Dispositivo := '';
    for i := 0 to Montagens.Count - 1 do
    begin
      Partes := Montagens[i].Split([' ']);
      if (Length(Partes) > 1) and (Partes[1] = '/') and (Pos('/dev/', Partes[0]) = 1) then
        Dispositivo := Partes[0];
    end;
  finally
    Montagens.Free;
  end;
  if Dispositivo = '' then
    Exit;
  Dispositivo := ExpandFileName(Dispositivo);
  Bloco := ExtractFileName(LeLink(Dispositivo));
  if Bloco = '' then
    Bloco := ExtractFileName(Dispositivo);
  { partição -> disco: /sys/class/block/sda2 aponta para .../block/sda/sda2 }
  Pai := ExtractFileName(ExcludeTrailingPathDelimiter(ExtractFileDir(LeLink('/sys/class/block/' + Bloco))));
  if (Pai <> '') and (Pai <> 'block') then
    Result := Pai
  else
    Result := Bloco;
end;

function IdentidadeDaMaquina: string;
var
  Busca: TSearchRec;
  Disco, Alvo, Melhor: string;
begin
  Result := '';
  Disco := DiscoDoSistema;
  Melhor := '';
  if (Disco <> '') and (FindFirst('/dev/disk/by-id/*', faAnyFile, Busca) = 0) then
  begin
    repeat
      Alvo := ExtractFileName(LeLink('/dev/disk/by-id/' + Busca.Name));
      if (Alvo = Disco) and (Pos('-part', Busca.Name) = 0) then
        { ata-/nvme-/scsi- trazem modelo e serial; wwn- é só o número }
        if (Melhor = '') or (Pos('wwn-', Melhor) = 1) then
          Melhor := Busca.Name;
    until FindNext(Busca) <> 0;
    FindClose(Busca);
  end;
  if Melhor <> '' then
    Result := 'disco:' + Melhor
  else
  begin
    Result := PrimeiraLinhaDe('/etc/machine-id');
    if Result <> '' then
      Result := 'maquina:' + Result
    else
      Result := 'host:' + GetEnvironmentVariable('HOSTNAME');
  end;
end;

function DigitosDe(const Digest: TSHA1Digest; Inicio, Bytes, Quantos: Integer): string;
var
  Valor: QWord;
  i: Integer;
begin
  Valor := 0;
  for i := Inicio to Inicio + Bytes - 1 do
    Valor := (Valor shl 8) or Digest[i];
  Result := IntToStr(Valor);
  while Length(Result) < Quantos do
    Result := '0' + Result;
  Result := Copy(Result, Length(Result) - Quantos + 1, Quantos);
end;

function Agrupa(const Digitos: string): string;
var
  i: Integer;
begin
  Result := '';
  for i := 1 to Length(Digitos) do
  begin
    if (i > 1) and ((i - 1) mod 4 = 0) then
      Result := Result + '-';
    Result := Result + Digitos[i];
  end;
end;

function CodigoDaMaquina(const Identidade: string): string;
begin
  Result := Agrupa(DigitosDe(SHA1String('JukeLinux Nova|' + Identidade), 0, 8, 16));
end;

{ ------------------------------------------------------------------------------------------------------------
  Ed25519 pela libcrypto (OpenSSL 3), carregada na primeira vez }

const
  NID_ED25519 = 1087;

type
  TNovoPkey = function(Tipo: cint; Motor: Pointer; Chave: PByte; Tamanho: csize_t): Pointer; cdecl;
  TLiberaPkey = procedure(Pkey: Pointer); cdecl;
  TNovoCtx = function: Pointer; cdecl;
  TLiberaCtx = procedure(Ctx: Pointer); cdecl;
  TVerificaInicio = function(Ctx: Pointer; PCtx: PPointer; Tipo, Motor, Pkey: Pointer): cint; cdecl;
  TVerifica = function(Ctx: Pointer; Assinatura: PByte; TamAss: csize_t; Dados: PByte; TamDados: csize_t): cint; cdecl;

var
  Libcrypto: TLibHandle = NilHandle;
  Tentou: Boolean = False;
  NovoPkey: TNovoPkey;
  LiberaPkey: TLiberaPkey;
  NovoCtx: TNovoCtx;
  LiberaCtx: TLiberaCtx;
  VerificaInicio: TVerificaInicio;
  Verifica: TVerifica;

function CarregaLibcrypto: Boolean;
const
  NOMES: array[0..2] of string = ('libcrypto.so.3', 'libcrypto.so', 'libcrypto.so.1.1');
var
  i: Integer;
begin
  if not Tentou then
  begin
    Tentou := True;
    for i := 0 to High(NOMES) do
    begin
      Libcrypto := LoadLibrary(NOMES[i]);
      if Libcrypto <> NilHandle then
        Break;
    end;
    if Libcrypto <> NilHandle then
    begin
      Pointer(NovoPkey) := GetProcedureAddress(Libcrypto, 'EVP_PKEY_new_raw_public_key');
      Pointer(LiberaPkey) := GetProcedureAddress(Libcrypto, 'EVP_PKEY_free');
      Pointer(NovoCtx) := GetProcedureAddress(Libcrypto, 'EVP_MD_CTX_new');
      Pointer(LiberaCtx) := GetProcedureAddress(Libcrypto, 'EVP_MD_CTX_free');
      Pointer(VerificaInicio) := GetProcedureAddress(Libcrypto, 'EVP_DigestVerifyInit');
      Pointer(Verifica) := GetProcedureAddress(Libcrypto, 'EVP_DigestVerify');
    end;
  end;
  Result := (Libcrypto <> NilHandle) and Assigned(NovoPkey) and Assigned(LiberaPkey) and Assigned(NovoCtx)
    and Assigned(LiberaCtx) and Assigned(VerificaInicio) and Assigned(Verifica);
end;

function AssinaturaConfere(const Mensagem, AssinaturaBase64: string; const Chave: array of Byte): Boolean;
var
  Assinatura: string;
  Pkey, Ctx: Pointer;
begin
  Result := False;
  if (Length(Chave) <> 32) or not CarregaLibcrypto then
    Exit;
  try
    Assinatura := DecodeStringBase64(Trim(AssinaturaBase64), True);
  except
    Exit;
  end;
  if Length(Assinatura) <> 64 then
    Exit;
  Pkey := NovoPkey(NID_ED25519, nil, @Chave[0], 32);
  if Pkey = nil then
    Exit;
  Ctx := NovoCtx();
  try
    if (Ctx <> nil) and (VerificaInicio(Ctx, nil, nil, nil, Pkey) = 1) then
      Result := Verifica(Ctx, PByte(PChar(Assinatura)), 64, PByte(PChar(Mensagem)), Length(Mensagem)) = 1;
  finally
    if Ctx <> nil then
      LiberaCtx(Ctx);
    LiberaPkey(Pkey);
  end;
end;

{ ------------------------------------------------------------------------------------------------------------
  Licença }

function DataDaLicenca(const Texto: string; out Data: TDateTime): Boolean;
var
  A, M, D: Integer;
begin
  Result := False;
  Data := 0;
  if (Length(Texto) <> 10) or (Texto[5] <> '-') or (Texto[8] <> '-') then
    Exit;
  A := StrToIntDef(Copy(Texto, 1, 4), -1);
  M := StrToIntDef(Copy(Texto, 6, 2), -1);
  D := StrToIntDef(Copy(Texto, 9, 2), -1);
  Result := TryEncodeDate(A, M, D, Data);
end;

function Campo(Linhas: TStrings; const Nome: string): string;
var
  i: Integer;
begin
  Result := '';
  for i := 1 to Linhas.Count - 1 do
    if Pos(Nome + '=', Linhas[i]) = 1 then
      Exit(Copy(Linhas[i], Length(Nome) + 2, MaxInt));
end;

function ConfereTextoLicenca(const Texto, Codigo: string; Hoje: TDateTime; out L: TLicenca): TEstadoLicenca;
var
  i: Integer;
  Corpo, Normal: string;
  Linhas: TStringList;
  Data, Emitida: TDateTime;
begin
  L := Default(TLicenca);
  L.Codigo := Codigo;
  L.Hoje := Hoje;
  Result := elSemLicenca;
  if Trim(Texto) = '' then
    Exit;
  Result := elAssinaturaErrada;
  Normal := StringReplace(Texto, #13, '', [rfReplaceAll]);
  i := Pos(#10'assinatura=', Normal);
  if i = 0 then
    Exit;
  Corpo := Copy(Normal, 1, i);  // com o \n final, como foi assinado
  if not CarregaLibcrypto then
    Exit(elSemOpenSSL);
  if not AssinaturaConfere(Corpo, Copy(Normal, i + Length(#10'assinatura='), MaxInt), NOVA_CHAVE_PUBLICA) then
    Exit;

  Linhas := TStringList.Create;
  try
    Linhas.Text := Corpo;
    if (Linhas.Count < 2) or (Linhas[0] <> CABECALHO_LICENCA) then
      Exit;
    if Campo(Linhas, 'codigo') <> SoDigitos(Codigo) then
      Exit(elOutraMaquina);
    L.Validade := Campo(Linhas, 'validade');
    L.ContatoAte := Campo(Linhas, 'contato_ate');
    L.Cliente := Campo(Linhas, 'cliente');
    L.Emitida := StrToInt64Def(Campo(Linhas, 'emitida'), 0);
    { o dia considerado nunca é antes da emissão }
    if L.Emitida > 0 then
    begin
      Emitida := UniversalTimeToLocal(UnixToDateTime(L.Emitida));
      if Trunc(L.Hoje) < Trunc(Emitida) then
        L.Hoje := Trunc(Emitida);
    end;
    if Campo(Linhas, 'situacao') = 'bloqueada' then
      Exit(elBloqueada);
    if Campo(Linhas, 'situacao') <> 'ativa' then
      Exit;
    if L.Validade <> 'permanente' then
    begin
      if not DataDaLicenca(L.Validade, Data) then
        Exit;
      if Trunc(L.Hoje) > Trunc(Data) then
        Exit(elVencida);
    end;
    if L.ContatoAte <> 'nunca' then
    begin
      if not DataDaLicenca(L.ContatoAte, Data) then
        Exit;
      if Trunc(L.Hoje) > Trunc(Data) then
        Exit(elSemContato);
    end;
    Result := elValida;
  finally
    Linhas.Free;
  end;
end;

function UltimoDia(const Pasta: string): Integer;
begin
  Result := StrToIntDef(PrimeiraLinhaDe(IncludeTrailingPathDelimiter(Pasta) + ARQ_LICENCA_DIA), 0);
end;

procedure GravaUltimoDia(const Pasta: string; Dia: TDateTime);
begin
  if Trunc(Dia) <= UltimoDia(Pasta) then
    Exit;
  try
    GravaArquivo(IncludeTrailingPathDelimiter(Pasta) + ARQ_LICENCA_DIA, IntToStr(Trunc(Dia)) + #10);
  except
    { sem gravar o dia, a licença continua valendo }
  end;
end;

function LeLicenca(const Pasta: string; Agora: TDateTime): TLicenca;
var
  Hoje: TDateTime;
begin
  Hoje := Agora;
  { relógio atrasado: o último dia visto manda }
  if Trunc(Hoje) < UltimoDia(Pasta) then
    Hoje := UltimoDia(Pasta);
  Result.Estado := ConfereTextoLicenca(LeArquivo(IncludeTrailingPathDelimiter(Pasta) + ARQ_LICENCA),
    CodigoDaMaquina(IdentidadeDaMaquina), Hoje, Result);
end;

function InstalaLicenca(const Pasta, Texto: string; Agora: TDateTime; out Instalou: Boolean): TEstadoLicenca;
var
  Nova, Atual: TLicenca;
  Codigo: string;
begin
  Instalou := False;
  Codigo := CodigoDaMaquina(IdentidadeDaMaquina);
  Result := ConfereTextoLicenca(Texto, Codigo, Agora, Nova);
  if Result in [elSemLicenca, elAssinaturaErrada, elOutraMaquina, elSemOpenSSL] then
    Exit;
  { não volta para uma licença mais velha que a atual (por exemplo, a de antes de um bloqueio) }
  ConfereTextoLicenca(LeArquivo(IncludeTrailingPathDelimiter(Pasta) + ARQ_LICENCA), Codigo, Agora, Atual);
  if Nova.Emitida < Atual.Emitida then
    Exit;
  if LeArquivo(IncludeTrailingPathDelimiter(Pasta) + ARQ_LICENCA) = Texto then
    Exit;
  GravaArquivo(IncludeTrailingPathDelimiter(Pasta) + ARQ_LICENCA, Texto);
  Instalou := True;
end;

end.

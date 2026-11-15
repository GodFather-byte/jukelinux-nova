unit Licenca;

{ Licença da JukeLinux Nova (no lugar do pendrive-chave da original). Usa a tela de ativação da original: a máquina
  mostra o código dela, o técnico liga para a empresa, a empresa gera a contra-senha e o técnico digita.

  - Código da máquina: 16 dígitos (NNNN-NNNN-NNNN-NNNN) tirados do número de série do disco onde está o sistema
    (/dev/disk/by-id). Uma imagem do HD clonada para outra máquina tem outro código. Sem serial (máquina virtual),
    usa o /etc/machine-id.
  - Contra-senha: 12 dígitos = 5 da validade (dias desde 01/01/2020; 00000 = permanente) + 7 de um HMAC-SHA1 do código
    e da validade com a chave secreta da empresa. Sem a chave não se gera contra-senha que funcione.
  - licenca.txt guarda o código, a contra-senha e o último dia visto (também assinado): atrasar o relógio não
    estende a validade.

  A chave secreta fica em licenca_chave.inc, fora do git (ferramentas/licenca/nova_chave.sh cria uma). Sem ela, o
  build usa licenca_chave.desenvolvimento.inc, que só serve para testes.

  Sem LCL: usada pela jukebox, pelo gerador de contra-senhas e pelos testes. }

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils;

{$I licenca_chave.inc}

const
  ARQ_LICENCA = 'licenca.txt';
  LICENCA_PERMANENTE = 0;

type
  TEstadoLicenca = (elValida, elSemLicenca, elOutraMaquina, elContraSenhaErrada, elVencida);

  TLicenca = record
    Estado: TEstadoLicenca;
    Codigo: string;          // da máquina, com os tracinhos
    ContraSenha: string;
    Validade: Integer;       // dias desde BASE_LICENCA; 0 = permanente
    Hoje: TDateTime;         // o dia considerado (nunca antes do último dia visto)
  end;

{ Texto que identifica a máquina (serial do disco do sistema ou machine-id). }
function IdentidadeDaMaquina: string;
{ Código de 16 dígitos mostrado na tela de ativação. }
function CodigoDaMaquina(const Identidade: string): string;
{ Contra-senha de 12 dígitos para um código. Validade em dias desde 01/01/2020 (0 = permanente). }
function GeraContraSenha(const Codigo: string; Validade: Integer; const Chave: string): string;
{ Confere uma contra-senha digitada. Devolve o estado e, se válida, a validade. }
function ConfereContraSenha(const Codigo, ContraSenha: string; const Chave: string; Hoje: TDateTime;
  out Validade: Integer): TEstadoLicenca;

{ Lê e confere o licenca.txt da pasta. }
function LeLicenca(const Pasta: string; Agora: TDateTime): TLicenca;
{ Grava o licenca.txt (depois de uma ativação, ou para atualizar o último dia visto). }
procedure GravaLicenca(const Pasta, Codigo, ContraSenha: string; UltimoDia: TDateTime);

function ValidadeParaData(Validade: Integer): TDateTime;
function DataParaValidade(Data: TDateTime): Integer;
function SoDigitos(const Texto: string): string;
function DescreveEstado(E: TEstadoLicenca): string;

implementation

uses
  BaseUnix, sha1, hmac;

const
  BASE_LICENCA: TDateTime = 43831;  // 01/01/2020

function SoDigitos(const Texto: string): string;
var
  i: Integer;
begin
  Result := '';
  for i := 1 to Length(Texto) do
    if Texto[i] in ['0'..'9'] then
      Result := Result + Texto[i];
end;

function ValidadeParaData(Validade: Integer): TDateTime;
begin
  Result := BASE_LICENCA + Validade;
end;

function DataParaValidade(Data: TDateTime): Integer;
begin
  Result := Trunc(Data) - Trunc(BASE_LICENCA);
end;

function DescreveEstado(E: TEstadoLicenca): string;
begin
  case E of
    elValida: Result := 'válida';
    elSemLicenca: Result := 'sem licença';
    elOutraMaquina: Result := 'licença de outra máquina';
    elContraSenhaErrada: Result := 'contra-senha errada';
    elVencida: Result := 'licença vencida';
  end;
end;

function LeArquivo(const Arquivo: string): string;
var
  Linhas: TStringList;
begin
  Result := '';
  if not FileExists(Arquivo) then
    Exit;
  Linhas := TStringList.Create;
  try
    try
      Linhas.LoadFromFile(Arquivo);
      if Linhas.Count > 0 then
        Result := Trim(Linhas[0]);
    except
      Result := '';
    end;
  finally
    Linhas.Free;
  end;
end;

{ Alvo de um link simbólico, ou vazio se não for link. }
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
    Result := LeArquivo('/etc/machine-id');
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

function Assinatura(const Texto, Chave: string; Quantos: Integer): string;
begin
  Result := DigitosDe(HMACSHA1Digest(Chave, Texto), 0, 4, Quantos);
end;

function GeraContraSenha(const Codigo: string; Validade: Integer; const Chave: string): string;
var
  V: string;
begin
  V := IntToStr(Validade);
  while Length(V) < 5 do
    V := '0' + V;
  Result := Agrupa(V + Assinatura(SoDigitos(Codigo) + '|' + V, Chave, 7));
end;

function IguaisSemPressa(const A, B: string): Boolean;
var
  i: Integer;
  Diferenca: Integer;
begin
  Diferenca := Length(A) xor Length(B);
  for i := 1 to Length(A) do
    if i <= Length(B) then
      Diferenca := Diferenca or (Ord(A[i]) xor Ord(B[i]));
  Result := Diferenca = 0;
end;

function ConfereContraSenha(const Codigo, ContraSenha: string; const Chave: string; Hoje: TDateTime;
  out Validade: Integer): TEstadoLicenca;
var
  D: string;
begin
  Validade := -1;
  D := SoDigitos(ContraSenha);
  if Length(D) <> 12 then
    Exit(elContraSenhaErrada);
  Validade := StrToIntDef(Copy(D, 1, 5), -1);
  if (Validade < 0) or not IguaisSemPressa(SoDigitos(GeraContraSenha(Codigo, Validade, Chave)), D) then
    Exit(elContraSenhaErrada);
  if (Validade <> LICENCA_PERMANENTE) and (Trunc(Hoje) > Trunc(ValidadeParaData(Validade))) then
    Exit(elVencida);
  Result := elValida;
end;

function SeloDoDia(const Codigo: string; Dia: Integer): string;
begin
  Result := IntToStr(Dia) + '|' + Assinatura(SoDigitos(Codigo) + '|dia|' + IntToStr(Dia), NOVA_CHAVE_LICENCA, 8);
end;

function LeLicenca(const Pasta: string; Agora: TDateTime): TLicenca;
var
  Linhas: TStringList;
  Selo: TStringArray;
  UltimoDia: Integer;
begin
  Result := Default(TLicenca);
  Result.Codigo := CodigoDaMaquina(IdentidadeDaMaquina);
  Result.Hoje := Agora;
  Result.Estado := elSemLicenca;
  if not FileExists(IncludeTrailingPathDelimiter(Pasta) + ARQ_LICENCA) then
    Exit;
  Linhas := TStringList.Create;
  try
    try
      Linhas.LoadFromFile(IncludeTrailingPathDelimiter(Pasta) + ARQ_LICENCA);
    except
      Exit;
    end;
    if Linhas.Count < 2 then
      Exit;
    if SoDigitos(Linhas[0]) <> SoDigitos(Result.Codigo) then
    begin
      Result.Estado := elOutraMaquina;
      Exit;
    end;
    Result.ContraSenha := Trim(Linhas[1]);
    { O último dia visto só vale com o selo certo; o dia considerado nunca é anterior a ele. }
    if Linhas.Count > 2 then
    begin
      Selo := Trim(Linhas[2]).Split(['|']);
      if Length(Selo) = 2 then
      begin
        UltimoDia := StrToIntDef(Selo[0], -1);
        if (UltimoDia >= 0) and (Trim(Linhas[2]) = SeloDoDia(Result.Codigo, UltimoDia))
          and (Trunc(Result.Hoje) < UltimoDia) then
          Result.Hoje := UltimoDia;
      end;
    end;
  finally
    Linhas.Free;
  end;
  Result.Estado := ConfereContraSenha(Result.Codigo, Result.ContraSenha, NOVA_CHAVE_LICENCA, Result.Hoje,
    Result.Validade);
end;

procedure GravaLicenca(const Pasta, Codigo, ContraSenha: string; UltimoDia: TDateTime);
var
  Linhas: TStringList;
begin
  Linhas := TStringList.Create;
  try
    Linhas.Add(Codigo);
    Linhas.Add(ContraSenha);
    Linhas.Add(SeloDoDia(Codigo, Trunc(UltimoDia)));
    Linhas.SaveToFile(IncludeTrailingPathDelimiter(Pasta) + ARQ_LICENCA);
  finally
    Linhas.Free;
  end;
end;

end.

program teste_licenca;

{ Testa src/licenca.pas (rodar por rodar.sh). Usa a chave com que o projeto for compilado. }

{$mode objfpc}{$H+}

uses
  Classes, SysUtils, Licenca;

var
  Falhas: Integer = 0;
  Pasta: string;

procedure Confere(Ok: Boolean; const Nome: string);
begin
  if Ok then WriteLn('OK    ', Nome) else begin WriteLn('FALHA ', Nome); Inc(Falhas); end;
end;

procedure Escreve(const Linhas: array of string);
var
  L: TStringList;
  i: Integer;
begin
  L := TStringList.Create;
  try
    for i := 0 to High(Linhas) do L.Add(Linhas[i]);
    L.SaveToFile(Pasta + ARQ_LICENCA);
  finally
    L.Free;
  end;
end;

var
  Cod, Outro, Contra, C2, D: string;
  V: Integer;
  L: TLicenca;
  Hoje: TDateTime;
begin
  Pasta := IncludeTrailingPathDelimiter(ParamStr(1));
  Hoje := Date;
  Cod := CodigoDaMaquina(IdentidadeDaMaquina);
  Outro := CodigoDaMaquina('disco:ata-OUTRO_DISCO_123');
  WriteLn('identidade: ', IdentidadeDaMaquina, '  código: ', Cod);

  Confere((Length(SoDigitos(Cod)) = 16) and (Length(Cod) = 19), 'código com 16 dígitos (NNNN-NNNN-NNNN-NNNN)');
  Confere(Cod = CodigoDaMaquina(IdentidadeDaMaquina), 'código é sempre o mesmo na mesma máquina');
  Confere(Cod <> Outro, 'outra identidade dá outro código');

  Contra := GeraContraSenha(Cod, LICENCA_PERMANENTE, NOVA_CHAVE_LICENCA);
  Confere(Length(SoDigitos(Contra)) = 12, 'contra-senha com 12 dígitos: ' + Contra);
  Confere(ConfereContraSenha(Cod, Contra, NOVA_CHAVE_LICENCA, Hoje, V) = elValida, 'permanente vale');
  Confere(ConfereContraSenha(Cod, ' ' + StringReplace(Contra, '-', ' ', [rfReplaceAll]) + ' ', NOVA_CHAVE_LICENCA, Hoje, V) = elValida,
    'aceita digitada com espaços ou sem tracinhos');
  Confere(ConfereContraSenha(Cod, Contra, NOVA_CHAVE_LICENCA, Hoje + 365 * 50, V) = elValida, 'permanente não vence');

  C2 := GeraContraSenha(Cod, DataParaValidade(Hoje + 30), NOVA_CHAVE_LICENCA);
  Confere(ConfereContraSenha(Cod, C2, NOVA_CHAVE_LICENCA, Hoje, V) = elValida, 'com prazo: vale antes');
  Confere(ConfereContraSenha(Cod, C2, NOVA_CHAVE_LICENCA, Hoje + 30, V) = elValida, 'com prazo: vale no último dia');
  Confere(ConfereContraSenha(Cod, C2, NOVA_CHAVE_LICENCA, Hoje + 31, V) = elVencida, 'com prazo: vence no dia seguinte');

  Confere(ConfereContraSenha(Outro, Contra, NOVA_CHAVE_LICENCA, Hoje, V) = elContraSenhaErrada,
    'contra-senha de outra máquina não vale');
  D := SoDigitos(Contra);
  D[12] := Chr(Ord('0') + (Ord(D[12]) - Ord('0') + 1) mod 10);
  Confere(ConfereContraSenha(Cod, D, NOVA_CHAVE_LICENCA, Hoje, V) = elContraSenhaErrada, 'um dígito trocado não vale');
  D := SoDigitos(C2);
  D := '00000' + Copy(D, 6, 7);
  Confere(ConfereContraSenha(Cod, D, NOVA_CHAVE_LICENCA, Hoje, V) = elContraSenhaErrada,
    'trocar a validade para permanente não vale');
  Confere(ConfereContraSenha(Cod, Contra, 'outra-chave', Hoje, V) = elContraSenhaErrada, 'outra chave não vale');
  Confere(ConfereContraSenha(Cod, '1234', NOVA_CHAVE_LICENCA, Hoje, V) = elContraSenhaErrada, 'número curto não vale');

  DeleteFile(Pasta + ARQ_LICENCA);
  Confere(LeLicenca(Pasta, Now).Estado = elSemLicenca, 'sem licenca.txt: sem licença');
  Escreve([Outro, GeraContraSenha(Outro, 0, NOVA_CHAVE_LICENCA)]);
  Confere(LeLicenca(Pasta, Now).Estado = elOutraMaquina, 'licenca.txt copiado de outra máquina não vale');
  GravaLicenca(Pasta, Cod, Contra, Now);
  Confere(LeLicenca(Pasta, Now).Estado = elValida, 'licenca.txt gravado vale');

  { relógio atrasado: o último dia visto (assinado) manda }
  GravaLicenca(Pasta, Cod, C2, Hoje + 40);
  L := LeLicenca(Pasta, Hoje);
  Confere((L.Estado = elVencida) and (Trunc(L.Hoje) = Trunc(Hoje) + 40),
    'atrasar o relógio não estende a validade');
  { último dia adulterado (sem o selo certo) é ignorado }
  Escreve([Cod, C2, IntToStr(Trunc(Hoje) - 999) + '|00000000']);
  Confere(LeLicenca(Pasta, Hoje).Estado = elValida, 'selo do último dia adulterado é ignorado');

  WriteLn; WriteLn('Falhas: ', Falhas);
  if Falhas > 0 then Halt(1);
end.

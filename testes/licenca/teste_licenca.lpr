program teste_licenca;

{ Testa src/licenca.pas (rodar por rodar.sh). Sem argumento, mostra o código da máquina. Com a pasta das licenças
  geradas por licencas.mjs (chave de desenvolvimento), confere cada caso. }

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

function Le(const Nome: string): string;
var
  L: TStringList;
begin
  L := TStringList.Create;
  try
    L.LoadFromFile(Pasta + Nome);
    L.LineBreak := #10;
    Result := L.Text;
  finally
    L.Free;
  end;
end;

function Estado(const Nome: string; Dia: TDateTime): TEstadoLicenca;
var
  L: TLicenca;
begin
  Result := ConfereTextoLicenca(Le(Nome), CodigoDaMaquina(IdentidadeDaMaquina), Dia, L);
end;

function NovaPasta(const Nome: string): string;
begin
  Result := Pasta + Nome + '/';
  ForceDirectories(Result);
end;

var
  Cod, Outro, Juke, Juke2, Texto: string;
  L: TLicenca;
  Instalou: Boolean;
begin
  Cod := CodigoDaMaquina(IdentidadeDaMaquina);
  if ParamCount = 0 then
  begin
    WriteLn(Cod);
    Halt(0);
  end;
  Pasta := IncludeTrailingPathDelimiter(ParamStr(1));
  Outro := CodigoDaMaquina('disco:ata-OUTRO_DISCO_123');
  WriteLn('identidade: ', IdentidadeDaMaquina, '  código: ', Cod);
  if NOVA_CHAVE_DESENVOLVIMENTO then WriteLn('(chave de desenvolvimento)');

  Confere((Length(SoDigitos(Cod)) = 16) and (Length(Cod) = 19), 'código com 16 dígitos (NNNN-NNNN-NNNN-NNNN)');
  Confere(Cod = CodigoDaMaquina(IdentidadeDaMaquina), 'código é sempre o mesmo na mesma máquina');
  Confere(Cod <> Outro, 'outra identidade dá outro código');

  Confere(Estado('permanente.txt', Date) = elValida, 'permanente vale');
  Confere(Estado('permanente.txt', Date + 365 * 50) = elValida, 'permanente não vence');
  Confere(Estado('trinta-dias.txt', Date) = elValida, 'com prazo: vale antes');
  Confere(Estado('trinta-dias.txt', Date + 30) = elValida, 'com prazo: vale no último dia');
  Confere(Estado('trinta-dias.txt', Date + 31) = elVencida, 'com prazo: vence no dia seguinte');
  Confere(Estado('vencida.txt', Date) = elVencida, 'vencida não vale');
  Confere(Estado('bloqueada.txt', Date) = elBloqueada, 'bloqueada pela empresa trava');
  Confere(Estado('contato-7.txt', Date) = elValida, 'contato obrigatório: vale dentro do prazo');
  Confere(Estado('contato-7.txt', Date + 8) = elSemContato, 'contato obrigatório: trava depois do prazo sem internet');
  Confere(Estado('outra-maquina.txt', Date) = elOutraMaquina, 'licença de outra máquina não vale');
  Confere(Estado('adulterada.txt', Date) = elAssinaturaErrada, 'trocar a validade no arquivo invalida a assinatura');
  Confere(ConfereTextoLicenca('', Cod, Date, L) = elSemLicenca, 'arquivo vazio: sem licença');
  Confere(ConfereTextoLicenca('qualquer coisa'#10'assinatura=AAAA', Cod, Date, L) = elAssinaturaErrada, 'lixo não vale');
  Confere(ConfereTextoLicenca(StringReplace(Le('permanente.txt'), #10, #13#10, [rfReplaceAll]), Cod, Date, L) = elValida,
    'vale com quebra de linha do Windows (pendrive)');
  Confere(L.Cliente = 'Bar de Teste', 'lê o cliente: ' + L.Cliente);

  Juke := NovaPasta('juke');
  Confere(LeLicenca(Juke, Now).Estado = elSemLicenca, 'pasta sem licenca.txt: sem licença');
  Confere(InstalaLicenca(Juke, Le('outra-maquina.txt'), Now, Instalou) = elOutraMaquina, 'não instala de outra máquina');
  Confere(not Instalou and not FileExists(Juke + ARQ_LICENCA), 'licença de outra máquina não grava nada');
  Confere(InstalaLicenca(Juke, Le('adulterada.txt'), Now, Instalou) = elAssinaturaErrada, 'não instala adulterada');
  Confere(InstalaLicenca(Juke, Le('permanente.txt'), Now, Instalou) = elValida, 'instala a permanente');
  Confere(Instalou and (LeLicenca(Juke, Now).Estado = elValida), 'licenca.txt instalado vale');
  InstalaLicenca(Juke, Le('permanente.txt'), Now, Instalou);
  Confere(not Instalou, 'a mesma licença não é regravada');
  InstalaLicenca(Juke, Le('antiga.txt'), Now, Instalou);
  Confere(not Instalou, 'licença mais velha não substitui a atual');
  Confere(InstalaLicenca(Juke, Le('bloqueada.txt'), Now, Instalou) = elBloqueada, 'bloqueio chega pela nuvem');
  Confere(Instalou and (LeLicenca(Juke, Now).Estado = elBloqueada), 'bloqueio fica gravado');
  InstalaLicenca(Juke, Le('permanente.txt'), Now, Instalou);
  Confere(not Instalou and (LeLicenca(Juke, Now).Estado = elBloqueada), 'voltar a licença de antes do bloqueio não desbloqueia');

  { relógio atrasado: o último dia visto manda }
  Juke2 := NovaPasta('juke2');
  InstalaLicenca(Juke2, Le('trinta-dias.txt'), Now, Instalou);
  Confere(LeLicenca(Juke2, Now).Estado = elValida, 'trinta dias: vale hoje');
  GravaUltimoDia(Juke2, Date + 40);
  Confere(LeLicenca(Juke2, Now).Estado = elVencida, 'depois de ver o dia +40, atrasar o relógio não ressuscita a licença');
  GravaUltimoDia(Juke2, Date);
  Confere(LeLicenca(Juke2, Now).Estado = elVencida, 'o último dia visto não volta para trás');
  Texto := Le('vencida.txt');
  Confere((ConfereTextoLicenca(Texto, Cod, EncodeDate(2000, 1, 1), L) = elValida) and (Trunc(L.Hoje) = Trunc(Date) - 40),
    'relógio em 2000: o dia considerado é o da emissão (vencida há 2 dias, emitida há 40)');

  WriteLn;
  WriteLn('Falhas: ', Falhas);
  if Falhas > 0 then Halt(1);
end.

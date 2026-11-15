program gerar_contrasenha;

{ Gera a contra-senha de ativação de uma jukebox (para a empresa; não vai para as máquinas).
  Uso: gerar_contrasenha CODIGO [permanente | dd/mm/aaaa | N]
    CODIGO       o número que a jukebox mostra na tela de ativação (NNNN-NNNN-NNNN-NNNN)
    permanente   não vence (padrão)
    dd/mm/aaaa   vence nesse dia (a jukebox funciona até o fim dele)
    N            vence daqui a N dias
  Usa a mesma chave da jukebox (src/licenca_chave.inc): gere as duas com o mesmo arquivo. }

{$mode objfpc}{$H+}

uses
  SysUtils, DateUtils, Licenca;

var
  Codigo, Prazo: string;
  Validade, Dias: Integer;
  Data: TDateTime;
  Formato: TFormatSettings;
begin
  if (ParamCount < 1) or (Length(SoDigitos(ParamStr(1))) <> 16) then
  begin
    WriteLn('Uso: gerar_contrasenha CODIGO [permanente | dd/mm/aaaa | dias]');
    WriteLn('     CODIGO = o número de 16 dígitos que a jukebox mostra (NNNN-NNNN-NNNN-NNNN)');
    Halt(2);
  end;
  Codigo := ParamStr(1);
  Prazo := LowerCase(Trim(ParamStr(2)));
  Formato := DefaultFormatSettings;
  Formato.DateSeparator := '/';
  Formato.ShortDateFormat := 'dd/mm/yyyy';
  if (Prazo = '') or (Prazo = 'permanente') then
    Validade := LICENCA_PERMANENTE
  else if TryStrToInt(Prazo, Dias) and (Dias > 0) then
    Validade := DataParaValidade(Date + Dias)
  else if TryStrToDate(Prazo, Data, Formato) then
    Validade := DataParaValidade(Data)
  else
  begin
    WriteLn('Prazo inválido: ', ParamStr(2));
    Halt(2);
  end;
  if (Validade <> LICENCA_PERMANENTE) and ((Validade < 1) or (Validade > 99999) or (ValidadeParaData(Validade) < Date)) then
  begin
    WriteLn('A validade precisa ser uma data futura.');
    Halt(2);
  end;
  if NOVA_CHAVE_DESENVOLVIMENTO then
    WriteLn('ATENÇÃO: chave de DESENVOLVIMENTO (só para testes). Crie a chave real com nova_chave.sh.');
  WriteLn('Código da máquina: ', Codigo);
  if Validade = LICENCA_PERMANENTE then
    WriteLn('Validade:          permanente')
  else
    WriteLn('Validade:          até ', FormatDateTime('dd"/"mm"/"yyyy', ValidadeParaData(Validade)));
  WriteLn('Contra-senha:      ', GeraContraSenha(Codigo, Validade, NOVA_CHAVE_LICENCA));
end.

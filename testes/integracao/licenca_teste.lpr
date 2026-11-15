program licenca_teste;

{ Grava em PASTA uma licença permanente desta máquina (só para o teste de integração). }

{$mode objfpc}{$H+}

uses
  SysUtils, Licenca;

var
  Codigo: string;
begin
  Codigo := CodigoDaMaquina(IdentidadeDaMaquina);
  GravaLicenca(IncludeTrailingPathDelimiter(ParamStr(1)), Codigo,
    GeraContraSenha(Codigo, LICENCA_PERMANENTE, NOVA_CHAVE_LICENCA), Date);
  WriteLn('licença de teste para ', Codigo);
end.

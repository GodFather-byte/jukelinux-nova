program jukelinux;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}
  cthreads,
  {$ENDIF}
  SysUtils, Interfaces, Forms, jukelinux1;

type
  { Grava toda exceção não tratada com o rastro (arquivo e linha) em /tmp/jukelinux-nova-erros.log e na saída de
    erro, sem abrir caixa de mensagem. Enquanto a tradução não estiver completa, é assim que se acha onde parou. }
  TRegistraErros = class
    procedure Excecao(Sender: TObject; E: Exception);
  end;

procedure TRegistraErros.Excecao(Sender: TObject; E: Exception);
var
  F: Text;
  I: Integer;
  Quadros: PPointer;
begin
  AssignFile(F, '/tmp/jukelinux-nova-erros.log');
  if FileExists('/tmp/jukelinux-nova-erros.log') then Append(F) else Rewrite(F);
  Writeln(F, FormatDateTime('dd/mm/yy hh:nn:ss', Now), ' ', E.ClassName, ': ', E.Message);
  Writeln(F, BackTraceStrFunc(ExceptAddr));
  Quadros := ExceptFrames;
  for I := 0 to ExceptFrameCount - 1 do
    Writeln(F, BackTraceStrFunc(Quadros[I]));
  Writeln(F);
  CloseFile(F);
  Writeln(ErrOutput, 'EXCEÇÃO ', E.ClassName, ': ', E.Message);
end;

var
  Registro: TRegistraErros;

begin
  Registro := TRegistraErros.Create;
  Application.OnException := @Registro.Excecao;
  RequireDerivedFormResource := True;
  Application.Title := 'JukeLinux';
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.

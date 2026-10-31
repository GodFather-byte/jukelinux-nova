program jukelinux;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}
  cthreads,
  {$ENDIF}
  Interfaces, Forms, jukelinux1;

begin
  RequireDerivedFormResource := True;
  Application.Title := 'JukeLinux';
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.

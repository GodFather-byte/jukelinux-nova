unit jukelinux1;

{ Tela principal da JukeLinux Nova.
  Recria a unit jukelinux1.pas da JukeLinux original (versão de 19/01/2018). Os nomes das rotinas seguem os
  da original (referencia/funcoes.txt) para facilitar a comparação lado a lado com o programa antigo.
  Fase 1: só o esqueleto da janela; o layout completo (referencia/telas/Form1.lfm) entra na fase 2. }

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, StdCtrls;

const
  { A original só roda nesta pasta ("O Software Roda Somente na Pasta //home/jkb/jukelinux/"). }
  PASTA_JUKELINUX = '/home/jkb/jukelinux/';

type
  TForm1 = class(TForm)
    LabelVersao: TLabel;
    procedure FormCreate(Sender: TObject);
  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

procedure TForm1.FormCreate(Sender: TObject);
begin
  LabelVersao.Caption := 'JukeLinux Nova - em construção';
end;

end.

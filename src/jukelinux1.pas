unit jukelinux1;

{ Tela principal da JukeLinux Nova.
  Recria a unit jukelinux1.pas da JukeLinux original (versão de 19/01/2018). O formulário (jukelinux1.lfm) é o da
  original, extraído do binário; os campos e eventos publicados vêm de jukelinux1_form.inc e os eventos ainda não
  reimplementados ficam vazios em jukelinux1_eventos.inc (ambos gerados por ferramentas/extracao/gerar_unit.py).
  Os nomes das rotinas seguem os da original (referencia/funcoes.txt) para comparar lado a lado. }

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls, ComCtrls, FileCtrl, ShellCtrls,
  MPlayerCtrl;

const
  { A original só roda nesta pasta ("O Software Roda Somente na Pasta //home/jkb/jukelinux/"). }
  PASTA_JUKELINUX = '/home/jkb/jukelinux/';

type

  { TForm1 }

  TForm1 = class(TForm)
  {$I jukelinux1_form.inc}
  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

{$I jukelinux1_eventos.inc}

end.

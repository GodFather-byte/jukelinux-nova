unit jukelinux1;

{ Tela principal da JukeLinux Nova.
  Recria a unit jukelinux1.pas da JukeLinux original (versão de 19/01/2018). O formulário (jukelinux1.lfm) é o da
  original, extraído do binário; os campos e eventos publicados vêm de jukelinux1_form.inc (gerar_unit.py).
  As rotinas e os eventos vêm do código descompilado, traduzidos por ferramentas/extracao/gerar_rotinas.py para
  jukelinux1_rotinas.inc, com as variáveis globais da original em globais.inc (globais.py). Uma rotina reescrita à
  mão aqui sai do arquivo gerado na próxima geração.
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

uses
  Types, Process, FileUtil;

{$R *.lfm}

{$I globais.inc}

{$I jukelinux1_rotinas.inc}

{$I jukelinux1_eventos.inc}

end.

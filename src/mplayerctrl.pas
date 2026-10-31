unit MPlayerCtrl;

{ Player embutido usado pela JukeLinux original (componente TMPlayerControl, que controla o mplayer em modo
  -slave). Esta versão tem as propriedades que o formulário original grava (Loop, Volume); o controle do mplayer
  em si entra na fase 3. }

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Controls;

type

  { TMPlayerControl }

  TMPlayerControl = class(TCustomControl)
  private
    FFilename: string;
    FLoop: Integer;
    FMPlayerPath: string;
    FStartParam: string;
    FVolume: Integer;
  published
    property Align;
    property Anchors;
    property Visible;
    property Filename: string read FFilename write FFilename;
    { -1 desligado, 0 para sempre, n vezes (mesmo significado do parâmetro -loop do mplayer). }
    property Loop: Integer read FLoop write FLoop;
    property MPlayerPath: string read FMPlayerPath write FMPlayerPath;
    property StartParam: string read FStartParam write FStartParam;
    property Volume: Integer read FVolume write FVolume;
  end;

implementation

end.

unit MPlayerCtrl;

{ Player embutido usado pela JukeLinux original (componente TMPlayerControl, que controla o mplayer em modo
  -slave). Cada música ou vídeo é um processo mplayer próprio. Volume e parada são enviados pela entrada padrão
  do mplayer (comandos do modo -slave). A API segue as chamadas da original: SetFileName, Play, Stop,
  SetVolume, Playing e Running. }

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Controls, Process;

type

  { TMPlayerControl }

  TMPlayerControl = class(TCustomControl)
  private
    FFilename: string;
    FLoop: Integer;
    FMPlayerPath: string;
    FProcesso: TProcess;
    FStartParam: string;
    FVolume: Integer;
    procedure ApagaProcesso;
    procedure DrenaSaida;
    procedure EnviaComando(const ATexto: string);
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    { Define o arquivo que o próximo Play vai tocar. }
    procedure SetFileName(const AArquivo: string);
    { Ajusta o volume (0 a 100). Se já estiver tocando, o ajuste vale na hora. }
    procedure SetVolume(AVolume: Integer);
    { Inicia o mplayer com Filename. Se já houver algo tocando, para antes. Se o mplayer não puder ser
      executado, Playing devolve False. }
    procedure Play;
    { Manda o mplayer encerrar e espera um pouco; se ele não sair, mata o processo. }
    procedure Stop;
    { True enquanto o processo do mplayer estiver ativo. }
    function Running: Boolean;
    { Mesmo valor de Running (a original usava os dois nomes). }
    function Playing: Boolean;
  published
    property Align;
    property Anchors;
    property Visible;
    property Filename: string read FFilename write SetFileName;
    { -1 desligado, 0 para sempre, n vezes (mesmo significado do parâmetro -loop do mplayer). }
    property Loop: Integer read FLoop write FLoop;
    { Caminho do executável; vazio usa o mplayer do PATH. }
    property MPlayerPath: string read FMPlayerPath write FMPlayerPath;
    { Parâmetros extras separados por espaço, passados ao mplayer antes do arquivo. }
    property StartParam: string read FStartParam write FStartParam;
    property Volume: Integer read FVolume write SetVolume;
  end;

implementation

uses
  Math;

const
  { Quanto esperar o mplayer sair depois do comando quit, em passos de 20 ms. }
  PASSOS_ESPERA_SAIDA = 50;

constructor TMPlayerControl.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FLoop := -1;
  FVolume := 100;
  FMPlayerPath := '';
  FProcesso := nil;
end;

destructor TMPlayerControl.Destroy;
begin
  Stop;
  ApagaProcesso;
  inherited Destroy;
end;

procedure TMPlayerControl.ApagaProcesso;
begin
  if FProcesso <> nil then
  begin
    FProcesso.Free;
    FProcesso := nil;
  end;
end;

procedure TMPlayerControl.DrenaSaida;
var
  Buffer: array[0..1023] of Byte;
  Lidos: Integer;
begin
  FillChar(Buffer, SizeOf(Buffer), 0);
  { O mplayer escreve na saída; se ninguém ler, o buffer enche e ele trava. }
  if FProcesso = nil then
    Exit;
  while FProcesso.Output.NumBytesAvailable > 0 do
  begin
    Lidos := FProcesso.Output.Read(Buffer, SizeOf(Buffer));
    if Lidos <= 0 then
      Break;
  end;
end;

procedure TMPlayerControl.EnviaComando(const ATexto: string);
var
  Linha: string;
begin
  if (FProcesso = nil) or not FProcesso.Running then
    Exit;
  Linha := ATexto + #10;
  try
    FProcesso.Input.Write(Linha[1], Length(Linha));
  except
    { Processo que acabou de morrer: o Running logo vai dar False. }
  end;
end;

procedure TMPlayerControl.SetFileName(const AArquivo: string);
begin
  FFilename := AArquivo;
end;

procedure TMPlayerControl.SetVolume(AVolume: Integer);
begin
  FVolume := EnsureRange(AVolume, 0, 100);
  if Running then
    EnviaComando('volume ' + IntToStr(FVolume) + ' 1');
end;

procedure TMPlayerControl.Play;
var
  Partes: TStringList;
  i: Integer;
  Executavel: string;
begin
  Stop;
  { Sem arquivo, o mplayer em modo -slave fica ocioso em vez de sair: não iniciar evita dar como tocando. }
  if (FFilename = '') or not FileExists(FFilename) then
    Exit;

  Executavel := FMPlayerPath;
  if Executavel = '' then
    Executavel := 'mplayer';

  FProcesso := TProcess.Create(nil);
  FProcesso.Executable := Executavel;
  FProcesso.Options := [poUsePipes, poStderrToOutPut];
  FProcesso.Parameters.Add('-slave');
  FProcesso.Parameters.Add('-quiet');
  if FLoop >= 0 then
  begin
    FProcesso.Parameters.Add('-loop');
    FProcesso.Parameters.Add(IntToStr(FLoop));
  end;
  FProcesso.Parameters.Add('-volume');
  FProcesso.Parameters.Add(IntToStr(FVolume));

  Partes := TStringList.Create;
  try
    ExtractStrings([' '], [], PChar(FStartParam), Partes);
    for i := 0 to Partes.Count - 1 do
      if Partes[i] <> '' then
        FProcesso.Parameters.Add(Partes[i]);
  finally
    Partes.Free;
  end;

  { O arquivo entra como um único parâmetro, sem passar por shell: nomes com espaço ou acento funcionam. }
  FProcesso.Parameters.Add(FFilename);

  try
    FProcesso.Execute;
  except
    { mplayer ausente ou não executável: Playing devolve False e a tela segue funcionando. }
    ApagaProcesso;
  end;
end;

procedure TMPlayerControl.Stop;
var
  i: Integer;
begin
  if (FProcesso = nil) or not FProcesso.Running then
  begin
    ApagaProcesso;
    Exit;
  end;

  EnviaComando('quit');
  for i := 1 to PASSOS_ESPERA_SAIDA do
  begin
    if not FProcesso.Running then
      Break;
    Sleep(20);
  end;
  if FProcesso.Running then
    FProcesso.Terminate(0);
  ApagaProcesso;
end;

function TMPlayerControl.Running: Boolean;
begin
  Result := (FProcesso <> nil) and FProcesso.Running;
  if Result then
    DrenaSaida;
end;

function TMPlayerControl.Playing: Boolean;
begin
  Result := Running;
end;

initialization
  { Sem o registro, o formulário não consegue criar o componente ao ler o .lfm. }
  RegisterClass(TMPlayerControl);

end.

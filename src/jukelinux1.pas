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

  { Estado da original (símbolos U_JUKELINUX1_*). FORMCREATE, que preenchia a maior parte
    disto a partir dos .txt, estourou o tempo do Ghidra e ainda não está portado. }
  TempoAbertura: Integer;
  TelaAbertura: Integer;
  RotinaDoActivate: Integer;
  ErroSerialNum: Integer;
  Resolucao: Integer;
  KMat: Integer;
  MusicaSelecionada: Integer;
  MusicaSelecionadaPosTela: Integer;
  MusicaSelecionadaTS: Integer;
  TamanhoMusicaGrande: Integer;
  SomaMusicaGrande: Integer;
  MostrandoRitmos: Integer;
  MostrandoLetras: Integer;
  TotalFrase: Integer;
  TempoParaPaginarSozinho: Integer;
  BloquearQuandoTocar: Integer;
  QuantidadesDeMusicasTocadas: Integer;
  PressionadoTecla: Integer;
  TocandoMusica: Integer;
  TocandoMusicaDVD: Integer;
  TocandoMusicaGratis: Integer;
  PosL, PosT, PosW, PosH: Integer;

implementation

{$R *.lfm}

{ A original só grava se o arquivo já existe. O nome verdadeiro é uma constante Ld do binário,
  que esta cópia ainda não tem; até lá usa log.txt na pasta da jukebox. }
procedure GRAVALOG(const Msg: string);
var
  Arq: TextFile;
  Caminho: string;
begin
  Caminho := PASTA_JUKELINUX + 'log.txt';
  if not FileExists(Caminho) then
    Exit;
  try
    AssignFile(Arq, Caminho);
    Append(Arq);
    try
      WriteLn(Arq, DateToStr(Date), ' ', TimeToStr(Time), ' ', Msg);
      Flush(Arq);
    finally
      CloseFile(Arq);
    end;
  except
    on EInOutError do
      ;
  end;
end;

procedure DEFINE_EXIBIRVIDEOS;
begin
  { Posição da área de vídeo por largura de tela. O texto de configuração que escolhe o ramo
    (e o controle que recebe Left/Top/Width/Height) ia em registrador e o Ghidra não mostrou. }
  if Resolucao = 1366 then
  begin
    PosL := $26; PosT := $133; PosW := $16B; PosH := $D0;
  end;
  if Resolucao = 1024 then
  begin
    PosL := $13; PosT := $140; PosW := $B7; PosH := $A0;
  end;
  if Resolucao = 1440 then
  begin
    PosL := $26; PosT := $188; PosW := $16B; PosH := $D0;
  end;
end;

procedure CARREGANDO_CARTOES;
begin
  GRAVALOG('CARREGANDO_CARTOES');
end;

procedure CARREGANDO_CDS;
begin
  GRAVALOG('CARREGANDO_CDS');
end;

procedure CARREGANDO_KARAOKES;
begin
  GRAVALOG('CARREGANDO_KARAOKES');
end;

procedure CARREGANDO_PROPAGANDAS;
begin
  GRAVALOG('CARREGANDO_PROPAGANDAS');
end;

procedure ATIVA_PROPAGANDA;
begin
  GRAVALOG('ATIVA_PROPAGANDA');
end;

procedure TELA_DE_AUTOTESTE;
begin
  GRAVALOG('TELA_DE_AUTOTESTE');
end;

procedure TELA1;
begin
  GRAVALOG('TELA1');
end;

procedure MOSTRA_CDS(const Genero: string);
begin
  GRAVALOG('MOSTRA_CDS ' + Genero);
end;

procedure MOSTRA_NOME_DAS_MUSICAS;
begin
  GRAVALOG('MOSTRA_NOME_DAS_MUSICAS');
end;

procedure MOSTRA_FILA;
begin
  GRAVALOG('MOSTRA_FILA');
end;

procedure MOSTRA_TELA_CARREGANDO_CDS;
begin
  GRAVALOG('MOSTRA_TELA_CARREGANDO_CDS');
  Form1.PanelLendo.SetBounds(0, 0, Form1.ClientWidth, Form1.ClientHeight);
  Form1.PanelLendo.Show;
  Form1.PanelLendo.BringToFront;
  Form1.PanelVersao.Caption := DateToStr(Date) + ' ' + TimeToStr(Time);
end;

procedure INICIA_TELA;
begin
  GRAVALOG('INICIA_TELA');
  DEFINE_EXIBIRVIDEOS;
  CARREGANDO_CARTOES;
  MOSTRA_TELA_CARREGANDO_CDS;
  CARREGANDO_CDS;
  { ListBoxRCds.Top e três chamadas virtuais +0x220: o argumento e o método não vieram no C. }
  CARREGANDO_KARAOKES;
  { FileExists de um caminho montado na hora: se existir, apaga, ShowMessage e Close.
    O caminho é registrador; não fechar o programa com um nome inventado. }
  Form1.TimerCadastro.Enabled := True;
  TELA1;
  CARREGANDO_PROPAGANDAS;
  ATIVA_PROPAGANDA;
  KMat := -4;
  MusicaSelecionada := 0;
  MusicaSelecionadaPosTela := 0;
  MusicaSelecionadaTS := 0;
  if Resolucao = 1366 then
    TamanhoMusicaGrande := 30;
  if Resolucao = 1024 then
    TamanhoMusicaGrande := 22;
  if Resolucao = 1440 then
    TamanhoMusicaGrande := 30;
  SomaMusicaGrande := 0;
  MostrandoRitmos := 0;
  MostrandoLetras := 0;
  MOSTRA_CDS('');
  MOSTRA_NOME_DAS_MUSICAS;
  MOSTRA_FILA;
  if (BloquearQuandoTocar <> -1) and
    (BloquearQuandoTocar <= QuantidadesDeMusicasTocadas) then
  begin
    Form1.PanelBloqueio.Show;
    Form1.PanelBloqueio.BringToFront;
    GRAVALOG('bloqueio por quantidade de musicas');
  end;
end;

procedure TForm1.FormCreate(Sender: TObject);
var
  i: Integer;
begin
  for i := 0 to ComponentCount - 1 do
    if Components[i] is TTimer then
      TTimer(Components[i]).Enabled := False;
  Timerabertura.Interval := 1000;

  ErroSerialNum := 0;
  RotinaDoActivate := 1;
  Resolucao := 1024;
  BloquearQuandoTocar := -1;
  QuantidadesDeMusicasTocadas := 0;
  TotalFrase := 0;
  TempoParaPaginarSozinho := 0;

  { FORMCREATE mudava o monitor para 1024x768. Essa função não descompilou (timeout). }
  Position := poDesigned;
  Left := 0;
  Top := 0;
  ClientWidth := 1024;
  ClientHeight := 768;
end;

procedure TForm1.FormActivate(Sender: TObject);
var
  i: Integer;
begin
  if RotinaDoActivate = 1 then
  begin
    GRAVALOG('FormActivate');
    { Fases 1 e 2 da original: número de série e pendrive-chave. A leitura da chave está no
      FORMCREATE, que faltou. A licença nova é outra fase; a abertura segue. }
    RotinaDoActivate := 3;
  end;
  if RotinaDoActivate = 3 then
  begin
    for i := 0 to ComponentCount - 1 do
      if (Components[i] is TControl) and (TControl(Components[i]).Parent = Self) then
        TControl(Components[i]).Visible := False;

    Panelabertura.SetBounds(0, 0, ClientWidth, ClientHeight);
    Panelabertura.Color := clBlack;
    Labelabertura.Font.Color := clWhite;
    Labelabertura1.Font.Color := clWhite;
    Labelrodape.Font.Color := clWhite;
    Labelabertura.Caption := '';
    Labelabertura1.Caption := '';
    Labelrodape.Caption := '';
    Labelaberturatempo.Font.Color := clWhite;
    Labelaberturatempo.Font.Height := -48;

    TempoAbertura := 5;
    { A original baixa para 1 se um arquivo existe. O caminho ia em registrador. }
    Labelaberturatempo.Caption := IntToStr(TempoAbertura);
    TelaAbertura := 1;
    PressionadoTecla := 0;
    TocandoMusica := 0;
    TocandoMusicaDVD := 0;
    TocandoMusicaGratis := 0;
    Panelabertura.Show;
    Panelabertura.BringToFront;
    RotinaDoActivate := 4;
  end;
  if (RotinaDoActivate = 4) and (TempoAbertura > 0) then
    Timerabertura.Enabled := True;
end;

procedure TForm1.TimeraberturaTimer(Sender: TObject);
begin
  TempoAbertura := TempoAbertura - 1;
  Labelaberturatempo.Caption := IntToStr(TempoAbertura);
  if TempoAbertura = 0 then
  begin
    Timerabertura.Enabled := False;
    Panelabertura.Hide;
    INICIA_TELA;
  end;
end;

procedure TForm1.PanelaberturaClick(Sender: TObject);
begin
  Close;
end;

{$I jukelinux1_eventos.inc}

end.

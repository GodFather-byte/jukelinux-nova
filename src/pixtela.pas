unit PixTela;

{ Tela do Pix da JukeLinux Nova (não existe na original). Põe um botão PIX na tela principal; quem toca escolhe o
  valor, a jukebox mostra o QR Code dinâmico e, quando o PSP confirma o pagamento, chama OnCreditar com os reais
  pagos.

  - As chamadas ao PSP rodam numa thread (TPixTarefa), uma por vez, para a tela não congelar.
  - Cada cobrança criada fica em pix-pendentes.txt até ser paga, removida ou vencer. Assim um pagamento feito durante
    uma queda de rede, ou com a tela já fechada, ou antes de a máquina reiniciar, ainda vira crédito.
  - Cada cobrança paga vai para pix-creditados.txt antes de creditar, e nada que esteja lá é creditado de novo. }

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Controls, ExtCtrls, StdCtrls, Graphics, Forms, Pix;

type
  TPixCreditar = procedure(Reais: Integer) of object;
  TPixRegistrar = procedure(const Texto: string) of object;

  TPixOperacao = (poCriar, poConsultar, poCancelar);

  { TPixTarefa: uma chamada ao PSP. Não mexe na tela; quem a criou lê o resultado quando ela termina. }

  TPixTarefa = class(TThread)
  protected
    procedure Execute; override;
  public
    Cliente: TPixCliente;
    Operacao: TPixOperacao;
    Txid: string;
    Reais: Integer;
    Ok: Boolean;
    CopiaECola: string;
    Status: TPixStatus;
    Erro: string;
    constructor Create(ACliente: TPixCliente; AOperacao: TPixOperacao; const ATxid: string; AReais: Integer);
  end;

  TPixPendente = record
    Txid: string;
    Reais: Integer;
    Criado: TDateTime;
    ProximaConsulta: TDateTime;
    Cancelar: Boolean;
  end;

  TPixEstado = (peFechada, peEscolhendo, peGerando, peAguardando, pePago, peErro);

  { TTelaPix }

  TTelaPix = class(TComponent)
  private
    FConfig: TPixConfig;
    FCliente: TPixCliente;
    FForm: TForm;
    FPasta: string;
    FOnCreditar: TPixCreditar;
    FOnRegistrar: TPixRegistrar;
    FBotao: TPanel;
    FPainel: TPanel;
    FTitulo: TLabel;
    FValoresBox: TPanel;
    FQr: TImage;
    FAviso: TLabel;
    FBotaoCancelar: TPanel;
    FTimer: TTimer;
    FTarefa: TPixTarefa;
    FEstado: TPixEstado;
    FReaisEscolhidos: Integer;
    FTxidAtual: string;
    { Txid da cobrança que a tela está esperando ser criada; uma resposta de outra (cancelada) não aparece. }
    FTxidGerando: string;
    FFimAtual: TDateTime;
    FFecharEm: TDateTime;
    FPendentes: array of TPixPendente;
    FAntigoKeyDown: TKeyEvent;
    procedure Registra(const Texto: string);
    function CriaBotao(AParent: TWinControl; const Texto: string; Cor: TColor): TPanel;
    procedure MontaTela;
    procedure MostraValores;
    procedure MostraAviso(const Texto: string; Cor: TColor);
    procedure BotaoPixClick(Sender: TObject);
    procedure ValorClick(Sender: TObject);
    procedure CancelarClick(Sender: TObject);
    procedure FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure Tick(Sender: TObject);
    procedure IniciaTarefa(Operacao: TPixOperacao; const Txid: string; Reais: Integer);
    procedure TrataResultado(Tarefa: TPixTarefa);
    function AchaPendente(const Txid: string): Integer;
    procedure RemovePendente(Indice: Integer);
    procedure GravaPendentes;
    procedure LePendentes;
    function JaCreditado(const Txid: string): Boolean;
    procedure Credita(Indice: Integer);
    procedure AbandonaAtual;
    function TelaDaOriginalPorCima: Boolean;
    procedure AjustaBotao;
  public
    constructor Cria(AForm: TForm; const AConfig: TPixConfig; const APasta: string; ACreditar: TPixCreditar;
      ARegistrar: TPixRegistrar);
    destructor Destroy; override;
    procedure Abre;
    procedure Fecha;
  end;

const
  ARQ_PIX_PENDENTES = 'pix-pendentes.txt';
  ARQ_PIX_CREDITADOS = 'pix-creditados.txt';
  { Depois de vencer, a cobrança ainda é consultada por este tempo (pagamento feito no último segundo). }
  PIX_FOLGA_SEGUNDOS = 600;
  PIX_CONSULTA_ATUAL_SEGUNDOS = 3;
  PIX_CONSULTA_FUNDO_SEGUNDOS = 20;

{ Desenha o QR Code de Texto num bitmap quadrado de até Tamanho pixels, com a margem branca que os leitores pedem. }
procedure DesenhaQrCode(const Texto: string; Bitmap: TBitmap; Tamanho: Integer);

implementation

uses
  Math, fpqrcodegen;

procedure DesenhaQrCode(const Texto: string; Bitmap: TBitmap; Tamanho: Integer);
const
  MARGEM = 4;
var
  Temp, Qr: TQRBuffer;
  Lado, Total, Escala, x, y: Integer;
begin
  SetLength(Temp, QRBUFFER_LEN_FOR_VERSION(QRVERSIONMAX));
  SetLength(Qr, QRBUFFER_LEN_FOR_VERSION(QRVERSIONMAX));
  if not QREncodeText(Texto, Temp, Qr, EccMEDIUM, QRVERSIONMIN, QRVERSIONMAX, mpAuto, True) then
    raise Exception.Create('QR Code: texto grande demais');
  Lado := QRgetSize(Qr);
  Total := Lado + 2 * MARGEM;
  Escala := Max(1, Tamanho div Total);
  Bitmap.SetSize(Total * Escala, Total * Escala);
  Bitmap.Canvas.Brush.Style := bsSolid;
  Bitmap.Canvas.Brush.Color := clWhite;
  Bitmap.Canvas.FillRect(0, 0, Bitmap.Width, Bitmap.Height);
  Bitmap.Canvas.Brush.Color := clBlack;
  for y := 0 to Lado - 1 do
    for x := 0 to Lado - 1 do
      if QRgetModule(Qr, x, y) then
        Bitmap.Canvas.FillRect((x + MARGEM) * Escala, (y + MARGEM) * Escala, (x + MARGEM + 1) * Escala,
          (y + MARGEM + 1) * Escala);
end;

{ TPixTarefa }

constructor TPixTarefa.Create(ACliente: TPixCliente; AOperacao: TPixOperacao; const ATxid: string; AReais: Integer);
begin
  Cliente := ACliente;
  Operacao := AOperacao;
  Txid := ATxid;
  Reais := AReais;
  FreeOnTerminate := False;
  inherited Create(False);
end;

procedure TPixTarefa.Execute;
begin
  try
    case Operacao of
      poCriar: Ok := Cliente.CriaCobranca(Txid, Reais, CopiaECola);
      poConsultar: Ok := Cliente.Consulta(Txid, Status);
      poCancelar: Ok := Cliente.Cancela(Txid);
    end;
    if not Ok then
      Erro := Cliente.UltimoErro;
  except
    on E: Exception do
    begin
      Ok := False;
      Erro := E.Message;
    end;
  end;
end;

{ TTelaPix }

constructor TTelaPix.Cria(AForm: TForm; const AConfig: TPixConfig; const APasta: string; ACreditar: TPixCreditar;
  ARegistrar: TPixRegistrar);
begin
  inherited Create(AForm);
  FForm := AForm;
  FConfig := AConfig;
  FPasta := IncludeTrailingPathDelimiter(APasta);
  FOnCreditar := ACreditar;
  FOnRegistrar := ARegistrar;
  FCliente := TPixCliente.Create(FConfig);
  FEstado := peFechada;
  MontaTela;
  LePendentes;

  if FConfig.Tecla <> 0 then
  begin
    FAntigoKeyDown := FForm.OnKeyDown;
    FForm.OnKeyDown := @FormKeyDown;
  end;

  FTimer := TTimer.Create(Self);
  FTimer.Interval := 500;
  FTimer.OnTimer := @Tick;
  FTimer.Enabled := True;
  Registra(Format('ligado; botão em %d,%d (%dx%d) numa tela de %dx%d; %d cobrança(s) pendente(s) de antes',
    [FBotao.Left, FBotao.Top, FBotao.Width, FBotao.Height, FForm.ClientWidth, FForm.ClientHeight,
    Length(FPendentes)]));
end;

destructor TTelaPix.Destroy;
begin
  if FTimer <> nil then
    FTimer.Enabled := False;
  if FTarefa <> nil then
  begin
    { No máximo o tempo limite do curl. }
    FTarefa.WaitFor;
    FreeAndNil(FTarefa);
  end;
  FreeAndNil(FCliente);
  inherited Destroy;
end;

procedure TTelaPix.Registra(const Texto: string);
begin
  if Assigned(FOnRegistrar) then
    FOnRegistrar(Texto);
end;

function TTelaPix.CriaBotao(AParent: TWinControl; const Texto: string; Cor: TColor): TPanel;
begin
  Result := TPanel.Create(Self);
  Result.Parent := AParent;
  Result.Caption := Texto;
  Result.Color := Cor;
  Result.Font.Color := clWhite;
  Result.Font.Style := [fsBold];
  Result.Font.Size := 20;
  Result.BevelOuter := bvRaised;
  Result.BevelWidth := 2;
  Result.Cursor := crHandPoint;
end;

procedure TTelaPix.MontaTela;
var
  Largura, Altura: Integer;
begin
  { Botão na tela principal. }
  FBotao := CriaBotao(FForm, 'PIX', $00A0A000);
  if FConfig.BotaoLargura > 0 then
    FBotao.SetBounds(FConfig.BotaoX, FConfig.BotaoY, FConfig.BotaoLargura, FConfig.BotaoAltura)
  else
  begin
    FBotao.SetBounds(FForm.ClientWidth - 130, FForm.ClientHeight - 74, 120, 64);
    FBotao.Anchors := [akRight, akBottom];
  end;
  FBotao.OnClick := @BotaoPixClick;
  FBotao.BringToFront;

  { Painel do pagamento, no meio da tela. }
  Largura := Min(560, FForm.ClientWidth - 40);
  Altura := Min(680, FForm.ClientHeight - 40);
  FPainel := TPanel.Create(Self);
  FPainel.Parent := FForm;
  FPainel.SetBounds((FForm.ClientWidth - Largura) div 2, (FForm.ClientHeight - Altura) div 2, Largura, Altura);
  FPainel.Anchors := [];
  FPainel.Color := clBlack;
  FPainel.BevelOuter := bvRaised;
  FPainel.BevelWidth := 3;
  FPainel.Visible := False;

  FTitulo := TLabel.Create(Self);
  FTitulo.Parent := FPainel;
  FTitulo.AutoSize := False;
  FTitulo.SetBounds(10, 12, Largura - 20, 44);
  FTitulo.Alignment := taCenter;
  FTitulo.Font.Color := clWhite;
  FTitulo.Font.Size := 24;
  FTitulo.Font.Style := [fsBold];
  FTitulo.Caption := 'Pague com Pix';

  FValoresBox := TPanel.Create(Self);
  FValoresBox.Parent := FPainel;
  FValoresBox.BevelOuter := bvNone;
  FValoresBox.Color := clBlack;
  FValoresBox.SetBounds(20, 70, Largura - 40, Altura - 170);

  FQr := TImage.Create(Self);
  FQr.Parent := FPainel;
  FQr.Center := True;
  FQr.Proportional := True;
  FQr.Stretch := False;
  FQr.SetBounds(20, 62, Largura - 40, Altura - 200);
  FQr.Visible := False;

  FAviso := TLabel.Create(Self);
  FAviso.Parent := FPainel;
  FAviso.AutoSize := False;
  FAviso.WordWrap := True;
  FAviso.Alignment := taCenter;
  FAviso.SetBounds(10, Altura - 136, Largura - 20, 56);
  FAviso.Font.Color := clWhite;
  FAviso.Font.Size := 16;

  FBotaoCancelar := CriaBotao(FPainel, 'Cancelar', $000000B0);
  FBotaoCancelar.SetBounds((Largura - 220) div 2, Altura - 74, 220, 60);
  FBotaoCancelar.OnClick := @CancelarClick;
end;

procedure TTelaPix.MostraValores;
var
  i, Colunas, Linhas, Lado, Largura, Altura: Integer;
  Botao: TPanel;
begin
  for i := FValoresBox.ControlCount - 1 downto 0 do
    FValoresBox.Controls[i].Free;
  Colunas := Min(3, Length(FConfig.Valores));
  Linhas := (Length(FConfig.Valores) + Colunas - 1) div Colunas;
  Largura := (FValoresBox.Width - (Colunas - 1) * 12) div Colunas;
  Altura := Min(110, (FValoresBox.Height - (Linhas - 1) * 12) div Max(1, Linhas));
  for i := 0 to High(FConfig.Valores) do
  begin
    Botao := CriaBotao(FValoresBox, 'R$ ' + IntToStr(FConfig.Valores[i]), $00007000);
    Botao.Font.Size := 26;
    Lado := i mod Colunas;
    Botao.SetBounds(Lado * (Largura + 12), (i div Colunas) * (Altura + 12), Largura, Altura);
    Botao.Tag := FConfig.Valores[i];
    Botao.OnClick := @ValorClick;
  end;
  FValoresBox.Visible := True;
  FQr.Visible := False;
  MostraAviso('Escolha o valor', clWhite);
end;

procedure TTelaPix.MostraAviso(const Texto: string; Cor: TColor);
begin
  FAviso.Font.Color := Cor;
  FAviso.Caption := Texto;
end;

procedure TTelaPix.Abre;
begin
  if FEstado <> peFechada then
    Exit;
  FEstado := peEscolhendo;
  FTitulo.Caption := 'Pague com Pix';
  FBotaoCancelar.Caption := 'Cancelar';
  MostraValores;
  FPainel.Visible := True;
  FPainel.BringToFront;
end;

procedure TTelaPix.Fecha;
begin
  FPainel.Visible := False;
  FEstado := peFechada;
  FTxidAtual := '';
  FTxidGerando := '';
  FReaisEscolhidos := 0;
end;

procedure TTelaPix.BotaoPixClick(Sender: TObject);
begin
  Abre;
end;

procedure TTelaPix.FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if (FConfig.Tecla <> 0) and (Key = FConfig.Tecla) then
  begin
    if FEstado = peFechada then
      Abre
    else
      CancelarClick(nil);
    Key := 0;
    Exit;
  end;
  if Assigned(FAntigoKeyDown) then
    FAntigoKeyDown(Sender, Key, Shift);
end;

procedure TTelaPix.ValorClick(Sender: TObject);
begin
  if FEstado <> peEscolhendo then
    Exit;
  FReaisEscolhidos := (Sender as TComponent).Tag;
  FEstado := peGerando;
  FValoresBox.Visible := False;
  FTitulo.Caption := 'Pix de R$ ' + IntToStr(FReaisEscolhidos) + ',00';
  MostraAviso('Gerando o QR Code...', clWhite);
  { A tarefa começa no próximo Tick, quando o PSP estiver livre. }
end;

procedure TTelaPix.AbandonaAtual;
var
  i: Integer;
begin
  { A cobrança aberta é removida no PSP para não poder mais ser paga; até lá, continua sendo consultada. }
  if FTxidAtual <> '' then
  begin
    i := AchaPendente(FTxidAtual);
    if i >= 0 then
    begin
      FPendentes[i].Cancelar := True;
      FPendentes[i].ProximaConsulta := Now;
    end;
  end;
end;

procedure TTelaPix.CancelarClick(Sender: TObject);
begin
  case FEstado of
    peAguardando, peGerando:
      begin
        AbandonaAtual;
        Registra('cancelado na tela (' + FTxidAtual + ')');
      end;
  end;
  Fecha;
end;

procedure TTelaPix.IniciaTarefa(Operacao: TPixOperacao; const Txid: string; Reais: Integer);
begin
  FTarefa := TPixTarefa.Create(FCliente, Operacao, Txid, Reais);
end;

procedure TTelaPix.Tick(Sender: TObject);
var
  i, Restam: Integer;
  Tarefa: TPixTarefa;
begin
  { Resultado da chamada que terminou. }
  if (FTarefa <> nil) and FTarefa.Finished then
  begin
    Tarefa := FTarefa;
    FTarefa := nil;
    try
      TrataResultado(Tarefa);
    finally
      Tarefa.Free;
    end;
  end;

  { Contagem do QR Code na tela. }
  if FEstado = peAguardando then
  begin
    Restam := Round((FFimAtual - Now) * SecsPerDay);
    if Restam <= 0 then
    begin
      Registra('tempo esgotado (' + FTxidAtual + ')');
      AbandonaAtual;
      Fecha;
    end
    else
      MostraAviso(Format('Aponte a câmera do celular para o QR Code' + LineEnding + 'Vence em %d:%.2d',
        [Restam div 60, Restam mod 60]), clWhite);
  end;
  if (FEstado in [pePago, peErro]) and (Now >= FFecharEm) then
    Fecha;
  AjustaBotao;

  { Próxima chamada ao PSP, uma de cada vez. }
  if FTarefa <> nil then
    Exit;
  if (FEstado = peGerando) and (FTxidGerando = '') then
  begin
    FTxidGerando := NovoTxid;
    IniciaTarefa(poCriar, FTxidGerando, FReaisEscolhidos);
    Exit;
  end;
  for i := 0 to High(FPendentes) do
    if Now >= FPendentes[i].ProximaConsulta then
    begin
      if FPendentes[i].Cancelar then
        IniciaTarefa(poCancelar, FPendentes[i].Txid, FPendentes[i].Reais)
      else
        IniciaTarefa(poConsultar, FPendentes[i].Txid, FPendentes[i].Reais);
      Exit;
    end;
end;

function TTelaPix.TelaDaOriginalPorCima: Boolean;
var
  i: Integer;
  Controle: TControl;
begin
  { Bloqueio, menu do operador, erro, ativação: a original mostra painéis grandes por cima da tela principal.
    Com um deles à vista, o Pix fica escondido (não se vende crédito com a jukebox bloqueada ou no menu). }
  Result := False;
  for i := 0 to FForm.ControlCount - 1 do
  begin
    Controle := FForm.Controls[i];
    if (Controle = FBotao) or (Controle = FPainel) or not Controle.Visible or not (Controle is TCustomPanel) then
      Continue;
    if (Controle.Align = alClient) or
      (Controle.Width * Controle.Height * 2 >= FForm.ClientWidth * FForm.ClientHeight) then
      Exit(True);
  end;
end;

procedure TTelaPix.AjustaBotao;
var
  Livre: Boolean;
begin
  Livre := (FEstado = peFechada) and not TelaDaOriginalPorCima;
  if Livre <> FBotao.Visible then
    FBotao.Visible := Livre;
  { A original traz componentes para a frente nos seus timers; o Pix volta para cima a cada ciclo. }
  if Livre then
    FBotao.BringToFront
  else if FPainel.Visible then
    FPainel.BringToFront;
end;

procedure TTelaPix.TrataResultado(Tarefa: TPixTarefa);
var
  i: Integer;
  Imagem: TBitmap;
  DaTela: Boolean;
begin
  case Tarefa.Operacao of
    poCriar:
      begin
        DaTela := (FEstado = peGerando) and (Tarefa.Txid = FTxidGerando);
        if not Tarefa.Ok then
        begin
          Registra('erro ao criar cobrança: ' + Tarefa.Erro);
          if DaTela then
          begin
            FEstado := peErro;
            FFecharEm := Now + 6 / SecsPerDay;
            FBotaoCancelar.Caption := 'OK';
            MostraAviso('Pix indisponível agora. Tente de novo em instantes.', clRed);
          end;
          Exit;
        end;
        { Fica pendente mesmo que a tela já tenha sido fechada: a cobrança existe no PSP. }
        SetLength(FPendentes, Length(FPendentes) + 1);
        with FPendentes[High(FPendentes)] do
        begin
          Txid := Tarefa.Txid;
          Reais := Tarefa.Reais;
          Criado := Now;
          ProximaConsulta := Now + PIX_CONSULTA_ATUAL_SEGUNDOS / SecsPerDay;
          Cancelar := not DaTela;
        end;
        GravaPendentes;
        Registra('cobrança criada: ' + Tarefa.Txid + ' R$ ' + IntToStr(Tarefa.Reais));
        if not DaTela then
          Exit;

        Imagem := TBitmap.Create;
        try
          DesenhaQrCode(Tarefa.CopiaECola, Imagem, Min(FQr.Width, FQr.Height));
          FQr.Picture.Assign(Imagem);
        finally
          Imagem.Free;
        end;
        FQr.Visible := True;
        FTxidAtual := Tarefa.Txid;
        FFimAtual := Now + FConfig.Expiracao / SecsPerDay;
        FEstado := peAguardando;
      end;

    poConsultar:
      begin
        i := AchaPendente(Tarefa.Txid);
        if i < 0 then
          Exit;
        if not Tarefa.Ok then
        begin
          Registra('erro ao consultar ' + Tarefa.Txid + ': ' + Tarefa.Erro);
          FPendentes[i].ProximaConsulta := Now + PIX_CONSULTA_FUNDO_SEGUNDOS / SecsPerDay;
        end
        else
          case Tarefa.Status of
            psConcluida:
              begin
                Credita(i);
                Exit;
              end;
            psRemovida:
              begin
                Registra('cobrança removida no PSP: ' + Tarefa.Txid);
                RemovePendente(i);
                Exit;
              end;
          else
            if FPendentes[i].Cancelar then
              { Cancelada enquanto esta consulta estava no ar: remove no PSP já no próximo ciclo. }
              FPendentes[i].ProximaConsulta := Now
            else if Tarefa.Txid = FTxidAtual then
              FPendentes[i].ProximaConsulta := Now + PIX_CONSULTA_ATUAL_SEGUNDOS / SecsPerDay
            else
              FPendentes[i].ProximaConsulta := Now + PIX_CONSULTA_FUNDO_SEGUNDOS / SecsPerDay;
          end;
        { Vencida há tempo e não paga: já não pode ser paga, para de consultar. }
        if Now > FPendentes[i].Criado + (FConfig.Expiracao + PIX_FOLGA_SEGUNDOS) / SecsPerDay then
        begin
          Registra('cobrança vencida sem pagamento: ' + Tarefa.Txid);
          RemovePendente(i);
        end;
      end;

    poCancelar:
      begin
        i := AchaPendente(Tarefa.Txid);
        if i < 0 then
          Exit;
        if Tarefa.Ok then
        begin
          Registra('cobrança removida: ' + Tarefa.Txid);
          RemovePendente(i);
        end
        else
        begin
          { Pode ter sido paga enquanto cancelava: segue consultando até vencer. }
          Registra('não removeu ' + Tarefa.Txid + ' (' + Tarefa.Erro + '); segue consultando');
          FPendentes[i].Cancelar := False;
          FPendentes[i].ProximaConsulta := Now;
        end;
      end;
  end;
end;

function TTelaPix.AchaPendente(const Txid: string): Integer;
begin
  for Result := 0 to High(FPendentes) do
    if FPendentes[Result].Txid = Txid then
      Exit;
  Result := -1;
end;

procedure TTelaPix.RemovePendente(Indice: Integer);
var
  i: Integer;
begin
  for i := Indice to High(FPendentes) - 1 do
    FPendentes[i] := FPendentes[i + 1];
  SetLength(FPendentes, Length(FPendentes) - 1);
  GravaPendentes;
end;

procedure TTelaPix.GravaPendentes;
var
  Linhas: TStringList;
  i: Integer;
begin
  Linhas := TStringList.Create;
  try
    for i := 0 to High(FPendentes) do
      Linhas.Add(FPendentes[i].Txid + ';' + IntToStr(FPendentes[i].Reais) + ';' +
        FormatDateTime('yyyy-mm-dd hh:nn:ss', FPendentes[i].Criado));
    try
      Linhas.SaveToFile(FPasta + ARQ_PIX_PENDENTES);
    except
      on E: Exception do
        Registra('não consegui gravar ' + ARQ_PIX_PENDENTES + ': ' + E.Message);
    end;
  finally
    Linhas.Free;
  end;
end;

procedure TTelaPix.LePendentes;
var
  Linhas, Partes: TStringList;
  i: Integer;
  DataCriado: TDateTime;
  Formato: TFormatSettings;
begin
  SetLength(FPendentes, 0);
  if not FileExists(FPasta + ARQ_PIX_PENDENTES) then
    Exit;
  Formato := DefaultFormatSettings;
  Formato.DateSeparator := '-';
  Formato.TimeSeparator := ':';
  Formato.ShortDateFormat := 'yyyy-mm-dd';
  Formato.LongTimeFormat := 'hh:nn:ss';
  Linhas := TStringList.Create;
  Partes := TStringList.Create;
  try
    Linhas.LoadFromFile(FPasta + ARQ_PIX_PENDENTES);
    for i := 0 to Linhas.Count - 1 do
    begin
      Partes.Clear;
      Partes.StrictDelimiter := True;
      Partes.Delimiter := ';';
      Partes.DelimitedText := Trim(Linhas[i]);
      if (Partes.Count < 3) or JaCreditado(Partes[0]) then
        Continue;
      if not TryStrToDateTime(Partes[2], DataCriado, Formato) then
        DataCriado := Now;
      SetLength(FPendentes, Length(FPendentes) + 1);
      with FPendentes[High(FPendentes)] do
      begin
        Txid := Partes[0];
        Reais := StrToIntDef(Partes[1], 0);
        Criado := DataCriado;
        ProximaConsulta := Now;
        Cancelar := False;
      end;
    end;
  finally
    Partes.Free;
    Linhas.Free;
  end;
end;

function TTelaPix.JaCreditado(const Txid: string): Boolean;
var
  Linhas: TStringList;
  i: Integer;
begin
  Result := False;
  if not FileExists(FPasta + ARQ_PIX_CREDITADOS) then
    Exit;
  Linhas := TStringList.Create;
  try
    Linhas.LoadFromFile(FPasta + ARQ_PIX_CREDITADOS);
    for i := 0 to Linhas.Count - 1 do
      if Copy(Linhas[i], 1, Length(Txid) + 1) = Txid + ';' then
        Exit(True);
  finally
    Linhas.Free;
  end;
end;

procedure TTelaPix.Credita(Indice: Integer);
var
  Pendente: TPixPendente;
  Arquivo: TextFile;
begin
  Pendente := FPendentes[Indice];
  RemovePendente(Indice);
  if JaCreditado(Pendente.Txid) then
    Exit;

  { Registra antes de creditar: se a máquina cair no meio, o pagamento não vira crédito duas vezes. }
  try
    AssignFile(Arquivo, FPasta + ARQ_PIX_CREDITADOS);
    if FileExists(FPasta + ARQ_PIX_CREDITADOS) then
      Append(Arquivo)
    else
      Rewrite(Arquivo);
    Writeln(Arquivo, Pendente.Txid, ';', Pendente.Reais, ';', FormatDateTime('yyyy-mm-dd hh:nn:ss', Now));
    CloseFile(Arquivo);
  except
    on E: Exception do
      Registra('não consegui gravar ' + ARQ_PIX_CREDITADOS + ': ' + E.Message);
  end;

  Registra('pago: ' + Pendente.Txid + ' R$ ' + IntToStr(Pendente.Reais));
  if Assigned(FOnCreditar) then
    FOnCreditar(Pendente.Reais);

  if Pendente.Txid = FTxidAtual then
  begin
    FEstado := pePago;
    FFecharEm := Now + 4 / SecsPerDay;
    FBotaoCancelar.Caption := 'OK';
    FQr.Visible := False;
    MostraAviso('Pagamento recebido!' + LineEnding + 'Créditos liberados. Boa música!', clLime);
  end;
end;

end.

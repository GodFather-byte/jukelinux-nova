{ Rotinas próprias da JukeLinux Nova (não existem na original). As declarações "forward" ficam em nova_decl.inc,
  para o código traduzido poder chamá-las. }

const
  { Guarda os dois seriais do pendrive-chave antigo da máquina, cifrados como a original cifra os seus arquivos. }
  ARQ_SERIAL_DA_CHAVE = 'serial-da-chave.txt';

function PrimeiraLinha(const Arquivo: string): string;
var
  F: Text;
begin
  Result := '';
  if not FileExists(Arquivo) then Exit;
  AssignFile(F, Arquivo);
  Reset(F);
  if not Eof(F) then Readln(F, Result);
  CloseFile(F);
end;

{ A original confere os arquivos do HD contra os seriais do pendrive-chave: o do hardware (JC_SERIALPENDRIVE, que
  vai cifrado com Cripta, por exemplo no jukelinux.ini e no creditos.txt) e o gravado no jukebox.contadores
  (JC_SERIALPENDRIVECON, com Criptasuper2, por exemplo no bloquearquandotocar.txt). A Nova não depende do pendrive:
  lê os dois uma vez da primeira linha desses arquivos e guarda em serial-da-chave.txt. A licença nova (fase 6)
  passa a cuidar desse arquivo. }
procedure Serial_Da_Chave_No_Hd;
var
  F: Text;
  Hardware, Contadores: string;
begin
  if FileExists(PASTA + ARQ_SERIAL_DA_CHAVE) then begin
    AssignFile(F, PASTA + ARQ_SERIAL_DA_CHAVE);
    Reset(F);
    Readln(F, Hardware);
    Readln(F, Contadores);
    CloseFile(F);
    Hardware := Descripta(Hardware);
    Contadores := Descriptasuper2(Contadores);
  end
  else begin
    Hardware := Descripta(PrimeiraLinha(PASTA + 'jukelinux.ini'));
    Contadores := Descriptasuper2(PrimeiraLinha(PASTA + 'bloquearquandotocar.txt'));
    if Hardware = '' then begin
      { Instalação nova (sem os arquivos da máquina antiga): o serial vem do código da máquina da licença nova. }
      Hardware := 'NOVA' + SoDigitos(CodigoDaMaquina(IdentidadeDaMaquina));
      Contadores := Hardware;
      Gravalog('Serial da chave: maquina nova, serial tirado do codigo da licenca: ' + Hardware);
    end;
    AssignFile(F, PASTA + ARQ_SERIAL_DA_CHAVE);
    Rewrite(F);
    Writeln(F, Cripta(Hardware));
    Writeln(F, Criptasuper2(Contadores));
    CloseFile(F);
    Gravalog('Serial da chave guardado no HD em ' + ARQ_SERIAL_DA_CHAVE);
  end;
  JC_SERIALPENDRIVE := Hardware;
  JC_SERIALPENDRIVECON := Contadores;
  JC_INI := Hardware;
  ERROSERIALNUM := 0;
  ERROSERIAL := '';
  Gravalog('Serial da chave lido do HD: ' + Hardware + ' / ' + Contadores);
end;

{ ---------------------------------------------------------------------------------------------------------------
  Pix no relógio. O relógio parcial conta o dinheiro do noteiro e o do Pix juntos (um Pix de R$ N é N pulsos); o
  Pix vai direto para a conta do dono. pixrelogio.txt guarda, cifrado como os relógios, o Pix do período (zera com
  o relógio parcial) e o total. No menu Relógios aparecem o Pix, o dinheiro no noteiro e o acerto com a casa. }

const
  ARQ_PIX_RELOGIO = 'pixrelogio.txt';

var
  NovaPixParcial: LongInt = 0;
  NovaPixTotal: LongInt = 0;
  NovaPixLabels: array[1..3] of TLabel;

procedure Nova_Le_Pix_Relogio;
var
  L: TStringList;
begin
  NovaPixParcial := 0;
  NovaPixTotal := 0;
  if not FileExists(PASTA + ARQ_PIX_RELOGIO) then
    Exit;
  L := TStringList.Create;
  try
    try
      L.LoadFromFile(PASTA + ARQ_PIX_RELOGIO);
      if L.Count > 0 then NovaPixParcial := StrToIntDef(Descripta(L[0]), 0);
      if L.Count > 1 then NovaPixTotal := StrToIntDef(Descripta(L[1]), 0);
    except
      on E: Exception do
        Gravalog('Pix: nao li ' + ARQ_PIX_RELOGIO + ' (' + E.Message + ')');
    end;
  finally
    L.Free;
  end;
end;

procedure Nova_Grava_Pix_Relogio;
var
  L: TStringList;
begin
  L := TStringList.Create;
  try
    L.Add(Cripta(IntToStr(NovaPixParcial)));
    L.Add(Cripta(IntToStr(NovaPixTotal)));
    try
      L.SaveToFile(PASTA + ARQ_PIX_RELOGIO);
    except
      on E: Exception do
        Gravalog('Pix: nao gravei ' + ARQ_PIX_RELOGIO + ' (' + E.Message + ')');
    end;
  finally
    L.Free;
  end;
end;

procedure Nova_Soma_Pix_Relogio(Reais: LongInt);
begin
  if Reais <= 0 then
    Exit;
  Nova_Le_Pix_Relogio;
  NovaPixParcial := NovaPixParcial + Reais;
  NovaPixTotal := NovaPixTotal + Reais;
  Nova_Grava_Pix_Relogio;
  Gravalog('Pix no relogio: +R$ ' + IntToStr(Reais) + ' [Pix parcial=' + IntToStr(NovaPixParcial) + ' total=' +
    IntToStr(NovaPixTotal) + ']');
end;

{ Fechamento (zerar o relógio parcial): o Pix do período vai para o histórico pixfechamentos.txt e zera. }
procedure Nova_Zera_Pix_Parcial;
var
  F: TextFile;
begin
  Nova_Le_Pix_Relogio;
  try
    AssignFile(F, PASTA + 'pixfechamentos.txt');
    if FileExists(PASTA + 'pixfechamentos.txt') then Append(F) else Rewrite(F);
    Writeln(F, FormatDateTime('dd/mm/yyyy hh:nn', Now), ' - Pix no periodo: R$ ', NovaPixParcial, ',00');
    CloseFile(F);
  except
    on E: Exception do
      Gravalog('Pix: nao gravei pixfechamentos.txt (' + E.Message + ')');
  end;
  Gravalog('Pix no relogio: fechamento, Pix do periodo R$ ' + IntToStr(NovaPixParcial) + ',00');
  NovaPixParcial := 0;
  Nova_Grava_Pix_Relogio;
end;

{ Linhas do Pix no menu Relógios, abaixo do Valor do Ponto, no mesmo estilo das da original. A casa fica com o
  Valor do Ponto; como o Pix já está com o dono, a casa recebe a parte dela do dinheiro do noteiro e, se ele não
  bastar, o dono completa. }
procedure Nova_Mostra_Pix_Relogio;
var
  i, Dinheiro, Casa: LongInt;
  Pai: TWinControl;
begin
  Nova_Le_Pix_Relogio;
  Pai := Form1.LabelVE.Parent;
  for i := 1 to 3 do
    if NovaPixLabels[i] = nil then
    begin
      NovaPixLabels[i] := TLabel.Create(Form1);
      NovaPixLabels[i].Parent := Pai;
      NovaPixLabels[i].Left := Form1.LabelVE.Left;
      { entre os avisos do menu (LabelPress2 termina em 506) e o Último Fechamento (586), à esquerda do QR }
      NovaPixLabels[i].Top := 508 + (i - 1) * 25;
      NovaPixLabels[i].Font.Name := Form1.LabelVE.Font.Name;
      NovaPixLabels[i].Font.Height := -21;
      NovaPixLabels[i].Font.Color := clWhite;
      NovaPixLabels[i].Transparent := True;
    end;
  Dinheiro := RELOGIOPARCIAL - NovaPixParcial;
  if Dinheiro < 0 then Dinheiro := 0;
  Casa := VALORPONTO;
  NovaPixLabels[1].Caption := 'Pix (conta do dono): R$ ' + IntToStr(NovaPixParcial) + ',00';
  NovaPixLabels[2].Caption := 'Dinheiro no noteiro: R$ ' + IntToStr(Dinheiro) + ',00';
  NovaPixLabels[3].Font.Color := clYellow;
  if Casa <= Dinheiro then
    NovaPixLabels[3].Caption := 'Acerto: casa tira R$ ' + IntToStr(Casa) + ',00 do noteiro'
  else
    NovaPixLabels[3].Caption := 'Acerto: casa tira R$ ' + IntToStr(Dinheiro) + ',00 + dono paga R$ ' +
      IntToStr(Casa - Dinheiro) + ',00';
  for i := 1 to 3 do
  begin
    NovaPixLabels[i].Show;
    NovaPixLabels[i].BringToFront;
  end;
end;

{ ---------------------------------------------------------------------------------------------------------------
  Pix (pixtela.pas e pix.pas). Liga a tela do Pix às rotinas da original. Fica desligado se não houver pix.txt na
  pasta da jukebox; o modelo do arquivo está em instalacao/pix.txt.exemplo. }

type
  TNovaPix = class
    procedure Creditar(Reais: Integer);
    procedure Registrar(const Texto: string);
  end;

var
  NovaPix: TNovaPix = nil;

procedure TNovaPix.Creditar(Reais: Integer);
var
  i, Antes, RelogioAntes: LongInt;
begin
  { Um Pix de R$ N vale N pulsos de R$ 1 do noteiro: a própria Rotina_Creditos soma os créditos, grava o
    creditos.txt e os relógios e aplica o bônus de cédula do modo REAISXMUSICAS, como faria com dinheiro. }
  Antes := CREDITOS;
  RelogioAntes := RELOGIOPARCIAL;
  for i := 1 to Reais do
    Rotina_Creditos('Normal');
  { o que entrou no relógio por Pix (o dinheiro foi para a conta do dono, não para o noteiro) }
  Nova_Soma_Pix_Relogio(RELOGIOPARCIAL - RelogioAntes);
  Gravalog('Pix: R$ ' + IntToStr(Reais) + ' viraram créditos (' + IntToStr(Antes) + ' -> ' + IntToStr(CREDITOS) +
    ')');
  if CREDITOS = Antes then
    Gravalog('Pix: ATENÇÃO, nenhum crédito somado (menu aberto ou REAISXMUSICAS desconhecido: ' + REAISXMUSICAS +
      '); conferir pix-creditados.txt');
end;

procedure TNovaPix.Registrar(const Texto: string);
begin
  Gravalog('Pix: ' + Texto);
end;

procedure Nova_Inicia_Pix;
var
  Config: TPixConfig;
  Erro, PastaJuke: string;
begin
  PastaJuke := PASTA;
  if PastaJuke = '' then
    PastaJuke := PASTA_JUKELINUX;
  if not FileExists(PastaJuke + 'pix.txt') then
    Exit;
  if not LeConfigPix(PastaJuke + 'pix.txt', Config, Erro) then
  begin
    Gravalog('Pix desligado: ' + Erro);
    Exit;
  end;
  if not Config.Ativo then
    Exit;
  NovaPix := TNovaPix.Create;
  TTelaPix.Cria(Form1, Config, PastaJuke, @NovaPix.Creditar, @NovaPix.Registrar);
end;

{ ---------------------------------------------------------------------------------------------------------------
  Músicas: decifra (ou copia) a música da fila para o arquivo que o player toca. Ver musicacifra.pas. }
function Nova_Decifra_Musica(const Origem, Destino: string; Chave: LongInt): Boolean;
var
  Gravadora, Erro: string;
begin
  Result := DecifraMusica(Origem, Destino, Chave, Gravadora, Erro);
  if Result then
    TIMER1GRAVADORA := Gravadora
  else
    Gravalog('Musica: nao consegui preparar ' + Origem + ' (' + Erro + ')');
end;

{ ---------------------------------------------------------------------------------------------------------------
  Licença (licenca.pas). Usa a tela de ativação da original (PanelAtivacao): sem licença válida ela fica por cima, as
  teclas da jukebox não respondem (só o campo da contra-senha) e a fila não toca. }

type
  TNovaLicenca = class
  private
    FPasta: string;
    FCodigo: string;
    FBloqueada: Boolean;
    FTimer: TTimer;
    FTicks: Integer;
    FAvisoAte: TDateTime;
    FAntigoKeyDown, FAntigoKeyUp: TKeyEvent;
    procedure Bloqueia(const Titulo: string);
    procedure Libera;
    procedure Confere;
  public
    constructor Create(const APasta: string);
    procedure AtivarClick(Sender: TObject);
    procedure KeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure KeyUp(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure Tick(Sender: TObject);
  end;

const
  TEXTO_ATIVACAO4 = ' Digite o Número Informado pela Empresa no Campo Abaixo e Clique em Ativar';

var
  NovaLicenca: TNovaLicenca = nil;

constructor TNovaLicenca.Create(const APasta: string);
begin
  inherited Create;
  FPasta := APasta;
  FAntigoKeyDown := Form1.OnKeyDown;
  FAntigoKeyUp := Form1.OnKeyUp;
  Form1.OnKeyDown := @KeyDown;
  Form1.OnKeyUp := @KeyUp;
  Form1.ButtonAtivar.OnClick := @AtivarClick;
  FTimer := TTimer.Create(Form1);
  FTimer.Interval := 500;
  FTimer.OnTimer := @Tick;
  if NOVA_CHAVE_DESENVOLVIMENTO then
    Gravalog('Licenca: ATENCAO, compilado com a chave de DESENVOLVIMENTO (qualquer um gera contra-senha)');
  Confere;
  FTimer.Enabled := True;
end;

procedure TNovaLicenca.Confere;
var
  L: TLicenca;
begin
  L := LeLicenca(FPasta, Now);
  FCodigo := L.Codigo;
  case L.Estado of
    elValida:
      begin
        if L.Validade = LICENCA_PERMANENTE then
          Gravalog('Licenca: valida, permanente (maquina ' + FCodigo + ')')
        else
          Gravalog('Licenca: valida ate ' + FormatDateTime('dd"/"mm"/"yyyy', ValidadeParaData(L.Validade)) +
            ' (maquina ' + FCodigo + ')');
        { guarda o dia de hoje: atrasar o relógio depois não estende a validade }
        GravaLicenca(FPasta, FCodigo, L.ContraSenha, L.Hoje);
        if FBloqueada then
          Libera;
      end;
    elVencida:
      begin
        Gravalog('Licenca: vencida (maquina ' + FCodigo + ')');
        Bloqueia('Licença Vencida');
      end;
  else
    Gravalog('Licenca: ' + DescreveEstado(L.Estado) + ' (maquina ' + FCodigo + ')');
    Bloqueia('Ativação da Jukebox');
  end;
end;

procedure TNovaLicenca.Bloqueia(const Titulo: string);
begin
  FBloqueada := True;
  Form1.LabelAtivacao1.Caption := Titulo;
  Form1.LabelAtivacao2.Caption := FCodigo;
  Form1.LabelAtivacao4.Caption := TEXTO_ATIVACAO4;
  Form1.LabelAtivacao4.Font.Color := clTeal;
  Form1.EditSenhaAtivacao.Text := '';
  Form1.PanelAtivacao.Align := alClient;
  Form1.PanelAtivacao.Show;
  Form1.PanelAtivacao.BringToFront;
  Form1.TimerTocar.Enabled := False;
  if Form1.Play.Running then
    Form1.Play.Stop;
  { o foco no campo vem no Tick: aqui a janela pode ainda não estar na tela }
end;

procedure FocaSemErro(Controle: TWinControl);
begin
  try
    if Form1.Showing and Controle.CanFocus then
      Controle.SetFocus;
  except
    { a janela ainda não aceita foco: tenta no próximo Tick }
  end;
end;

procedure TNovaLicenca.Libera;
begin
  FBloqueada := False;
  Form1.PanelAtivacao.Hide;
  Form1.TimerTocar.Enabled := True;
  FocaSemErro(Form1);
end;

procedure TNovaLicenca.AtivarClick(Sender: TObject);
var
  Validade: Integer;
  Estado: TEstadoLicenca;
begin
  Estado := ConfereContraSenha(FCodigo, Form1.EditSenhaAtivacao.Text, NOVA_CHAVE_LICENCA, Now, Validade);
  if Estado = elValida then
  begin
    GravaLicenca(FPasta, FCodigo, Form1.EditSenhaAtivacao.Text, Now);
    Gravalog('Licenca: ativada (maquina ' + FCodigo + ')');
    { a mesma tela de "Ativação OK" da original; a Nova libera sem precisar desligar }
    Form1.PanelAtivacao.Hide;
    Form1.PanelErro.Align := alClient;
    Form1.LabelErro1.Caption := 'Ativação';
    Form1.LabelErro2.Caption := 'OK';
    Form1.MemoErro.Caption := 'Ativação OK';
    Form1.PanelErro.Show;
    Form1.PanelErro.BringToFront;
    FAvisoAte := Now + 4 / SecsPerDay;
    FBloqueada := False;
    Form1.TimerTocar.Enabled := True;
  end
  else
  begin
    Gravalog('Licenca: tentativa de ativacao recusada: ' + DescreveEstado(Estado));
    if Estado = elVencida then
      Form1.LabelAtivacao4.Caption := ' Este Número Já Venceu. Ligue para a Empresa'
    else
      Form1.LabelAtivacao4.Caption := ' Número Errado. Confira e Digite de Novo';
    Form1.LabelAtivacao4.Font.Color := clRed;
    Form1.EditSenhaAtivacao.Text := '';
    FAvisoAte := Now + 5 / SecsPerDay;
  end;
end;

procedure TNovaLicenca.KeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if FBloqueada then
  begin
    if Form1.ActiveControl = Form1.EditSenhaAtivacao then
    begin
      if Key = VK_RETURN then
      begin
        Key := 0;
        AtivarClick(nil);
      end;
    end
    else
      Key := 0;  // a jukebox não responde sem licença
    Exit;
  end;
  if Assigned(FAntigoKeyDown) then
    FAntigoKeyDown(Sender, Key, Shift);
end;

procedure TNovaLicenca.KeyUp(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if FBloqueada then
  begin
    if Form1.ActiveControl <> Form1.EditSenhaAtivacao then
      Key := 0;
    Exit;
  end;
  if Assigned(FAntigoKeyUp) then
    FAntigoKeyUp(Sender, Key, Shift);
end;

procedure TNovaLicenca.Tick(Sender: TObject);
begin
  if (FAvisoAte <> 0) and (Now >= FAvisoAte) then
  begin
    FAvisoAte := 0;
    if FBloqueada then
    begin
      Form1.LabelAtivacao4.Caption := TEXTO_ATIVACAO4;
      Form1.LabelAtivacao4.Font.Color := clTeal;
    end
    else if Form1.PanelErro.Visible and (Form1.LabelErro1.Caption = 'Ativação') then
    begin
      Form1.PanelErro.Hide;
      FocaSemErro(Form1);
    end;
  end;
  if FBloqueada then
  begin
    { a original mexe nos painéis e timers por conta própria: a ativação fica por cima }
    if not Form1.PanelAtivacao.Visible then
      Form1.PanelAtivacao.Show;
    Form1.PanelAtivacao.BringToFront;
    Form1.TimerTocar.Enabled := False;
    if Form1.ActiveControl <> Form1.EditSenhaAtivacao then
      FocaSemErro(Form1.EditSenhaAtivacao);
  end;
  { confere de novo a cada hora (a licença pode vencer com a jukebox ligada) }
  Inc(FTicks);
  if FTicks >= 7200 then
  begin
    FTicks := 0;
    Confere;
  end;
end;

procedure Nova_Inicia_Licenca;
var
  PastaJuke: string;
begin
  PastaJuke := PASTA;  // a global (o nome da local não pode ser Pasta: o Pascal não diferencia maiúsculas)
  if PastaJuke = '' then
    PastaJuke := PASTA_JUKELINUX;
  NovaLicenca := TNovaLicenca.Create(PastaJuke);
end;

{ Horas ligadas a partir dos minutos, como a original mostra: com ponto e até 2 casas ("12.5", "3.33"). A original
  cortava o texto em "posição do ponto + 2", o que com horas inteiras de 100 para cima ("120") deixava "12". }
function Nova_Horas(Minutos: LongInt): string;
var
  Formato: TFormatSettings;
  Ponto: Integer;
begin
  Formato := DefaultFormatSettings;
  Formato.DecimalSeparator := '.';
  Result := FloatToStr(Minutos / 60, Formato);
  Ponto := Pos('.', Result);
  if Ponto > 0 then
    Result := Copy(Result, 1, Ponto + 2);
end;

{ Data do arquivo .ATU de um CD de lançamento. A original usava StrToDate com o formato do sistema; aqui vale
  dd/mm/aaaa (também com '-' ou '.') e, se não der, o formato do sistema. 0 = data que não deu para ler (o CD não
  entra como lançamento, em vez de a jukebox parar com erro). }
function Nova_Data_Atu(const Texto: string): TDateTime;
var
  Formato: TFormatSettings;
  Separador: Char;
begin
  for Separador in ['/', '-', '.'] do
  begin
    Formato := DefaultFormatSettings;
    Formato.DateSeparator := Separador;
    Formato.ShortDateFormat := 'dd' + Separador + 'mm' + Separador + 'yyyy';
    if TryStrToDate(Trim(Texto), Result, Formato) then
      Exit;
  end;
  if not TryStrToDate(Trim(Texto), Result) then
    Result := 0;
end;

var
  NovaImagensAvisadas: TStringList = nil;

{ Carrega uma imagem num componente. Na original, uma imagem que faltasse (ritmo, letra, capa, propaganda) dava erro
  e a tela parava pela metade. Aqui, se o arquivo não existir ou não abrir, aparece uma imagem feita na hora com o
  nome (por exemplo o nome do ritmo, tirado do arquivo axe.jpg -> AXE) e o log registra uma vez qual arquivo falta. }
procedure Nova_Carrega_Imagem(Imagem: TPicture; const Arquivo: string);
var
  Bmp: TBitmap;
  Nome: string;
  Estilo: TTextStyle;
begin
  if Arquivo = '' then
  begin
    Imagem.Clear;
    Exit;
  end;
  if FileExists(Arquivo) then
  try
    Imagem.LoadFromFile(Arquivo);
    Exit;
  except
    on E: Exception do
      Gravalog('Imagem: nao abriu ' + Arquivo + ' (' + E.Message + ')');
  end
  else
  begin
    if NovaImagensAvisadas = nil then
    begin
      NovaImagensAvisadas := TStringList.Create;
      NovaImagensAvisadas.Sorted := True;
    end;
    if NovaImagensAvisadas.IndexOf(Arquivo) < 0 then
    begin
      NovaImagensAvisadas.Add(Arquivo);
      Gravalog('Imagem: falta o arquivo ' + Arquivo + ' (mostrando o nome no lugar)');
    end;
  end;
  Nome := UpperCase(ChangeFileExt(ExtractFileName(ExcludeTrailingPathDelimiter(Arquivo)), ''));
  if (Nome = 'CAPAPEQUENA') or (Nome = 'CAPA') then
    Nome := UpperCase(ExtractFileName(ExcludeTrailingPathDelimiter(ExtractFilePath(Arquivo))));
  Bmp := TBitmap.Create;
  try
    Bmp.SetSize(300, 300);
    Bmp.Canvas.Brush.Color := $00302820;
    Bmp.Canvas.FillRect(0, 0, 300, 300);
    Bmp.Canvas.Pen.Color := $00A0A0A0;
    Bmp.Canvas.Pen.Width := 4;
    Bmp.Canvas.Rectangle(2, 2, 298, 298);
    Bmp.Canvas.Font.Color := clWhite;
    Bmp.Canvas.Font.Style := [fsBold];
    Bmp.Canvas.Font.Height := -34;
    Estilo := Bmp.Canvas.TextStyle;
    Estilo.Alignment := taCenter;
    Estilo.Layout := tlCenter;
    Estilo.Wordbreak := True;
    Estilo.SingleLine := False;
    Bmp.Canvas.TextRect(Rect(12, 12, 288, 288), 12, 12, Nome, Estilo);
    Imagem.Assign(Bmp);
  finally
    Bmp.Free;
  end;
end;

{ SetFocus que não para a jukebox: só foca o que está visível e pode receber o foco agora. }
procedure Nova_Foca(Controle: TWinControl);
begin
  try
    if (Controle <> nil) and Controle.CanFocus then
      Controle.SetFocus;
  except
    on E: Exception do
      Gravalog('Foco: ' + Controle.Name + ' (' + E.Message + ')');
  end;
end;

{ Uma máquina nova (sem a JukeLinux antiga) não tem os arquivos que a original esperava achar prontos. Cria só o
  que falta, sem mexer no que já existe:
  - a pasta /home/jkb/jukelinux/;
  - inicio.sh: a original o executava para listar os discos (ls -l /dev/disk/by-id > inicio.txt) e achar o pendrive
    -chave; sem ele a abertura dava erro e a tela ficava pela metade. A licença da Nova substitui o pendrive, mas a
    lista dos discos continua sendo usada (serial do HD). }
procedure Nova_Prepara_Pasta;
const
  PASTA_JUKE = '/home/jkb/jukelinux/';
var
  F: TextFile;
begin
  try
    ForceDirectories(PASTA_JUKE);
    if not FileExists(PASTA_JUKE + 'inicio.sh') then
    begin
      AssignFile(F, PASTA_JUKE + 'inicio.sh');
      Rewrite(F);
      Writeln(F, '#!/bin/sh');
      Writeln(F, '# Criado pela JukeLinux Nova: lista os discos para a jukebox (pendrive e HD).');
      Writeln(F, 'ls -l /dev/disk/by-id/ > ' + PASTA_JUKE + 'inicio.txt 2>/dev/null');
      Writeln(F, '[ -f ' + PASTA_JUKE + 'inicio.txt ] || : > ' + PASTA_JUKE + 'inicio.txt');
      CloseFile(F);
      fpChmod(PASTA_JUKE + 'inicio.sh', &755);
    end;
  except
    { sem permissão na pasta: a abertura segue e registra o erro como a original }
  end;
end;

{ ---------------------------------------------------------------------------------------------------------------
  Pesquisa de músicas pelas teclas da jukebox (sem teclado). Abre com Cancelar apertado 3 vezes seguidas (ou com a
  tecla de teclapesquisa.txt, se houver um botão para isso). Na tela de pesquisa:
    CD+ / CD-          escolhem a letra
    Tocar              põe a letra (ou, na lista, vai para o CD/música escolhido)
    Música+ / Música-  andam pela lista de resultados
    Cancelar           apaga a última letra; sem letras, fecha
  O resultado leva ao CD (como se tivesse paginado até ele) com a música já selecionada: é só apertar Tocar para
  pô-la na fila, com a cobrança de créditos normal. As teclas de crédito e de menu continuam funcionando. }

type
  TNovaResultado = record
    Cd, Musica: LongInt;
    Texto: string;
  end;

  TNovaPesquisa = class
  private
    FPainel: TPanel;
    FTitulo, FTexto, FAjuda: TLabel;
    FLetras: array[0..12] of TLabel;
    FLinhas: array[0..7] of TLabel;
    FTimer: TTimer;
    FOrigDown, FOrigUp: TKeyEvent;
    FAberta: Boolean;
    FBusca: string;
    FLetra: Integer;
    FNaLista: Boolean;
    FSel, FTopo: Integer;
    FResultados: array of TNovaResultado;
    FCancelas: array[0..2] of QWord;
    FTeclaPesquisa: Integer;
    procedure Monta;
    procedure Mostra;
    procedure Busca;
    procedure Abre;
    procedure Fecha;
    procedure VaiPara(const R: TNovaResultado);
    procedure Inativo(Sender: TObject);
    function Trata(Key: Word): Boolean;
  public
    procedure KeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure KeyUp(Sender: TObject; var Key: Word; Shift: TShiftState);
  end;

const
  NOVA_ALFABETO = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ';

var
  NovaPesquisa: TNovaPesquisa = nil;

function Nova_Sem_Acento(const S: string): string;
const
  DE = 'ÁÀÂÃÄÉÈÊËÍÌÎÏÓÒÔÕÖÚÙÛÜÇÑáàâãäéèêëíìîïóòôõöúùûüçñ';
  PARA = 'AAAAAEEEEIIIIOOOOOUUUUCNAAAAAEEEEIIIIOOOOOUUUUCN';
var
  U: UnicodeString;
  i, p: Integer;
begin
  U := UTF8Decode(S);
  for i := 1 to Length(U) do
  begin
    p := Pos(U[i], UnicodeString(UTF8Decode(DE)));
    if p > 0 then U[i] := WideChar(PARA[p]);
  end;
  Result := UpperCase(UTF8Encode(U));
end;

procedure TNovaPesquisa.Monta;
var
  i, W, H: Integer;
  function Rotulo(Topo, Altura, Fonte: Integer; Cor: TColor): TLabel;
  begin
    Result := TLabel.Create(FPainel);
    Result.Parent := FPainel;
    Result.AutoSize := False;
    Result.Left := W div 40;
    Result.Width := W - 2 * (W div 40);
    Result.Top := Topo;
    Result.Height := Altura;
    Result.Font.Name := 'Sans';
    Result.Font.Style := [fsBold];
    Result.Font.Height := -Fonte;
    Result.Font.Color := Cor;
    Result.Transparent := False;
    Result.Color := clTeal;
    Result.Layout := tlCenter;
  end;
begin
  W := Form1.ClientWidth;
  H := Form1.ClientHeight;
  FPainel := TPanel.Create(Form1);
  FPainel.Parent := Form1;
  FPainel.SetBounds(0, 0, W, H);
  FPainel.BevelOuter := bvNone;
  FPainel.Color := clTeal;
  FPainel.Visible := False;
  FTitulo := Rotulo(H div 40, H div 12, H div 16, clYellow);
  FTitulo.Caption := 'PESQUISA';
  FTitulo.Alignment := taCenter;
  FTexto := Rotulo(H div 40 + H div 11, H div 10, H div 14, clWhite);
  FTexto.Alignment := taCenter;
  FTexto.Color := clBlack;
  for i := 0 to High(FLetras) do
  begin
    FLetras[i] := Rotulo(H div 4, H div 10, H div 14, clWhite);
    FLetras[i].Left := W div 2 + (i - 6) * (W div 15) - (W div 30);
    FLetras[i].Width := W div 16;
    FLetras[i].Alignment := taCenter;
  end;
  for i := 0 to High(FLinhas) do
    FLinhas[i] := Rotulo(H div 4 + H div 8 + i * (H div 15), H div 16, H div 24, clWhite);
  FAjuda := Rotulo(H - H div 12, H div 14, H div 34, clSilver);
  FAjuda.Alignment := taCenter;
  FAjuda.Caption := 'CD+/CD-: letra    TOCAR: escolhe    MÚSICA+/-: resultados    CANCELAR: apaga / sai';
  FTimer := TTimer.Create(Form1);
  FTimer.Enabled := False;
  FTimer.Interval := 60000;  // sem ninguém mexer por 1 minuto, a pesquisa fecha
  FTimer.OnTimer := @Inativo;
end;

procedure TNovaPesquisa.Busca;
var
  i, k, n: Integer;
  Alvo, Nome: string;
  procedure Junta(Cd, Musica: Integer; const Texto: string);
  begin
    if n >= 300 then Exit;
    if n >= Length(FResultados) then SetLength(FResultados, n + 50);
    FResultados[n].Cd := Cd;
    FResultados[n].Musica := Musica;
    FResultados[n].Texto := Texto;
    Inc(n);
  end;
begin
  n := 0;
  SetLength(FResultados, 0);
  Alvo := Trim(Nova_Sem_Acento(FBusca));
  { (o nome do CD na original termina com "/": só aparece sem ela) }
  if Alvo <> '' then
    for i := 1 to TOTALCDS do
    begin
      if MAT[i].Genero = '50+TOCADOS' then Continue;  // cópias do ranking: o CD de verdade já aparece
      Nome := Nova_Sem_Acento(MAT[i].Nome);
      if Pos(Alvo, Nome) > 0 then
        Junta(i, 0, 'CD: ' + ExcludeTrailingPathDelimiter(MAT[i].Nome));
      for k := 1 to MAT[i].TotalMusicas do
        if Pos(Alvo, Nova_Sem_Acento(MAT[i].Musica[k])) > 0 then
          Junta(i, k, MAT[i].Musica[k] + '   (' + ExcludeTrailingPathDelimiter(MAT[i].Nome) + ')');
    end;
  SetLength(FResultados, n);
  FSel := 0;
  FTopo := 0;
  if n = 0 then FNaLista := False;
end;

procedure TNovaPesquisa.Mostra;
var
  i, p: Integer;
begin
  FTexto.Caption := FBusca + '_';
  for i := 0 to High(FLetras) do
  begin
    p := (FLetra + i - 6 + Length(NOVA_ALFABETO) * 3) mod Length(NOVA_ALFABETO) + 1;
    if NOVA_ALFABETO[p] = ' ' then FLetras[i].Caption := '␣' else FLetras[i].Caption := NOVA_ALFABETO[p];
    if (i = 6) and not FNaLista then
    begin
      FLetras[i].Color := clYellow;
      FLetras[i].Font.Color := clBlack;
    end
    else
    begin
      FLetras[i].Color := clTeal;
      FLetras[i].Font.Color := clWhite;
    end;
  end;
  if FSel < FTopo then FTopo := FSel;
  if FSel > FTopo + High(FLinhas) then FTopo := FSel - High(FLinhas);
  for i := 0 to High(FLinhas) do
  begin
    p := FTopo + i;
    if p < Length(FResultados) then
      FLinhas[i].Caption := FResultados[p].Texto
    else if (i = 0) and (Trim(FBusca) <> '') then
      FLinhas[i].Caption := 'Nada encontrado'
    else
      FLinhas[i].Caption := '';
    if FNaLista and (p = FSel) then
    begin
      FLinhas[i].Color := clYellow;
      FLinhas[i].Font.Color := clBlack;
    end
    else
    begin
      FLinhas[i].Color := clTeal;
      FLinhas[i].Font.Color := clWhite;
    end;
  end;
  if Length(FResultados) > 0 then
    FTitulo.Caption := 'PESQUISA  (' + IntToStr(Length(FResultados)) + ')'
  else
    FTitulo.Caption := 'PESQUISA';
end;

procedure TNovaPesquisa.Abre;
begin
  if FPainel = nil then Monta;
  FBusca := '';
  FLetra := 0;
  FNaLista := False;
  SetLength(FResultados, 0);
  FAberta := True;
  Mostra;
  FPainel.Show;
  FPainel.BringToFront;
  FTimer.Enabled := False;
  FTimer.Enabled := True;
  Gravalog('Pesquisa: aberta');
end;

procedure TNovaPesquisa.Fecha;
begin
  FAberta := False;
  if FPainel <> nil then FPainel.Hide;
  if FTimer <> nil then FTimer.Enabled := False;
end;

procedure TNovaPesquisa.Inativo(Sender: TObject);
begin
  Fecha;
end;

procedure TNovaPesquisa.VaiPara(const R: TNovaResultado);
var
  i: Integer;
begin
  Fecha;
  Gravalog('Pesquisa: ' + FBusca + ' -> ' + R.Texto);
  { como a paginação: o CD do centro é MAT[KMAT + 5] }
  KMAT := R.Cd - 5;
  if KMAT < -4 then KMAT := -4;
  Desselecionamusica;
  MUSICASELECIONADA := 0;
  MUSICASELECIONADAPOSTELA := 0;
  MUSICASELECIONADATS := 0;
  MOSTRANDORITMOS := 0;
  MOSTRANDOLETRAS := 0;
  MUDOUDECDOUMUSICA := 1;
  TEMPOPALHINHA := 0;
  Mostra_Cds(' ');
  Mostra_Nome_Das_Musicas;
  { a música: os mesmos passos da tecla Música, sem o bipe de cada um }
  for i := 1 to R.Musica do
    if MUSICASELECIONADA < MAT[KMAT + 5].TotalMusicas then
    begin
      Desselecionamusica;
      MUSICASELECIONADA := MUSICASELECIONADA + 1;
      MUSICASELECIONADAPOSTELA := MUSICASELECIONADAPOSTELA + 1;
      if 12 < MUSICASELECIONADAPOSTELA then MUSICASELECIONADAPOSTELA := 12;
      Selecionamusica;
    end;
end;

{ True = a tecla era da pesquisa (não vai para a jukebox) }
function TNovaPesquisa.Trata(Key: Word): Boolean;
var
  N: Integer;
begin
  Result := True;
  FTimer.Enabled := False;
  FTimer.Enabled := True;
  N := Length(NOVA_ALFABETO);
  if (Key = TECLACDMAIS) and not FNaLista then
    FLetra := (FLetra + 1) mod N
  else if (Key = TECLACDMENOS) and not FNaLista then
    FLetra := (FLetra + N - 1) mod N
  else if Key = TECLAMUSICAMENOS then
  begin
    if not FNaLista then
    begin
      if Length(FResultados) > 0 then
      begin
        FNaLista := True;
        FSel := 0;
      end;
    end
    else if FSel < High(FResultados) then
      Inc(FSel);
  end
  else if Key = TECLAMUSICAMAIS then
  begin
    if FNaLista then
    begin
      if FSel > 0 then Dec(FSel) else FNaLista := False;
    end;
  end
  else if (Key = TECLACDMAIS) or (Key = TECLACDMENOS) then
    FNaLista := False
  else if Key = TECLATOCAR then
  begin
    if FNaLista and (FSel < Length(FResultados)) then
    begin
      VaiPara(FResultados[FSel]);
      Exit;
    end;
    if Length(FBusca) < 30 then
      FBusca := FBusca + NOVA_ALFABETO[FLetra + 1];
    Busca;
  end
  else if Key = TECLACANCELAR then
  begin
    if FNaLista then
      FNaLista := False
    else if FBusca = '' then
    begin
      Fecha;
      Exit;
    end
    else
    begin
      Delete(FBusca, Length(FBusca), 1);
      Busca;
    end;
  end
  else
    Result := False;  // crédito, menu, volume...: a jukebox trata
  Mostra;
end;

procedure TNovaPesquisa.KeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if FAberta and ((Key = TECLACDMAIS) or (Key = TECLACDMENOS) or (Key = TECLAMUSICAMAIS) or
    (Key = TECLAMUSICAMENOS) or (Key = TECLATOCAR) or (Key = TECLACANCELAR)) then
  begin
    Key := 0;  // a jukebox não pagina nem anda nas músicas por baixo da pesquisa
    Exit;
  end;
  if Assigned(FOrigDown) then FOrigDown(Sender, Key, Shift);
end;

procedure TNovaPesquisa.KeyUp(Sender: TObject; var Key: Word; Shift: TShiftState);
var
  Agora: QWord;
begin
  if FAberta then
  begin
    if Trata(Key) then
    begin
      Key := 0;
      Exit;
    end;
  end
  else if (ESTANOMENU = 0) and (SENHAOK = 0) then
  begin
    if (FTeclaPesquisa > 0) and (Key = FTeclaPesquisa) then
    begin
      Abre;
      Key := 0;
      Exit;
    end;
    if Key = TECLACANCELAR then
    begin
      { Cancelar 3 vezes em 1,5 s abre a pesquisa (cada Cancelar faz também o que fazia) }
      Agora := GetTickCount64;
      FCancelas[0] := FCancelas[1];
      FCancelas[1] := FCancelas[2];
      FCancelas[2] := Agora;
      if (FCancelas[0] > 0) and (Agora - FCancelas[0] <= 1500) then
      begin
        FillChar(FCancelas, SizeOf(FCancelas), 0);
        if Assigned(FOrigUp) then FOrigUp(Sender, Key, Shift);
        Abre;
        Key := 0;
        Exit;
      end;
    end;
  end;
  if Assigned(FOrigUp) then FOrigUp(Sender, Key, Shift);
end;

procedure Nova_Inicia_Pesquisa;
var
  Texto: string;
  L: TStringList;
begin
  NovaPesquisa := TNovaPesquisa.Create;
  NovaPesquisa.FOrigDown := Form1.OnKeyDown;
  NovaPesquisa.FOrigUp := Form1.OnKeyUp;
  Form1.OnKeyDown := @NovaPesquisa.KeyDown;
  Form1.OnKeyUp := @NovaPesquisa.KeyUp;
  NovaPesquisa.FTeclaPesquisa := 0;
  if FileExists(PASTA + 'teclapesquisa.txt') then
  begin
    L := TStringList.Create;
    try
      L.LoadFromFile(PASTA + 'teclapesquisa.txt');
      if L.Count > 0 then
      begin
        Texto := Trim(L[0]);
        NovaPesquisa.FTeclaPesquisa := StrToIntDef(Texto, 0);
        if (NovaPesquisa.FTeclaPesquisa = 0) and (Length(Texto) = 1) then
          NovaPesquisa.FTeclaPesquisa := Ord(UpCase(Texto[1]));
      end;
    finally
      L.Free;
    end;
  end;
end;

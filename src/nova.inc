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

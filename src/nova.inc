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
      Gravalog('Serial da chave: nao achei o jukelinux.ini; a maquina precisa de licenca nova');
      Exit;
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
  i, Antes: LongInt;
begin
  { Um Pix de R$ N vale N pulsos de R$ 1 do noteiro: a própria Rotina_Creditos soma os créditos, grava o
    creditos.txt e os relógios e aplica o bônus de cédula do modo REAISXMUSICAS, como faria com dinheiro. }
  Antes := CREDITOS;
  for i := 1 to Reais do
    Rotina_Creditos('Normal');
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
  Erro, Pasta: string;
begin
  Pasta := PASTA;
  if Pasta = '' then
    Pasta := PASTA_JUKELINUX;
  if not FileExists(Pasta + 'pix.txt') then
    Exit;
  if not LeConfigPix(Pasta + 'pix.txt', Config, Erro) then
  begin
    Gravalog('Pix desligado: ' + Erro);
    Exit;
  end;
  if not Config.Ativo then
    Exit;
  NovaPix := TNovaPix.Create;
  TTelaPix.Cria(Form1, Config, Pasta, @NovaPix.Creditar, @NovaPix.Registrar);
end;

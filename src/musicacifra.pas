unit MusicaCifra;

{ Músicas cifradas da JukeLinux (rotina própria da Nova, no lugar da Descriptografa da original, que usava arquivos
  binários e um timer que o tradutor não acompanha). Mesmo formato das máquinas atuais, deduzido da original:

    10 caracteres   tamanho N do bloco de informação, em texto (com espaços)
    30 caracteres   nome da gravadora, cifrado com a Cripta (cada letra + posição + 17)
    N bytes         bloco de informação (a original copia para um .INF e apaga; aqui é pulado)
    o resto         a música, em blocos de 2048 bytes: byte i do bloco (i = 1..2048) = original + i + chave

  A chave é a do chavecriptografica.txt (a original cria com 71). Chave 0 = músicas sem cifra (só copia).
  Novidade da Nova: um arquivo sem o cabeçalho (música comum) é copiado mesmo com chave, em vez de não tocar.

  Sem LCL: usada pela jukebox, pelos testes e pela ferramenta de cifrar. }

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils;

const
  CIFRA_TAM_BLOCO = 2048;
  CIFRA_TAM_CABECALHO = 10;
  CIFRA_TAM_GRAVADORA = 30;

{ Gera em Destino a música tocável. Devolve False (e o motivo em Erro) se não conseguir. }
function DecifraMusica(const Origem, Destino: string; Chave: Integer; out Gravadora, Erro: string): Boolean;

{ Cifra no formato da original (para carregar músicas e para os testes). }
function CifraMusica(const Origem, Destino: string; Chave: Integer; const Gravadora: string;
  out Erro: string): Boolean;

{ True se o arquivo começa com o cabeçalho das músicas cifradas. }
function MusicaEstaCifrada(const Arquivo: string): Boolean;

implementation

procedure Decifra(var Buffer: array of Byte; Quantos: Integer; Chave: Integer);
var
  i: Integer;
begin
  for i := 0 to Quantos - 1 do
    Buffer[i] := Byte(Buffer[i] - (i + 1) - Chave);
end;

procedure Cifra(var Buffer: array of Byte; Quantos: Integer; Chave: Integer);
var
  i: Integer;
begin
  for i := 0 to Quantos - 1 do
    Buffer[i] := Byte(Buffer[i] + (i + 1) + Chave);
end;

{ Tamanho do bloco de informação lido do cabeçalho; 0 se não for um cabeçalho válido. }
function LeCabecalho(Fluxo: TStream): Integer;
var
  Bytes: array[0..CIFRA_TAM_CABECALHO - 1] of Byte;
  Texto: string;
  i: Integer;
begin
  Result := 0;
  FillChar(Bytes, SizeOf(Bytes), 0);
  if Fluxo.Read(Bytes, SizeOf(Bytes)) <> SizeOf(Bytes) then
    Exit;
  Texto := '';
  for i := 0 to High(Bytes) do
  begin
    if Bytes[i] = 0 then
      Break;  // como o fpc_chararray_to_ansistr da original
    if not (Chr(Bytes[i]) in ['0'..'9', ' ']) then
      Exit;
    Texto := Texto + Chr(Bytes[i]);
  end;
  Result := StrToIntDef(Trim(Texto), 0);
  if Result < 0 then
    Result := 0;
end;

function MusicaEstaCifrada(const Arquivo: string): Boolean;
var
  Fluxo: TFileStream;
begin
  Result := False;
  if not FileExists(Arquivo) then
    Exit;
  try
    Fluxo := TFileStream.Create(Arquivo, fmOpenRead or fmShareDenyNone);
    try
      Result := LeCabecalho(Fluxo) > 0;
    finally
      Fluxo.Free;
    end;
  except
    Result := False;
  end;
end;

function CopiaArquivo(Origem, Destino: TStream): Boolean;
begin
  Origem.Position := 0;
  Destino.CopyFrom(Origem, 0);
  Result := True;
end;

function DecifraMusica(const Origem, Destino: string; Chave: Integer; out Gravadora, Erro: string): Boolean;
var
  Entrada, Saida: TFileStream;
  Buffer: array[0..CIFRA_TAM_BLOCO - 1] of Byte;
  Bytes: array[0..CIFRA_TAM_GRAVADORA - 1] of Byte;
  TamInfo, Lidos, i: Integer;
begin
  Result := False;
  Gravadora := '';
  Erro := '';
  if not FileExists(Origem) then
  begin
    Erro := 'música não encontrada: ' + Origem;
    Exit;
  end;
  try
    Entrada := TFileStream.Create(Origem, fmOpenRead or fmShareDenyNone);
    try
      Saida := TFileStream.Create(Destino, fmCreate);
      try
        TamInfo := 0;
        if Chave <> 0 then
          TamInfo := LeCabecalho(Entrada);
        if TamInfo <= 0 then
          { chave 0, ou música comum sem o cabeçalho: toca como está }
          Result := CopiaArquivo(Entrada, Saida)
        else
        begin
          FillChar(Bytes, SizeOf(Bytes), 0);
          Entrada.Read(Bytes, SizeOf(Bytes));
          for i := 0 to High(Bytes) do
            if Bytes[i] <> 0 then
              Gravadora := Gravadora + Chr(Byte(Bytes[i] - (i + 1) - 17));  // a Descripta da original
          Gravadora := Trim(Gravadora);
          Entrada.Seek(TamInfo, soCurrent);  // bloco de informação
          FillChar(Buffer, SizeOf(Buffer), 0);
          repeat
            Lidos := Entrada.Read(Buffer, SizeOf(Buffer));
            if Lidos > 0 then
            begin
              Decifra(Buffer, Lidos, Chave);
              Saida.WriteBuffer(Buffer, Lidos);
            end;
          until Lidos < SizeOf(Buffer);
          Result := True;
        end;
      finally
        Saida.Free;
      end;
    finally
      Entrada.Free;
    end;
  except
    on E: Exception do
    begin
      Erro := E.Message;
      Result := False;
    end;
  end;
end;

function CifraMusica(const Origem, Destino: string; Chave: Integer; const Gravadora: string;
  out Erro: string): Boolean;
const
  INFO = 'JukeLinux Nova';
var
  Entrada, Saida: TFileStream;
  Buffer: array[0..CIFRA_TAM_BLOCO - 1] of Byte;
  Cabecalho, Nome: string;
  Bytes: array[0..CIFRA_TAM_GRAVADORA - 1] of Byte;
  Lidos, i: Integer;
begin
  Result := False;
  Erro := '';
  if Chave = 0 then
  begin
    Erro := 'chave 0 quer dizer sem cifra';
    Exit;
  end;
  try
    Entrada := TFileStream.Create(Origem, fmOpenRead or fmShareDenyNone);
    try
      Saida := TFileStream.Create(Destino, fmCreate);
      try
        Cabecalho := IntToStr(Length(INFO));
        while Length(Cabecalho) < CIFRA_TAM_CABECALHO do
          Cabecalho := Cabecalho + ' ';
        Saida.WriteBuffer(Cabecalho[1], CIFRA_TAM_CABECALHO);
        Nome := Copy(Gravadora, 1, CIFRA_TAM_GRAVADORA);
        while Length(Nome) < CIFRA_TAM_GRAVADORA do
          Nome := Nome + ' ';
        for i := 0 to High(Bytes) do
          Bytes[i] := Byte(Ord(Nome[i + 1]) + (i + 1) + 17);  // a Cripta da original
        Saida.WriteBuffer(Bytes, SizeOf(Bytes));
        Saida.WriteBuffer(INFO[1], Length(INFO));
        FillChar(Buffer, SizeOf(Buffer), 0);
        repeat
          Lidos := Entrada.Read(Buffer, SizeOf(Buffer));
          if Lidos > 0 then
          begin
            Cifra(Buffer, Lidos, Chave);
            Saida.WriteBuffer(Buffer, Lidos);
          end;
        until Lidos < SizeOf(Buffer);
        Result := True;
      finally
        Saida.Free;
      end;
    finally
      Entrada.Free;
    end;
  except
    on E: Exception do
      Erro := E.Message;
  end;
end;

end.

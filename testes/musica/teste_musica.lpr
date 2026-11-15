program teste_musica;

{ Testa src/musicacifra.pas. Rodar por rodar.sh (que gera os arquivos com o codificador independente em Python). }

{$mode objfpc}{$H+}

uses
  Classes, SysUtils, MusicaCifra;

var
  Pasta: string;
  Falhas: Integer = 0;

procedure Confere(Ok: Boolean; const Nome: string);
begin
  if Ok then WriteLn('OK    ', Nome) else begin WriteLn('FALHA ', Nome); Inc(Falhas); end;
end;

function Iguais(const A, B: string): Boolean;
var
  FA, FB: TMemoryStream;
begin
  FA := TMemoryStream.Create; FB := TMemoryStream.Create;
  try
    FA.LoadFromFile(A); FB.LoadFromFile(B);
    Result := (FA.Size = FB.Size) and CompareMem(FA.Memory, FB.Memory, FA.Size);
  finally
    FA.Free; FB.Free;
  end;
end;

var
  Gravadora, Erro: string;
  Ok: Boolean;
begin
  Pasta := IncludeTrailingPathDelimiter(ParamStr(1));

  Ok := DecifraMusica(Pasta + 'py71.cif', Pasta + 'saida1.bin', 71, Gravadora, Erro);
  Confere(Ok and Iguais(Pasta + 'musica.bin', Pasta + 'saida1.bin'), 'decifra o formato da original (chave 71) ' + Erro);
  Confere(Gravadora = 'SOM LIVRE', 'gravadora do cabeçalho: [' + Gravadora + ']');

  Ok := DecifraMusica(Pasta + 'py200.cif', Pasta + 'saida2.bin', 200, Gravadora, Erro);
  Confere(Ok and Iguais(Pasta + 'musica.bin', Pasta + 'saida2.bin'), 'outra chave (200) e bloco de informação grande');

  Ok := DecifraMusica(Pasta + 'py_exato.cif', Pasta + 'saida3.bin', 71, Gravadora, Erro);
  Confere(Ok and Iguais(Pasta + 'exato.bin', Pasta + 'saida3.bin'), 'música com tamanho múltiplo de 2048');

  Ok := DecifraMusica(Pasta + 'musica.bin', Pasta + 'saida4.bin', 71, Gravadora, Erro);
  Confere(Ok and Iguais(Pasta + 'musica.bin', Pasta + 'saida4.bin'), 'música sem cifra com chave 71: copia (novidade)');

  Ok := DecifraMusica(Pasta + 'py71.cif', Pasta + 'saida5.bin', 0, Gravadora, Erro);
  Confere(Ok and Iguais(Pasta + 'py71.cif', Pasta + 'saida5.bin'), 'chave 0: copia como está (como a original)');

  Confere(MusicaEstaCifrada(Pasta + 'py71.cif') and not MusicaEstaCifrada(Pasta + 'musica.bin'),
    'reconhece arquivo cifrado e comum');

  Ok := CifraMusica(Pasta + 'musica.bin', Pasta + 'nova.cif', 71, 'GRAVADORA NOVA', Erro)
    and DecifraMusica(Pasta + 'nova.cif', Pasta + 'saida6.bin', 71, Gravadora, Erro);
  Confere(Ok and Iguais(Pasta + 'musica.bin', Pasta + 'saida6.bin') and (Gravadora = 'GRAVADORA NOVA'),
    'cifra e decifra de volta (Nova)');

  Ok := DecifraMusica(Pasta + 'vazio.bin', Pasta + 'saida7.bin', 71, Gravadora, Erro);
  Confere(Ok and FileExists(Pasta + 'saida7.bin'), 'arquivo vazio não quebra');

  Ok := DecifraMusica(Pasta + 'nao-existe.mp3', Pasta + 'saida8.bin', 71, Gravadora, Erro);
  Confere(not Ok and (Pos('não encontrada', Erro) > 0), 'música que não existe: ' + Erro);

  WriteLn; WriteLn('Falhas: ', Falhas);
  if Falhas > 0 then Halt(1);
end.

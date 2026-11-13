program teste_pix;

{ Testa pix.pas e o QR Code de pixtela.pas contra o PSP simulado (psp_falso.py). Rodar por rodar.sh.
  Parâmetro: a pasta com pix.txt e certs/ (cliente.pem, cliente.key, ca.pem, outra-ca.pem). }

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}cthreads,{$ENDIF}
  Interfaces, Classes, SysUtils, Graphics, Process, Pix, PixTela;

var
  Pasta: string;
  Falhas: Integer = 0;

procedure Confere(Ok: Boolean; const Nome: string);
begin
  if Ok then
    WriteLn('OK    ', Nome)
  else
  begin
    WriteLn('FALHA ', Nome);
    Inc(Falhas);
  end;
end;

{ Marca a cobrança como paga no PSP simulado. }
procedure Paga(const Url, Txid: string);
var
  Saida: string;
begin
  RunCommand('curl', ['-s', '--cacert', Pasta + 'certs/ca.pem', '--cert', Pasta + 'certs/cliente.pem',
    '--key', Pasta + 'certs/cliente.key', Url + '/_pagar/' + Txid], Saida);
end;

var
  Cfg, Cfg2: TPixConfig;
  Erro, Tx1, Tx2, Codigo, Lido, Base: string;
  C, C2: TPixCliente;
  St: TPixStatus;
  Ok: Boolean;
  B: TBitmap;
  Linhas: TStringList;
begin
  Pasta := IncludeTrailingPathDelimiter(ParamStr(1));

  Ok := LeConfigPix(Pasta + 'pix.txt', Cfg, Erro);
  Confere(Ok, 'lê pix.txt ' + Erro);
  Confere(Copy(Cfg.UrlApi, Length(Cfg.UrlApi), 1) <> '/', 'tira a barra final de url_api');
  Confere((Length(Cfg.Valores) = 3) and (Cfg.Valores[0] = 2) and (Cfg.Valores[1] = 5) and (Cfg.Valores[2] = 10),
    'valores 2, 5 e 10');
  Confere(Cfg.ClientSecret = 'segredo "com" aspas\', 'segredo com aspas e barra lido inteiro');
  Confere((Cfg.BotaoX = 10) and (Cfg.BotaoY = 20) and (Cfg.BotaoLargura = 130) and (Cfg.BotaoAltura = 70),
    'posição do botão');
  Base := Copy(Cfg.UrlApi, 1, Pos('/api/', Cfg.UrlApi) - 1);

  Tx1 := NovoTxid;
  Tx2 := NovoTxid;
  Confere((Length(Tx1) = 32) and (Tx1 <> Tx2), 'txid de 32 caracteres, diferente a cada vez');

  C := TPixCliente.Create(Cfg);
  Ok := C.CriaCobranca(Tx1, 5, Codigo);
  Confere(Ok, 'cria cobrança de R$ 5 ' + C.UltimoErro);
  Confere(Pos(Tx1, Codigo) > 0, 'devolve o pixCopiaECola');
  Ok := C.Consulta(Tx1, St) and (St = psAtiva);
  Confere(Ok, 'consulta: ATIVA');
  Paga(Base, Tx1);
  Ok := C.Consulta(Tx1, St) and (St = psConcluida);
  Confere(Ok, 'consulta depois de pago: CONCLUIDA');
  Ok := not C.Cancela(Tx1);
  Confere(Ok, 'não cancela cobrança já paga -> ' + C.UltimoErro);
  Ok := C.CriaCobranca(Tx2, 2, Codigo);
  Confere(Ok, 'cria a segunda cobrança');
  Ok := C.Cancela(Tx2);
  Confere(Ok, 'cancela cobrança ativa ' + C.UltimoErro);
  Ok := C.Consulta(Tx2, St) and (St = psRemovida);
  Confere(Ok, 'consulta depois de cancelar: REMOVIDA');
  Ok := not C.CriaCobranca('curto', 2, Codigo);
  Confere(Ok, 'PSP recusa txid inválido -> ' + C.UltimoErro);

  Cfg2 := Cfg;
  Cfg2.ClientSecret := 'errado';
  C2 := TPixCliente.Create(Cfg2);
  Ok := not C2.CriaCobranca(NovoTxid, 2, Codigo) and (Pos('token recusado', C2.UltimoErro) > 0);
  Confere(Ok, 'segredo errado -> ' + C2.UltimoErro);
  C2.Free;

  Cfg2 := Cfg;
  Cfg2.CertificadoCA := Pasta + 'certs/outra-ca.pem';
  C2 := TPixCliente.Create(Cfg2);
  Ok := not C2.CriaCobranca(NovoTxid, 2, Codigo) and (Pos('curl (código 60)', C2.UltimoErro) = 1);
  Confere(Ok, 'servidor que não é o PSP (outra CA) é recusado -> ' + Copy(C2.UltimoErro, 1, 90));
  C2.Free;

  Cfg2 := Cfg;
  Cfg2.Certificado := '';
  Cfg2.ChavePrivada := '';
  C2 := TPixCliente.Create(Cfg2);
  Ok := not C2.CriaCobranca(NovoTxid, 2, Codigo);
  Confere(Ok, 'sem certificado de cliente o PSP recusa -> ' + Copy(C2.UltimoErro, 1, 90));
  C2.Free;

  Cfg2 := Cfg;
  Cfg2.Curl := '/nao/existe/curl';
  C2 := TPixCliente.Create(Cfg2);
  Ok := not C2.CriaCobranca(NovoTxid, 2, Codigo);
  Confere(Ok, 'sem curl -> ' + C2.UltimoErro);
  C2.Free;

  Linhas := TStringList.Create;
  try
    Linhas.Add('url_api=https://x');
    Linhas.Add('url_token=https://x/t');
    Linhas.Add('client_id=a');
    Linhas.Add('client_secret=b');
    Linhas.Add('valores=5');
    Linhas.SaveToFile(Pasta + 'incompleto.txt');
  finally
    Linhas.Free;
  end;
  Ok := not LeConfigPix(Pasta + 'incompleto.txt', Cfg2, Erro) and (Erro = 'falta chave');
  Confere(Ok, 'pix.txt sem chave é recusado: ' + Erro);

  { O QR Code desenhado tem de ser lido de volta igual ao pixCopiaECola. }
  Ok := C.CriaCobranca(NovoTxid, 10, Codigo);
  B := TBitmap.Create;
  try
    DesenhaQrCode(Codigo, B, 400);
    B.SaveToFile(Pasta + 'qr.bmp');
  finally
    B.Free;
  end;
  Lido := '';
  RunCommand('zbarimg', ['-q', '--raw', Pasta + 'qr.bmp'], Lido);
  Confere(Ok and (Trim(Lido) = Codigo), 'QR Code lido pelo zbarimg = pixCopiaECola');
  C.Free;

  WriteLn;
  WriteLn('Falhas: ', Falhas);
  if Falhas > 0 then
    Halt(1);
end.

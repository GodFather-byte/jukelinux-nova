program teste_nuvem;

{ Testa src/nuvem.pas contra a nuvem rodando de verdade (rodar.sh sobe a nuvem e libera a máquina pelo painel).
    teste_nuvem offline PASTA      eventos sem internet ficam na fila
    teste_nuvem pendente PASTA     com a nuvem: tudo é entregue e a máquina fica aguardando liberação
    teste_nuvem liberada PASTA     depois de liberar no painel: a licença chega e é instalada
    teste_nuvem bloqueada PASTA    depois de bloquear no painel: o bloqueio chega }

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}cthreads,{$ENDIF}
  Classes, SysUtils, DateUtils, Nuvem, Licenca;

type
  TReceptor = class
    Recebida: string;
    Estado: TEstadoLicenca;
    Instalou: Boolean;
    Pasta: string;
    procedure Licenca(const Texto: string);
    procedure Log(const Texto: string);
  end;

procedure TReceptor.Licenca(const Texto: string);
begin
  Recebida := Texto;
  Estado := InstalaLicenca(Pasta, Texto, Now, Instalou);
end;

procedure TReceptor.Log(const Texto: string);
begin
  WriteLn('  log: ', Texto);
end;

var
  Falhas: Integer = 0;
  Avanco: Integer = 0;

procedure Confere(Ok: Boolean; const Nome: string);
begin
  if Ok then WriteLn('OK    ', Nome) else begin WriteLn('FALHA ', Nome); Inc(Falhas); end;
end;

{ Um contato completo: começa, espera e trata a resposta. }
procedure Contato(N: TNuvem);
var
  R: TRelogioNuvem;
  Agora: TDateTime;
begin
  R := Default(TRelogioNuvem);
  R.Total := 500; R.Parcial := 120; R.PixParcial := 20; R.PixTotal := 20; R.PontoPct := 30; R.Creditos := 3;
  Inc(Avanco);
  Agora := Now + Avanco;  // cada contato um dia depois: sempre "na hora" do próximo
  N.Tick(R, Agora);  // começa
  N.Espera;
  N.Tick(R, Agora);  // trata a resposta
end;

var
  Fase, Pasta, Codigo: string;
  N: TNuvem;
  Rec: TReceptor;
  i: Integer;
begin
  Fase := ParamStr(1);
  Pasta := IncludeTrailingPathDelimiter(ParamStr(2));
  Codigo := CodigoDaMaquina(IdentidadeDaMaquina);
  Rec := TReceptor.Create;
  Rec.Pasta := Pasta;
  N := TNuvem.Create(Pasta, Codigo, 'teste');
  N.OnLicenca := @Rec.Licenca;
  N.OnRegistro := @Rec.Log;
  try
    if Fase = 'offline' then
    begin
      Confere(N.Ligada, 'nuvem.txt lido: ' + N.Url);
      N.Ligou(Now);
      for i := 1 to 10 do
        N.Pulso(Now);                // uma nota de R$ 10 = 10 pulsos seguidos
      N.Credito('pix', 20, 20, Now); // junta os pulsos antes
      N.Musica('ROBERTO CARLOS - EMOCOES', '01 - EMOCOES', Now);
      N.Musica('ALCEU VALENCA - "AO VIVO"', '01 - ANUNCIAÇÃO', Now);
      Confere(N.TamanhoDaFila = 5, 'cinco eventos na fila (a nota de R$ 10 vira um só): ' + IntToStr(N.TamanhoDaFila));
      Contato(N);
      Confere(N.Situacao = snSemContato, 'sem internet: ' + N.DescreveSituacao);
      Confere(N.TamanhoDaFila = 5, 'sem internet a fila fica inteira');
      Confere(FileExists(Pasta + ARQ_NUVEM_SEGREDO), 'segredo da máquina criado');
    end
    else if Fase = 'pendente' then
    begin
      Contato(N);
      Confere(N.Situacao = snPendente, 'máquina nova fica aguardando a licença: ' + N.DescreveSituacao);
      Confere(N.TamanhoDaFila = 0, 'a nuvem confirmou e a fila esvaziou');
      Confere(Rec.Recebida = '', 'pendente não recebe licença');
      N.Fechamento(120, 20, 36, Now);
      Contato(N);
      Confere(N.TamanhoDaFila = 0, 'fechamento entregue');
    end
    else if Fase = 'liberada' then
    begin
      Contato(N);
      Confere(N.Situacao = snAtiva, 'licença enviada pelo painel: ' + N.DescreveSituacao);
      Confere(Rec.Instalou and (Rec.Estado = elValida), 'licença chegou e foi instalada: ' + DescreveEstado(Rec.Estado));
      Confere(LeLicenca(Pasta, Now).Estado = elValida, 'licenca.txt vale');
      Sleep(1100);  // outro segundo: a nuvem manda a mesma licença enquanto nada muda
      Contato(N);
      Confere(not Rec.Instalou, 'a mesma licença de novo não regrava (só muda quando a nuvem emite outra)');
    end
    else if Fase = 'bloqueada' then
    begin
      Sleep(1100);  // a licença de bloqueio é emitida num segundo depois da anterior
      Contato(N);
      Confere(N.Situacao = snBloqueada, 'licença de bloqueio enviada pelo painel: ' + N.DescreveSituacao);
      Confere(LeLicenca(Pasta, Now).Estado = elBloqueada, 'licenca.txt agora diz bloqueada');
    end
    else if Fase = 'intruso' then
    begin
      Contato(N);
      Confere(N.Situacao = snRecusada, 'outro aparelho com o mesmo código é recusado: ' + N.DescreveSituacao);
    end
    else
      WriteLn('fase desconhecida: ', Fase);
  finally
    N.Free;
    Rec.Free;
  end;
  if Falhas > 0 then Halt(1);
end.

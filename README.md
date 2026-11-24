# JukeLinux Nova

Recriação fiel da **JukeLinux** (jukebox de bar, versão de 19/01/2018) em **Lazarus/Free Pascal**, feita com
autorização do desenvolvedor da original.

- **Mesma tela e mesmo comportamento:** o layout parte do formulário extraído do programa original
  (`referencia/telas/Form1.lfm`) e cada rotina reimplementa a de mesmo nome da original
  (`referencia/funcoes.txt`, 266 funções da unit `jukelinux1.pas`).
- **Troca direta:** usa os mesmos arquivos das máquinas atuais (`/home/jkb/jukelinux`, as configurações `.txt`,
  `/home/jkb/musicas` com `ARTISTA - CD`, `genero.txt` e `capa.jpg`, `tocados.txt`, relógios).
- **Licença feita pelo gerador de licenças da empresa** (só no computador dela) no lugar da trava do pendrive-chave
  da original, entregue pela **nuvem**, que tem o **painel das máquinas, dinheiro e relatórios** (`nuvem/`), ou
  por pendrive. A jukebox não depende da internet para funcionar.
- 64 bits, GTK2, roda no Linux Mint 22.

## Compilar

```bash
sudo apt install lazarus-ide lcl-gtk2 lcl-units fpc
lazbuild --widgetset=gtk2 jukelinux.lpi
```

A CI (GitHub Actions → **Build**) roda os testes, compila a cada push e publica o executável em *Artifacts*. O
executável confere as licenças com a chave pública de `src/licenca_publica.inc`, que fica no git (ela só confere, não
emite). Enquanto ela for a de desenvolvimento, o CI avisa e o executável não serve para as máquinas: crie a chave no
gerador de licenças (ver "Licença e nuvem") e troque `src/licenca_publica.inc` pelo arquivo que ele baixa.

O modo **Teste** (`lazbuild --build-mode=Teste jukelinux.lpi`) gera `jukelinux-teste`, que usa a chave de
desenvolvimento. É o executável dos testes de integração; não vai para as máquinas.

## Instalar numa máquina

O CI publica o pacote **jukelinux-nova-linux-x86_64** (em *Actions → Build → Artifacts*): o executável, o instalador
e o exemplo do Pix. Na máquina:

```bash
sudo sh instalar.sh --nuvem https://nuvem.suaempresa.com.br  # instala e liga a jukebox à nuvem da empresa
sudo sh instalar.sh --iniciar-sozinha  # idem, e a jukebox abre sozinha ao entrar no Linux (dá para juntar com --nuvem)
sudo sh instalar.sh --desfazer         # volta o executável anterior
```

Funciona no Linux Mint 21/22 e Ubuntu 22.04/24.04 (o executável pede glibc 2.34+; o pacote do GTK2 tem nome novo no
24.04 e o instalador escolhe o certo). Numa máquina nova, sem a JukeLinux antiga, o instalador:
- usa o usuário `jkb` ou, se não houver, quem rodou o `sudo`;
- cria `iniciar-jukebox.sh`, que deixa a tela sem apagar nem bloquear e não abre duas jukeboxes;
- põe a jukebox para abrir sozinha ao entrar no Linux (falta só ligar o login automático do usuário).

O pacote traz um `LEIA-ME.txt` com o passo a passo.

A Nova fica em `/home/jkb/jukelinux/jukelinux`, mesmo caminho e nome da antiga: o que já inicia a jukebox continua
iniciando, e músicas, configurações, relógios e créditos ficam como estão. Na primeira vez aparece a tela de ativação.

## Máquina nova

Numa máquina que nunca teve a JukeLinux, a Nova cria o que falta na primeira abertura:

- **Configurações:** todos os `.txt` com os valores padrão da original (créditos, relógios, teclado, paginação...).
  A original já fazia isso; o que impedia era o `inicio.sh`.
- **`inicio.sh`:** a original o executava para listar os discos e achar o pendrive-chave, e sem ele a abertura parava
  pela metade. A Nova o cria; a licença substitui o pendrive, e a abertura não espera mais por ele (eram 5 s).
- **Imagens:** uma imagem que falte (ritmo, letra, capa, propaganda) não para a tela. Aparece o nome no lugar, por
  exemplo o nome do ritmo, e o log registra uma vez o arquivo que falta.

O instalador cria as pastas `/home/jkb/musicas`, `ritmos/` e `letras/`. O que vem de cada bar:

| O quê | Onde | Formato |
|---|---|---|
| CD/DVD | `/home/jkb/musicas/ARTISTA - CD/` | as músicas (`01 - NOME.mp3`, `.mp4` para DVD), `genero.txt` (ritmo, ex. `MP - MPB`), `capapequena.jpg` e outra `.jpg` como capa |
| Lançamento | `qualquer.atu` na pasta do CD | linha 1: dias que fica como lançamento; linha 2: data (`dd/mm/aaaa`, também com `-` ou `.`) |
| Imagem do ritmo/letra | `ritmos/`, `letras/` + `ritmosxjgps.txt`, `letrasxjgps.txt` | nos `.txt`, pares de linhas: nome do ritmo, arquivo `.jpg` |
| Cartões | `*.CAR` na pasta da jukebox | arquivo de registros de 94 bytes (String[93]); o 0 é cabeçalho, os outros são códigos cifrados |
| Créditos dos cartões | `cartoes.ccc` (criado sozinho) | registros de 38 bytes: código, créditos e situação, cifrados; o 0 é a data de criação |

## Licença e nuvem

As licenças são feitas pelo **gerador de licenças**, `ferramentas/licenca/gerador-de-licencas.html`. Ele fica **só no
computador da empresa**: abre no navegador (Chrome, Edge ou Firefox), funciona sem internet e não precisa instalar
nada. Só quem tem a chave dele cria licença; nem a nuvem tem essa chave. A **nuvem** (`nuvem/`) entrega a licença às
máquinas e tem o painel, o dinheiro e os relatórios ([nuvem/LEIA-ME.md](nuvem/LEIA-ME.md)).

**Uma vez só, no gerador:**
1. **Criar chave nova.** O navegador guarda a chave e baixa uma cópia (`chave-privada-licencas.json`). Guarde a cópia
   num pendrive: sem ela não dá para gerar licenças para as jukeboxes já instaladas.
2. **Baixar licenca_publica.inc** e trocar o `src/licenca_publica.inc` do repositório por ele. No GitHub: *Add file
   → Upload files*, na pasta `src`. O CI passa a gerar o executável com a sua chave.
3. Pôr a chave pública que o gerador mostra em `LICENCA_CHAVE_PUBLICA` na nuvem. Ela não é segredo: serve para a
   nuvem recusar licença que não seja sua.

**Para cada máquina:**
- **Código da máquina:** são 16 dígitos tirados do número de série do disco do sistema. Uma imagem clonada em outro HD
  tem outro código. Ele aparece na tela de ativação e no painel.
- **Ativação:** sem licença válida, a jukebox abre em **Ativação da Jukebox**, mostra o código e não responde às
  teclas.
  - No gerador: digite o código, escolha **Liberar**, permanente ou até uma data, e clique em **Gerar licença**.
  - Com internet: no painel, **Enviar licença**, cole e envie. Em até um minuto a jukebox recebe e libera sozinha, com
    o "Ativação OK" da original.
  - Sem internet: grave o `licenca.txt` na raiz de um pendrive. A jukebox procura nos pendrives e instala sozinha.
- **Bloquear:** gere no gerador uma licença de **Bloquear** e envie do mesmo jeito. A máquina trava no próximo
  contato, ou quando o pendrive for colocado.
- **Licença assinada:** o `licenca.txt` é um texto assinado com Ed25519 (código, situação, validade, data de
  emissão). A jukebox confere com a chave pública embutida (`src/licenca_publica.inc`), pela libcrypto do sistema,
  sem internet. Mexer no arquivo invalida a assinatura, e o código-fonte aberto não ajuda a falsificar.
  - Uma licença só é trocada por outra mais nova.
  - O `licenca-dia.txt` guarda o último dia visto, então atrasar o relógio não estende a validade.
- **Sem internet a jukebox funciona normalmente.** O que acontece vai para `nuvem-fila.txt` e é mandado quando a
  internet volta: dinheiro do noteiro (pulsos juntados por nota), Pix, música pedida, fechamento do relógio e
  "ligou". Cada evento tem um id, então nada conta duas vezes. A cada contato vão também os relógios.
- **Segredo do aparelho:** no primeiro uso a jukebox sorteia `nuvem-segredo.txt`. A nuvem amarra o código a ele e
  recusa outro aparelho com o mesmo código. Para uma jukebox reinstalada, use "Esquecer o aparelho" no painel.

Testes:
- `testes/licenca/rodar.sh`: licença, com licenças feitas pelo próprio núcleo do gerador.
- `testes/nuvem/rodar.sh`: jukebox × nuvem de verdade.
- `cd nuvem && npm test`: nuvem.

Máquina antiga trocada pela Nova continua com o serial da chave antiga (lido dos arquivos dela); máquina nova recebe um
serial tirado do código da máquina.

## Músicas

A Nova toca as músicas cifradas das máquinas atuais (mesmo formato: chave do `chavecriptografica.txt`, 71 por padrão;
0 = sem cifra) com uma rotina própria, `src/musicacifra.pas`. Novidade: uma música comum, sem cifra, toca mesmo numa
máquina com chave. Testes contra um codificador independente do formato: `testes/musica/rodar.sh`.

## Pix

A Nova aceita Pix (a original não tinha). Com `pix.txt` na pasta da jukebox, aparece um botão **PIX** na tela
principal: o cliente escolhe o valor, aponta o celular para o QR Code e, quando o banco confirma, os créditos entram
como se fosse uma cédula no noteiro (`Rotina_Creditos('Normal')` uma vez por real, com a mesma regra de reais x
músicas, relógios e `creditos.txt`).

- Usa a **API Pix padrão do Banco Central** (cobrança imediata `/cob`, OAuth2 e certificado de cliente), a mesma em
  todos os PSPs que a oferecem. É preciso conta num PSP com essa API (em geral PJ); não achei API pública de
  cobrança no Nubank (vale confirmar com o banco). Modelo e explicação de cada campo: `instalacao/pix.txt.exemplo`.
- As chamadas HTTPS vão pelo `curl` (que confere o certificado e o nome do servidor do PSP).
- O botão some quando a original mostra bloqueio, menu, erro ou ativação.
- Cobranças em aberto ficam em `pix-pendentes.txt`; um pagamento feito com a tela fechada, durante uma queda de
  rede ou com a máquina reiniciando ainda vira crédito. As pagas ficam em `pix-creditados.txt` e nunca são
  creditadas duas vezes. Tudo vai para o `log.txt` com o prefixo `Pix:`.
- Teste contra um PSP simulado (HTTPS com certificado de cliente): `testes/pix/rodar.sh`.

## Pesquisa pelas teclas da jukebox

Apertar **Cancelar 3 vezes seguidas** (em 1,5 s) abre a tela de pesquisa. Se houver um botão sobrando, o código da
tecla dele (ou a letra) pode ir em `teclapesquisa.txt` para abrir direto. Na pesquisa:

- **CD+ / CD-** escolhem a letra;
- **Tocar** põe a letra;
- **Música+ / Música-** andam pelos resultados;
- **Cancelar** apaga a última letra e, sem letras, fecha.

A busca não liga para acentos e procura no nome do CD e no das músicas. Tocar num resultado leva ao CD, como se
tivesse paginado até ele, com a música já selecionada: outro Tocar a põe na fila, cobrando créditos como sempre.
As teclas de crédito e de menu continuam funcionando com a pesquisa aberta, e ela fecha sozinha depois de um minuto
sem uso.

## Pix no relógio

O relógio parcial soma dinheiro e Pix (um Pix de R$ N vale N pulsos), mas o Pix cai na conta do dono. O menu
**Relógios** mostra, abaixo do Valor do Ponto:

- o Pix do período;
- o dinheiro no noteiro;
- o acerto: a casa tira a parte dela (o Valor do Ponto) do noteiro e, se não der, o dono paga a diferença.

`pixrelogio.txt` guarda os valores cifrados. Ao zerar o relógio parcial, o Pix do período vai para
`pixfechamentos.txt`.

## Baixar músicas do YouTube

`baixar-youtube.sh` (instalado na pasta da jukebox, com atalho no menu do Linux) usa o
[yt-dlp](https://github.com/yt-dlp/yt-dlp): o link de um vídeo ou de uma playlist vira um CD em `/home/jkb/musicas`,
no formato da jukebox. As faixas ficam `01 - NOME.mp3` (ou `.mp4` para DVD), com nome em maiúsculas e sem acento;
o script grava o `genero.txt` e tira `capa.jpg` (400x400) e `capapequena.jpg` (200x200) da miniatura. Num CD que
já existe, as faixas entram depois das que estão, até 40. Sem argumentos, o script abre janelas (zenity); pelo
terminal: `baixar-youtube.sh LINK "ARTISTA - CD" "MP - MPB" [mp3|mp4]`. O yt-dlp se atualiza antes de cada
download, porque o YouTube muda sempre. Baixe só o que tem direito de tocar (direitos autorais / ECAD).

## Teste de integração

`sudo sh testes/integracao/rodar.sh` monta uma máquina de teste em `/home/jkb/jukelinux` e `/home/jkb/musicas` (o que
já estiver lá é guardado e volta no fim), abre a jukebox numa tela virtual (Xvfb) e confere o que ela grava: as
configurações padrão, o ranking das mais tocadas, os cartões (lidos do `.CAR` e do `cartoes.ccc`, e um lido pelo
leitor de código de barras no modo Bar, que usa 1 crédito), um CD de lançamento e a
falta de exceções. Roda também no CI.

## Fases

1. Base: repositório, CI, extração completa do formulário, fotos de referência da original.
2. Tela principal idêntica, navegando pelos CDs reais.
3. Créditos, fila e player (mplayer). **Feito:** acervo, fila, músicas cifradas e player tocando em sequência.
4. Regras: palhinha, música grátis, VIP, sorteio, volume, propaganda e vídeos na TV. Vídeo dentro da tela (`-wid`) feito.
5. Menu do operador. Senha e as cinco seções abrem com a configuração da máquina; falta testar cada opção.
6. Licença nova. **Feito:** gerador de licenças (Ed25519) só no computador da empresa, ativação pela tela da
   original, licença entregue pela nuvem ou por pendrive.
7. Pacote de instalação e piloto. **Feito:** instalador com troca direta e desfazer; falta o piloto numa máquina real.
8. Nuvem da empresa. **Feito:** painel das máquinas, dinheiro (noteiro e Pix), relatórios com CSV, fechamentos e
   histórico das licenças. Próximos, no modelo do Jukebox Pix: alertas no Telegram, fechamento diário automático,
   bônus de recarga e vale-música.

## O que ficou do C sem traduzir

Restam 13 linhas `// C:` em `src/jukelinux1_rotinas.inc`, todas sem efeito na Nova:

- **`Criptabuf`/`Descriptabuf`:** a cifra das músicas em blocos. A Nova usa `musicacifra.pas` no lugar.
- **`ButtonAtivarClick`:** a ativação antiga. A tela de ativação é tratada pela licença da Nova (`nova.inc`), que
  esconde o campo e o botão enquanto espera a licença da nuvem.
- **Duas propriedades de painel (vmt 0x21c) e um byte do Form1 (0x33e) sem nome conhecido.** São aparência na
  abertura.
- **Um item do ComboBoxMG6 e uma cópia na lista de discos do `inicio.txt` (o pendrive-chave),** que a licença
  substitui.

## Referência

- `referencia/funcoes.txt`: as funções da original com endereço e tamanho no binário.
- `referencia/telas/Form1.lfm`: a tela principal completa (478 componentes), remontada na ordem exata a partir da
  função `JUKELINUX1_init`, que registra os pedaços do `.lrs`. As imagens embutidas vêm junto como binário.
- `referencia/descompilado/`: as funções descompiladas pelo Ghidra 12.2 (C aproximado, um arquivo por função).
  Ainda faltam os argumentos das chamadas em convenção *register* do FPC (comparações de texto), e o
  `FORMCREATE` precisa de nova rodada com mais tempo.
- `ferramentas/extracao/`: os scripts que geraram tudo isso a partir do binário `jukelinux`. O último passo,
  `completar.py`, converte no Pascal gerado o que o tradutor deixou como `if False { C: ... }` e `// C:` quando
  todos os nomes têm tipo conhecido (teclas, chamadas do player, textos). Condições com o operador vírgula do C
  (`A && (x = x + 1, x == 2)`, como no modo 2x1 de créditos) viram comandos que guardam o resultado em `NovaCond`,
  mantendo o curto-circuito. Vetores globais que o Ghidra não reconheceu (ritmos, letras, propagandas, frases,
  karaokê, 50 mais tocadas) estão em `VETORES_GLOBAIS`, com as formas de acesso de cada um. Roda sozinho com
  `python3 ferramentas/extracao/completar.py src/globais.inc src/jukelinux1_rotinas.inc`.
- O acervo de CDs da original (`MAT`, 8000 registros de 576 bytes) é o registro `TIPOCD` em `src/globais.inc`, com
  os campos deduzidos dos acessos no código descompilado (pasta, nome, capas, gênero, as 40 músicas, contadores).
  Trechos em que o Ghidra perdeu informação demais são reescritos à mão, seguindo o C, em
  `ferramentas/extracao/correcoes.py` (por exemplo a leitura das pastas dos CDs em `Carregando_Cds`).

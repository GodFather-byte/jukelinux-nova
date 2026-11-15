# JukeLinux Nova

Recriação fiel da **JukeLinux** (jukebox de bar, versão de 19/01/2018) em **Lazarus/Free Pascal**, feita com
autorização do desenvolvedor da original.

- **Mesma tela e mesmo comportamento:** o layout parte do formulário extraído do programa original
  (`referencia/telas/Form1.lfm`) e cada rotina reimplementa a de mesmo nome da original
  (`referencia/funcoes.txt`, 266 funções da unit `jukelinux1.pas`).
- **Troca direta:** usa os mesmos arquivos das máquinas atuais (`/home/jkb/jukelinux`, as configurações `.txt`,
  `/home/jkb/musicas` com `ARTISTA - CD`, `genero.txt` e `capa.jpg`, `tocados.txt`, relógios).
- **Licença própria** no lugar da trava do pendrive-chave da original.
- 64 bits, GTK2, roda no Linux Mint 22.

## Compilar

```bash
sudo apt install lazarus-ide lcl-gtk2 lcl-units fpc
ferramentas/licenca/nova_chave.sh   # uma vez: cria src/licenca_chave.inc (a chave secreta das licenças)
lazbuild --widgetset=gtk2 jukelinux.lpi
```

A CI (GitHub Actions → **Build**) roda os testes, compila a cada push e publica o executável em *Artifacts*. Para o
executável do CI servir nas máquinas, cadastre o segredo `LICENCA_CHAVE` no repositório (o valor de
`NOVA_CHAVE_LICENCA` do seu `src/licenca_chave.inc`); sem ele o CI usa a chave de desenvolvimento e avisa.

## Instalar numa máquina

O CI publica o pacote **jukelinux-nova-linux-x86_64** (em *Actions → Build → Artifacts*): o executável, o instalador
e o exemplo do Pix. Na máquina:

```bash
sudo sh instalar.sh             # instala dependências, guarda o executável antigo e põe a Nova no lugar dele
sudo sh instalar.sh --desfazer  # volta o executável anterior
```

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

## Licença

No lugar do pendrive-chave, a Nova usa a tela de ativação da original. Sem licença válida, a jukebox abre em
**Ativação da Jukebox** mostrando o código da máquina (16 dígitos, tirados do número de série do disco do sistema;
uma imagem clonada em outro HD tem outro código) e não responde às teclas. A empresa gera a contra-senha:

```bash
ferramentas/licenca/gerar.sh 1020-7373-4289-6379              # permanente
ferramentas/licenca/gerar.sh 1020-7373-4289-6379 31/12/2027   # vence nesse dia
ferramentas/licenca/gerar.sh 1020-7373-4289-6379 30           # vence em 30 dias
```

O técnico digita os 12 dígitos e clica em Ativar (ou Enter): aparece o "Ativação OK" da original e a jukebox libera
na hora, sem desligar. A contra-senha leva a validade e uma assinatura HMAC com a chave secreta; o `licenca.txt` guarda
também o último dia visto, assinado, para atrasar o relógio não estender a validade. A licença é conferida de novo a
cada hora. Testes: `testes/licenca/rodar.sh`.

Máquina antiga trocada pela Nova continua com o serial da chave antiga (lido dos arquivos dela); máquina nova recebe um
serial tirado do código da licença.

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

## Teste de integração

`sudo sh testes/integracao/rodar.sh` monta uma máquina de teste em `/home/jkb/jukelinux` e `/home/jkb/musicas` (o que
já estiver lá é guardado e volta no fim), abre a jukebox numa tela virtual (Xvfb) e confere o que ela grava: as
configurações padrão, o ranking das mais tocadas, um cartão lido do `.CAR` e do `cartoes.ccc`, um CD de lançamento e a
falta de exceções. Roda também no CI.

## Fases

1. Base: repositório, CI, extração completa do formulário, fotos de referência da original.
2. Tela principal idêntica, navegando pelos CDs reais.
3. Créditos, fila e player (mplayer). **Feito:** acervo, fila, músicas cifradas e player tocando em sequência.
4. Regras: palhinha, música grátis, VIP, sorteio, volume, propaganda e vídeos na TV. Vídeo dentro da tela (`-wid`) feito.
5. Menu do operador. Senha e as cinco seções abrem com a configuração da máquina; falta testar cada opção.
6. Licença nova e ferramenta de gerar licenças. **Feito:** ativação pela tela da original e gerador de contra-senhas.
7. Pacote de instalação e piloto. **Feito:** instalador com troca direta e desfazer; falta o piloto numa máquina real.

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

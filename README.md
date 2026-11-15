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

## Fases

1. Base: repositório, CI, extração completa do formulário, fotos de referência da original.
2. Tela principal idêntica, navegando pelos CDs reais.
3. Créditos, fila e player (mplayer). **Feito:** acervo, fila, músicas cifradas e player tocando em sequência.
4. Regras: palhinha, música grátis, VIP, sorteio, volume, propaganda e vídeos na TV.
5. Menu do operador.
6. Licença nova e ferramenta de gerar licenças. **Feito:** ativação pela tela da original e gerador de contra-senhas.
7. Pacote de instalação e piloto.

## Referência

- `referencia/funcoes.txt`: as funções da original com endereço e tamanho no binário.
- `referencia/telas/Form1.lfm`: a tela principal completa (478 componentes), remontada na ordem exata a partir da
  função `JUKELINUX1_init`, que registra os pedaços do `.lrs`. As imagens embutidas vêm junto como binário.
- `referencia/descompilado/`: as funções descompiladas pelo Ghidra 12.2 (C aproximado, um arquivo por função).
  Ainda faltam os argumentos das chamadas em convenção *register* do FPC (comparações de texto), e o
  `FORMCREATE` precisa de nova rodada com mais tempo.
- `ferramentas/extracao/`: os scripts que geraram tudo isso a partir do binário `jukelinux`. O último passo,
  `completar.py`, converte no Pascal gerado o que o tradutor deixou como `if False { C: ... }` e `// C:` quando
  todos os nomes têm tipo conhecido (teclas, chamadas do player, textos); roda sozinho com
  `python3 ferramentas/extracao/completar.py src/globais.inc src/jukelinux1_rotinas.inc`.
- O acervo de CDs da original (`MAT`, 8000 registros de 576 bytes) é o registro `TIPOCD` em `src/globais.inc`, com
  os campos deduzidos dos acessos no código descompilado (pasta, nome, capas, gênero, as 40 músicas, contadores).
  Trechos em que o Ghidra perdeu informação demais são reescritos à mão, seguindo o C, em
  `ferramentas/extracao/correcoes.py` (por exemplo a leitura das pastas dos CDs em `Carregando_Cds`).

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
lazbuild --widgetset=gtk2 jukelinux.lpi
```

A CI (GitHub Actions → **Build**) compila a cada push e publica o executável em *Artifacts*.

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
3. Créditos, fila e player (mplayer).
4. Regras: palhinha, música grátis, VIP, sorteio, volume, propaganda e vídeos na TV.
5. Menu do operador.
6. Licença nova e ferramenta de gerar licenças.
7. Pacote de instalação e piloto.

## Referência

- `referencia/funcoes.txt`: as funções da original com endereço e tamanho no binário.
- `referencia/telas/Form1.lfm`: a tela principal completa (478 componentes), remontada na ordem exata a partir da
  função `JUKELINUX1_init`, que registra os pedaços do `.lrs`. As imagens embutidas vêm junto como binário.
- `referencia/descompilado/`: as funções descompiladas pelo Ghidra 12.2 (C aproximado, um arquivo por função).
  Ainda faltam os argumentos das chamadas em convenção *register* do FPC (comparações de texto), e o
  `FORMCREATE` precisa de nova rodada com mais tempo.
- `ferramentas/extracao/`: os scripts que geraram tudo isso a partir do binário `jukelinux`.

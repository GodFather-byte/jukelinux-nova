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
- `referencia/descompilado/funcoes/`: as funções descompiladas pelo Ghidra 12.2 (C aproximado, um arquivo
  por função). Ainda faltam os argumentos das chamadas em convenção *register* do FPC (comparações de texto
  e Left/Top/Width/Caption).
- `referencia/descompilado/legivel/`: a mesma saída com o nome do componente no lugar do deslocamento
  (`Form1.Timerabertura` em vez de `FORM1 + 0xbc4`). Os textos `__JUKELINUX1__LdNNN` continuam com o
  rótulo: trocá-los pede o binário `jukelinux` (`python textos_ld.py jukelinux textos_ld.json` e de novo
  `trocar_textos.py`).
- Das 266 funções, o Ghidra gravou 265. A que falhou é `TForm1.FORMCREATE` (55.544 bytes, timeout de 900 s
  em `080b73d0`). `MOSTRA_COORDENADAS_TOUCHSCREEN` não saiu em arquivo. A abertura da tela (contador do
  `Timerabertura` e `INICIA_TELA`) já está reescrita em `src/jukelinux1.pas`.
- `ferramentas/extracao/`: os scripts que geraram tudo isso a partir do binário `jukelinux`.

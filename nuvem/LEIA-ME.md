# Nuvem da JukeLinux Nova

Servidor da empresa. As jukeboxes falam com ele quando têm internet. Ele faz quatro coisas:

- **Entregar licenças:** você gera a licença no **gerador de licenças**, que fica só no seu computador
  (`ferramentas/licenca/gerador-de-licencas.html`), e envia pelo painel (**Enviar licença**). A nuvem confere e
  entrega à máquina no próximo contato. **A nuvem não tem a chave que cria licenças**: mesmo que alguém invada o
  servidor, não consegue liberar máquina nenhuma.
- **Painel das máquinas:** quais estão online, último contato, versão, relógios (total, parcial, Pix do período,
  ponto da casa) e o dinheiro de hoje de cada uma.
- **Dinheiro e relatórios:** noteiro e Pix por dia, por máquina e por hora, a parte da casa e a sua, ticket médio do
  Pix, horário de pico, mais tocadas, CDs mais pedidos e fechamentos do relógio. Dá para baixar em CSV (Excel) ou
  imprimir.
- **Histórico:** licenças enviadas (liberação, validade, bloqueio), aparelhos esquecidos e quando cada coisa
  aconteceu.

**As jukeboxes não dependem da nuvem para funcionar.** Sem internet elas tocam, aceitam notas e Pix (o Pix já
precisa de internet de qualquer jeito) e guardam tudo numa fila. Quando a internet volta, mandam o que juntaram.
Cada evento tem um id, então nada é contado duas vezes.

Não tem dependências: é Node 22.13+ com o SQLite embutido. Os dados ficam num arquivo só (`nuvem.db`).

## 1. A chave (uma vez, no seu computador)

Abra `ferramentas/licenca/gerador-de-licencas.html` no navegador (Chrome, Edge ou Firefox) e clique em **Criar chave
nova**:

- **Cópia da chave:** o navegador guarda a chave e baixa uma cópia (`chave-privada-licencas.json`). **Guarde a cópia
  num pendrive ou lugar seguro.** Não coloque na nuvem nem no git. Quem tem essa chave cria licenças, e sem ela não dá
  para gerar licenças para as jukeboxes já instaladas. Em outro computador, abra o gerador e use **Abrir arquivo da
  chave**.
- **licenca_publica.inc:** baixe e troque o `src/licenca_publica.inc` do repositório por ele (no GitHub: *Add file →
  Upload files*, na pasta `src`). O CI gera o executável com a sua chave.
- **Chave pública:** a que o gerador mostra em "Primeira vez" vai na nuvem, em `LICENCA_CHAVE_PUBLICA`. Ela não é
  segredo: só serve para a nuvem recusar licença que não seja sua.

Enquanto a chave não for trocada, o repositório usa a chave de **desenvolvimento**, cuja privada está no git
(`nuvem/testes/chave-desenvolvimento.pem`). Com ela, a jukebox registra um aviso no log e o CI também avisa.
**Não use o executável com a chave de desenvolvimento nas máquinas.**

## 2. Variáveis de ambiente

| Variável | Para quê |
|---|---|
| `ADMIN_SENHA` | senha do painel (obrigatória em produção, mínimo 10 letras) |
| `ADMIN_USUARIO` | usuário do painel (padrão `admin`) |
| `LICENCA_CHAVE_PUBLICA` | a chave pública que o gerador de licenças mostra (base64). Recomendado: sem ela, a nuvem não confere as licenças enviadas (a jukebox confere de qualquer jeito) |
| `BANCO` | arquivo do banco (padrão `dados/nuvem.db`; na imagem Docker, `/dados/nuvem.db`) |
| `PORTA` (ou `PORT`) | porta HTTP (padrão 8080) |
| `FUSO_HORARIO` | fuso dos relatórios (padrão `-03:00`, Brasília) |
| `VIRADA_DO_DIA` | hora em que o "dia" do bar vira (padrão 6: a noite que passa da meia-noite fica no mesmo dia) |
| `INTERVALO_CONTATO` | de quantos em quantos segundos a jukebox fala com a nuvem (padrão 60) |
| `NODE_ENV=production` | exige a senha, liga o cookie só por HTTPS e confia no IP do proxy (`X-Forwarded-For`) |

## 3. Hospedar

A nuvem precisa de três coisas: **HTTPS**, **disco que não se apaga** (para o `nuvem.db`) e Node 22.13+ ou Docker.

- **Servidor próprio ou VPS com Docker:**
  ```bash
  docker build -t jukelinux-nuvem nuvem/
  docker run -d --restart=always --name nuvem -p 127.0.0.1:8080:8080 -v jukelinux-dados:/dados \
    -e ADMIN_SENHA='uma senha forte' -e LICENCA_CHAVE_PUBLICA='a chave pública do gerador' jukelinux-nuvem
  ```
  Na frente, um proxy com HTTPS, por exemplo o Caddy com `nuvem.suaempresa.com.br { reverse_proxy 127.0.0.1:8080 }`.
- **Render, Railway, Fly e parecidos:** serviço Docker apontando para a pasta `nuvem/`, com um **disco persistente**
  montado em `/dados`. Sem disco persistente o banco some a cada deploy. As variáveis vão no painel do provedor.
- **Sem Docker:** `cd nuvem && NODE_ENV=production ADMIN_SENHA=... LICENCA_CHAVE_PUBLICA=... npm start`.

**Backup:** copie o `nuvem.db` de vez em quando, com a nuvem parada ou com `sqlite3 nuvem.db ".backup copia.db"`.
Ele guarda o histórico de dinheiro e as licenças enviadas. Se o banco se perder, as jukeboxes continuam funcionando
com a licença que já têm. Basta reenviar as licenças, que o gerador lista em "Licenças geradas neste computador".

## 4. Ligar as jukeboxes

Instale com o endereço da nuvem:

```bash
sudo sh instalar.sh --nuvem https://nuvem.suaempresa.com.br
```

Isso grava `/home/jkb/jukelinux/nuvem.txt` com `url = https://...`.

1. Na primeira vez que a jukebox abre com internet, ela aparece em **Máquinas** **aguardando licença**, com o mesmo
   código da tela de ativação.
2. No gerador: código da máquina, **Liberar**, permanente ou até uma data, e **Gerar licença**.
3. No painel: **Enviar licença**, cole (ou abra o `licenca.txt`) e envie. Em até um minuto a jukebox recebe e libera
   sozinha.

Outros casos:
- **Máquina sem internet:** grave o `licenca.txt` do gerador na raiz de um pendrive e espete na jukebox; ela instala
  em poucos segundos. Dá para enviar a licença pelo painel antes de a máquina aparecer: ela fica guardada e vai no
  primeiro contato.
- **Bloquear:** gere no gerador uma licença de **Bloquear** e envie. A jukebox trava no próximo contato. Se ela
  estiver sem internet, trava quando a internet voltar ou quando o pendrive for colocado. Para desbloquear, gere uma
  de **Liberar**.
- **Máquina alugada:** use a validade ("vale até"). Ao renovar, gere uma licença nova e envie.
- **Jukebox reinstalada:** o código é o mesmo (vem do disco), mas o segredo do aparelho muda. A nuvem recusa e avisa
  "outro aparelho". Se foi você que reinstalou, clique em **Esquecer o aparelho** e ela pareia de novo.

## 5. Desenvolvimento

```bash
cd nuvem
npm test                                             # testes da nuvem
ADMIN_SENHA=uma-senha-qualquer npm start
```

Testes da conversa com a jukebox (Pascal contra a nuvem de verdade, licenças feitas pelo núcleo do gerador):
`sh testes/nuvem/rodar.sh` na raiz do repositório.

### API das máquinas

`POST /api/v1/contato` com `Authorization: Bearer <segredo da máquina>` e JSON:

```json
{ "codigo": "1020737342896379", "versao": "Nova ...",
  "relogio": { "total": 500, "parcial": 120, "pix_parcial": 20, "pix_total": 80, "ponto_pct": 30, "creditos": 3 },
  "eventos": [
    { "id": "abc-1", "tipo": "credito", "quando": 1795500000, "origem": "noteiro", "reais": 10 },
    { "id": "abc-2", "tipo": "credito", "quando": 1795500060, "origem": "pix", "reais": 20, "creditos": 20 },
    { "id": "abc-3", "tipo": "musica", "quando": 1795500120, "cd": "ARTISTA - CD", "musica": "01 - NOME" },
    { "id": "abc-4", "tipo": "fechamento", "quando": 1795503600, "parcial": 120, "pix": 20, "ponto": 36 },
    { "id": "abc-5", "tipo": "ligou", "quando": 1795490000, "versao": "Nova ..." } ] }
```

Resposta:
- `situacao`: `pendente` (ainda sem licença), `ativa` ou `bloqueada`.
- `licenca` (texto) e `licenca_b64`: a última licença enviada para a máquina.
- `recebidos`: ids que a máquina tira da fila.
- `rejeitados`, `intervalo` e `agora`.

O formato da licença está em `src/licenca.js` e no gerador.

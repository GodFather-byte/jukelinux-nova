# Nuvem da JukeLinux Nova

Servidor da empresa. As jukeboxes falam com ele quando têm internet. Ele faz quatro coisas:

- **Licenças:** cada máquina nova aparece no painel aguardando liberação. Liberar, bloquear, dar validade ou exigir
  contato a cada N dias é feito aqui. A licença vai assinada (Ed25519) e a jukebox confere sozinha, sem internet.
- **Painel das máquinas:** quais estão online, último contato, versão, relógios (total, parcial, Pix do período,
  ponto da casa) e o dinheiro de hoje de cada uma.
- **Dinheiro e relatórios:** noteiro e Pix por dia, por máquina e por hora, a parte da casa e a sua, ticket médio do
  Pix, horário de pico, mais tocadas, CDs mais pedidos e fechamentos do relógio. Dá para baixar em CSV (Excel) ou
  imprimir.
- **Histórico:** quem liberou, bloqueou ou mudou a validade, e quando.

**As jukeboxes não dependem da nuvem para funcionar.** Sem internet elas tocam, aceitam notas e Pix (o Pix já
precisa de internet de qualquer jeito) e guardam tudo numa fila. Quando a internet volta, mandam o que juntaram.
Cada evento tem um id, então nada é contado duas vezes.

Não tem dependências: é Node 22.13+ com o SQLite embutido. Os dados ficam num arquivo só (`nuvem.db`).

## 1. Chaves das licenças (uma vez, no computador da empresa)

```bash
sh ferramentas/licenca/nova_chave.sh
```

- Cria `~/jukelinux-chave/chave-privada-licencas.pem`, a **chave privada**. Ela fica fora do git e vai para a
  nuvem. Guarde uma cópia em lugar seguro: quem tem essa chave emite licenças, e sem ela não dá para emitir licença
  para as máquinas já instaladas.
- Grava a **chave pública** em `src/licenca_publica.inc`. Faça commit dela: o CI gera o executável já com a chave
  certa. A chave pública só confere licenças, não cria.

Enquanto isso não for feito, o repositório usa a chave de **desenvolvimento**, cuja privada está no git
(`nuvem/testes/chave-desenvolvimento.pem`). Com ela, a jukebox registra um aviso no log e o CI também avisa.
**Não use o executável com a chave de desenvolvimento nas máquinas.**

## 2. Variáveis de ambiente

| Variável | Para quê |
|---|---|
| `ADMIN_SENHA` | senha do painel (obrigatória em produção, mínimo 10 letras) |
| `ADMIN_USUARIO` | usuário do painel (padrão `admin`) |
| `LICENCA_CHAVE_PRIVADA` | o conteúdo do `chave-privada-licencas.pem` (ou `LICENCA_CHAVE_PRIVADA_ARQUIVO` com o caminho) |
| `BANCO` | arquivo do banco (padrão `dados/nuvem.db`; na imagem Docker, `/dados/nuvem.db`) |
| `PORTA` (ou `PORT`) | porta HTTP (padrão 8080) |
| `FUSO_HORARIO` | fuso dos relatórios (padrão `-03:00`, Brasília) |
| `VIRADA_DO_DIA` | hora em que o "dia" do bar vira (padrão 6: a noite que passa da meia-noite fica no mesmo dia) |
| `INTERVALO_CONTATO` | de quantos em quantos segundos a jukebox fala com a nuvem (padrão 60) |
| `NODE_ENV=production` | exige senha e chave, liga o cookie só por HTTPS e confia no IP do proxy (`X-Forwarded-For`) |

## 3. Hospedar

A nuvem precisa de três coisas: **HTTPS**, **disco que não se apaga** (para o `nuvem.db`) e Node 22.13+ ou Docker.

- **Servidor próprio ou VPS com Docker:**
  ```bash
  docker build -t jukelinux-nuvem nuvem/
  docker run -d --restart=always --name nuvem -p 127.0.0.1:8080:8080 -v jukelinux-dados:/dados \
    -e ADMIN_SENHA='uma senha forte' -e LICENCA_CHAVE_PRIVADA="$(cat ~/jukelinux-chave/chave-privada-licencas.pem)" \
    jukelinux-nuvem
  ```
  Na frente, um proxy com HTTPS, por exemplo o Caddy com `nuvem.suaempresa.com.br { reverse_proxy 127.0.0.1:8080 }`.
- **Render, Railway, Fly e parecidos:** serviço Docker apontando para a pasta `nuvem/`, com um **disco persistente**
  montado em `/dados`. Sem disco persistente o banco some a cada deploy. As variáveis vão no painel do provedor.
- **Sem Docker:** `cd nuvem && NODE_ENV=production ADMIN_SENHA=... LICENCA_CHAVE_PRIVADA_ARQUIVO=... npm start`.

**Backup:** copie o `nuvem.db` de vez em quando (com a nuvem parada, ou use `sqlite3 nuvem.db ".backup copia.db"`).
As licenças não dependem do banco: com a chave privada, uma nuvem nova emite de novo. Já o histórico de dinheiro
fica só no banco.

## 4. Ligar as jukeboxes

Instale com o endereço da nuvem:

```bash
sudo sh instalar.sh --nuvem https://nuvem.suaempresa.com.br
```

Isso grava `/home/jkb/jukelinux/nuvem.txt` com `url = https://...`. Na primeira vez que a jukebox abre com internet,
ela aparece em **Máquinas** aguardando liberação, com o mesmo código da tela de ativação. Clique em **Liberar**: em até
um minuto a licença chega e a jukebox libera sozinha.

- **Máquina sem internet:** libere no painel e clique em **Baixar licenca.txt**. Copie o arquivo para a raiz de um
  pendrive e espete na jukebox; ela instala em poucos segundos.
- **Jukebox reinstalada:** o código é o mesmo (vem do disco), mas o segredo do aparelho muda. A nuvem recusa e avisa
  "outro aparelho". Se foi você que reinstalou, clique em **Esquecer o aparelho** e ela pareia de novo.
- **Bloquear:** a jukebox trava no próximo contato. Se ela estiver sem internet, trava quando voltar.
- **Exigir contato a cada N dias:** a jukebox trava se passar N dias sem falar com a nuvem. Use em máquina alugada;
  com 0 (padrão) ela nunca depende da internet.

## 5. Desenvolvimento

```bash
cd nuvem
npm test                                             # testes da nuvem
ADMIN_SENHA=uma-senha-qualquer LICENCA_CHAVE_PRIVADA_ARQUIVO=testes/chave-desenvolvimento.pem npm start
```

Testes da conversa com a jukebox (Pascal contra a nuvem de verdade): `sh testes/nuvem/rodar.sh` na raiz do repositório.

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

Resposta: `situacao` (`pendente`, `ativa`, `bloqueada`), `licenca` (texto) e `licenca_b64`, `recebidos` (ids que a
máquina tira da fila), `rejeitados`, `intervalo` e `agora`. O formato da licença está em `src/licenca.js`.

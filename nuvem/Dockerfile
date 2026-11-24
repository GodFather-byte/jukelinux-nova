# Nuvem da JukeLinux Nova. Sem dependências: só o Node (SQLite embutido).
#   docker build -t jukelinux-nuvem nuvem/
#   docker run -d --name nuvem -p 8080:8080 -v jukelinux-dados:/dados \
#     -e ADMIN_SENHA=... -e LICENCA_CHAVE_PRIVADA="$(cat chave-privada-licencas.pem)" jukelinux-nuvem
# Ponha um HTTPS na frente (Caddy, Cloudflare, o do provedor): a senha do painel e o segredo das máquinas passam por aqui.
FROM node:22-alpine
WORKDIR /app
COPY package.json servidor.js ./
COPY src ./src
RUN mkdir /dados && chown node:node /dados
ENV NODE_ENV=production BANCO=/dados/nuvem.db PORTA=8080
VOLUME /dados
USER node
EXPOSE 8080
HEALTHCHECK --interval=60s --timeout=5s CMD wget -qO- http://127.0.0.1:8080/saude || exit 1
CMD ["node", "--disable-warning=ExperimentalWarning", "servidor.js"]

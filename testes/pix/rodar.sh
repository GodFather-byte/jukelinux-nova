#!/bin/sh
# Testa o Pix (src/pix.pas e o QR Code de src/pixtela.pas) contra um PSP simulado com HTTPS e certificado de cliente.
# Precisa de: lazbuild, python3, openssl, curl, zbarimg (zbar-tools) e xvfb-run (xvfb).
set -e
AQUI=$(cd "$(dirname "$0")" && pwd)
PORTA=${PORTA:-8443}
T=$(mktemp -d)
PSP=
limpa() {
  [ -n "$PSP" ] && kill "$PSP" 2>/dev/null || true
  [ -n "$T" ] && [ -d "$T" ] && rm -r "$T"
}
trap limpa EXIT

mkdir "$T/certs"
cd "$T/certs"
openssl req -x509 -newkey rsa:2048 -nodes -keyout ca.key -out ca.pem -days 1 -subj "/CN=PSP Teste CA" 2>/dev/null
openssl req -newkey rsa:2048 -nodes -keyout servidor.key -out servidor.csr -subj "/CN=localhost" 2>/dev/null
printf "subjectAltName=DNS:localhost,IP:127.0.0.1\n" > san.ext
openssl x509 -req -in servidor.csr -CA ca.pem -CAkey ca.key -CAcreateserial -out servidor.pem -days 1 -extfile san.ext 2>/dev/null
openssl req -newkey rsa:2048 -nodes -keyout cliente.key -out cliente.csr -subj "/CN=jukebox" 2>/dev/null
openssl x509 -req -in cliente.csr -CA ca.pem -CAkey ca.key -CAcreateserial -out cliente.pem -days 1 2>/dev/null
openssl req -x509 -newkey rsa:2048 -nodes -keyout outra.key -out outra-ca.pem -days 1 -subj "/CN=Outra CA" 2>/dev/null

cat > "$T/pix.txt" <<FIM
# configuração de teste
ativo = sim
url_api = https://localhost:$PORTA/api/v2/
url_token = https://localhost:$PORTA/oauth/token
client_id = cid-jukebox
client_secret = segredo "com" aspas\\
certificado = $T/certs/cliente.pem
chave_privada = $T/certs/cliente.key
ca = $T/certs/ca.pem
chave = pix@exemplo.com.br
valores = 2, 5,10
expiracao = 120
botao = 10,20,130,70
FIM

cd "$AQUI"
python3 -I psp_falso.py "$T/certs" "$PORTA" "$T/psp.log" &
PSP=$!
lazbuild --widgetset=gtk2 teste_pix.lpi >/dev/null
i=0
until curl -s -o /dev/null --cacert "$T/certs/ca.pem" --cert "$T/certs/cliente.pem" --key "$T/certs/cliente.key" \
    "https://localhost:$PORTA/_estado"; do
  i=$((i + 1)); [ $i -gt 50 ] && { echo "PSP simulado não subiu"; exit 1; }
  sleep 0.2
done
xvfb-run -a ./teste_pix "$T"

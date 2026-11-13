# PSP simulado para teste: API Pix do Banco Central (OAuth2 + mTLS + /cob). Nunca usar fora de teste.
# Uso: python3 -I psp_falso.py <pasta dos certificados> <porta> <arquivo de log>
# Controle do teste: GET /_pagar/<txid> (ou /_pagar/todas) marca como paga; GET /_estado lista as cobranças.
import json, re, ssl, sys, base64, threading
from http.server import HTTPServer, BaseHTTPRequestHandler
C = sys.argv[1]; PORTA = int(sys.argv[2]); LOG = sys.argv[3]
COBS = {}; TOKEN = 'tok-' + 'x'*20
TXID = re.compile(r'^[a-zA-Z0-9]{26,35}$')
trava = threading.Lock()
def log(*a):
    with open(LOG, 'a') as f: f.write(' '.join(str(x) for x in a) + '\n')
class H(BaseHTTPRequestHandler):
    def log_message(self, *a): pass
    def resp(self, cod, obj):
        b = json.dumps(obj).encode(); self.send_response(cod)
        self.send_header('Content-Type', 'application/json'); self.send_header('Content-Length', str(len(b)))
        self.end_headers(); self.wfile.write(b)
    def corpo(self):
        n = int(self.headers.get('Content-Length') or 0); return self.rfile.read(n).decode() if n else ''
    def autorizado(self):
        if self.headers.get('Authorization') != 'Bearer ' + TOKEN:
            self.resp(401, {'title': 'nao autorizado'}); return False
        return True
    def do_POST(self):
        b = self.corpo()
        if self.path == '/oauth/token':
            esperado = 'Basic ' + base64.b64encode(b'cid-jukebox:segredo "com" aspas\\').decode()
            ok = self.headers.get('Authorization') == esperado and 'grant_type=client_credentials' in b
            log('TOKEN', 'ok' if ok else 'recusado', b, self.headers.get('Content-Type'))
            if not ok: return self.resp(401, {'error': 'invalid_client'})
            return self.resp(200, {'access_token': TOKEN, 'token_type': 'Bearer', 'expires_in': 3600})
        self.resp(404, {})
    def do_PUT(self):
        b = self.corpo(); m = re.match(r'^/api/v2/cob/(.+)$', self.path)
        if not m or not self.autorizado(): return
        txid = m.group(1)
        if not TXID.match(txid): log('PUT txid invalido', txid); return self.resp(400, {'title': 'txid invalido'})
        d = json.loads(b)
        ok = (re.match(r'^\d+\.\d\d$', d['valor']['original']) and d['chave'] == 'pix@exemplo.com.br'
              and d['calendario']['expiracao'] == 120)
        log('PUT', txid, b)
        if not ok: return self.resp(400, {'title': 'corpo invalido'})
        with trava:
            COBS[txid] = {'status': 'ATIVA', 'valor': d['valor']['original']}
        self.resp(201, {'txid': txid, 'status': 'ATIVA', 'valor': d['valor'],
            'pixCopiaECola': '00020101021226830014br.gov.bcb.pix2561psp.exemplo/qr/v2/' + txid +
                             '5204000053039865802BR5913JUKEBOX TESTE6009SAO PAULO62070503***6304ABCD'})
    def do_GET(self):
        m = re.match(r'^/api/v2/cob/(.+)$', self.path)
        if self.path.startswith('/_pagar/'):
            t = self.path.split('/')[-1]
            with trava:
                if t == 'todas':
                    for c in COBS.values():
                        if c['status'] == 'ATIVA': c['status'] = 'CONCLUIDA'
                elif t in COBS: COBS[t]['status'] = 'CONCLUIDA'
            log('PAGO', t); return self.resp(200, {})
        if self.path == '/_estado': return self.resp(200, COBS)
        if not m or not self.autorizado(): return
        c = COBS.get(m.group(1))
        log('GET', m.group(1), c and c['status'])
        if not c: return self.resp(404, {'title': 'nao encontrada'})
        self.resp(200, {'txid': m.group(1), 'status': c['status'], 'valor': {'original': c['valor']}})
    def do_PATCH(self):
        b = self.corpo(); m = re.match(r'^/api/v2/cob/(.+)$', self.path)
        if not m or not self.autorizado(): return
        c = COBS.get(m.group(1)); log('PATCH', m.group(1), b, c and c['status'])
        if not c: return self.resp(404, {})
        if c['status'] != 'ATIVA': return self.resp(400, {'title': 'cobranca nao esta ativa'})
        c['status'] = json.loads(b)['status']; self.resp(200, {'status': c['status']})
s = HTTPServer(('127.0.0.1', PORTA), H)
ctx = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
ctx.load_cert_chain(C + '/servidor.pem', C + '/servidor.key')
ctx.verify_mode = ssl.CERT_REQUIRED; ctx.load_verify_locations(C + '/ca.pem')
s.socket = ctx.wrap_socket(s.socket, server_side=True)
log('INICIO'); s.serve_forever()

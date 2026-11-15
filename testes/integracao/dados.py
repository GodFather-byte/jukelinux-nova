"""Monta a máquina de teste: CDs, músicas tocadas, lançamento (.ATU) e cartões (.CAR e cartoes.ccc), com os formatos
e as cifras da original (Cripta: +i+17; Criptasuper: 5 caracteres + i+72)."""
import base64, datetime, os, sys

juke, musicas = sys.argv[1], sys.argv[2]


def escreve(caminho, texto, modo='w'):
    os.makedirs(os.path.dirname(caminho), exist_ok=True)
    with open(caminho, modo) as f:
        f.write(texto)


# JPEG de 8x8 (a original só mostra CDs com capa.jpg e capapequena.jpg)
JPG = base64.b64decode('/9j/4AAQSkZJRgABAQAAAAAAAAD/2wBDAAMCAgICAgMCAgIDAwMDBAYEBAQEBAgGBgUGCQgKCgkICQkKDA8MCgsOCwkJDRENDg8QEBEQCgwSExIQEw8QEBD/2wBDAQMDAwQDBAgEBAgQCwkLEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBD/wAARCAAIAAgDAREAAhEBAxEB/8QAFAABAAAAAAAAAAAAAAAAAAAAB//EABQQAQAAAAAAAAAAAAAAAAAAAAD/xAAVAQEBAAAAAAAAAAAAAAAAAAAGB//EABQRAQAAAAAAAAAAAAAAAAAAAAD/2gAMAwEAAhEDEQA/AB8UQx//2Q==')

cds = {'ALCEU VALENCA - AO VIVO': ('MP - MPB', ['01 - ANUNCIACAO', '02 - MORENA TROPICANA']),
       'ROBERTO CARLOS - EMOCOES': ('RO - ROMANTICO', ['01 - EMOCOES', '02 - DETALHES']),
       'ZEZE DI CAMARGO - AO VIVO': ('SE - SERTANEJO', ['01 - E O AMOR'])}
for cd, (genero, faixas) in cds.items():
    escreve(f'{musicas}/{cd}/genero.txt', genero + '\n')
    escreve(f'{musicas}/{cd}/capa.jpg', JPG, 'wb')
    escreve(f'{musicas}/{cd}/capapequena.jpg', JPG, 'wb')
    for faixa in faixas:
        escreve(f'{musicas}/{cd}/{faixa}.mp3', 'x')
# lançamento: 30 dias a partir de hoje
hoje = datetime.date.today().strftime('%d/%m/%Y')
escreve(f'{musicas}/ROBERTO CARLOS - EMOCOES/lancamento.atu', f'30\n{hoje}\n')
# músicas tocadas: 3x ANUNCIACAO, 2x EMOCOES, 1x DETALHES
tocadas = [('ALCEU VALENCA - AO VIVO', '01 - ANUNCIACAO')] * 3 + [('ROBERTO CARLOS - EMOCOES', '01 - EMOCOES')] * 2 + \
          [('ROBERTO CARLOS - EMOCOES', '02 - DETALHES')]
escreve(f'{juke}/tocados.txt', datetime.date.today().strftime('%d-%m-%y') + '\n' +
        ''.join(f'/{musicas}/{cd}/{faixa}.mp3\n' for cd, faixa in tocadas))


def ss(b, cap):
    return bytes([len(b)]) + b + bytes(cap - len(b))


cripta = lambda s: bytes((ord(c) + i + 17) & 255 for i, c in enumerate(s, 1))
criptasuper = lambda s: b'XXXXX' + bytes((ord(c) + i + 72) & 255 for i, c in enumerate(s, 1))
escreve(f'{juke}/teste.CAR', ss(b'CABECALHO', 93) + ss(criptasuper('12345678'), 93), 'wb')
reg = lambda cod, val, sit: ss(cod, 30) + ss(val, 4) + ss(sit, 1)
escreve(f'{juke}/cartoes.ccc', reg(cripta('01-01-26'), b'', b'') + reg(cripta('12345678'), cripta('7'), cripta('N')), 'wb')

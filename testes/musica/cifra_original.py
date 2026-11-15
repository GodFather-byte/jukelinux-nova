# Codificador independente no formato das músicas cifradas da JukeLinux original (deduzido da Descriptografa e da
# Criptabuf): 10 caracteres com o tamanho N do bloco de informação, 30 da gravadora (Cripta: +posição+17), N bytes de
# informação e a música em blocos de 2048 com byte i (1..2048) = original + i + chave.
# Uso: python3 -I cifra_original.py origem destino chave gravadora tamanho_info
import sys
origem, destino, chave, gravadora, tam = sys.argv[1], sys.argv[2], int(sys.argv[3]), sys.argv[4], int(sys.argv[5])
dados = open(origem, 'rb').read()
saida = bytearray(str(tam).rjust(10).encode('ascii'))           # alinhado à direita, ao contrário da Nova
nome = gravadora.ljust(30)[:30]
saida += bytes((ord(c) + i + 1 + 17) % 256 for i, c in enumerate(nome))
saida += bytes(range(tam % 256)) if tam < 256 else bytes(tam)
for ini in range(0, len(dados), 2048):
    bloco = dados[ini:ini + 2048]
    saida += bytes((b + i + 1 + chave) % 256 for i, b in enumerate(bloco))
open(destino, 'wb').write(saida)

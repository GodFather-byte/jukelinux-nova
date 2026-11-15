"""Mostra código - créditos de cada registro do cartoes.ccc (decifrando como a original: -i-17)."""
import sys

dados = open(sys.argv[1], 'rb').read()
decifra = lambda b: ''.join(chr((c - i - 17) & 255) for i, c in enumerate(b, 1))
for r in range(1, len(dados) // 38):
    reg = dados[r * 38:(r + 1) * 38]
    print(decifra(reg[1:1 + reg[0]]), '-', decifra(reg[32:32 + reg[31]]))

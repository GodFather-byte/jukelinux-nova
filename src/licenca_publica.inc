{ Chave pública das licenças SÓ PARA DESENVOLVIMENTO E TESTES: a privada está no git
  (nuvem/testes/chave-desenvolvimento.pem), então qualquer um emite licenças para ela.
  Para as máquinas, crie a chave de verdade no gerador de licenças (ferramentas/licenca/gerador-de-licencas.html)
  e troque este arquivo pelo licenca_publica.inc que ele baixa. }
const
  NOVA_CHAVE_PUBLICA: array[0..31] of Byte = (200, 7, 218, 175, 179, 91, 254, 238, 214, 124, 20, 58, 16, 151, 170, 7, 49, 3, 46, 39, 200, 32, 13, 37, 177, 98, 239, 228, 240, 248, 0, 221);
  NOVA_CHAVE_DESENVOLVIMENTO = True;

{ Chave da licença SÓ PARA DESENVOLVIMENTO E TESTES: está no git, então qualquer um gera contra-senhas com ela.
  Para as máquinas, crie a chave de verdade com ferramentas/licenca/nova_chave.sh (grava src/licenca_chave.inc, que
  fica fora do git) ou configure o segredo LICENCA_CHAVE no GitHub para o build do CI. }
const
  NOVA_CHAVE_LICENCA = 'jukelinux-nova-chave-de-desenvolvimento-nao-usar-nas-maquinas';
  NOVA_CHAVE_DESENVOLVIMENTO = True;

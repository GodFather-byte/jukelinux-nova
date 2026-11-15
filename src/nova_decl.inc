{ Declarações das rotinas próprias da Nova (corpos em nova.inc), para o código traduzido poder chamá-las. }
procedure Serial_Da_Chave_No_Hd; forward;
function Nova_Decifra_Musica(const Origem, Destino: string; Chave: LongInt): Boolean; forward;
function Nova_Horas(Minutos: LongInt): string; forward;
function Nova_Data_Atu(const Texto: string): TDateTime; forward;
procedure Nova_Carrega_Imagem(Imagem: TPicture; const Arquivo: string); forward;
procedure Nova_Foca(Controle: TWinControl); forward;
procedure Nova_Soma_Pix_Relogio(Reais: LongInt); forward;
procedure Nova_Zera_Pix_Parcial; forward;
procedure Nova_Mostra_Pix_Relogio; forward;

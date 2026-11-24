// Datas no fuso da empresa. O "dia" do bar vai da VIRADA_DO_DIA (padrão 6h) até a mesma hora do dia seguinte:
// a noite de sexta, que passa da meia-noite, fica toda na sexta.
const DIA_MS = 86_400_000;
const FORMATO = /^\d{4}-\d{2}-\d{2}$/;

export function diaDe(ms, config) {
  return new Date(ms + config.fusoMinutos * 60_000 - config.viradaDoDia * 3_600_000).toISOString().slice(0, 10);
}

/** Instante (ms UTC) em que começa o dia `texto` (AAAA-MM-DD). */
export function inicioDoDia(texto, config) {
  return Date.parse(`${texto}T00:00:00Z`) - config.fusoMinutos * 60_000 + config.viradaDoDia * 3_600_000;
}

export function hoje(config, agora = Date.now()) {
  return diaDe(agora, config);
}

export function somaDias(texto, dias) {
  return new Date(Date.parse(`${texto}T00:00:00Z`) + dias * DIA_MS).toISOString().slice(0, 10);
}

export function horaLocal(ms, config) {
  return new Date(ms + config.fusoMinutos * 60_000).getUTCHours();
}

export function dataHora(ms, config) {
  if (!ms) return '—';
  const d = new Date(ms + config.fusoMinutos * 60_000).toISOString();
  return `${d.slice(8, 10)}/${d.slice(5, 7)}/${d.slice(0, 4)} ${d.slice(11, 16)}`;
}

export function dataBr(texto) {
  return texto ? texto.split('-').reverse().join('/') : '';
}

export function validaDia(texto) {
  if (!FORMATO.test(texto ?? '') || Number.isNaN(Date.parse(`${texto}T00:00:00Z`))) return false;
  return new Date(Date.parse(`${texto}T00:00:00Z`)).toISOString().slice(0, 10) === texto;
}

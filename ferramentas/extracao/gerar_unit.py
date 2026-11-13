"""Gera src/jukelinux1_form.inc (campos e eventos publicados do TForm1) e src/jukelinux1_eventos.inc (corpos
vazios dos eventos que ainda não foram reimplementados) a partir de componentes.json (lfm_texto.py).
Os corpos já escritos à mão ficam em src/jukelinux1.pas e os traduzidos do código descompilado em
src/jukelinux1_rotinas.inc (lista em src/rotinas_feitas.txt, de gerar_rotinas.py); este script só gera os que faltam.

Uso: python gerar_unit.py componentes.json src/
"""
import json
import os
import re
import sys

ASSINATURA = {
    'OnMouseDown': '(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer)',
    'OnMouseUp': '(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer)',
    'OnKeyDown': '(Sender: TObject; var Key: Word; Shift: TShiftState)',
    'OnKeyUp': '(Sender: TObject; var Key: Word; Shift: TShiftState)',
    'OnKeyPress': '(Sender: TObject; var Key: Char)',
    'OnClose': '(Sender: TObject; var CloseAction: TCloseAction)',
}


def assinatura(ev):
    if ev['classe'] == 'TShellTreeView' and ev['evento'] == 'OnChange':
        return '(Sender: TObject; Node: TTreeNode)'
    return ASSINATURA.get(ev['evento'], '(Sender: TObject)')


if __name__ == '__main__':
    dados = json.load(open(sys.argv[1], encoding='utf-8'))
    pasta = sys.argv[2]

    # Métodos já implementados à mão em jukelinux1.pas ou traduzidos (não gerar o corpo vazio).
    pas = open(os.path.join(pasta, 'jukelinux1.pas'), encoding='utf-8').read()
    feitos = {m.lower() for m in re.findall(r'^procedure TForm1\.(\w+)', pas, re.M)}
    lista = os.path.join(pasta, 'rotinas_feitas.txt')
    if os.path.exists(lista):
        feitos |= {l.strip().lower() for l in open(lista, encoding='utf-8') if l.strip()}

    metodos = {}
    for ev in dados['eventos']:
        nome = ev['metodo']
        sig = assinatura(ev)
        if nome in metodos and metodos[nome] != sig:
            raise SystemExit(f'evento {nome} usado com assinaturas diferentes')
        metodos[nome] = sig

    with open(os.path.join(pasta, 'jukelinux1_form.inc'), 'w', encoding='utf-8', newline='\n') as f:
        f.write('{ Gerado por ferramentas/extracao/gerar_unit.py a partir do Form1 da JukeLinux original. Não editar. }\n')
        for c in dados['componentes']:
            if c['classe'] == 'TForm1': continue
            f.write(f"    {c['nome']}: {c['classe']};\n")
        for nome in sorted(metodos, key=str.lower):
            f.write(f'    procedure {nome}{metodos[nome]};\n')

    with open(os.path.join(pasta, 'jukelinux1_eventos.inc'), 'w', encoding='utf-8', newline='\n') as f:
        f.write('{ Eventos da original ainda não reimplementados (gerado por gerar_unit.py). Ao escrever um evento em\n'
                '  jukelinux1.pas, rode o gerador de novo para ele sair daqui. }\n\n')
        pend = 0
        for nome in sorted(metodos, key=str.lower):
            if nome.lower() in feitos: continue
            f.write(f'procedure TForm1.{nome}{metodos[nome]};\nbegin\nend;\n\n')
            pend += 1
    print(f'{len(dados["componentes"]) - 1} componentes, {len(metodos)} eventos ({len(metodos) - pend} já escritos, {pend} pendentes)')

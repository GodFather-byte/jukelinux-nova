// Ghidra (headless): descompila as funções da unit jukelinux1 e grava um .c por função.
// Uso: analyzeHeadless <projeto> JukeLinux -import jukelinux -postScript DescompilarJukeLinux.java <pasta-de-saida>
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import java.io.File;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;

public class DescompilarJukeLinux extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        File saida = new File(args.length > 0 ? args[0] : "descompilado");
        File funcoes = new File(saida, "funcoes");
        funcoes.mkdirs();

        DecompInterface dec = new DecompInterface();
        dec.setOptions(new DecompileOptions());
        dec.openProgram(currentProgram);

        int total = 0, falhas = 0;
        try (PrintWriter tudo = new PrintWriter(new File(saida, "jukelinux1-completo.c"), StandardCharsets.UTF_8)) {
            tudo.println("/* JukeLinux (versão de 19/01/2018) - funções da unit jukelinux1.pas descompiladas pelo Ghidra.");
            tudo.println("   É uma reconstrução em C aproximado, não o código Pascal original: serve para entender a lógica. */\n");
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                String nome = f.getName();
                if (!(nome.startsWith("JUKELINUX1_") || nome.contains("_TFORM1_"))) continue;
                if (monitor.isCancelled()) break;
                DecompileResults r = dec.decompileFunction(f, 180, monitor);
                String c = (r != null && r.decompileCompleted()) ? r.getDecompiledFunction().getC()
                        : "/* falhou: " + (r == null ? "?" : r.getErrorMessage()) + " */\n";
                if (r == null || !r.decompileCompleted()) falhas++;
                String arq = nome.replaceAll("[^A-Za-z0-9_]", "_");
                if (arq.length() > 120) arq = arq.substring(0, 120);
                try (PrintWriter w = new PrintWriter(new File(funcoes, arq + ".c"), StandardCharsets.UTF_8)) {
                    w.println("// " + nome + "  @ " + f.getEntryPoint());
                    w.print(c);
                }
                tudo.println("// ===== " + nome + "  @ " + f.getEntryPoint());
                tudo.println(c);
                total++;
                if (total % 20 == 0) println("descompiladas: " + total);
            }
        }
        dec.dispose();
        println("FIM: " + total + " funções descompiladas, " + falhas + " com falha, em " + saida.getAbsolutePath());
    }
}

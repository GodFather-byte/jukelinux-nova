@echo off
rem Analisa o programa jukelinux no Ghidra com a convenção de chamada do Free Pascal/Delphi (__register:
rem EAX, EDX, ECX), para as chamadas aparecerem com os argumentos, e descompila as funções da unit jukelinux1.
set "JAVA_HOME=C:\Users\ITAUTEC\ferramentas\jdk-25.0.5+8"
set "PATH=%JAVA_HOME%\bin;%PATH%"
set "GHIDRA_MAXMEM=3G"
set "JAVA_TOOL_OPTIONS=-Dapplication.settingsdir=C:\Users\ITAUTEC\ferramentas\ghidra-config"
set "BASE=C:\Users\ITAUTEC\Documents\jukelinux-descompilado"
call "C:\Users\ITAUTEC\ferramentas\ghidra_12.2_PUBLIC\support\analyzeHeadless.bat" ^
  "C:\Users\ITAUTEC\ferramentas\projetos-ghidra" JukeLinuxFPC ^
  -import "C:\Users\ITAUTEC\Documents\jukeboxlinux\jukelinux" -overwrite ^
  -processor x86:LE:32:default -cspec borlanddelphi ^
  -scriptPath "%BASE%\ghidra" -postScript DescompilarJukeLinux.java "%BASE%\v2" ^
  -analysisTimeoutPerFile 7200 > "%BASE%\ghidra\analise-fpc.log" 2>&1 < NUL
echo codigo %ERRORLEVEL%

@echo off
rem Analisa o programa jukelinux no Ghidra (sem janela) e descompila as funções da unit jukelinux1.
set "JAVA_HOME=C:\Users\ITAUTEC\ferramentas\jdk-25.0.5+8"
set "PATH=%JAVA_HOME%\bin;%PATH%"
set "GHIDRA_MAXMEM=3G"
rem Configurações do Ghidra fora do perfil roaming (o cache OSGi falhava lá).
set "JAVA_TOOL_OPTIONS=-Dapplication.settingsdir=C:\Users\ITAUTEC\ferramentas\ghidra-config"
set "SAIDA=C:\Users\ITAUTEC\Documents\jukelinux-descompilado"
call "C:\Users\ITAUTEC\ferramentas\ghidra_12.2_PUBLIC\support\analyzeHeadless.bat" ^
  "C:\Users\ITAUTEC\ferramentas\projetos-ghidra" JukeLinux ^
  -import "C:\Users\ITAUTEC\Documents\jukeboxlinux\jukelinux" -overwrite ^
  -scriptPath "%SAIDA%\ghidra" -postScript DescompilarJukeLinux.java "%SAIDA%" ^
  -analysisTimeoutPerFile 5400 > "%SAIDA%\ghidra\analise.log" 2>&1 < NUL
echo codigo %ERRORLEVEL%

@echo off

REM Defina o diretório do compilador MinGW
set MINGW_DIR=C:\Caminho\Para\MinGW

REM Defina o nome do arquivo executável
set EXECUTABLE=programa.exe

REM Comando de compilação
g++ -Iinclude/core src/core/*.cpp src/menu/*.cpp main.cpp -o %EXECUTABLE%

REM Verifique se a compilação foi bem-sucedida
if %errorlevel% neq 0 (
    echo Erro durante a compilação.
    exit /b %errorlevel%
)

REM Comando de execução
.\%EXECUTABLE%

REM Mantenha a janela aberta após a execução (opcional)
pause
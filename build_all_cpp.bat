@echo off
echo Compiling all .cpp files in the current directory...
g++ -g *.cpp -o main.exe
if %errorlevel% neq 0 (
    echo Build failed.
) else (
    echo Build succeeded. Run with: main.exe
)
pause

@echo off
:: ------------------------------------
:: C++ Compiler Check, Build and Run Script
:: ------------------------------------

:: Get the directory of this batch file
set SCRIPT_DIR=%~dp0

:: C++ source file (located in the same folder as this .bat)
set CPP_FILE="%SCRIPT_DIR%main.cpp"

:: Output executable name
set OUTPUT_FILE="UniCode-Converter.exe"

echo Checking for C++ compiler (g++)...

:: Check if g++ is available in PATH
g++ --version >nul 2>&1
if %errorlevel%==0 (
    echo g++ is installed.
    g++ --version
) else (
    echo g++ not found.
    echo.
    echo Please install MinGW / MSYS2 from:
    echo https://www.msys2.org/
    echo Make sure g++ is added to PATH.
    pause
    exit /b
)

:: Compile the C++ source file
echo.
echo Compiling %CPP_FILE% ...
g++ %CPP_FILE% -o %OUTPUT_FILE%

if %errorlevel%==0 (
    echo Compilation successful!
    echo Running program...
    echo.
    %OUTPUT_FILE%
) else (
    echo Compilation failed!
)

pause
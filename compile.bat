@echo off

set SOURCEDIR=src
set SMINCLUDES=src\include
set BUILDDIR=src
set SPCOMP=src\spcomp.exe

:: Make build directory.
if not exist "%BUILDDIR%" (
    mkdir %BUILDDIR%
)

:: Compile.
echo Starting compiler:
%SPCOMP% -i%SOURCEDIR% -i%SOURCEDIR%/include -i%SMINCLUDES% -o%BUILDDIR%/zombieriot.smx %SOURCEDIR%\zombieriot.sp

echo Compiling done. This script is looped, close if you're done.
pause

compile.bat
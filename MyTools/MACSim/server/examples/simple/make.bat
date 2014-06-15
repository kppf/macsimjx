@echo off

echo Building example "simple"...
echo.

set SRC_PATH=.
set SRC_FILES=
set SRC_FILES=%SRC_FILES% %SRC_PATH%\simple.cpp

set MAT_INC=..\..\..\lib\MatrixClassLib\code\include
print MAT_INC
set MACSIM_INC=..\..\include

set LIB_PATH=..\..\bin
set LIB_FILE=macsim.lib

set COMP_FLAGS=-w- -v

set OUT_PATH=.\

bcc32 %COMP_FLAGS% -n%OUT_PATH% -I%MACSIM_INC% -I%MAT_INC% -L%LIB_PATH% %SRC_FILES% %LIB_FILE%

if %errorlevel%==0 goto rm
goto end

:rm
del *.obj
del *.tds

:end
echo Done.

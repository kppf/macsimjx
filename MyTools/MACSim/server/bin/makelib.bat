@echo off

echo Building MACSim Server Library...
echo.

set SRC_PATH=..\src
set SRC_FILES=
set SRC_FILES=%SRC_FILES% %SRC_PATH%\macsim.cpp
set SRC_FILES=%SRC_FILES% %SRC_PATH%\server.cpp
set SRC_FILES=%SRC_FILES% %SRC_PATH%\thread.cpp

set MAT_PATH=..\..\lib\MatrixClassLib\code\src
set MAT_FILES=
set MAT_FILES=%MAT_FILES% %MAT_PATH%\matrix.cpp
set MAT_FILES=%MAT_FILES% %MAT_PATH%\matrix_operator.cpp
set MAT_FILES=%MAT_FILES% %MAT_PATH%\matrix_access.cpp

set MAT_INC=..\..\lib\MatrixClassLib\code\include

set COMP_FLAGS=-c -w- -v

set OUT_PATH=.\

bcc32 %COMP_FLAGS% -n%OUT_PATH% -I%MAT_INC% %SRC_FILES% %MAT_FILES%

if %errorlevel%==0 goto lib
goto end

:lib
set OUT_FILE=%OUT_PATH%macsim.lib

set LIB_OPT=-+

if exist %OUT_FILE% goto lib_exists
set LIB_OPT=+
:lib_exists

set SRC_PATH=.
set SRC_FILES=
set SRC_FILES=%SRC_FILES% %LIB_OPT%%SRC_PATH%\macsim.obj
set SRC_FILES=%SRC_FILES% %LIB_OPT%%SRC_PATH%\server.obj
set SRC_FILES=%SRC_FILES% %LIB_OPT%%SRC_PATH%\thread.obj

set MAT_PATH=.
set MAT_FILES=
set MAT_FILES=%MAT_FILES% %LIB_OPT%%MAT_PATH%\matrix.obj
set MAT_FILES=%MAT_FILES% %LIB_OPT%%MAT_PATH%\matrix_operator.obj
set MAT_FILES=%MAT_FILES% %LIB_OPT%%MAT_PATH%\matrix_access.obj

set LIB_FLAGS=/P32

tlib %LIB_FLAGS% %OUT_FILE% %SRC_FILES% %MAT_FILES%

if %errorlevel%==0 goto rm
goto end

:rm
del *.obj

:end
echo Done.

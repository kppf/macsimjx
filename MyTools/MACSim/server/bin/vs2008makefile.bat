rem ------start of vs2008makefile.bat--------------------------

@echo off
:: Load compilation environment
call "C:\Program Files\Microsoft Visual Studio 9.0\VC\vcvarsall.bat"

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

::Matrix.cpp
set NEW_PATH=C:\macsimjx\MyTools\MACSim\lib\MatrixClassLib\code\src

::matrix.obj
set NEW_PATH2=C:\macsimjx\MyTools\MACSim\server\bin

::matrix.h
set NEW_PATH3=C:\macsimjx\MyTools\MACSim\lib\MatrixClassLib\code\include

set OTHER=C:\Program Files\Microsoft Visual Studio 9.0\

set NEW_FILE=C:\macsimjx\MyTools\MACSim\server\include\macsim.h

:: Invoke compiler with any options passed to this batch file 
rem CL [option...] file... [option | file]... [lib...] [@command-file] [/link link-opt...]
rem /c create .obj files without linking. /EHsc to enable unwind semantics

:: may need /I C:\macsimjx\MyTools\MACSim\lib\SimClassLib\code\include\sim.h

"C:\Program Files\Microsoft Visual Studio 9.0\VC\bin\cl.exe" /EHsc /c /I %MAT_INC% %SRC_FILES% %MAT_FILES% /I %NEW_PATH% /I %NEW_PATH2% /I %NEW_PATH3% /I C:\macsimjx\MyTools\MACSim\lib\MatrixClassLib\code\src\matrix.cpp 

rem ------------------------------------------------------------

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



:: Compile macsim library
"C:\Program Files\Microsoft Visual Studio 9.0\VC\bin\lib.exe" /MACHINE:X86 /OUT:macsim.lib %SRC_FILES% %MAT_FILES%

pause 

rem ---------end of .bat----------------------------------------
@echo off
:: Load compilation environment
call "C:\Program Files\Microsoft Visual Studio 9.0\VC\vcvarsall.bat"

set SRC_PATH=src\
set SRC_FILES=
set SRC_FILES=%SRC_FILES% %SRC_PATH%\matrix.cpp
set SRC_FILES=%SRC_FILES% %SRC_PATH%\matrix_operator.cpp
set SRC_FILES=%SRC_FILES% %SRC_PATH%\matrix_access.cpp

"C:\Program Files\Microsoft Visual Studio 9.0\VC\bin\cl.exe" /EHsc /c /I %SRC_FILES%

rem Old code: bcc32 example.cpp src/matrix.cpp src/matrix_operator.cpp src/matrix_access.cpp
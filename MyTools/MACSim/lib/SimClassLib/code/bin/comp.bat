@echo off

echo Compiling Object Files...
echo.

set MATLAB=C:\MATLABR11
::set MATLAB=C:\Progra~1\MATLABR11

set SIM_PATH=..\src
set SIM_FILES=
set SIM_FILES=%SIM_FILES% %SIM_PATH%\sim_functions.cpp
set SIM_FILES=%SIM_FILES% %SIM_PATH%\sim_class.cpp
set SIM_FILES=%SIM_FILES% %SIM_PATH%\sim_interface_container.cpp
set SIM_FILES=%SIM_FILES% %SIM_PATH%\sim_interface.cpp
set SIM_FILES=%SIM_FILES% %SIM_PATH%\sim_exception.cpp
set SIM_FILES=%SIM_FILES% %SIM_PATH%\sim_vector.cpp

set MAT_PATH=..\..\..\MatrixClassLib\code\src
set MAT_FILES=
set MAT_FILES=%MAT_FILES% %MAT_PATH%\matrix.cpp
set MAT_FILES=%MAT_FILES% %MAT_PATH%\matrix_operator.cpp
set MAT_FILES=%MAT_FILES% %MAT_PATH%\matrix_access.cpp

set COMP_FLAGS=-c -w- -v

set OUT_PATH=.\

set MATLAB_DEF=MATLAB_MEX_FILE
set MATLAB_INC=%MATLAB%\extern\include
set SIMULINK_INC=%MATLAB%\simulink\include

bcc32 %COMP_FLAGS% -n%OUT_PATH% -D%MATLAB_DEF% -I%MATLAB_INC% -I%SIMULINK_INC% %SIM_FILES% %MAT_FILES%

if %NO_PAUSE%==none goto no_pause
pause
:no_pause

echo.

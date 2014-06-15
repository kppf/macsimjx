@echo off

echo Creating Library...
echo.

set OUT_PATH=.
set OUT_FILE=%OUT_PATH%\sim.lib

set LIB_OPT=-+

if exist %OUT_FILE% goto lib_exists
set LIB_OPT=+
:lib_exists

set SIM_PATH=.
set SIM_FILES=
set SIM_FILES=%SIM_FILES% %LIB_OPT%%SIM_PATH%\sim_functions.obj
set SIM_FILES=%SIM_FILES% %LIB_OPT%%SIM_PATH%\sim_class.obj
set SIM_FILES=%SIM_FILES% %LIB_OPT%%SIM_PATH%\sim_interface_container.obj
set SIM_FILES=%SIM_FILES% %LIB_OPT%%SIM_PATH%\sim_interface.obj
set SIM_FILES=%SIM_FILES% %LIB_OPT%%SIM_PATH%\sim_exception.obj
set SIM_FILES=%SIM_FILES% %LIB_OPT%%SIM_PATH%\sim_vector.obj

set MAT_PATH=.
set MAT_FILES=
set MAT_FILES=%MAT_FILES% %LIB_OPT%%MAT_PATH%\matrix.obj
set MAT_FILES=%MAT_FILES% %LIB_OPT%%MAT_PATH%\matrix_operator.obj
set MAT_FILES=%MAT_FILES% %LIB_OPT%%MAT_PATH%\matrix_access.obj

set LIB_FLAGS=/P32

tlib %LIB_FLAGS% %OUT_FILE% %SIM_FILES% %MAT_FILES%

if %NO_PAUSE%==none goto no_pause
pause
:no_pause

echo.

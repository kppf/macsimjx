@echo off

set NO_PAUSE=none

call comp.bat
call lib.bat

if not exist %OUT_FILE% goto no_outfile
del *.obj
:no_outfile

pause
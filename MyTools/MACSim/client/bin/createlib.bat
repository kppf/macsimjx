echo off

rem At cmd type "createlib nameOfDll" 
rem without quotes and replace nameOfDll appropriately 
rem e.g. createlib libmx 
rem
rem N.B. To generate MS Visual Studio lib file, requires perl.exe, adjust 
rem each rem below and use the visual studio tools cmd prompt.


cd C:\macsimjx\MyTools\MACSim\client\bin


IF (%1)==() GOTO error

:setup
SET "%1=libmx"

IF NOT EXIST %1.dll GOTO error2

:main

rem ---Generate .lib file for Borland Compiler---
rem borland method to generate .def from .dll (if you require this intermedary stage):
IMPDEF -a %1.def %1.dll

rem remove symbolically decorated functions not understood by borland compiler (intermediary stage 2):
"C:\Program Files\MATLAB\R2009a\sys\perl\win32\bin\perl.exe" removeSymbols.pl --opt1="%1"

rem generate lib file from definition for borland compiler (intermediary stage 3):
C:\Borland\BCC55\Bin\implib.exe -c -f %1.lib %1.def

rem As above, but skipping intermediary stage (does not work if symbolic decorations present).
rem implib -f -c %1.lib %1.dll


rem ---Generate .lib file for MS Visual Studio---
rem visual studio method to generate .def from .dll:
rem dumpbin /exports %1.dll > %1.txt

rem Extract relevant data from txt file and create .def:
rem C:\MATLAB\R2009b\sys\perl\win32\bin\perl.exe extractCol.pl --opt1="%1"

rem Use following to create ms visual studio lib file: 
rem lib /def:%1.def /out:%1.lib /machine:x86


GOTO end


:error
echo No file name supplied. Type createlib followed by name of dll.
GOTO end


:error2
echo Could not locate %1.dll.

:end


rem This method seems to produce warnings about duplicate symbols.  Perhaps best method
rem is to generate the .def file using microsoft visual studio and then use borland to
rem compile the .def into the .lib.


rem The following generates the lib without the intermediate step for borland:

rem implib -f msvcrt.lib msvcrt.dll

rem (source:http://thaines.net/content/programming/blfs/)
rem "However, whilst this will work for some programs there is a gotcha. msvcrt.dll only 
rem exports a certain set of C library routines, whilst the borland one, cw32mt.lib, 
rem exports another set. The msvcrt set then hide the borland set, except for the functions 
rem borland provides which m$ dosn't. This could potentially catch you out, and whilst I didn't 
rem determine why causes the program which drove this aricle to crash. (If my memory serves me 
rem correctly it was related to replacing the borland malloc/free etc with the m$ one, didn't 
rem like it for some reason.) This is why I go to the effort of an intermediate .def, which I 
rem prune down to just the file IO functions so it does not hide the other borland functions."
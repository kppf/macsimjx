@echo off

echo Building example "simple"...

set SRC_PATH=.
set SRC_FILES=
set SRC_FILES=%SRC_FILES% %SRC_PATH%\simple.java

set JAR_PATH=../../bin
set JAR_FILE=macsim.jar

javac -classpath %JAR_PATH%/%JAR_FILE% %SRC_FILES%

:end
echo Done.

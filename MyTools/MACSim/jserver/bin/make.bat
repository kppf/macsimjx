@echo off

set BIN_PATH=../bin
set INC_PATH=../include
set JAVA_SRC_PATH=../src.java
set CPP_SRC_PATH=..\src.cpp

set JAVA_SRC_FILES=
set JAVA_SRC_FILES=%JAVA_SRC_FILES% macsim/MACSimServer.java

set JAVA_NATIVE_FILES=
set JAVA_NATIVE_FILES=%JAVA_NATIVE_FILES% macsim.internal.Server
set JAVA_NATIVE_FILES=%JAVA_NATIVE_FILES% macsim.internal.ConfigServer
set JAVA_NATIVE_FILES=%JAVA_NATIVE_FILES% macsim.internal.SimServer

set CPP_SRC_FILES=
set CPP_SRC_FILES=%CPP_SRC_FILES% %CPP_SRC_PATH%\Server.cpp
set CPP_SRC_FILES=%CPP_SRC_FILES% %CPP_SRC_PATH%\ConfigServer.cpp
set CPP_SRC_FILES=%CPP_SRC_FILES% %CPP_SRC_PATH%\SimServer.cpp
set CPP_SRC_FILES=%CPP_SRC_FILES% %CPP_SRC_PATH%\ServerUtil.cpp

set JAVA_INC="C:\Program Files\Java\jdk1.6.0_18\include"
set JAVA_WIN32_INC="C:\Program Files\Java\jdk1.6.0_18\include\win32"

set COMP_FLAGS=-WDR -w- -v

set DLL_FILE=MACSimServer.dll

set JAR_FILE=macsim.jar
set JAR_PATH=macsim

cd %JAVA_SRC_PATH%
echo Compiling Java files
javac -d %BIN_PATH% %JAVA_SRC_FILES% -classpath .
cd %BIN_PATH%

if %ERRORLEVEL%==0 goto jni
goto end

:jni
echo Generating Native header files
javah -d %INC_PATH%  -classpath . -jni %JAVA_NATIVE_FILES%

if %ERRORLEVEL%==0 goto bcc
goto end

:bcc
echo Compiling C++ files
bcc32 %COMP_FLAGS% -I%JAVA_INC% -I%JAVA_WIN32_INC% %CPP_SRC_FILES%

if %errorlevel%==0 goto rm
goto end

:rm
ren Server.dll %DLL_FILE%
del *.obj
del *.tds

if not exist %JAR_FILE% goto cjar
del %JAR_FILE%

:cjar
echo Creating JAR file
jar cf %JAR_FILE% %JAR_PATH% %DLL_FILE%

if %errorlevel%==0 goto dtree
goto end

:dtree
rmdir /s /q macsim
del %DLL_FILE%

:end
echo Done.

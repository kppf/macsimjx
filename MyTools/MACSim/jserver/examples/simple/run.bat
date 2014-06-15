@echo off

set JAR_PATH=../../bin/macsim.jar
set RUN_FILE=Simple

java -classpath .;%JAR_PATH% %RUN_FILE%

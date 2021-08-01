@echo off
echo Compiling Tool...
g++ writepath.cpp -o writepath.exe
echo Finished.
cd > info.txt
writepath.exe
echo Compiling iPac...
g++ ipac.cpp -o ipac.exe -I .
echo Finished.
ipac

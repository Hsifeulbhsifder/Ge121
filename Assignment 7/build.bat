@echo off

pushd "%~dp0"

set SRC=A7Q3

x86_64-w64-mingw32-g++ -m32 -mwindows "-Iccc3e/cccfiles" %SRC%.cpp -o %SRC% -g
rem g++ %SRC%.cpp -o %SRC% -g -Wall

Call %SRC%

popd
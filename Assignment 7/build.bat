@echo off

pushd "%~dp0"

set SRC=A7Q1

rem x86_64-w64-mingw32-g++ -m32 -mwindows "-Iccc3e/cccfiles" %SRC%.cpp -o %SRC% -g
g++ %SRC%.cpp -o %SRC% -g -Wall

Call %SRC%

popd
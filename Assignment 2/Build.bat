@echo off

set SRC=stones

g++ %SRC%.cpp -o %SRC% -g -Wall

rem Call %SRC%
@echo off

set SRCS=A6Q2

g++ -std=gnu++11 %SRCS%.cpp -o %SRCS% -g -Wall

rem Call %SRCS%
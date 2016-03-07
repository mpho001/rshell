#!/bin/sh

cd ..
cd src

echo test | ./a.out
echo test -e | ./a.out
echo test main.cpp | ./a.out
echo test -e main.cpp | ./a.out
echo test -f | ./a.out
echo test -f main.cpp | ./a.out
echo test -d | ./a.out
echo test -d main.cpp | ./a.out
echo test -e wrong | ./a.out
echo test -f notfile | ./a.out
echo test -d dir | ./a.out
echo "[ ]" | ./a.out
echo "[ -e ]" | ./a.out
echo "[ -e main.cpp ]" | ./a.out
echo "[ -e not ]" | ./a.out
echo "[ -f ]" | ./a.out
echo "[ -f main.cpp ]" | ./a.out
echo "[ -f notfile ]" | ./a.out
echo "[ -d ]" | ./a.out
echo "[ -d notdir ]" | ./a.out
echo test -e /home/csmajs/mpho001/rshell/src/main.cpp | ./a.out
echo test -d /home/csmajs/mpho001/rshell/src | ./a.out
echo test -d /home/csmajs/mpho001/rshell/fake | ./a.out
echo test -f /home/csmajs/mpho001/rshell | ./a.out
echo test -f /home/csmajs/mpho001/rshell/Connector.cpp | ./a.out

#!/bin/sh
# this script tests out commented commands

# goes to the src directory
cd ..
cd src

echo echo "hello #world" | ./a.out
echo echo "#you suck" | ./a.out
echo "ls#-a" | ./a.out
echo ls -a "#echo this" | ./a.out
echo "#" | ./a.out
echo date# "$$ random command" | ./a.out

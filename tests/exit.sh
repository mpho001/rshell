#!/bin/sh

# tests the exit command
cd ..
cd src

echo "exit" | ./a.out
echo "echo hello && exit" | ./a.out
echo "exit || echo hello" | ./a.out
echo "echo this || exit" | ./a.out
echo "date || echo hello && exit" | ./a.out
echo "dat || exit" | ./a.out
echo "     exit" | ./a.out
echo "(fail || (date && exit))" | ./a.out
echo "fail || exit" | ./a.out
echo "(echo world && exit)" | ./a.out
echo "(exit)" | ./a.out
echo "(exit;) || fail" | ./a.out
echo "(fail || (echo world && exit))" | ./a.out
echo "( (echo hello || exit) && (date) ) || exit" | ./a.out

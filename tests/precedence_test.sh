#!/bin/sh

cd ..
cd src

echo "(echo hello)" | ./a.out
echo "(echo hello) && (echo this)" | ./a.out
echo "(echo hello) || (echo this)" | ./a.out
echo "(fail) && (echo this)" | ./a.out
echo "(fail) || (echo this)" | ./a.out
echo "(date && echo hello) || (ls)" | ./a.out
echo "(date || fail) && echo hello" | ./a.out
echo "(ls;)" | ./a.out
echo "(ls);" | ./a.out
echo "(echo" | ./a.out
echo "( (echo hello || date) && (echo world && (echo peace || ls)) )" | ./a.out
echo "( test -e main.cpp )" | ./a.out
echo "( [ test -e main.cpp ] )" | ./a.out
echo "( test -e main.cpp && date) || test" | ./a.out
echo "(ls; date; echo hello;)" | ./a.out
echo "(ls; date; echo hello;) || echo this" | ./a.out
echo "(ls; date) && fail" | ./a.out
echo "((ls))" | ./a.out
echo "(echo world && (echo this" | ./a.out
echo "(((echo)))" | ./a.out
echo "( test -e main.cpp" | ./a.out
echo "( test -e fake || test -f main.cpp) && (date;)" | ./a.out
echo "( [ -f main.cpp ] && (date || fail) )" | ./a.out
echo "( fail || test -e) && (test -f main.cpp || date)" | ./a.out
echo "echo hi && ((echo two || echo pringles)" | ./a.out

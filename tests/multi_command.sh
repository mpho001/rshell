#!/bin/sh

cd ..
cd src

echo "echo hello && echo this" | ./a.out
printf "\n"
echo "ls && echo this && echo that && date;" | ./a.out
printf "\n"
echo "date || echo shouldn't; && echo should" | ./a.out
printf "\n"
echo "fail && ec; echo definitely" | ./a.out
printf "\n"
echo "ls -a; echo hello; date" | ./a.out
printf "\n"
echo "ls -a; echo hello && echo world || echo cool; git status" | ./a.out
printf "\n"
echo "ech oops || echo it's ok && date; echo you" | ./a.out
printf "\n"
echo "ech oops; ech oops; ech oops; date" | ./a.out
printf "\n"
echo "date && echo hmm &&" | ./a.out
printf "\n"
echo "echo        hello || echo soa; date;" | ./a.out
printf "\n"
echo "dat || ehc || date; echo top && no" | ./a.out

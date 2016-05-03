#!/bin/bash
nasm -felf64 madlibs.asm
gcc madlibs.o madlib-by-numbers.c -std=c99
./a.out "0 1 2" string0 string1 string2
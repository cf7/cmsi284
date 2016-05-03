#!/bin/bash
nasm -felf64 madlibs.asm
gcc madlibs.o madlib-by-numbers.c -std=c99
./a.out "string 1" string2 string3
#!/bin/bash
nasm -felf64 calc-ops.asm
gcc calc-ops.o gcd.c
./a.out 1 2
gcc calc-ops.o add.c
./a.out 1 2
gcc calc-ops.o mod.c
./a.out 1 2
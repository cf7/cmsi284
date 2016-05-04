#!/bin/bash
nasm -felf64 calc-ops.asm
gcc calc-ops.o gcd.c
./a.out 1 2
./a.out 64 16
./a.out 128 64
./a.out 0 0
gcc calc-ops.o add.c
./a.out 1 2
./a.out 10 10
./a.out 100 100
gcc calc-ops.o mod.c
./a.out 1 2
./a.out 5 3
./a.out 3 5
./a.out 100 101
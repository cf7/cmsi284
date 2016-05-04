#!/bin/bash
nasm -felf64 rev-echo.asm
gcc rev-echo.o reverse-range-in-place.c -std=c99
./a.out hello, this is a sentence
./a.out       does it look     for spaces
./a.out  12345678910
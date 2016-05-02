#!/bin/bash
nasm -felf64 calc-ops.asm
gcc calc-ops.o calc-ops.c
./a.out
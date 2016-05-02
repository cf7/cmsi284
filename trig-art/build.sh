#!/bin/bash
nasm -felf64 trig-art.asm
gcc trig-art.o -lm
./a.out
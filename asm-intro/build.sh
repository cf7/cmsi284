#!/bin/bash
nasm -felf64 make-change.asm
gcc make-change.o
./a.out 100
./a.out 65
./a.out 15
./a.out 35
./a.out 71
nasm -felf64 leap-year.asm
gcc leap-year.o
./a.out 2016
./a.out 2017
./a.out 2018
./a.out 2019
./a.out 2020
./a.out 2021
./a.out 2022
./a.out 2023
./a.out 2024
./a.out 2025
./a.out 2026
./a.out 2027
./a.out 2028
./a.out 2029
./a.out 2030
./a.out 2031
./a.out 2032
nasm -felf64 sys-calls.asm
gcc sys-calls.o
./a.out leap-year.asm
date +%s
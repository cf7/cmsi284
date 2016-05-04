#include <stdio.h>
#include "madlib-by-numbers.h"

int main(int argc, char* argv[]) {
    printf("%s\n", madlib_by_numbers(argv[1], argc - 2, &argv[2]));
    return 0;
}
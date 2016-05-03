#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int64_t gcd(int64_t x, int64_t y);

int main(int argc, char** argv) {
    if (argc == 3) {
        char *input1 = argv[1];
        char *input2 = argv[2];

        int x = atoi(input1);
        int y = atoi(input2);

        printf("gcd(%d, %d) = %ld\n", x, y, gcd(x, y));

    } else {
        perror("Please input exactly two arguments");
    }

}
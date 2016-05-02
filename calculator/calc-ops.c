#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int64_t gcd(int64_t x, int64_t y);
int64_t add(int64_t x, int64_t y);
int64_t mod(int64_t x, int64_t y);

int main() {
    printf("gcd(%d, %d) = %ld\n", 1, 2, gcd(1, 2));
    printf("add(%d, %d) = %ld\n", 1, 2, add(1, 2));
    printf("mod(%d, %d) = %ld\n", 1, 2, mod(1, 2));
}
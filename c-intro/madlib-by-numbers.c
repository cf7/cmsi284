#include <stdio.h>  // %s - strings, %p - pointer
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

char *numbers[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
long numbersLength = sizeof(numbers) / sizeof(numbers[0]);
int ascii[10] = { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57 };



char* madlib_by_numbers(char* template, int word_count, char* words[]) {
    char* newString;

    printf("%s\n", template);
    
    // returns a pointer to the matching byte
    char *p = memchr(template, '1', strlen(template));
    printf("%s\n", p);
    // returns a segfault
    return newString;
}
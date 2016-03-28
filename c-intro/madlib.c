// screencast 3/10 at 32:30

#include <stdio.h>  // %s - strings, %p - pointer
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

char* madlib(char* template, char* adjective, char* noun, char* verb) {
    printf("%s\n", "inside");
    char *newString = malloc(100);
    printf("%s\n", "after newString");
    printf("%s\n", template);
    sprintf(newString, template, adjective, noun, verb);
    printf("%s\n", "after sprintf");
    printf("%s\n", newString);
    free(newString);
    return newString;
}
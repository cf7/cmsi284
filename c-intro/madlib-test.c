#include <stdio.h>  // %s - strings, %p - pointer
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "madlib.h"
// gcc madlib-test.c madlib.c

int main() {
    printf("%s\n", "Testing madlibs from Problem 3");

    char* string = madlib("How much %s could a %s %s?", "wood", "woodchuck", "chuck");
    assert(!strcmp(string, "How much wood could a woodchuck chuck?"));
    free(string);

    char* string2 = madlib("%s %s %s", "brilliant", "git", "swim");
    assert(!strcmp(string2, "brilliant git swim"));
    free(string2);

    char* string3 = madlib("The %s %s likes to %s in the moonlight.", "brilliant", "git", "swim");
    assert(!strcmp(string3, "The brilliant git likes to swim in the moonlight."));
    free(string3);
    
    printf("%s\n", "End of tests");
}
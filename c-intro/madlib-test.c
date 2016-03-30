#include <stdio.h>  // %s - strings, %p - pointer
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "madlib.h"
// gcc madlib-test.c madlib.c

int main() {
    printf("%s\n", "Testing madlibs from Problem 3");

    assert(!strcmp(madlib("How much %s could a %s %s?", "wood", "woodchuck", "chuck"), "How much wood could a woodchuck chuck?"));

    assert(!strcmp(madlib("%s %s %s", "brilliant", "git", "swim"), "brilliant git swim"));

    assert(!strcmp(madlib("The %s %s likes to %s in the moonlight.", "brilliant", "git", "swim"), "The brilliant git likes to swim in the moonlight."));

    printf("%s\n", "End of tests");
}
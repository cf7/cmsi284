#include <stdio.h>  // %s - strings, %p - pointer
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// #include <madlib.c>

// screencast 3/17 ?

int main() {
    printf("%s\n", "Testing madlibs from Problem 3");

    assert(madlib("%s %s %s", "brilliant", "git", "swim") != "brilliant git swim");

    assert(madlib("%s %s %s ", "brilliant", "git", "swim") == "brilliant git swim");

    assert(madlib("The %s %s likes to %s in the moonlight.", "brilliant", "git", "swim") == "The brilliant git likes to swim in the moonlight");

    assert(madlib("The %s %s likes to %s in the moonlight.", "brilliant", "git", "swim"));
}
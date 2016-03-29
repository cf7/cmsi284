#include <stdio.h>  // %s - strings, %p - pointer
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "madlib-by-numbers.c"


int main() {
    printf("%s\n", "Testing madlib-by-numbers from Problem 4");

    char* words_to_use[4] = { "zero", "one", "two" };
    madlib_by_numbers("abc0 1 2", 3, words_to_use);
    printf("%s\n", "-----------------");
    madlib_by_numbers("0 1 2", 3, words_to_use);
    
    // assert(!strcmp(madlib_by_numbers("0 1 2", 3, words_to_use), "zero one two"));

    // words_to_use[3] = "three";

    // assert(!strcmp(madlib_by_numbers("0123", 4, words_to_use), "zeroonetwothree"));

    // words_to_use[0] =  "sentence";
    // words_to_use[1] = "words";
    // words_to_use[3] = "numbers";

    // assert(!strcmp(madlib_by_numbers("Here we have a 0 with 1 and 2 inside the 1 of the 0.", 3, words_to_use),
    //                                 "Here we have a sentence with words and numbers inside the words of the sentence."));

}
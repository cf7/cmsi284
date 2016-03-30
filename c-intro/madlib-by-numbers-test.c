#include <stdio.h>  // %s - strings, %p - pointer
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "madlib-by-numbers.h"
// gcc madlib-by-numbers-test.c madlib-by-numbers.c

/**
    free all return values from madlib_by_numbers
*/
int main() {

    printf("%s\n", "Testing madlib-by-numbers from Problem 4");

    char* words_to_use[4] = { "zero", "one", "two" };

    char* string = madlib_by_numbers("abc0 1 2", 3, words_to_use);
    assert(!strcmp(string, "abczero one two"));
    free(string);

    char* string2 = madlib_by_numbers("0 1 2", 3, words_to_use);
    assert(!strcmp(string2, "zero one two"));
    free(string2);

    words_to_use[3] = "three";

    char* string3 = madlib_by_numbers("0123", 4, words_to_use);
    assert(!strcmp(string3, "zeroonetwothree"));
    free(string3);

    words_to_use[0] =  "sentence";
    words_to_use[1] = "words";
    words_to_use[2] = "numbers";

    char* string4 = madlib_by_numbers("Here we have a 0 with 1 and 2 inside the 1 of the 0.", 4, words_to_use);
    assert(!strcmp(string4, "Here we have a sentence with words and numbers inside the words of the sentence."));
    free(string4);

    char* more_words[10] = { "verb", "noun", "adjective" };
    more_words[8] = "subject";
    more_words[9] = "predicate";

    char* string5 = madlib_by_numbers("Where shall we place the 0 and the 1? Can they be accompanied by an 2? Which part of the sentence is the 8 and which is the 9?", 10, more_words);
    assert(!strcmp(string5, "Where shall we place the verb and the noun? Can they be accompanied by an adjective? Which part of the sentence is the subject and which is the predicate?"));
    free(string5);

    // with numbers that do not have corresponding words in more_words
    // madlib_by_numbers should ignore them
    char* string6 = madlib_by_numbers("0 1 2 8 9 7 6 5 4", 10, more_words);
    assert(!strcmp(string6, "verb noun adjective subject predicate 7 6 5 4"));
    free(string6);

    char* string7 = madlib_by_numbers("Where shall 7we place the 0 and the 1? Can they be 45accompanied by an 2? Which part of the 36sentence is the 8 and which is the 9?", 10, more_words); 
    assert(!strcmp(string7, "Where shall 7we place the verb and the noun? Can they be 45accompanied by an adjective? Which part of the 36sentence is the subject and which is the predicate?"));
    free(string7);
    
    printf("%s\n", "End of tests");
}
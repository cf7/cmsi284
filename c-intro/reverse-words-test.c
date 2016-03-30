#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "reverse-words.c"

int main() {
    printf("%s\n", "Testing reverse_words from Problem 5");

    // // reverse_range_in_place requires word[] instead of char* word
    // char word[] = "0";
    // // reverse_words(word);
    // // assert(!strncmp(word, "0", strlen(word)));

    // char word1[] = "reverse";
    // reverse_words(word1);
    // // assert(!strncmp(word1, "reverse", strlen(word1)));

    // char word2[] = "this";
    // reverse_words(word2);
    // // assert(!strncmp(word, "this", strlen(word)));

    // // word = "0 1 2 3 4 5 6 7 8 9";
    // // reverse_words(word);
    // // assert(!strncmp(word, "9 8 7 6 5 4 3 2 1", strlen(word)));

    char word4[] = "This is a sentence.";
    reverse_words(word4);
    assert(!strncmp(word4, "sentence. a is This", strlen(word4)));

    // word = "This is a really long sentence to make sure there is enough space allocated.";
    // reverse_words(word);
    // assert(!strncmp(word, "allocated. space enough is there sure make to sentence long really a is This", strlen(word)));

    // word = "";
    // reverse_words(word);
    // assert(!strncmp(word, "", strlen(word)));

    printf("%s\n", "End of tests");
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "reverse-words.c"

int main() {
    printf("%s\n", "Testing reverse_words from Problem 5");

    char* word = "0";
    reverse_words(word);
    assert(!strncmp(word, "0", strlen(word)));

    word = "reverse";
    reverse_words(word);
    assert(!strncmp(word, "reverse", strlen(word)));

    word = "this";
    reverse_words(word);
    assert(!strncmp(word, "this", strlen(word)));

    word = "0 1 2 3 4 5 6 7 8 9";
    reverse_words(word);
    assert(!strncmp(word, "9 8 7 6 5 4 3 2 1", strlen(word)));

    word = "This is a sentence.";
    reverse_words(word);
    assert(!strncmp(word, "sentence. a is This", strlen(word)));

    word = "This is a really long sentence to make sure there is enough space allocated.";
    reverse_words(word);
    assert(!strncmp(word, "allocated. space enough is there sure make to sentence long really a is This", strlen(word)));

    // word = "";
    // reverse_words(word);
    // assert(!strncmp(word, "", strlen(word)));

    printf("%s\n", "End of tests");
}
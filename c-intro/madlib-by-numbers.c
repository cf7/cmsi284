#include <stdio.h>  // %s - strings, %p - pointer
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

char *numbers[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
long numbersLength = sizeof(numbers) / sizeof(numbers[0]);
int ascii[10] = { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57 };

char* process_String(char* template, char* words[]) {
    char *p = memchr(template, '0', strlen(template));
    // chop off the zero after finding it
    p = memchr(p, p[1], strlen(p));
    char* word = malloc(sizeof(words[0]) + sizeof(p));
    strcpy(word, words[0]);
    strcat(word, p);
    printf("%s\n", word);
    free(word);
    return word;
}

char* madlib_by_numbers(char* template, int word_count, char* words[]) {
    char* newString;
    printf("%s\n", template);
    process_String(template, words);
    // returns a pointer to the matching byte
    

    /**
        "0 1 2"
        "word"
        
        identify which number is next
        use memchr to find first occurrence
        shift memory space of char array
        insert new word
        recursively return string
    */

    // returns a segfault
    return newString;
}
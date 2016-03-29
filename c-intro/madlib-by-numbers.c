#include <stdio.h>  // %s - strings, %p - pointer
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

char numbers[10] = {'0','1','2','3','4','5','6','7', '8','9' };
long numbersLength = sizeof(numbers) / sizeof(numbers[0]);
int ascii[10] = { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57 };

int parseCharToInt(char c) {
    return c - '0';
}

void process_String(char* string, char number, char* words[]) {
    char *p = memchr(string, number, strlen(string));
    printf("p before: %s\n", p);
    if (p != NULL) {
        char *p2 = malloc(strlen(string));
        strcpy(p2, memchr(string, number, strlen(string)));
        
        printf("p2 just just before: %s\n", p2);
        // chop off the zero after finding it
        if (strlen(p2) > 1) {
            p2 = memchr(p2, p2[1], strlen(p2));
            if (p2 != NULL) {
                printf("%s\n", "just before");
                printf("p2 before %s\n", p2);
                // check for null, if not found memchr returns null
                // ** taking sizeof(string) is returning sizeof a pointer!
                // ** need to store size of string array separately
                char* word = malloc(strlen(words[parseCharToInt(number)]));
                strcpy(word, words[parseCharToInt(number)]);
                // if segfaulting here, probably because not enough memory allocated for word
                strcat(word, p2); // double copying here
                strcpy(p, word);
                printf("p2 after %s\n", p2);
                printf("word: %s\n", word);
                free(word);
            }
        } else {
            char* word = malloc(strlen(words[parseCharToInt(number)]));
            strcpy(word, words[parseCharToInt(number)]);
            strcpy(p, word);
            free(word);
        }
        // free(p2); // for some reason it says p2 isn't being allocated and thus does not need to be freed
    }
}

bool numbersPresent(char* string) {
    bool nums = false;
    for (int index = 0; index < strlen(string); index++) {
        for (int index2 = 0; index2 < numbersLength; index2++) {
            if (string[index] == numbers[index2]) {
                nums = true;
            }
        }
    }
    return nums;
}

char* madlib_by_numbers(char* template, int word_count, char* words[]) {

    printf("size %ld\n", sizeof(template) + sizeof(*words) * word_count);
    char *newString = malloc(strlen(template) + strlen(*words) * word_count);
    strcpy(newString, template);
    printf("template: %s\n", template);

    printf("%s\n", numbersPresent(newString) ? "true" : "false");

    // printf("size of word: %s\n", newString);
    // printf("%ld\n", strlen(newString));
    // hardcoding for now
    int index = 0;
    while (numbersPresent(newString)) {
        process_String(newString, numbers[index], words);
        printf("newString outside: %s\n", newString);
        if (index >= numbersLength) {
            index = 0;
        } else {
            index++;
        }
    }

    // process_String(newString, numbers[0], words);
    // printf("newString outside: %s\n", newString);

    // process_String(newString, numbers[1], words);
    // printf("newString outside: %s\n", newString);

    // process_String(newString, numbers[2], words);
    // printf("newString outside: %s\n", newString);


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
    free(newString);
    // returns a segfault
    return newString;
}
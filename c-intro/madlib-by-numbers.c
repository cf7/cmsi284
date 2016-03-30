#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

char numbers[10] = {'0','1','2','3','4','5','6','7', '8','9' };
long numbersLength = sizeof(numbers) / sizeof(numbers[0]);

int parseCharToInt(char c) {
    return c - '0';
}

void process_String(char* string, char number, char* words[]) {
    if (memchr(string, number, strlen(string)) != NULL) {
        char *p = memchr(string, number, strlen(string));

        char *p2 = malloc(strlen(string));
        strcpy(p2, memchr(string, number, strlen(string)));

        if (strlen(p2) > 1) {
            // chop off the number after finding it
            p2 = memchr(p2, p2[1], strlen(p2));
            if (p2 != NULL) {
                char* word = malloc(strlen(words[parseCharToInt(number)]) + strlen(p2));
                strcpy(word, words[parseCharToInt(number)]);
                strcat(word, p2);
                strcpy(p, word);
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

    char *newString = malloc(strlen(template) + strlen(*words) * word_count);
    strcpy(newString, template);

    int index = 0;
    while (numbersPresent(newString)) {
        process_String(newString, numbers[index], words);
        if (index >= numbersLength) {
            index = 0;
        } else {
            index++;
        }
    }
    
    free(newString);

    return newString;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>


char activeNums[10];
long activeNumsLength = sizeof(activeNums) / sizeof(activeNums[0]);
char numbers[10] = {'0','1','2','3','4','5','6','7', '8','9' };
long numbersLength = sizeof(numbers) / sizeof(numbers[0]);

int parseCharToInt(char c) {
    return c - '0';
}

bool isActiveNum(char num) {
    bool isActive = false;
    for (int index = 0; index < activeNumsLength; index++) {
        if (num == activeNums[index]) {
            isActive = true;
        }
    }
    return isActive;
}

void process_String(char* string, char number, char* words[]) {
    if (isActiveNum(number) && memchr(string, number, strlen(string))) {
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

void activeNumbers(int word_count, char* words[]) {
    for (int index = 0; index < activeNumsLength; index++) {
        if (index < word_count && words[index] != NULL) {
            activeNums[index] = numbers[index];
        } else {
            activeNums[index] = 'n';
        }
    }
}

bool activeNumbersPresent(char* string) {
    bool nums = false;
    for (int index = 0; index < strlen(string); index++) {
        for (int index2 = 0; index2 < numbersLength; index2++) {
            if (string[index] == numbers[index2]) {
                if (isActiveNum(string[index])) {
                    nums = true;
                }
            }
        }
    }
    return nums;
}

char* madlib_by_numbers(char* template, int word_count, char* words[]) {

    for (int index = 0; index < word_count; index++) {
        printf("%s\n", words[index]);
    }

    activeNumbers(word_count, words);

    char *newString = malloc(strlen(template) + strlen(*words) * word_count);
    strcpy(newString, template);

    int index = 0;
    while (activeNumbersPresent(newString)) {
        process_String(newString, numbers[index], words);
        if (index >= numbersLength) {
            index = 0;
        } else {
            index++;
        }
    }

    // printf("%s\n", newString);

    return newString;
}
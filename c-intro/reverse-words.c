#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// ** structuring the includes
// ** 3/22 at 5:00 and 19:20
#include "reverse-range-in-place.c"

// ** cannot allocate additional memory
// ** can only use strlen from string manipulation functions

/**
    1: scan string first
        -if no whitespace, return the same string
    2: reverse the whole string except for the \0 at the end
    3: then scan again, if non-space character,
    reverse that word individually, go to next word, reverse that word invidividually
    4: finish when reached the \0
*/

// ** reverse words without building a new string

int scan(char* string, int start, int end) {
    int index = 0;
    for (int index2 = start; index2 < end; index2++) {
        if (string[index2] != ' ' && string[index2] != '\t') {
            return index2;
        }
    }
    return index;
}

void reverse_words(char* string) {
    int start_index = 0; // start index may be different when indexing word in middle of sentence
    int end_index = strlen(string) - 1; // careful on passing indices, reverse_range_in_place needs valid lengths

    printf("before: %s\n", string);
    // reverse the entire string once
    reverse_range_in_place(string, 0, end_index);

    int scan_index = 0;
    int start = 0;
    int end = 0;
    while (scan_index < end_index) {
        if (string[scan_index] != ' ' && string[scan_index] != '\t') {
            start = scan_index;
            while (string[scan_index] != ' ' && string[scan_index] != '\t') {
                scan_index++;
            }
            end = scan_index - 1;
        }
        reverse_range_in_place(string, start, end);
        scan_index++;
    }

    printf("after: %s\n", string);
}
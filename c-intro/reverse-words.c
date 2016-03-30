#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// ** structuring the includes
// ** 3/22 at 5:00 and 19:20
#include "reverse-range-in-place.h"

void reverse_words(char* string) {
    int start_index = 0;
    int end_index = strlen(string) - 1;

    // printf("before: %s\n", string);

    // reverse the entire string once
    reverse_range_in_place(string, 0, end_index);

    // reverse each individual word after
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
            reverse_range_in_place(string, start, end);
        }
        scan_index++;
    }

    // printf("after: %s\n", string);
}
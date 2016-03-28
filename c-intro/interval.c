#include <stdio.h>  // %s - strings, %p - pointer
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// compile:  gcc <filename>
// run: ./a.out

// courtesy of stackoverflow: way of finding array length
// sizeof(array) / sizeof(array[0]) = total bits that array takes up / bits for one element
char *notes[12] = { "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#" };
long notesLength = sizeof(notes) / sizeof(notes[0]);
char *intervalNames[12] = { "minor second", "major second", "minor third", "major third", 
                        "perfect fourth", "tritone", "perfect fifth", "minor sixth", "major sixth",
                        "minor seventh", "major seventh", "perfect octave" };

bool checkArgs(char *arg1, char *arg2) {
    bool validNote1 = false;
    bool validNote2 = false;
    printf("%s\n", arg1);
    printf("%s\n", arg2);
    for (int index = 0; index < notesLength; index++) {
        if (strcmp(notes[index], arg1) == 0) {
            validNote1 = true;
        }
        if (strcmp(notes[index], arg2) == 0) {
            validNote2 = true;
        }
    }
    return validNote1 && validNote2;
}

int noteIndex(char *arg) {
    int thisNote;
    for (int index = 0; index < notesLength; index++) {
        if (strcmp(notes[index], arg) == 0) {
            thisNote = index;
        }
    }
    return thisNote;
}

char* nextNote(int currentIndex, int distance) {
    char *note;
    while (currentIndex < notesLength - 1 && distance > 0) {
        note = notes[currentIndex++];
        distance--;
    }
    if (distance > 0) {
        currentIndex = 0;
        while (currentIndex < distance) {
            note = notes[currentIndex++];
        }
    }
    return note;
}

int main(int argc, char** argv) {
    if (argc > 2) {
        char *firstInput = argv[1];
        char *secondInput = argv[2];
        printf("first: %s\n", firstInput);
        printf("second: %s\n", secondInput);
        if (!checkArgs(firstInput, secondInput)) {
            perror("Invalid inputs. Please input two piano keys.");
        } else {
            printf("%s\n", "inside");
            int note1 = noteIndex(firstInput);
            int note2 = noteIndex(secondInput);
            printf("note1: %d\n", note1);
            printf("note2: %d\n", note2);
            
            
        }
    } else {
        perror("Please input two arguments separated by spaces");
    }
    
}
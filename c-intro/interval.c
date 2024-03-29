#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *notes[12] = { "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#" };
long notesLength = sizeof(notes) / sizeof(notes[0]);
char *intervalNames[12] = { "minor second", "major second", "minor third", "major third", 
                        "perfect fourth", "tritone", "perfect fifth", "minor sixth", "major sixth",
                        "minor seventh", "major seventh", "perfect octave" };
long intervalNamesLength = sizeof(intervalNames) / sizeof(intervalNames[0]);

bool checkArgs(char *arg1, char *arg2) {
    bool validNote1 = false;
    bool validNote2 = false;
    for (int index = 0; index < notesLength; index++) {
        if (!strcmp(notes[index], arg1)) {
            validNote1 = true;
        }
        if (!strcmp(notes[index], arg2)) {
            validNote2 = true;
        }
    }
    return validNote1 && validNote2;
}

int noteIndex(char *arg) {
    int thisNote;
    for (int index = 0; index < notesLength; index++) {
        if (!strcmp(notes[index], arg)) {
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

char* calcInterval(int note1Index, int note2Index) {
    if (note2Index < note1Index) {
        note2Index = note2Index + 12;
    }
    int diff = note2Index - note1Index;
    if (!diff) {
        return intervalNames[intervalNamesLength - 1];
    } else {
        return intervalNames[diff - 1];
    }
}

int main(int argc, char** argv) {
    if (argc > 2) {
        char *firstInput = argv[1];
        char *secondInput = argv[2];
        if (!checkArgs(firstInput, secondInput)) {
            perror("Invalid inputs. Please input two piano keys.");
        } else {
            int note1 = noteIndex(firstInput);
            int note2 = noteIndex(secondInput);
            
            printf("%s to %s is a %s\n", notes[note1], notes[note2], calcInterval(note1, note2));
        }
    } else {
        perror("Please input two arguments separated by spaces");
    }
    
}
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *notes[12] = { "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#" };
long notesLength = sizeof(notes) / sizeof(notes[0]);

bool checkArgs(char *arg) {
    bool validNote = false;
    for (int index = 0; index < notesLength; index++) {
        if (strcmp(notes[index], arg) == 0) {
            validNote = true;
        }
    }
    return validNote;
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
    if (argc > 1) {
        char *input = argv[1];

        if (!checkArgs(input)) {
            perror("Invalid input. Please input a piano key.");
        } else {
            int note = noteIndex(input);
            char *root = notes[note];
            printf("%s: %s %s %s\n", input, root, nextNote(note, 4), nextNote(note, 7));
            printf("%sm: %s %s %s\n", input, root, nextNote(note, 3), nextNote(note, 7));
            printf("%s7: %s %s %s %s\n", input, root, nextNote(note, 4), nextNote(note, 7), nextNote(note, 10));
            printf("%sdim7: %s %s %s %s\n", input, root, nextNote(note, 3), nextNote(note, 6), nextNote(note, 9));
        }
    } else {
        perror("Please input at least one argument");
    }
    
}
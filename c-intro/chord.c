#include <stdio.h>

// compile:  gcc <filename>
// run: ./a.out

/**
    12 notes of western music scale
    A (A#/Bb) B C (C#/Db) D (D#/Eb) E F (F#/Gb) G (G#/Ab)

    Major scale: (formula that takes you back the root)

    How number system represents notes
      1    2    3     4     5     6     7     1 (back to root)
    Root whole whole half whole whole whole half

    Root = 1 of the 12 notes

    "intervals"
    whole step = 2 steps ()
    half step = 1 step (notes that are right next to each other)

    Example:
    C as Root, use formula
    R --> W --> W --> H --> W --> W --> W --> H
    C --> D --> E --> F --> G --> A --> B --> C

    Numbers are assigned when root is A
    1 --> 2 -->    3    --> 4 --> 5 -->    6    -->    7    --> 1
    A --> B --> (C#/Db) --> D --> E --> (F#/Gb) --> (G#/Ab) --> A

    chords 1 - 7
    chords 1, 4, 5 are by default major chords
    chords 2, 3, 6 are by default minor chords
    chord 7 is called a diminished chord

    1 --> 2 -->    3    --> 4 --> 5 -->    6    -->    7    --> 1
    A --> B --> (C#/Db) --> D --> E --> (F#/Gb) --> (G#/Ab) --> A
        minor     minor   major  major   minor     diminished


    Fmaj  (almost every chord has perfect 5th, if left out, assume it is perf 5th)
    Root: F
    "maj" --> major third --> 2 whole steps
    "   " --> perfect fifth --> 3 whole steps and 1 half step
    this is definition of major chord

    Fmaj also written as F

    so F#maj is also written as just F# (major is implied)

    Fmin
    Root: F
    "min" --> minor 3rd --> 1 whole step and 1 half step
    "   " --> perfect 5th --> 3 whole steps and 1 half step

    Adim
    Root: A
    "dim" --> can only be minor third because major third would be too close to dim5th
    "   " --> diminished 5th --> 3 whole steps (no extra half step)

    Any two notes in a chord can be at most a major third apart or at least a minor 3rd apart

    seventh chords just means find the 4th note stacked on top
    "seventh chords" --> 4 note chords

    maj7 --> 5 whole steps and 1 half step (octave minus half step)
    min7 --> 5 whole steps (octave minus whole step/2 half steps)

    Only seven 7th chords:

    Amaj7   (will have an Amaj + maj7, everything is majored)
    F#min7  (will have F#min + min7)
    C7  ("dominant 7th chord" or "7 chord") not a major 7th chord
        Cmaj chord + min7
        have to explicitly say maj7 chord
        play a major triad with a min7th

    So from a root major triad can only get root major seventh or dominant sevenths
    Gmaj + maj7  --> Gmaj7 | G7
    Gmin + min7  --> Gmin7
    Gmin + maj7  --> Gminmaj7 (minor-major seventh)
    Gdim + min7  --> Ghalfdim7
    Gdim + dim7  --> Gdim7

    octave is 12 keys in between (6 whole steps)
    F# (major is implied)
    next note is 4 keys up from original note
    third note is 3 keys up from 2nd note

    minor is inverted
    F#m (m - minor)
    next note is 3 keys up from original note
    third note is 4 keys up from 2nd note


    F#7  (dominant 7th implied)
    

    F#dim7   (diminished 7th)


    "interval" - number of keys in between

    assignment:
    key:
        major:
        minor:
        dominant 7th:
        diminished 7th:

*/
int main(int argc, char** argv) {


}
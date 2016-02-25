#include <Arduino.h>

//1. The length of a dot is one unit.
//2. A dash is three units.
//3. The space between parts of the same letter is one unit.
//4. The space between letters is three units.
//5. The space between words is seven units.

#define NIL 0
static const long UNIT  = 350;
static const long DOT   = UNIT;
static const long DSH   = 3 * UNIT;

static const long UNIT_SPACE   = UNIT;
static const long LETTER_SPACE = 3 * UNIT;


struct MorseSignal {
    char symbol;
    long code[5];
};

static MorseSignal signals[] = {
        {'A', DOT, DSH, NIL, NIL, NIL},
        {'B', DSH, DOT, DOT, DOT, NIL},
        {'C', DSH, DOT, DSH, DOT, NIL},
        {'D', DSH, DOT, DOT, NIL, NIL},
        {'E', DOT, NIL, NIL, NIL, NIL},
        {'F', DOT, DOT, DSH, DOT, NIL},
        {'G', DSH, DSH, DOT, NIL, NIL},
        {'H', DOT, DOT, DOT, DOT, NIL},
        {'I', DOT, DOT, NIL, NIL, NIL},
        {'J', DOT, DSH, DSH, DSH, NIL},
        {'K', DSH, DOT, DSH, NIL, NIL},
        {'L', DOT, DSH, DOT, DOT, NIL},
        {'M', DSH, DSH, NIL, NIL, NIL},
        {'N', DSH, DOT, NIL, NIL, NIL},
        {'O', DSH, DSH, DSH, NIL, NIL},
        {'P', DOT, DSH, DSH, DOT, NIL},
        {'Q', DSH, DSH, DOT, DSH, NIL},
        {'R', DOT, DSH, DOT, NIL, NIL},
        {'S', DOT, DOT, DOT, NIL, NIL},
        {'T', DSH, NIL, NIL, NIL, NIL},
        {'U', DOT, DOT, DSH, NIL, NIL},
        {'V', DOT, DOT, DOT, DSH, NIL},
        {'W', DOT, DSH, DSH, NIL, NIL},
        {'X', DSH, DOT, DOT, DSH, NIL},
        {'Y', DSH, DOT, DSH, DSH, NIL},
        {'Z', DSH, DSH, DOT, DOT, NIL},

        {'0', DSH, DSH, DSH, DSH, DSH},
        {'1', DOT, DSH, DSH, DSH, DSH},
        {'2', DOT, DOT, DSH, DSH, DSH},
        {'3', DOT, DOT, DOT, DSH, DSH},
        {'4', DOT, DOT, DOT, DOT, DSH},
        {'5', DOT, DOT, DOT, DOT, DOT},
        {'6', DSH, DOT, DOT, DOT, DOT},
        {'7', DSH, DSH, DOT, DOT, DOT},
        {'8', DSH, DSH, DSH, DOT, DOT},
        {'9', DSH, DSH, DSH, DSH, DOT},
};

static MorseSignal *find(char sym) {
    for (int i = 0; i < 36; i++) {
        if (signals[i].symbol == sym) return &(signals[i]);
    }
    return NULL;
}


void setup() {
    pinMode(13, OUTPUT);
}



///////////////////////////////////////////////////////////////
//static char *MESSAGE = "C\n";
static char *MESSAGE = "CPP\n";      //'CPP' =  -.-. .--. .--.
//static char *MESSAGE = "SOS\n";
//static char *MESSAGE = "CLION\n";
///////////////////////////////////////////////////////////////

void loop() {

    for (char *sym = MESSAGE; *sym != '\n'; sym++) {
        MorseSignal *sig = find(*sym);
        for (int i = 0; i < 5; i++) {
            int code = sig->code[i];
            if (code != NIL) {
                digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
                delay(code);
                digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
                delay(UNIT_SPACE);
            }
        }
        delay(LETTER_SPACE);
    }



    // end of the word
    delay(4000);
}
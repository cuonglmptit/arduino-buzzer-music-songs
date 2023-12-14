#include "pitches.h"
const int BUZZZER_PIN = 15;  // pin connected to piezo buzzer
#define LED_PIN 4
// notes in the melody:
int melody[] = {
  C5, B4, A4, G4, A4, B4,
  C5, B4, A4, G4, A4, B4,
  C5, B4, A4, G4, A4, B4,
  C5, B4, A4, G4,

  D5, C5, B4, A4, B4, C5,
  D5, C5, B4, A4, B4, C5,
  D5, C5, B4, A4, B4, C5,
  B4, C5, CS5, D5,

  A5, B5, C6,
  F5, G5, A5,
  G5, A5, B5,

  E5, F5, G5,
  F5, G5, A5,

  D5, E5, F5,
  E5, F5, G5,

  C5, D5, E5, D5, CS5, C5,
  B4, AS4, A4, GS4, G4, FS4, F4, E4, DS4, D4,

  G3, C4, C4,
  E4, A4, E4, G4,
  G4, A4, G4, E4, F4, E4, D4,

  A3, D4, D4,
  F4, B4, B4, A4, G4, F4, F4, E4,
  A3, B3, C4, D4,

  G3, C4, C4,
  E4, A4, E4, G4,
  G4, A4, G4, E4, F4, E4, D4,

  A3, D4, D4,
  F4, B4, A4, G4, F4, F4, E4, D4,
  B3, D4, C4,

  A4,A4,
  G4,F4,G4,A4,G4,
  D4,E4,FS4,D4,G4,

  A4,G4,D4,G4,A4,A4,G4,

  A4,G4,F4,
  D4,
  B4,A4,G4,A4,G4,F4,
  G4,A4,E4,D4,C4
};

// note durations, also called tempo:
int noteDurations[] = {
  8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8,
  8, 8, 8, 4,

  8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8,
  8, 8, 8, 4,

  8, 8, 8,
  8, 8, 8,
  8, 8, 8,

  8, 8, 8,
  8, 8, 8,

  8, 8, 8,
  8, 8, 8,

  8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 1.2,

  6, 8, 6,
  8, 6, 8, 4,
  6, 8, 6, 8, 6, 8, 4,

  6, 8, 6,
  8, 6, 8, 6, 8, 4, 6, 8,
  6, 4, 8, 1.2,

  6, 8, 6,
  8, 6, 8, 4,
  6, 8, 6, 8, 6, 8, 4,

  6, 8, 6,
  8, 4, 6, 8, 6, 8, 6, 8,
  4, 4, 2,

  4,6,
  10,10,10,10,4,
  6,8,6,8,2,

  6,4,9,9,9,9,2,

  4,4,2,
  4,
  6,8,6,8,6,2,
  6,8,2,9,1.2
};

void setup() {
  pinMode(LED_PIN, OUTPUT);

  // iterate over the notes of the melody:
  int size = sizeof(noteDurations) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++) {

    // to calculate the note duration, takenoteDuration divided by the note type.
    int noteDuration = 1100 / noteDurations[thisNote];
    tone(BUZZZER_PIN, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    // delay(pauseBetweenNotes);

    digitalWrite(LED_PIN, HIGH);   // Turn on LED
    delay(pauseBetweenNotes*(8.0/10));  // Keep LED turn on for 8/10 of this note

    digitalWrite(LED_PIN, LOW);    // Turn off LED
    delay(pauseBetweenNotes*(2.0/10));  // Keep LED off for the rest of the note
    // stop the tone playing:
    noTone(BUZZZER_PIN);
  }
}
void loop() {
  //if you want to repeat the song, call setup() in this loop
  //setup();
}

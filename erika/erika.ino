#include "pitches.h"
const int BUZZZER_PIN = 15;  // pin connected to piezo buzzer
#define LED_PIN 4
// notes in the melody:
int melody[] = {
  C4,
  CS4,DS4,DS4,DS4,
  GS4,GS4,
  C5,C5,
  AS4,GS4,
  G4,GS4,AS4,
  C5,AS4,GS4,

  S,

  C4,
  CS4,DS4,DS4,DS4,
  GS4,GS4,
  C5,C5,
  AS4,GS4,
  G4,GS4,AS4,
  C5,AS4,GS4,
};

// note durations
int noteDurations[] = {
  4,
  10,6,6,6,
  6,6,
  6,4,
  10,3,
  6,6,3,
  5,10,6,

  3,

  4,
  10,6,6,6,
  6,6,
  6,4,
  10,3,
  6,6,3,
  5,10,6,
};

void setup() {
  pinMode(LED_PIN, OUTPUT);

  // iterate over the notes of the melody:
  int size = sizeof(noteDurations) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++) {

    int noteDuration = 2200 / noteDurations[thisNote];
    tone(BUZZZER_PIN, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    // delay(pauseBetweenNotes);

    if(melody[thisNote] > 0) digitalWrite(LED_PIN, HIGH); 
    delay(pauseBetweenNotes*(8.0/10));  

    digitalWrite(LED_PIN, LOW);   
    delay(pauseBetweenNotes*(2.0/10)); 
    // stop the tone playing:
    noTone(BUZZZER_PIN);
  }
}
void loop() {
  //setup();
}

#include "pitches.h"
const int BUZZZER_PIN = 15;  // pin connected to piezo buzzer
#define LED_PIN 4
// notes in the melody:
int melody[] = {
  MI4,RE4,DO4,
  DO4,DO4,DO4,
  RE4,MI4,RE4,
  
  RE4,RE4,MI4,RE4,DO4,
  DO4,DO5,DO5,SI4,LA4,SOL4,

  MI4,MI4,SOL4,LA4,MI4,
  RE4,RE4,MI4,SOL4,MI4,RE4,DO4,
  DO4,RE4,MI4,DO4,DO4,DO4,
  DO4,DO4,DO4,RE4,

  RE4,MI4,RE4,DO4,DO4,DO4,DO4,RE4,MI4,RE4,

  RE4,RE4,MI4,RE4,DO4,
  DO4,DO5,DO5,SI4,LA4,SOL4,

  MI4,RE4,MI4,SOL4,LA4,SOL4,RE4,
  MI4,SOL4,SI4,SI4,DO5,
  DO5,RE5,MI5,FA5,MI5,DO5,LA4,DO5,MI5,RE5,

  DO5,SI4,LA4,SOL4,
  SOL4,SOL4,SOL4,
  LA4,DO5,RE5,
  RE5,MI5,DO5,
  DO5,DO5,DO5,RE5,MI5,SI4,

  DO5,SI4,LA4,SOL4,LA4,
  LA4,MI5,MI5,
  LA4,SOL4,SOL4,DO5,DO5,
  LA4,SOL4,LA4,
  DO5,DO5,DO5,RE5,MI5,DO5,RE5,

  DO5,SI4,LA4,SOL4,
  SOL4,SOL4,SOL4,
  LA4,DO5,RE5,
  RE5,MI5,DO5,
  DO6,DO6,SI5,LA5,SOL5,

  DO5,SI4,LA4,SOL4,LA4,
  LA5,SOL5,
  MI5,
  RE5,SOL5,RE5,MI5,
  RE5,MI5,LA4,
  DO5,DO5,DO5,
  RE5,MI5,RE5,
  DO5,SI4,LA4,SI4,DO5,
};

// note durations
int noteDurations[] = {
  6,6,6,
  12,12,6,
  12,12,4,

  12,6,12,12,6,
  12,12,12,12,6,4,

  6,12,12,6,6,
  6,12,12,12,12,12,6,
  12,12,12,12,12,6,
  12,12,12,4,

  12,6,6,6,12,12,6,12,12,4,

  12,6,12,12,6,
  12,12,12,12,6,3,

  12,12,12,12,6,6,4,
  12,12,12,12,6,
  12,12,12,12,12,12,12,6,12,2,

  12,12,6,6,
  12,12,6,
  12,12,4,
  6,6,6,
  12,12,6,12,12,4,

  12,12,12,12,6,
  12,12,6,
  6,6,12,12,6,
  12,12,6,
  12,12,12,12,12,12,4,

  12,12,6,6,
  12,12,6,
  12,12,4,
  6,6,6,
  6,12,12,6,4,

  12,12,12,12,6,
  6,6,
  6,
  12,12,12,4,
  12,12,6,
  12,12,6,
  12,12,4,
  12,12,12,12,2,
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

    digitalWrite(LED_PIN, HIGH);  
    delay(pauseBetweenNotes*(8.0/10)); 

    digitalWrite(LED_PIN, LOW);   
    delay(pauseBetweenNotes*(2.0/10)); 
    // stop the tone playing:
    noTone(BUZZZER_PIN);
  }
}
void loop() {
  // setup();
}

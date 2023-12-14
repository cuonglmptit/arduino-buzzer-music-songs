#include "pitches.h"
const int BUZZZER_PIN = 15;  // pin connected to piezo buzzer
#define LED_PIN 4
// notes in the melody:
int melody[] = {
  MI5,GS5,

  E5,B4,CS5,CS5,B4,MI5,MI5,
  E5,B4,CS5,CS5,B4,MI5,GS5,

  E5,B4,CS5,CS5,CS5,B4,E5,E5,E5,FS5,E5,E5,E5,CS5,GS5,


  E5,E5,FS5,G5,GS5,E5,
  B4,CS5,
  E5,E5,FS5,G5,GS5,E5,

  CS5,E5,CS5,E5,
  CS5,E5,CS5,E5,

  E5,A5,GS5,E5,E5,CS5,GS5,


  E5,E5,FS5,G5,GS5,E5,
  B4,CS5,
  E5,E5,FS5,G5,GS5,E5,

  CS5,E5,CS5,E5,
  CS5,E5,CS5,E5,

  E5,A5,GS5,E5,E5,FS5,E5,
};

// note durations
int noteDurations[] = {
  4,10,
  
  16,16,6,6,10,6,6,
  16,16,6,6,10,6,6,
  
  16,16,6,10,16,10,6,10,16,10,6,10,16,10,3.5,


  6,10,16,10,6,6,
  16,16,
  6,10,16,10,6,6,

  10,10,16,6,
  10,10,16,6,

  10,16,10,10,16,10,3.5,


  6,10,16,10,6,6,
  16,16,
  6,10,16,10,6,6,

  10,10,16,6,
  10,10,16,6,

  10,16,10,10,16,10,3.5,
};

void setup() {
  pinMode(LED_PIN, OUTPUT);

  // iterate over the notes of the melody:
  int size = sizeof(noteDurations) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++) {

    // to calculate the note duration, take noteDuration divided by the note type.
    int noteDuration = 1850 / noteDurations[thisNote];
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
  //setup();
}

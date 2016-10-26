/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

 */
#include "pitches.h"

const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status

// notes in the melody:
int melody[] = {
  NOTE_E7, NOTE_E7, NOTE_E7,0, NOTE_E7, NOTE_E7, NOTE_E7, 0, NOTE_E7, NOTE_G7, NOTE_C7, NOTE_D7, NOTE_E7,
  NOTE_F7, NOTE_F7, NOTE_F7, 0, NOTE_F7, NOTE_F7, NOTE_E7, NOTE_E7, NOTE_E7,NOTE_E7,
  NOTE_E7, NOTE_D7, NOTE_D7, NOTE_E7, NOTE_D7,0, NOTE_G7,0, NOTE_E7, NOTE_E7, NOTE_E7, 0, NOTE_E7, NOTE_E7, NOTE_E7,
  NOTE_E7, NOTE_G7, NOTE_C7, 0, NOTE_D7, NOTE_E7, 0, NOTE_F7, NOTE_F7, NOTE_F7,NOTE_F7,
  NOTE_F7, NOTE_E7, NOTE_E7, NOTE_E7, NOTE_E7, NOTE_G7, NOTE_G7, NOTE_F7, NOTE_D7, NOTE_C7
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  3, 3, 3, 3, 3, 3, 3, 2, 3, 2, 3, 2, 2,/**/
  4, 4, 4, 3, 4, 3, 3, 3, 3, 3, 3,/**/
  3, 2, 2, 3, 2, 2, 5, 5, 3, 3, 3, 3, 3, 3, 3,
  3, 5, 1, 1, 2, 2, 3, 3 , 4, 4, 4,4,
  4, 3, 3, 3, 3, 4, 4, 4, 2, 1
};

void setup() {
    pinMode(buttonPin, INPUT);
  // iterate over the notes of the melody:
//  for (int thisNote = 0; thisNote < 8; thisNote++) {
//
//    // to calculate the note duration, take one second
//    // divided by the note type.
//    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
//    int noteDuration = 1000 / noteDurations[thisNote];
//    tone(3, melody[thisNote], noteDuration);
//
//    // to distinguish the notes, set a minimum time between them.
//    // the note's duration + 30% seems to work well:
//    int pauseBetweenNotes = noteDuration * 1.30;
//    delay(pauseBetweenNotes);
//    // stop the tone playing:
//    noTone(3);
//  }
}

void loop() {
  // no need to repeat the melody.
  // iterate over the notes of the melody:
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH){
    for (int thisNote = 0; thisNote < 61; thisNote++) {
  
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(3, melody[thisNote], noteDuration);
  
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(3);
    }
    noTone(3);
  }
  noTone(3);
}


/*

  Inspired by and indebted to: 

  Tom Igoe
  from his tutorial at
  http://www.arduino.cc/en/Tutorial/Tone

  This work in progress from 10/24/2022 features the classic tune "Crazy Train" by Ozzy Osbourne and was coded by
  Nicole Buckenwolf
  Call on me for your random transcription needs

*/

#include "pitches.h"

// notes in the melody: 
int melody[] = {

// first two bars, repeated

  NOTE_FS3, NOTE_FS3, NOTE_CS4, NOTE_FS3, NOTE_D4, NOTE_FS3, NOTE_CS4, NOTE_FS3, NOTE_B3, NOTE_A3, NOTE_GS3, NOTE_A3, NOTE_B3, NOTE_A3, NOTE_GS3, NOTE_E3,

  NOTE_FS3, NOTE_FS3, NOTE_CS4, NOTE_FS3, NOTE_D4, NOTE_FS3, NOTE_CS4, NOTE_FS3, NOTE_B3, NOTE_A3, NOTE_GS3, NOTE_A3, NOTE_B3, NOTE_A3, NOTE_GS3, NOTE_E3,

//  first two bars before all the 16th notes

  NOTE_FS3, NOTE_FS3, NOTE_CS4, NOTE_FS3, NOTE_D4, NOTE_FS3, NOTE_CS4, NOTE_B3, NOTE_D4, NOTE_G3,

// pre-singing, with the 16th notes

  NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A4, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_G4, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3,
  
  NOTE_FS4 , NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_E3, NOTE_G3, NOTE_GS3, NOTE_A3,

  NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A4, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_G4, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3,

  NOTE_FS4 , NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_E3, NOTE_A3,

// now the vocal melody

  NOTE_E5, NOTE_CS5, REST,
  REST, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_CS5, REST

};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {

  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 
  8, 8, 8, 8, 8, 8, 8, 8, 2, 2,

  8, 16, 16, 8, 16, 16, 16, 16, 8, 16, 16, 16, 16,
  8, 16, 16, 16, 16, 5, 16, 16, 8,
  8, 16, 16, 8, 16, 16, 16, 16, 8, 16, 16, 16, 16,
  8, 16, 16, 16, 16, 5, 4,

  8, 5, 2,
  3, 8, 8, 8, 8, 4, 8, 4, 2, 1
};

void setup() {
  // iterate over the notes of the melody:

  for (int thisNote = 0; thisNote < 97; thisNote++) {
    // to calculate the note duration, take one second divided by the note type.

    // e.g. quarter note = 1000/4, eight note = 1000/8, etc.

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(8);
  }

}

void loop() {
  // no need to repeat the melody.

}

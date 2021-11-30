#include "pitches.h"

// LED Pins
const int C4=2;
const int D4=3;
const int E4=4;
const int F4=5;
const int G4=6;
const int a4=7;
const int B4=8;

// Speaker Pin
const int SPEAKER=9; 

int notes[] = {
  NOTE_C4, NOTE_E3, NOTE_G4,
  NOTE_C4, NOTE_E3, NOTE_G4,
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4, 0,
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4,
  NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4,
  NOTE_D4, NOTE_C4, 0
};

int times[] = {
  250, 250, 250, 
  250, 250, 250,
  250, 250, 250, 250, 250, 
  250, 250, 250, 250,
  250, 250, 250, 250, 
  250, 250, 250
};

void setup() {
  pinMode(C4, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(E4, OUTPUT);
  pinMode(F4, OUTPUT);
  pinMode(G4, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(B4, OUTPUT);

  delay(2000);
    
  // put your setup code here, to run once:
  for (int i = 0; i < 20; i++) {
    if (notes[i] == NOTE_C4) {
      digitalWrite(C4, HIGH);
      tone(SPEAKER, notes[i], times[i]);
      delay(times[i]);
      digitalWrite(C4, LOW);
    }
    else if (notes[i] == NOTE_D4) {
      digitalWrite(D4, HIGH);
      tone(SPEAKER, notes[i], times[i]);
      delay(times[i]);
      digitalWrite(D4, LOW);
    }
    else if (notes[i] == NOTE_E4) {
      digitalWrite(E4, HIGH);
      tone(SPEAKER, notes[i], times[i]);
      delay(times[i]);
      digitalWrite(E4, LOW);
    }
    else if (notes[i] == NOTE_F4) {
      digitalWrite(F4, HIGH);
      tone(SPEAKER, notes[i], times[i]);
      delay(times[i]);
      digitalWrite(F4, LOW);
    }
    else if (notes[i] == NOTE_G4) {
      digitalWrite(G4, HIGH);
      tone(SPEAKER, notes[i], times[i]);
      delay(times[i]);
      digitalWrite(G4, LOW);
    }
    else if (notes[i] == NOTE_A4) {
      digitalWrite(a4, HIGH);
      tone(SPEAKER, notes[i], times[i]);
      delay(times[i]);
      digitalWrite(a4, LOW);
    }
    else if (notes[i] == NOTE_B4) {
      digitalWrite(B4, HIGH);
      tone(SPEAKER, notes[i], times[i]);
      delay(times[i]);
      digitalWrite(B4, LOW);
    }
  }
}

void loop() {
  
}

#include "pitches.h"

// Pentatonic Piano
// C D E G A
#define NOTE_C 262 //Hz
#define NOTE_D 294 //Hz
#define NOTE_E 330 //Hz
#define NOTE_G 392 //Hz
#define NOTE_A 440 //Hz

const int SPEAKER=9; //Speaker on pin 9
const int BUTTON_C=7; //Button pin
const int BUTTON_D=6; //Button pin
const int BUTTON_E=5; //Button pin
const int BUTTON_G=4; //Button pin
const int BUTTON_A=3; //Button pin
unsigned long count = 0;
char note;
bool flag = false;

void setup()
{
  Serial.begin(9600);
  
  //No setup needed
  //Tone function sets outputs
  pinMode(BUTTON_C, INPUT_PULLUP);
  pinMode(BUTTON_D, INPUT_PULLUP);
  pinMode(BUTTON_E, INPUT_PULLUP);
  pinMode(BUTTON_G, INPUT_PULLUP);
  pinMode(BUTTON_A, INPUT_PULLUP);
}
void loop()
{
  while(!digitalRead(BUTTON_C)) {
    tone(SPEAKER, NOTE_C);
    note = 'C';
    count += 1;
    flag = true;
  }
    
  while(!digitalRead(BUTTON_D)) {
     tone(SPEAKER, NOTE_D);
     note = 'D';
     count += 1;
     flag = true;
  }
     
  while(!digitalRead(BUTTON_E)) {
    tone(SPEAKER, NOTE_E);
    note = 'E';
    count += 1;
    flag = true;
  }
  
  while(!digitalRead(BUTTON_G)) {
    tone(SPEAKER, NOTE_G);
    note = 'G';
    count += 1;
    flag = true;
  }
  
  while(!digitalRead(BUTTON_A)) {
    tone(SPEAKER, NOTE_A);
    note = 'A';
    count += 1;
    flag = true;
  }
  
  noTone(SPEAKER);
  //Stop playing if all buttons have been released
  if (flag == true) { 
    Serial.print("Note: ");
    Serial.print(note);
    Serial.print(",  Time: ");
    Serial.println(count);
    count = 0;
    flag = false;
  }
}

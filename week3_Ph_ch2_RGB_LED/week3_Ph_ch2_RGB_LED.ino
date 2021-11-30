const int BLED=9; //Blue LED on Pin 9
const int GLED=10; //Green LED on Pin 10
const int RLED=11; //Red LED on Pin 11
const int BUTTON=2; //The Button is connected to pin 2

boolean lastButton = LOW; //Last Button State
boolean currentButton = LOW; //Current Button State
int ledMode = 0; //Cycle between LED states

void setup()
{
  pinMode (BLED, OUTPUT); //Set Blue LED as Output
  pinMode (GLED, OUTPUT); //Set Green LED as Output
  pinMode (RLED, OUTPUT); //Set Red LED as Output
  pinMode (BUTTON, INPUT); //Set button as input (not required)
}

boolean debounce(boolean last) {
  boolean current = digitalRead(BUTTON); //Read the button state
  
  if (last != current) //if it's different...
  {
    delay(5); //wait 5ms
    current = digitalRead(BUTTON); //read it again
  }
  
  return current; //return the current value
}

/*
* LED Mode Selection
* Pass a number for the LED state and set it accordingly.
*/
void setMode(int mode) {
  //RED
  if (mode == 1)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);
  }
  //GREEN
  else if (mode == 2) {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  }
  //BLUE
  else if (mode == 3)
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  }
  //OFF (mode == 0)
  else
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);
  }
}

void loop() {
  currentButton = debounce(lastButton); //read debounced state
  
  if (lastButton == LOW && currentButton == HIGH) //if it was pressed...
  {
    ledMode++; //increment the LED value
  }
    
  lastButton = currentButton; //reset button value
  
  //if you've cycled through the different options, reset the counter to 0
  if (ledMode == 4){
      ledMode = 0;
  }
  setMode(ledMode); //change the LED state
}

//Define LED pins
const int RED =11;
const int GREEN =10;
const int BLUE =9;
//Variables for RGB levels
int rval = 0;
int gval = 0;
int bval = 0;
int targetLED = -1;

void setup()
{
Serial.begin(9600); //9600 baud
//Set pins as outputs
pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
}

void loop()
{
  //Keep working as long as data is in the buffer
  while (Serial.available() > 0)
  {
    targetLED
    rval = Serial.parseInt(); //First valid integer
    gval = Serial.parseInt(); //Second valid integer
    bval = Serial.parseInt(); //Third valid integer
    
    if (Serial.read() == '\n') //Done transmitting
    { 
      //set LED
      analogWrite(RED, 255 - rval);
      analogWrite(GREEN, 255 - gval);
      analogWrite(BLUE, 255 - bval);
    }
  }
}

//Temperature Alert!
const int BLED=9; //Blue LED on pin 9
const int GLED=10; //Green LED on pin 10
const int RLED=11; //Red LED on pin 11

const int TEMP=0; //Temp Sensor is on pin A0

const int LOWER_BOUND=150; //Lower Threshold
const int UPPER_BOUND=160; //Upper Threshold
int val = 0; //Variable to hold analog reading

void setup()
{
  Serial.begin(9600);
  pinMode (BLED, OUTPUT); //Set Blue LED as Output
  pinMode (GLED, OUTPUT); //Set Green LED as Output
  pinMode (RLED, OUTPUT); //Set Red LED as Output
}

void loop()
{
  val=analogRead(TEMP);
  Serial.println(val);
  
  if(val < LOWER_BOUND)// blue
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  }
  else if(val > UPPER_BOUND) // red
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);
  }
  else // green
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  }
}

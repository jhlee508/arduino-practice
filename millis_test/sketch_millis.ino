unsigned long startMillis;  // some global variables available anywhere in the program
unsigned long currentMillis;
const unsigned long period = 1000;  // the value is a number of milliseconds
int currentTime = 0;
int count = 3 * 10; // 3 minute setting

void setup()
{
  Serial.begin(9600);  // start Serial in case we need to print debugging info
  startMillis = millis(); // initial start time
}

void loop()
{
  Serial.print("Start time: ");
  Serial.println(startMillis);
  Serial.print("Current time: ");
  Serial.println(currentTime);
  currentMillis = millis();  // get the current "time" (the number of milliseconds since the program started)
  Serial.print("CurrentMillis: ");
  Serial.println(currentMillis);

  if (currentTime == count) {
    currentTime = 0;
    // MQTT Implementation
  }
  
  if (currentMillis - startMillis >= period)  // test whether the period has elapsed
  {
    Serial.println("1 second passed");
    startMillis = currentMillis;
    // 만약 inRange라면 
    currentTime += 1;  
    // 아니면 0으로
  }
  delay(1000);
}

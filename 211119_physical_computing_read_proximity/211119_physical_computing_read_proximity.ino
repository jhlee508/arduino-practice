#include <Arduino_APDS9960.h>

int redLed = 9;

void setup() {
  pinMode(redLed, OUTPUT);
  Serial.begin(9600);
  while (!Serial);
    if (!APDS.begin()) {
      Serial.println("Error initializing APDS-9960!");
  }
}

void loop() {
  // check if a proximity reading is available
  if (APDS.proximityAvailable()) {
    // read the proximity
    // - 0 => close
    // - 255 => far
    // - -1 => error
    int prm = APDS.readProximity();
    // print value to the Serial Monitor
    Serial.println(prm);
    int distance = map(prm, 0, 255, 10, 20);
    Serial.println(distance);
    if (distance < 10) {
      analogWrite(redLed, 255);
    }
    else if (distance >= 20) {
      analogWrite(redLed, 0);
    }
    else {
      analogWrite(redLed, 255 - prm);
    }
  }
  
  // wait a bit before reading again
  delay(100);
}

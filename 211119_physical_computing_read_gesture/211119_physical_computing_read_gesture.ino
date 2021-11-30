#include <Arduino_APDS9960.h>

int up = 0;
int down = 0;
int left = 0;
int right = 0;

int ledRed = 9;
int ledBlue = 6;

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  Serial.begin(9600);
  while (!Serial);
  if (!APDS.begin()) {
    Serial.println("Error initializing sensor!");
  }
  // Default is 80
  APDS.setGestureSensitivity(80);
  Serial.println("Detecting gestures ...");
}
void loop() {
  if (APDS.gestureAvailable()) { 
    int gesture = APDS.readGesture();
    switch (gesture) {
      case GESTURE_UP:
        up += 1;
        Serial.println("Detected UP gesture");
        digitalWrite(ledRed, HIGH);
        break;
      case GESTURE_DOWN:
        down += 1;
        Serial.println("Detected DOWN gesture");
        digitalWrite(ledRed, LOW);
        break;
      case GESTURE_LEFT:
        left += 1;
        Serial.println("Detected LEFT gesture");
        digitalWrite(ledBlue, HIGH);
        break;
      case GESTURE_RIGHT:
        right += 1;
        Serial.println("Detected RIGHT gesture");
        digitalWrite(ledBlue, LOW);
        break;
      default:
        break;
    }
//    Serial.print("Up: ", up);
//    Serial.print("Down: ", down);
//    Serial.print("Left: ", left);
//    Serial.println("Right: ", right);
  }
}

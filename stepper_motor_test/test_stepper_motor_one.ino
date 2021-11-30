// Include the Arduino Stepper Library
#include <Stepper.h>

// Number of steps per output rotation
const int stepsPerRevolution = 200;

// Create Instance of Stepper library
//Stepper stepper1(stepsPerRevolution, 2, 3, 4, 5);
Stepper stepper2(stepsPerRevolution, 8, 9, 10, 11);

int angle1 = 10;
int angle2 = 10;
bool flag = true;

void setup()
{
  // set the speed at 60 rpm:
//  stepper1.setSpeed(30);
  stepper2.setSpeed(30);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() 
{
   
  if (flag == true) {
    stepper1.step(angle1); 
    Serial.println("stepper1");
    flag = false;
  }
  
  else if (flag == false) {
    stepper2.step(angle2);
    Serial.println("stepper2");
    flag == true;
  }

  delay(3000);
}

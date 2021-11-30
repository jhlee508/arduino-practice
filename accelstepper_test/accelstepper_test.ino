#include <AccelStepper.h>  
const int step_pin = 2;  
const int dir_pin  = 3;  
long motorPosition = 0;  
AccelStepper stepper(AccelStepper::DRIVER, step_pin, dir_pin, 4, 5);   
void setup()   
{   
  Serial.begin(9600);  
  stepper_init();    
  stepper.setCurrentPosition(0);  
}   
  
void loop()   
{   
  stepper.moveTo(8000);  
  stepper.runToPosition();  
  motorPosition = stepper.currentPosition();  
  Serial.println(motorPosition);  
  stepper.stop();  
  delay(1000);  
  
  stepper.moveTo(0);  
  stepper.runToPosition();  
  motorPosition = stepper.currentPosition();  
  Serial.println(motorPosition);  
  delay(1000);  
}   
  
void stepper_init(){   
  stepper.setMaxSpeed(2000);   
  stepper.setAcceleration(1500);   
}  

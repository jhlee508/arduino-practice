#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
byte p20[8]={
  B00001,
  B00001, 
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
};
byte p40[8]={
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
};
byte p60[8]={
  B00111,
  B00111,
  B00111,
  B00111,
  B00111,
  B00111,
  B00111,
  B00111,
};
byte p80[8]={
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
};
byte p100[8]={
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2); //Set up the LCDs number of columns and rows
  lcd.print("Jeremy's Display"); // Print a message to the LCD
  lcd.createChar(0, p20); //Make progress characters
  lcd.createChar(1, p40);
  lcd.createChar(2, p60);
  lcd.createChar(3, p80);
  lcd.createChar(4, p100);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("                "); //Clear the line each time it reaches the end with 16 " " (spaces)
  lcd.setCursor(0,1); //Move cursor to second line
  lcd.print("                "); //Clear the line each time it reaches the end with 16 " " (spaces)
  
  for (int i = 15; i >= 0; i--) { //Iterate through each character on the second line
    for (int j = 0; j < 4; j++) { //Iterate through each progress value for each character
      
      lcd.setCursor(i, 0); //Move the cursor to this location
      lcd.write(j); //Update progress bar
      lcd.setCursor(i, 1); //Move the cursor to this location
      lcd.write(j); //Update progress bar
      delay(100); //Wait
    }
  }
}

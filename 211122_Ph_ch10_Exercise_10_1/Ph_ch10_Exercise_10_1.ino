#include <LiquidCrystal.h> //Include the library code:

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //Initialize the library with the numbers of the interface pins
int cursorX = 0;
int cursorY = 0;

void setup()
{
  lcd.begin(16, 2); //Set up the LCD's number of columns and rows:
  
}
void loop()
{ 
  if (cursorX == 15 && cursorY == 1) {
     cursorX = 0;
     cursorY = 0;
  }
  if (cursorX == 15 && cursorY == 0) {
    cursorX = 0;
    cursorY = 1;
  }
  
  lcd.setCursor(cursorX, cursorY); //Move cursor to second line, first position
  lcd.print("SKKU"); //Print a message to the LCD.
  delay(1000);
  lcd.clear();
  cursorX++;
}

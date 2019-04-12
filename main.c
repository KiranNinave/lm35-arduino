#include <LiquidCrystal.h>
int val;
int tempPin = 1;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("getting ready...");
    delay(1000);
    lcd.clear();
}

void loop()
{
    val = analogRead(tempPin);
    float mv = (val * 4.88);
    float cel = mv / 10;

    lcd.setCursor(0, 0);
    lcd.print("TEMP = ");
    lcd.print(cel);
    lcd.print("*C");

    delay(1000);
}
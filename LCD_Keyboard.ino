//written by @M1ssing0 on github/M1ssing0#5061 on discord

#include <LiquidCrystal.h>

// boolean for program to know when there is text input available. this is so the LCD doesn't print anything but the string.
boolean newData = false;

// stores text input
String textInput;

// -Setup for LCD- Defines contrast amount. Sets LCD pins
int Contrast=75;
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  Serial.println("<Arduino is ready>");

  // sets contrast and starts LCD
  analogWrite(6,Contrast);
  lcd.begin(16, 2);
}

// clears LCD. reads serial for text input. assigns text input as a string. newData is turned to true
void recieveInput() {
  if (Serial.available() > 0) {
        lcd.clear();
        textInput = Serial.readString();
        newData = true;
    }
}

//  if newData is set to true. prints string from textInput. sets newData to false
void outputText() {
  if (newData == true) {
    lcd.setCursor(0, 0);
    lcd.print(textInput);
    newData = false;
  }
}

void loop() {
  recieveInput();
  outputText();
}

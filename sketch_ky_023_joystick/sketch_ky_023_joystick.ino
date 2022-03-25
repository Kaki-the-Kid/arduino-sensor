#include <LiquidCrystal.h>

/*
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K pot:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */
 
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


int value = 0;
int x_axis = A0;
int y_axis = A1;
int joy_button_pin = 8;

String directionString(int x, int y) {
  String direction = String(x, DEC);
  
  if ( x <= 450)
    direction  = "Bottom ";
  else  if ( x >= 550 )
    direction  = "Top ";
  else if ( x > 450 && x < 550)
    direction = "Middle ";

  if ( y < 450)
    direction += "- Left  ";
  else if ( y > 550 )
    direction += "- Right ";
  else
    direction += "- Center";
  
  return direction;
}

void setup() {
  pinMode(x_axis, INPUT);
  pinMode(y_axis, INPUT);
  pinMode(joy_button_pin, INPUT_PULLUP); //set pin 7 as an input and enable the internal pull-up resistor

  Serial.begin(9600);

  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  lcd.print("               "); // Print a message to the LCD.
}

void loop() {
  int x_value = analogRead(x_axis); // read X axis value [0..1023]
  Serial.print("X:");
  Serial.print(x_value, DEC);
  
  int y_value = analogRead(y_axis); // read Y axis value [0..1023]
  Serial.print(" | Y:");
  Serial.print(y_value, DEC);
  
  int b_value = digitalRead(joy_button_pin); // read Button state [0,1]
  Serial.print(" | Button:");
  Serial.println(b_value, DEC);

  lcd.setCursor(0, 0);
  lcd.print( directionString(x_value, y_value) );
  delay(100);
}

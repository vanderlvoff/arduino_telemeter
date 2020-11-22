// vanderlvoff
// 2020.11.22
#include "SR04.h"
#include <LiquidCrystal_I2C.h>

#define TRIG_PIN 12
#define ECHO_PIN 11

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
   Serial.begin(9600);//Initialization of Serial Port

   lcd.begin(16,2);  // initialize the LCD
   lcd.print("Started...");
   delay(1000);
}

void loop() {
   a=sr04.Distance();
   lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print(a);
   lcd.print("cm");
   delay(1000);
}

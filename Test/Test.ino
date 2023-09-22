#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

byte fill[] = {
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F
 } ;

byte halfFill1[] = {
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x00,
  0x00,
  0x00,
  0x00
};

byte halfFill2[] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x1F,
  0x1F,
  0x1F,
  0x1F
};

void defaultEye(){
  lcd.clear();
  lcd.setCursor(5,0); 
  lcd.write(0);
  lcd.setCursor(10,0); 
  lcd.write(0);
  lcd.setCursor(5,1); 
  lcd.write(0);
  lcd.setCursor(10,1); 
  lcd.write(0);
}

void half(){
  lcd.clear();
  lcd.setCursor(5,0); 
  lcd.write(2);
  lcd.setCursor(10,0); 
  lcd.write(2);
  lcd.setCursor(5,1); 
  lcd.write(1);
  lcd.setCursor(10,1); 
  lcd.write(1);
}
          
void setup() {
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  lcd.createChar(0,fill);
  lcd.createChar(1,halfFill1);
  lcd.createChar(2,halfFill2);
  
//  // Print a message on both lines of the LCD.
//  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
//  lcd.print("Hello world!");


}

void loop() {
  defaultEye();
  delay(1000);
  half();
  delay(1000);
}

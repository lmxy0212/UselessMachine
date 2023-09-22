#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display
int randNumber = 0;
int seconds;
int counter;
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

//draw a random action 
void randomAction(){  
  randNumber = random(1,5);
  Serial.println(randNumber);
  
  switch (randNumber) {
    case 1: 
      lcd.print("1");
      Serial.println("1");
      break;
     case 2: 
       lcd.print("2");
      Serial.println("2");
      break;
     case 3:
       lcd.print("3");
      Serial.println("3");
      break;
    default: 
      lcd.print("Default");
      Serial.println("Default");
      break;
  }
}

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.clear();         
  lcd.backlight();    
  
//  // Print a message on both lines of the LCD.
//  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
//  lcd.print("Hello world!");


}

void loop() {
  lcd.clear();
  lcd.setCursor(1,0); 
  lcd.print("rand= ");
  lcd.setCursor(9,0); 
  randomAction();
  seconds = millis();


  delay(3000);
}

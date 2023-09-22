// include the library code:
#include <LiquidCrystal.h>
#include <ESP32Servo.h>

Servo servo;
int pos = 0;    // variable to store the servo position


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int touchReading = 0;

int randNumber = 0;
byte smiley[8] = {
0b00000,
0b00000,
0b01010,
0b00000,
0b00000,
0b10001,
0b01110,
0b00000
};

byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};

void setup(){
  Serial.begin(9600);

  // create a new character
  lcd.createChar(3, smiley);
  // create a new character
  lcd.createChar(2, frownie);

   // set the cursor to the top left
  lcd.setCursor(0, 0);

  // Print a message to the lcd.
  lcd.print("I ");
  lcd.write(byte(0));
  
  servo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void servoController(boolean control = false){
  if(control == true){
      for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
  }else{
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      servo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  }   
}


//draw a random action 
void randomAction(){
  randNumber = random(1,5);
  Serial.println(randNumber);
  
  switch (randNumber) {
    case 1: // cry  (╥﹏╥)
      // statements
      lcd.write(byte(2));
      servoController(true);
      Serial.println("crying");
      break;
     case 2: // angry •`_´•
      // statements
      lcd.write(byte(2));
      servoController(true);
      Serial.println("angry");
      break;
     case 3: // laugh (ˣ∇ˣ)
      // statements
      lcd.write(byte(3));
      Serial.println("LOL");
      break;
    default: // poker face (0 _ 0)   (=____=)
      // statements
      lcd.write(byte(2));
      Serial.println("poker face");
      break;
  }
}

void loop(){
  lcd.clear();
  touchReading = touchRead(4);
  Serial.println(touchReading);
  if(touchReading < 20){
    randomAction();
  }
  delay(10);
}

  

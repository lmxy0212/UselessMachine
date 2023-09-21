#include "Arduino.h"

int touchReading = 0;



void setup(){
  Serial.begin(9600);
}

//draw a random action
void randomAction(){
  switch (randNumber) {
    case 1:
      // statements
      break;
    case 2:
      // statements
      break;
     case 3:
      // statements
      break;
     case 4:
      // statements
      break;
    default:
      // statements
      break;
  }
void loop(){
  randNumber = random(1,5);
  Serial.println(randNumber);
  touchReading = touchRead(4);
  Serial.println(touchReading);
  if(touchReading < 20){
    randomAction();
  }
}

  


  delay(10);
}

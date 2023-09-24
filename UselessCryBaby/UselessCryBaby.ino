#include <LiquidCrystal_I2C.h>
#define fsrpin A0

int fsrreading;
LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display
int randNumber = 5;
int seconds;
int counter;
int previous = 0;
int animateTime = 3;
int comp; 
int delayTime = 500;

byte cry11[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000
};

byte cry12[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte cry21[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000
};

byte cry22[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111
};

byte angry11[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111
};

byte angry12[] = {
  B00000,
  B00000,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000
};

byte angry21[] = {
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte angry22[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000
};

byte angry23[] = {
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000
};

byte angry24[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111
};

byte angry25[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00010,
  B00010,
  B00010,
  B00010
};
byte angry26[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B01000,
  B01000,
  B01000,
  B01000
};

byte angry27[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000
};

byte happy11[] = {
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00011,
  B00011
};

byte happy12[] = {
  B00000,
  B11111,
  B11111,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111
};

byte happy13[] = {
  B00000,
  B00000,
  B11111,
  B11111,
  B00000,
  B00000,
  B11000,
  B11000
};
byte happy14[] = {
  B00000,
  B00000,
  B11111,
  B11111,
  B00000,
  B00000,
  B00011,
  B00011
};
byte happy15[] = {
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B11000,
  B11000
};
byte happy16[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B00011,
  B00011,
  B00000,
  B00000
};
byte happy17[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111
};
byte happy18[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11000,
  B11000,
  B00000,
  B00000
};
byte happy21[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B11111
};
byte happy22[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B00000,
  B11111
};
byte happy23[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};
byte happy24[] = {
  B11111,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111
};
byte happy25[] = {
  B11111,
  B00000,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000
};
byte happy26[] = {
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte smile11[] = {
  B00000,
  B00000,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000
};
byte smile12[] = {
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};
byte smile13[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000
};
byte smile14[] = {
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte smile21[] = {
  B00000,
  B00000,
  B11111,
  B11111,
  B00000,
  B00000,
  B11111,
  B11111
};
byte smile22[] = {
  B11111,
  B11111,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111
};
byte smile23[] = {
  B11111,
  B11111,
  B00000,
  B00000,
  B11111,
  B11111,
  B00000,
  B00000
};
byte smile24[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000
};
byte smile25[] = {
B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte smile26[] = {
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};
byte heart11[] = {
  B00000,
  B00000,
  B00011,
  B00011,
  B11111,
  B11111,
  B11111,
  B11111
};
byte heart12[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11000,
  B11000,
  B11111,
  B11111
};
byte heart13[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00011,
  B00011,
  B11111,
  B11111
};
byte heart14[] = {
  B00000,
  B00000,
  B11000,
  B11000,
  B11111,
  B11111,
  B11111,
  B11111
};
byte heart15[] = {
  B00011,
  B00011,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte heart16[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B00011,
  B00011,
  B00000,
  B00000
};
byte heart17[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11000,
  B11000,
  B00000,
  B00000
};
byte heart18[] = {
  B11000,
  B11000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte heart21[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00011,
  B00011,
  B00011,
  B00011
};
byte heart22[] = {
  B00111,
  B00111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte heart23[] = {
  B00000,
  B00000,
  B11000,
  B11000,
  B11111,
  B11111,
  B11111,
  B11111
};
byte heart24[] = {
  B00000,
  B00000,
  B00011,
  B00011,
  B11111,
  B11111,
  B11111,
  B11111
};
byte heart25[] = {
  B11100,
  B11100,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte heart26[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11000,
  B11000,
  B11000,
  B11000
};
byte heart27[] = {
  B11111,
  B11111,
  B00011,
  B00011,
  B00000,
  B00000,
  B00000,
  B00000
};
byte heart28[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B00011,
  B00011
};
byte heart29[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11000,
  B11000
};
byte heart210[] = {
  B11111,
  B11111,
  B11000,
  B11000,
  B00000,
  B00000,
  B00000,
  B00000
};

void heart(){
  for (int i=0; i < animateTime; i++)
 {
  lcd.clear();
  lcd.createChar(1, heart11);
  lcd.createChar(2, heart12);
  lcd.createChar(3, heart13);
  lcd.createChar(4, heart14);
  lcd.createChar(5, heart15);
  lcd.createChar(6, heart16);
  lcd.createChar(7, heart17);
  lcd.createChar(8, heart18);
  //(3,0) && (9,0)
  lcd.setCursor(3,0); 
  lcd.write(1);
  lcd.setCursor(9,0); 
  lcd.write(1);
  //(4,0) && (10,0)
  lcd.setCursor(4,0); 
  lcd.write(2);
  lcd.setCursor(10,0); 
  lcd.write(2);
  //(5,0) && (11,0)
  lcd.setCursor(5,0); 
  lcd.write(3);
  lcd.setCursor(11,0); 
  lcd.write(3);
  //(6,0) && (12,0)
  lcd.setCursor(6,0); 
  lcd.write(4);
  lcd.setCursor(12,0); 
  lcd.write(4);
  //(3,1) && (9,1)
  lcd.setCursor(3,1); 
  lcd.write(5);
  lcd.setCursor(9,1); 
  lcd.write(5);
  //(4,1) && (10,1)
  lcd.setCursor(4,1); 
  lcd.write(6);
  lcd.setCursor(10,1); 
  lcd.write(6);
  //(5,1) && (11,1)
  lcd.setCursor(5,1); 
  lcd.write(7);
  lcd.setCursor(11,1); 
  lcd.write(7);
  //(6,1) && (12,1)
  lcd.setCursor(6,1); 
  lcd.write(8);
  lcd.setCursor(12,1); 
  lcd.write(8);
  delay(delayTime);

  lcd.clear();
//  lcd.createChar(1, heart21);
  lcd.createChar(1, heart22);
  lcd.createChar(2, heart23);
  lcd.createChar(3, heart24);
  lcd.createChar(4, heart25);
//  lcd.createChar(6, heart26);
  lcd.createChar(5, heart27);
  lcd.createChar(6, heart28);
  lcd.createChar(7, heart29);
  lcd.createChar(8, heart210);
//  //(2,0) & (8,0)
//  lcd.setCursor(2,0); 
//  lcd.write(1);
//  lcd.setCursor(8,0); 
//  lcd.write(1);
  //(4,0) & (9,0)
  lcd.setCursor(3,0); 
  lcd.write(1);
  lcd.setCursor(9,0); 
  lcd.write(1);
  //(5,0) & (10,0)
  lcd.setCursor(4,0); 
  lcd.write(2);
  lcd.setCursor(10,0); 
  lcd.write(2);
  //(6,0) & (11,0)
  lcd.setCursor(5,0); 
  lcd.write(3);
  lcd.setCursor(11,0); 
  lcd.write(3);
  //(7,0) & (12,0)
  lcd.setCursor(6,0); 
  lcd.write(4);
  lcd.setCursor(12,0); 
  lcd.write(4); 
  //(8,0) & (13,0)
//  lcd.setCursor(7,0); 
//  lcd.write(6);
//  lcd.setCursor(13,0); 
//  lcd.write(6); 

  //(3,1) && (9,1)
  lcd.setCursor(3,1); 
  lcd.write(5);
  lcd.setCursor(9,1); 
  lcd.write(5); 
  //(4,1) && (10,1)
  lcd.setCursor(4,1); 
  lcd.write(6);
  lcd.setCursor(10,1); 
  lcd.write(6); 
  //(5,1) && (11,1)
  lcd.setCursor(5,1); 
  lcd.write(7);
  lcd.setCursor(11,1); 
  lcd.write(7); 
  //(6,1) && (12,1)
  lcd.setCursor(6,1); 
  lcd.write(8);
  lcd.setCursor(12,1); 
  lcd.write(8); 
  delay(delayTime);
  }
}

void smileyFace(){
  for (int i=0; i < animateTime; i++)
 {
  lcd.clear();
  lcd.createChar(1, smile11);
  lcd.createChar(2, smile12);
  lcd.createChar(3, smile13);
  lcd.createChar(4, smile14);
  //(3,0) & (6,0) && (9,0) & (12,0)
  lcd.setCursor(3,0); 
  lcd.write(1);
  lcd.setCursor(6,0); 
  lcd.write(1);
  lcd.setCursor(9,0); 
  lcd.write(1);
  lcd.setCursor(12,0); 
  lcd.write(1);
  //(4,0) & (5,0) && (10,0) & (11,0)
  lcd.setCursor(4,0); 
  lcd.write(2);
  lcd.setCursor(5,0); 
  lcd.write(2);
  lcd.setCursor(10,0); 
  lcd.write(2);
  lcd.setCursor(11,0); 
  lcd.write(2);
  //(3,1) & (6,1) && (9,1) & (12,1)
  lcd.setCursor(3,1); 
  lcd.write(3);
  lcd.setCursor(6,1); 
  lcd.write(3);
  lcd.setCursor(9,1); 
  lcd.write(3);
  lcd.setCursor(12,1); 
  lcd.write(3);
  //(4,1) & (5,1) && (10,1) & (11,1)
  lcd.setCursor(4,1); 
  lcd.write(4);
  lcd.setCursor(5,1); 
  lcd.write(4);
  lcd.setCursor(10,1); 
  lcd.write(4);
  lcd.setCursor(11,1); 
  lcd.write(4);
  delay(delayTime);

  lcd.createChar(1, smile21);
  lcd.createChar(2, smile22);
  lcd.createChar(3, smile23);
  lcd.createChar(4, smile24);
  lcd.createChar(5, smile25);
  lcd.createChar(6, smile26);
  //(3,0) & (6,0) && (9,0) & (12,0)
  lcd.setCursor(3,0); 
  lcd.write(1);
  lcd.setCursor(6,0); 
  lcd.write(1);
  lcd.setCursor(9,0); 
  lcd.write(1);
  lcd.setCursor(12,0); 
  lcd.write(1);
  //(4,0) && (10,0) 
  lcd.setCursor(4,0); 
  lcd.write(2);
  lcd.setCursor(10,0); 
  lcd.write(2);
  //(5,0) && (11,0) 
  lcd.setCursor(5,0); 
  lcd.write(3);
  lcd.setCursor(11,0); 
  lcd.write(3);
  //(3,1) & (6,1) && (9,1) & (12,1)
  lcd.setCursor(3,1); 
  lcd.write(4);
  lcd.setCursor(6,1); 
  lcd.write(4);
  lcd.setCursor(9,1); 
  lcd.write(4);
  lcd.setCursor(12,1); 
  lcd.write(4);
  //(4,1)&& (10,1) 
  lcd.setCursor(4,1); 
  lcd.write(5);
  lcd.setCursor(10,1); 
  lcd.write(5);
  //(5,1) && (11,1) 
  lcd.setCursor(5,1); 
  lcd.write(6);
  lcd.setCursor(11,1); 
  lcd.write(6);
  delay(delayTime);
 }
}

void happyFace(){
 for (int i=0; i < animateTime; i++)
 {
  lcd.clear();
  lcd.createChar(1, happy11);
  lcd.createChar(2, happy12);
  lcd.createChar(3, happy13);
  lcd.createChar(4, happy14);
  lcd.createChar(5, happy15);
  lcd.createChar(6, happy16);
  lcd.createChar(7, happy17);
  lcd.createChar(8, happy18);
  //(4,0) 
  lcd.setCursor(4,0); 
  lcd.write(1);
  //(5,0) & (11,0)
  lcd.setCursor(10,0); 
  lcd.write(2);
  lcd.setCursor(5,0); 
  lcd.write(2); 
  //(6,0) 
  lcd.setCursor(6,0); 
  lcd.write(3);
  //(9,0) 
  lcd.setCursor(9,0); 
  lcd.write(4);
  //(11,0)
  lcd.setCursor(11,0); 
  lcd.write(5);
  //(4,1) & (9,1)
  lcd.setCursor(4,1); 
  lcd.write(6);
  lcd.setCursor(9,1); 
  lcd.write(6);
  //(5,1) & (10,1)
  lcd.setCursor(5,1); 
  lcd.write(7);
  lcd.setCursor(10,1); 
  lcd.write(7);
  //(6,1) & (11,1)
  lcd.setCursor(6,1); 
  lcd.write(8);
  lcd.setCursor(11,1); 
  lcd.write(8);
  delay(delayTime);

  lcd.clear();
  lcd.createChar(1, happy21);
  lcd.createChar(2, happy22);
  lcd.createChar(3, happy23);
  lcd.createChar(4, happy24);
  lcd.createChar(5, happy25);
  lcd.createChar(6, happy26);
  
  //(3,0) & (12,0) 
  lcd.setCursor(3,0); 
  lcd.write(1);
  lcd.setCursor(12,0); 
  lcd.write(1);
  //(4,0) & (11,0) 
  lcd.setCursor(4,0); 
  lcd.write(2);
  lcd.setCursor(11,0); 
  lcd.write(2);
  //(5,0) & (6,0) && (9,0) & (10,0)
  lcd.setCursor(5,0); 
  lcd.write(3);
  lcd.setCursor(6,0); 
  lcd.write(3);
  lcd.setCursor(9,0); 
  lcd.write(3);
  lcd.setCursor(10,0); 
  lcd.write(3);
  //(3,1) & (12,1)
  lcd.setCursor(3,1); 
  lcd.write(4);
  lcd.setCursor(12,1); 
  lcd.write(4);
  //(4,1) & (11,1)
  lcd.setCursor(4,1); 
  lcd.write(5);
  lcd.setCursor(11,1); 
  lcd.write(5);
  //(5,1) & (6,1) && (9,1) & (10,1)
  lcd.setCursor(5,1); 
  lcd.write(6);
  lcd.setCursor(6,1); 
  lcd.write(6);
  lcd.setCursor(9,1); 
  lcd.write(6);
  lcd.setCursor(10,1); 
  lcd.write(6);
  delay(delayTime);
 }
}
void angryFace(){
  lcd.createChar(4, angry11);
  lcd.createChar(5, angry12);
  lcd.createChar(6, angry21);
  lcd.createChar(7, angry22);
  lcd.createChar(8, angry23);
  lcd.createChar(9, angry24);
  lcd.createChar(10, angry25);
  lcd.createChar(11, angry26);
  lcd.createChar(12, angry27);


 for (int i=0; i < animateTime; i++)
    {
      lcd.clear();
      //(3,0) & (4,0) & (5,0) & (6,0) && (9,0) & (10,0) & (11,0) & (12,0) 
      lcd.setCursor(3,0); 
      lcd.write(4);
       lcd.setCursor(4,0); 
      lcd.write(4);
       lcd.setCursor(5,0); 
      lcd.write(4);
       lcd.setCursor(6,0); 
      lcd.write(4);
       lcd.setCursor(9,0); 
      lcd.write(4);
       lcd.setCursor(10,0); 
      lcd.write(4);
       lcd.setCursor(11,0); 
      lcd.write(4);
       lcd.setCursor(12,0); 
      lcd.write(4);

      //(3,1) & (4,1) & (5,1) & (6,1) && (9,1) & (10,1) & (11,1) & (12,1) 
       lcd.setCursor(3,1); 
      lcd.write(5);
       lcd.setCursor(4,1); 
      lcd.write(5);
       lcd.setCursor(5,1); 
      lcd.write(5);
       lcd.setCursor(6,1); 
      lcd.write(5);
       lcd.setCursor(9,1); 
      lcd.write(5);
       lcd.setCursor(10,1); 
      lcd.write(5);
       lcd.setCursor(11,1); 
      lcd.write(5);
       lcd.setCursor(12,1); 
      lcd.write(5);
      delay(delayTime);
  
  //(3,0) & (12,0)
  lcd.setCursor(3,0); 
  lcd.write(6);
   lcd.setCursor(12,0); 
  lcd.write(6);

  // (4,0) & (11,0) && (4,1) & (11,1)   
   lcd.setCursor(4,0); 
  lcd.write(7);
  lcd.setCursor(11,0); 
  lcd.write(7);
  lcd.setCursor(4,1); 
  lcd.write(7);
  lcd.setCursor(11,1); 
  lcd.write(7);

  //(5,0) & (10,0)
  lcd.setCursor(10,0); 
  lcd.write(8);
  lcd.setCursor(5,0); 
  lcd.write(8);

  //(6,0) & (9,0)
  lcd.setCursor(6,0); 
  lcd.write(9);
  lcd.setCursor(9,0); 
  lcd.write(9);
  //(7,0)
  lcd.setCursor(7,0); 
  lcd.write(10);
  //(8,0)
  lcd.setCursor(8,0); 
  lcd.write(11);
  //(4,1) & (11,1)
  lcd.setCursor(4,1); 
  lcd.write(12);
  lcd.setCursor(11,1); 
  lcd.write(12);
  delay(delayTime);
    }
  
}

void cryingFace(){
  lcd.createChar(0, cry11);
  lcd.createChar(1, cry12);
  lcd.createChar(2, cry21);
  lcd.createChar(3, cry22);

  for (int i=0; i < animateTime; i++)
    {
      lcd.clear();
       // (4,0) & (6,0) & (9,0) & (11,0) 
      lcd.setCursor(4,0); 
      lcd.write(0);
       lcd.setCursor(6,0); 
      lcd.write(0);
       lcd.setCursor(9,0); 
      lcd.write(0);
       lcd.setCursor(11,0); 
      lcd.write(0);
      //(5,0) & (10,0)
      lcd.setCursor(5,0); 
      lcd.write(1);
      lcd.setCursor(10,0); 
      lcd.write(1);
      delay(delayTime);
      
      //(5,1)&(10,1)
      lcd.setCursor(5,1); 
      lcd.write(3);
      lcd.setCursor(10,1); 
      lcd.write(3);
      delay(delayTime);
    }
}


//draw a random action 
void randomAction(){  
  randNumber = random(1,6);
  
  switch (randNumber) {
    case 1: 
//      lcd.print("1");
      heart();
      Serial.println("heart");
      break;
     case 2: 
//       lcd.print("2");
      smileyFace();
      Serial.println("simley");
      break;
     case 3:
//       lcd.print("3");
      happyFace();
      Serial.println("happy");
      break;
    case 4:
//       lcd.print("3");
      angryFace();
      Serial.println("angry");
      break;
    default: 
//      lcd.print("Default");
      cryingFace();
      Serial.println("crying");
      break;
  }
  randNumber = 5;
}


/////////////////////////////////////////////////////


int touchSensor(){
   comp = analogRead(A0);   
   comp = map(comp, 0, 1023, 1023, 0);
   Serial.print("Reading =");
   Serial.println(comp);
   return comp;
}


void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.clear();         
  lcd.backlight(); 

// 
//  // Print a message on both lines of the LCD.
//  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
//  lcd.print("Hello world!");
}

void loop() {
//  cryingFace();
    // (4,0) & (6,0) & (9,0) & (11,0) 
    lcd.createChar(1, cry12);
    //(5,0) & (10,0)
    lcd.setCursor(5,0); 
    lcd.write(1);
    lcd.setCursor(10,0); 
    lcd.write(1);
    lcd.setCursor(5,1); 
    lcd.write(1);
    lcd.setCursor(10,1); 
    lcd.write(1);
  fsrreading = analogRead(fsrpin);
  // Print the fsrreading in the serial monitor:
  // Print the string "Analog reading = ".
  Serial.print("Analog reading = ");
  // Print the fsrreading:
  Serial.println(fsrreading);

  if (fsrreading > 40) {
    Serial.println("touch");
    lcd.clear();  
    randomAction();
    lcd.clear();  
  }

//  if(touchSensor() <= 50 ){
//    randomAction();
//  }
//  delay(1000);
}

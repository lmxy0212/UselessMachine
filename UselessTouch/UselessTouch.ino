#include "Arduino.h"
#include "heltec.h"


int touchReading = 0;

void setup(){
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);
  Heltec.display->flipScreenVertically();
  Heltec.display->setFont(ArialMT_Plain_24);
}

void drawText() {
    Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
    Heltec.display->setFont(ArialMT_Plain_24);
//    Heltec.display->drawString(0, 26, "Hello world");
    touchReading = touchRead(touchRead(T0));
    if(touchReading < 10){
      Heltec.display->drawString(0, 26, "Touching");
    }else{
      Heltec.display->drawString(0, 26, "NOT Touching");
    }
    Serial.print("Touch0 value is = ");
    Serial.println(touchReading);
}

void loop(){
  


    // clear the display
  Heltec.display->clear();
  // draw the current demo method
  drawText();

  Heltec.display->setTextAlignment(TEXT_ALIGN_RIGHT);
  Heltec.display->drawString(10, 128, String(millis()));
  // write the buffer to the display
  Heltec.display->display();

  delay(10);
}

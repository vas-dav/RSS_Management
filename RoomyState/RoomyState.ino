#include "lcd.h"
int buttonState = 0; 
Counter c (0, 3);

void setup() {
  lcdAwake();
  pinMode(BI, INPUT);
}

void loop() {
  buttonState = digitalRead(BI);

  if(buttonState){
    c.inc();
    delay(300);
  }

  switch(c.getInit()){
    case 0:
      setHome();
    case 1:
      setAway();
    case 2:
      setBusy();
    case 3:
      setCome();
    default:
      break;
  }

}

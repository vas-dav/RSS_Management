#include "lcd.h"
#include "led.h"
int initial = 0;
int buttonState = 0;
int curr;
float temp, humid;
DHT sens(THERM_I, DHT11);
bool conn = true;
int incom = 0;
char *mess;
unsigned long lastTime;
Counter c (initial, 3);
bool sent = true;


void setup() {
  Serial.begin(57600);
  pinMode(BI, INPUT);
  initial = EEPROM.read(0);
  if(initial!= 255){
    c.setInit(initial);
  }
  sens.begin();
  lcdAwake();
  RGBinit();
  hexToRGB("ffffff");
   while(conn){
    setText("Waking up...");
    if (Serial.available() > 0){
      incom = Serial.read();
     if((char)incom == '#'){
      Serial.print("$");
      conn = false;
      setText("USB connected");
    }
    }
  }
  switch(c.getInit()){
    case 0:
      hexToRGB("0000ff"); 
      //delay(AFT_FUN);
      break;
    case 1:
      hexToRGB("ff5200");
      //delay(AFT_FUN);
      break;
    case 2:
      hexToRGB("ff0000");
      //delay(AFT_FUN);
      break;
    case 3:
      hexToRGB("00FF00");
      //delay(AFT_FUN);
      break;
    default:
      break;
  }
}

void loop() {
  buttonState = digitalRead(BI);
  temp = sens.readTemperature();
  humid = sens.readHumidity();
  curr = c.getInit();
  if(millis() - lastTime > 5000 && !sent){
    switch(curr){
    case 0:
      setHome(temp, humid); 
      //delay(AFT_FUN);
      break;
    case 1:
      setAway(temp, humid);
      //delay(AFT_FUN);
      break;
    case 2:
      setBusy(temp, humid);
      //delay(AFT_FUN);
      break;
    case 3:
      setCome(temp, humid);
      //delay(AFT_FUN);
      break;
    default:
      break;
  }
  sent = true;
  }
  if(buttonState){
    while(buttonState) buttonState = digitalRead(BI);
    c.inc();
    curr = c.getInit();
    lastTime = millis();
    switch(curr){
    case 0:
      hexToRGB("0000ff"); 
      //delay(AFT_FUN);
      break;
    case 1:
      hexToRGB("ff5200");
      //delay(AFT_FUN);
      break;
    case 2:
      hexToRGB("ff0000");
      //delay(AFT_FUN);
      break;
    case 3:
      hexToRGB("00FF00");
      //delay(AFT_FUN);
      break;
    default:
      break;
  }
  sent = false;
 
  }
    displayFloat(temp, true);
    displayFloat(humid, false);

}

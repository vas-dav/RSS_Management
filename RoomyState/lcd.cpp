#include "lcd.h"
#include "Arduino.h"
LiquidCrystal lcd(RS, ENA, D4, D5, D6, D7);

void lcdAwake(){
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(1, 0);
}

void setHome(float temp, float hum){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Currently Home");
  
  Serial.print('#');
  Serial.print('H');
  Serial.print('#');
  Serial.print(temp, 2);
  Serial.print('#');
  Serial.print(hum, 2);
  Serial.print(';');
  EEPROM.write(0, 0);
}

void setAway(float temp, float hum){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Not Home");
  Serial.print('#');
  Serial.print('A');
  Serial.print('#');
  Serial.print(temp, 2);
  Serial.print('#');
  Serial.print(hum, 2);
  Serial.print(';');
  EEPROM.write(0, 1);
}

void setBusy(float temp, float hum){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Currently Busy");
  Serial.print('#');
  Serial.print('B');
  Serial.print('#');
  Serial.print(temp, 2);
  Serial.print('#');
  Serial.print(hum, 2);
  Serial.print(';');
  EEPROM.write(0, 2);
}

void setCome(float temp, float hum){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Come in!");
  Serial.print('#');
  Serial.print('C');
  Serial.print('#');
  Serial.print(temp, 2);
  Serial.print('#');
  Serial.print(hum, 2);
  Serial.print(';');
  EEPROM.write(0, 3);
}

void setText(char *s){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(s);
  
}

void displayFloat(float num, bool row){
  if(row){
    lcd.setCursor(0, 1);
    lcd.print("T:");
    lcd.setCursor(2, 1);
    lcd.print(num);
  }else{
    lcd.setCursor(8, 1);
    lcd.print("H:");
    lcd.setCursor(10,1);
    lcd.print(num);
    lcd.setCursor(15,1);
    lcd.print("%");
  }
}

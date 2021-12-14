#include "lcd.h"

void lcdAwake(){
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(" LCD awake ");
  delay(1500);
  lcd.clear();
}


void setHome(){
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(" Currently ");
  lcd.setCursor(1, 1);
  lcd.print(" Home ");
}

void setAway(){
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(" Currently ");
  lcd.setCursor(1, 1);
  lcd.print(" Not Home ");
}

void setBusy(){
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(" Currently ");
  lcd.setCursor(1, 1);
  lcd.print(" Busy ");
}

void setCome(){
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(" Free... ");
  lcd.setCursor(1, 1);
  lcd.print(" Come in! ");
}

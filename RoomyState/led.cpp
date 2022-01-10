#include "led.h"

void RGBinit() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  setColor(255, 0 ,0);
  
}

void setColor(int Rv, int Gv, int Bv){
  analogWrite(R, Rv);
  analogWrite(G, Gv);
  analogWrite(B, Bv);
}

void hexToRGB(char* hex){
  int r, g, b;
  if(sscanf(hex, "%02x%02x%02x", &r, &g, &b) == 3){
    setColor(r, g, b);
  }else{
    setColor(255, 255, 255);
  }
  
}

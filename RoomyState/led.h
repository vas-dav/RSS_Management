#ifndef led_h
#define led_h

#include "lib.h"
#include "Arduino.h"

enum RGBpins {R = 9, G = 10, B = 11};
void RGBinit();
void setColor(int Rv, int Gv, int Bv);
void hexToRGB(char* hex);
#endif

#ifndef lcd_h
#define lcd_h

#include "lib.h"

void lcdAwake();

//Displaying functions
void setHome(float temp, float hum);

void setAway(float temp, float hum);

void setBusy(float temp, float hum);

void setCome(float temp, float hum);

void setText(char* s);

void displayFloat(float num, bool row);

#endif

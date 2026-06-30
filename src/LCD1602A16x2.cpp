#include "../include/LCD1602A16x2.h"
#include <Arduino.h>


LCD1602A16x2::LCD1602A16x2(int RS, int RW, int E, int D0, int D1, int D2, int D3, int D4, int D5,
         int D6, int D7) {

  PinNames[EnPin] = E;

  PinNames[RSPin] = RS;
  PinNames[RWPin] = RW;


  PinNames[D0Pin] = D0;
  PinNames[D1Pin] = D1;
  PinNames[D2Pin] = D2;
  PinNames[D3Pin] = D3;

  PinNames[D4Pin] = D4;
  PinNames[D5Pin] = D5;
  PinNames[D6Pin] = D6;
  PinNames[D7Pin] = D7;

  


}

void LCD1602A16x2::pulseEnable() const {

}
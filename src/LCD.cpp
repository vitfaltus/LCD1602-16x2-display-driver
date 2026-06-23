#include "../include/LCD.h"


LCD::LCD(int RS, int RW, int E, int D0, int D1, int D2, int D3, int D4, int D5,
         int D6, int D7) {
  RSPin = RS;
  RWPin = RW;
  EnablePin = E;
  Bus8Bit[0] = D0;
  Bus8Bit[1] = D1;
  Bus8Bit[2] = D2;
  Bus8Bit[3] = D3;
  Bus4Bit[0] = D4;
  Bus4Bit[1] = D5;
  Bus4Bit[2] = D6;
  Bus4Bit[3] = D7;

  for (int i = 0; i < 4; i++) {
    pinMode(Bus8Bit[i], OUTPUT);
    pinMode(Bus4Bit[i], OUTPUT);
  }

  pinMode(RWPin, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(RS, OUTPUT);

  for (auto& it : PinStates) {
    it = false;
  }

}

void LCD::setPins() {}
#include "../include/LCD1602A16x2.h"
#include <Arduino.h>


LCD1602A16x2::LCD1602A16x2(int RS, int RW, int E, int D0, int D1, int D2, int D3, int D4, int D5,
         int D6, int D7) {

  PinNames[RSPin] = RS;
  PinNames[RWPin] = RW;
  PinNames[EnPin] = E;

  PinNames[D0Pin] = D0;
  PinNames[D1Pin] = D1;
  PinNames[D2Pin] = D2;
  PinNames[D3Pin] = D3;

  PinNames[D4Pin] = D4;
  PinNames[D5Pin] = D5;
  PinNames[D6Pin] = D6;
  PinNames[D7Pin] = D7;

  
  clearStates();

}
void LCD1602A16x2::clear() {
  PinStates[D0Pin] = true;

  execute();
}
void LCD1602A16x2::returnHome() {
  PinStates[D1Pin] = true;

  execute();
}
void LCD1602A16x2::displayOn() {
  PinStates[D2Pin] = true;
  PinStates[D3Pin] = true;

  execute();
}
void LCD1602A16x2::displayOff() {
  PinStates[D3Pin] = true;

  execute();
}
void LCD1602A16x2::write(uint8_t CharCode) {
  PinStates[RSPin] = true;

  //TODO: CharCode to pin conversion loop


  execute();
}

void LCD1602A16x2::clearStates() {
  for (int i = 1; i < NUMBER_OF_PINS; i++) {
    PinStates[i] = false;
  }
}


void LCD1602A16x2::setPins() const {
  for (int i = 1; i < NUMBER_OF_PINS; i++) {
    digitalWrite(PinNames[i], PinStates[i]);
  }
}
void LCD1602A16x2::sendAndClear() {

}

void LCD1602A16x2::execute() {
  setPins();
  sendAndClear();
}
void LCD1602A16x2::entryModeSet(const bool ToRight,
                                const bool ShiftOfEntireDisplay) {
  PinStates[D1Pin] = ToRight;
  PinStates[D0Pin] = ShiftOfEntireDisplay;

  execute();
}
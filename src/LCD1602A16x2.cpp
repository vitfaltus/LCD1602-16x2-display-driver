#include "../include/LCD1602A16x2.h"
#include <Arduino.h>


LCD1602A16x2::LCD1602A16x2(uint8_t RS, uint8_t RW, uint8_t E, uint8_t D0, uint8_t D1, uint8_t D2, uint8_t D3, uint8_t D4, uint8_t D5,
         uint8_t D6, uint8_t D7) {

  EnablePin = E;
  RWPin = RW;
  RSPin = RS;

  BusNames[0] = D0;
  BusNames[1] = D1;
  BusNames[2] = D2;
  BusNames[3] = D3;
  BusNames[4] = D4;
  BusNames[5] = D5;
  BusNames[6] = D6;
  BusNames[7] = D7;

  pinMode(EnablePin, OUTPUT);
  pinMode(RWPin, OUTPUT);
  pinMode(RSPin, OUTPUT);

  for (unsigned char BusName : BusNames) {
    pinMode(BusName, OUTPUT);
  }

}
void LCD1602A16x2::clearDisplay() const {
  sendData(LCD_CLEARDISPLAY);
}

void LCD1602A16x2::pulseEnable() const {
  digitalWrite(EnablePin, LOW);
  delayMicroseconds(1);
  digitalWrite(EnablePin, HIGH);
  delayMicroseconds(1);
  digitalWrite(EnablePin, LOW);
  delayMicroseconds(1);
}
void LCD1602A16x2::waitForNotBusy() const {
  pinMode(BusNames[7], INPUT);
  digitalWrite(RWPin, HIGH);
  digitalWrite(RSPin, LOW);
  pulseEnable();
  while (digitalRead(BusNames[7]) == HIGH) {
    pulseEnable();
  }
  pinMode(BusNames[7], OUTPUT);

}
void LCD1602A16x2::setBusPins(uint8_t data) const {
  for (uint_fast8_t i = 0; i < BUS_PINS; i++) {
    if (data % 2 == 0) {
      digitalWrite(BusNames[i], LOW);
    }
    else {
      digitalWrite(BusNames[i], HIGH);
    }
    data >>= 1;
  }
}


void LCD1602A16x2::sendData(const uint8_t data) const {
  waitForNotBusy();
  setBusPins(data);
  delayMicroseconds(1);
  pulseEnable();
}
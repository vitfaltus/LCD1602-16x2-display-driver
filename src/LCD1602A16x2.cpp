#include "../include/LCD1602A16x2.h"
#include <Arduino.h>

void LCD1602A16x2::automaticInit() const {
  delay(25);
  sendData(LCD_FUNCTIONSET | LCD_8BITMODE | LCD_2LINE | LCD_5x8DOTS);
  sendData(LCD_DISPLAYCONTROL | LCD_DISPLAYON | LCD_CURSORON);
  sendData(LCD_CLEARDISPLAY);
  sendData(LCD_ENTRYMODESET | LCD_ENTRYSHIFTDECREMENT | LCD_ENTRYLEFT);
}

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
    digitalWrite(BusName, LOW);
  }

  // write mode
  digitalWrite(RWPin, LOW);

  digitalWrite(RSPin, LOW);

  digitalWrite(EnablePin, LOW);



}
void LCD1602A16x2::init() {
  automaticInit();
}
void LCD1602A16x2::clearDisplay() const {

  sendData(LCD_CLEARDISPLAY);
}
void LCD1602A16x2::returnHome() const {

  sendData(LCD_RETURNHOME);
}
void LCD1602A16x2::write(char code) const {

  sendData(code, false);
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
  for (uint8_t i = 0; i < BUS_PINS; i++) {
    pinMode(BusNames[i], INPUT);
  }


  digitalWrite(RWPin, HIGH);
  digitalWrite(RSPin, LOW);


  digitalWrite(EnablePin, LOW);
  delayMicroseconds(1);
  digitalWrite(EnablePin, HIGH);

  while (digitalRead(BusNames[7]) == HIGH) {
    delayMicroseconds(1);
    digitalWrite(EnablePin, LOW);
    delayMicroseconds(1);
    digitalWrite(EnablePin, HIGH);
    Serial.print("Waiting for notBusy: ");
    Serial.println(digitalRead(BusNames[7]));
  }
  digitalWrite(EnablePin, LOW);
  for (uint8_t i = 0; i < BUS_PINS; i++) {
    pinMode(BusNames[i], OUTPUT);
  }

  // set to write mode
  digitalWrite(RWPin, LOW);

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


void LCD1602A16x2::sendData(const uint8_t data, bool is_instruction) const {
  waitForNotBusy();
  if (is_instruction) {
    digitalWrite(RSPin, LOW);
  }
  else {
    digitalWrite(RSPin, HIGH);
  }
  setBusPins(data);
  delayMicroseconds(1);
  pulseEnable();
}

void LCD1602A16x2::safeInit() const {
  delay(45);

  waitForNotBusy();

  digitalWrite(RWPin, LOW);
  digitalWrite(RSPin, LOW);

  sendData(LCD_FUNCTIONSET);
  delay(5);
  sendData(LCD_FUNCTIONSET);
  delay(1);
  sendData(LCD_FUNCTIONSET);

}


#ifndef LCD1602_16X2_DISPLAY_DRIVER_LCD_H
#define LCD1602_16X2_DISPLAY_DRIVER_LCD_H
#include <stdint.h>
#define BUS_PINS 8

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80


class LCD1602A16x2
{

  uint8_t EnablePin;
  uint8_t RWPin;
  uint8_t RSPin;

  uint8_t BusNames[BUS_PINS];

  void pulseEnable() const;

  void waitForNotBusy() const;

  void setBusPins(uint8_t data) const;

  void sendData(uint8_t data) const;




public:
  LCD1602A16x2(uint8_t RS, uint8_t RW, uint8_t E, uint8_t D0,uint8_t D1,uint8_t D2,uint8_t D3, uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7);
  void clearDisplay() const;
  void returnHome() const;

};


#endif //LCD1602_16X2_DISPLAY_DRIVER_LCD_H

//00000001
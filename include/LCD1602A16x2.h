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

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00


class LCD1602A16x2
{

  uint8_t EnablePin;
  uint8_t RWPin;
  uint8_t RSPin;

  uint8_t BusNames[BUS_PINS];

  void pulseEnable() const;

  void waitForNotBusy() const;

  void setBusPins(uint8_t data) const;

  // call this function only after writing rs and rw pins
  void sendData(uint8_t data, bool is_instruction = true) const;

  void safeInit() const;

  void automaticInit() const;





public:
  LCD1602A16x2(uint8_t RS, uint8_t RW, uint8_t E, uint8_t D0,uint8_t D1,uint8_t D2,uint8_t D3, uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7);

  void init();

  void clearDisplay() const;
  void returnHome() const;

  void write(char code) const;

};


#endif //LCD1602_16X2_DISPLAY_DRIVER_LCD_H
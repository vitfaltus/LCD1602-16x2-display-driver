#ifndef LCD1602_16X2_DISPLAY_DRIVER_LCD_H
#define LCD1602_16X2_DISPLAY_DRIVER_LCD_H
#include <stdint.h>
#include <Arduino.h>



class LCD
{
  enum PinOrder {
    Enable,
    RW,
    RS,
    D0,
    D1,
    D2,
    D3,
    D4,
    D5,
    D6,
    D7,
  };

  int Bus8Bit[4];
  int Bus4Bit[4];
  int EnablePin;
  int RWPin;
  int RSPin;

  bool PinStates[10];

  // Sets pins according PinStates array with indexing of PinOrder enum.
  void setPins();


public:
  LCD(int RS, int RW, int E, int D0,int D1,int D2,int D3, int D4, int D5, int D6, int D7);
  void clear();
  void setCursor(uint8_t x, uint8_t y);
  void write(char c);
  void backLight(bool enable);

};


#endif //LCD1602_16X2_DISPLAY_DRIVER_LCD_H
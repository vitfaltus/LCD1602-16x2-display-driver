#ifndef LCD1602_16X2_DISPLAY_DRIVER_LCD_H
#define LCD1602_16X2_DISPLAY_DRIVER_LCD_H
#include <stdint.h>
#define NUMBER_OF_PINS 11


class LCD1602A16x2
{
  enum PinOrder {
    EnPin,
    RSPin,
    RWPin,
    D0Pin,
    D1Pin,
    D2Pin,
    D3Pin,
    D4Pin,
    D5Pin,
    D6Pin,
    D7Pin,
  };

  int PinNames[NUMBER_OF_PINS]{};

  bool PinStates[NUMBER_OF_PINS]{};



  void pulseEnable() const;



public:
  LCD1602A16x2(int RS, int RW, int E, int D0,int D1,int D2,int D3, int D4, int D5, int D6, int D7);


};


#endif //LCD1602_16X2_DISPLAY_DRIVER_LCD_H
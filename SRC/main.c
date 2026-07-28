#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LED/LED_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/KEYPAD/KPD_Interface.h"



//static volatile uint8_t UartData = 0 ;
//======LCD==========
void main()
{
    LCD_Init(Lcd_8bitMode);
    KeyPad_Init();
    uint8_t keypadvalue=0XFF;

    while(1)
    {
      keypadvalue = KeyPad_Getpressedkey();
      if(keypadvalue!=0XFF){
          LCD_WriteData(keypadvalue,Lcd_8bitMode);

      }
    }
}


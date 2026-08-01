/**
 * @file    Full_Program.c
 * @author (developer)  
 * @author (reviewer)
 * @brief  
 * @details
 * @version
 * @date
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "Full_Interface.h"
#include "Full_Private.h"
#include "Full_Config.h"

#include <stdint.h>

#include "LCD_Interface.h"
#include "LED_Interface.h"
#include "UART_Interface.h"

#include "SpotCounter_Interface.h"

#include "Full_Interface.h"

uint8_t Full_IsFull()
{
    if(SpotCounter_GetAvailable() == 0)
    {
        return 1;
    }

    return 0;
}

void Full_Check(void)
{
    if(Full_IsFull())
    {
        Lcd_ClearScreen;
        LCD_WriteString("PARKING FULL", Lcd_4bitMode);
        LED_On(Dio_GroupB, Dio_Pin4, 1);
        LED_Off(Dio_GroupB, Dio_Pin3, 1);
         UART_SendStringPolling("PARKING FULL");
    }
    else
    {
        Lcd_ClearScreen;
        LCD_WriteString("PARKING AVAILABLE", Lcd_4bitMode);
         LED_On(Dio_GroupB, Dio_Pin3, 1);
        LED_Off(Dio_GroupB, Dio_Pin4, 1);
         UART_SendStringPolling("PARKING AVAILABLE");
    }
}
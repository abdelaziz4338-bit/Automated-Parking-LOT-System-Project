/**
 * @file    Idle_Program.c
 * @author (yousef)
 * @author (Eng/Hesham)
 * @brief  
 * @details
 * @version
 * @date
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "Idle_Interface.h"
#include "Idle_Private.h"
#include "Idle_Config.h"
#include "../Full/Full_Interface.h"
#include "../SpotCounter/SpotCounter_Interface.h"
#include "../../HAL/LCD/LCD_Interface.h"


void Idle_Init(){

Full_Deactivate();

}

void Idle_Run(void)
{
    static uint8_t prev_available = 255;
    uint8_t current_available = SpotCounter_GetAvailable();

    if (current_available != prev_available)
    {
        LCD_WriteInstruction(Lcd_ClearScreen, Lcd_4bitMode);
        LCD_WriteString((uint8_t*)"Available: ", Lcd_4bitMode);
        LCD_WriteNumber(current_available, Lcd_4bitMode);
        
        prev_available = current_available; 
    }
}
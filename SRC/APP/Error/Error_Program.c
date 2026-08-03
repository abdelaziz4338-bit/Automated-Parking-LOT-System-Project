/**
 * @file    Error_Program.c
 * @author (yousef)
 * @author (Eng/Hesham)
 * @brief  
 * @details
 * @version
 * @date
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "Error_Interface.h"
#include "Error_Private.h"
#include "Error_Config.h"
#include "../../HAL/LCD/LCD_interface.h"
#include <stdint.h>

void Error_Run(void)
{
    LCD_WriteInstruction(Lcd_ClearScreen, Lcd_4bitMode);
    LCD_WriteString((uint8_t*)"System Error", Lcd_4bitMode);
}
/**
 * @file    Error_Program.c
 * @author (yousef)
 * @author (Eng/Hesham)
 * @brief  This file contains the implementation of the error handling functions for the system.
 * @details This file provides the implementation of the Error_Run function, which is responsible for displaying an error message on the LCD screen when a system error occurs.
 * @version 1.0.0
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "Error_Interface.h"
#include "Error_Private.h"
#include "Error_Config.h"
#include "../../HAL/LCD/LCD_interface.h"
#include <stdint.h>

/**
 * @brief  Runs the error handling routine
 * @details This function is responsible for displaying an error message on the LCD screen when a system error occurs.
 */
void Error_Run(void)
{
    LCD_WriteInstruction(Lcd_ClearScreen, Lcd_4bitMode);
    LCD_WriteString((uint8_t*)"System Error", Lcd_4bitMode);
}
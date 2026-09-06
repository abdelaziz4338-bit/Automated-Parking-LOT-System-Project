/**
 * @file    Idle_Program.c
 * @author (yousef)
 * @author (Eng/Hesham)
 * @brief  This file contains the implementation of the Idle module, which manages the idle state of a parking system. It provides functions to initialize the module and run the idle state, displaying the number of available parking spots on an LCD display.
 * @details The Idle module interacts with the SpotCounter module to retrieve the number of available parking spots and updates the LCD display accordingly. It ensures that the display is updated only when there is a change in the number of available spots, optimizing performance and reducing unnecessary updates.
 * @version 1.0.0
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "Idle_Interface.h"
#include "Idle_Private.h"
#include "Idle_Config.h"
#include "../Full/Full_Interface.h"
#include "../SpotCounter/SpotCounter_Interface.h"
#include "../../HAL/LCD/LCD_Interface.h"

/** @brief  Initializes the Idle module */
void Idle_Init(){

Full_Deactivate();

}
/** @brief  Runs the idle state */
void Idle_Run(void)
{
/*
Checks the number of available parking spots and updates the LCD display if there is a change. It retrieves the current number of available spots from the SpotCounter module and compares it with the previous value. If there is a difference, it clears the LCD screen, displays the updated number of available spots, and updates the previous value for future comparisons.   
*/
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
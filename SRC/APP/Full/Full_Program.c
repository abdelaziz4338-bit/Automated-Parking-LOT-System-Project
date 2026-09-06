/**
 * @file    Full_Program.c
 * @author (Developer: Abdulrahman Ali)  
 * @author (Reviewer:ENG\Hesham Ahmed)
 * @brief  This file contains the implementation of the Full module, which manages the state of a parking system, indicating whether the parking is full or available. It provides functions to initialize the module, activate and deactivate the full state, and check if the parking is currently full.
 * @details The Full module interacts with the LCD display, LEDs, and UART to provide visual and textual feedback about the parking status. It uses the SpotCounter module to determine the availability of parking spots.
 * @version 1.0.0
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "Full_Interface.h"
#include "Full_Private.h"
#include "Full_Config.h"

#include <stdint.h>

#include "../../HAL/LCD/LCD_Interface.h"
#include "../SpotCounter/SpotCounter_Interface.h"
#include "../../HAL/LED/LED_Interface.h"
#include "../../MCAL/UART/UART_Interface.h"

/** @brief  Initializes the Full module */
void Full_Init()
{
    Led_Init(FULL_GREEN_LED_GROUP, FULL_GREEN_LED_PIN);
    Led_Init(FULL_RED_LED_GROUP, FULL_RED_LED_PIN);
    Led_off(FULL_GREEN_LED_GROUP, FULL_GREEN_LED_PIN, SourceConnection);
    Led_off(FULL_RED_LED_GROUP, FULL_RED_LED_PIN, SourceConnection);

}
/** @brief  Activates the full state */
void Full_Activate()
{ 
/*
Check if the parking is full by verifying if the available spots are zero. If the parking is full, update the LCD display to show "Parking Full", turn on the red LED, turn off the green LED, and send a message via UART indicating that the parking is full.
*/
    LCD_WriteInstruction(Lcd_ClearScreen, Lcd_4bitMode);
    LCD_WriteString((uint8_t*)"Parking Full", Lcd_4bitMode);
    Led_on(FULL_RED_LED_GROUP, FULL_RED_LED_PIN, SourceConnection);
    Led_off(FULL_GREEN_LED_GROUP, FULL_GREEN_LED_PIN, SourceConnection);
    UART_SendStringPolling((uint8_t*)"PARKING FULL\n");

}
/** @brief  Deactivates the full state */
void Full_Deactivate()
{
/*
Check if the parking is available by verifying if the available spots are equal to the parking capacity. If the parking is available, update the LCD display to show "Parking Available", turn on the green LED, turn off the red LED, and send a message via UART indicating that the parking is available.
*/
    LCD_WriteInstruction(Lcd_ClearScreen, Lcd_4bitMode);
    LCD_WriteString((uint8_t*)"Parking Available", Lcd_4bitMode);
    Led_on(FULL_GREEN_LED_GROUP, FULL_GREEN_LED_PIN, SourceConnection);
    Led_off(FULL_RED_LED_GROUP, FULL_RED_LED_PIN, SourceConnection);
    UART_SendStringPolling((uint8_t*)"PARKING AVAILABLE\n");

}
/** @brief  Checks if the full state is active */
uint8_t Full_IsActive(void)
{
    return (SpotCounter_GetAvailable() == 0);
}
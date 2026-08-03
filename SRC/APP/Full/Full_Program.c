/**
 * @file    Full_Program.c
 * @author (Developer: Abdulrahman Ali)  
 * @author (Reviewer:ENG\Hesham Ahmed)
 * @brief  
 * @details
 * @version
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


void Full_Init()
{
    Led_Init(FULL_GREEN_LED_GROUP, FULL_GREEN_LED_PIN);
     Led_Init(FULL_RED_LED_GROUP, FULL_RED_LED_PIN);

    Led_off(FULL_GREEN_LED_GROUP, FULL_GREEN_LED_PIN, SourceConnection);
    Led_off(FULL_RED_LED_GROUP, FULL_RED_LED_PIN, SourceConnection);

}

void Full_Activate()
{ 
    LCD_WriteInstruction(Lcd_ClearScreen, Lcd_4bitMode);
    LCD_WriteString((uint8_t*)"Parking Full", Lcd_4bitMode);
    Led_on(FULL_RED_LED_GROUP, FULL_RED_LED_PIN, SourceConnection);
    Led_off(FULL_GREEN_LED_GROUP, FULL_GREEN_LED_PIN, SourceConnection);
    UART_SendStringPolling((uint8_t*)"PARKING FULL\n");

}

void Full_Deactivate()
{
    LCD_WriteInstruction(Lcd_ClearScreen, Lcd_4bitMode);
    LCD_WriteString((uint8_t*)"Parking Available", Lcd_4bitMode);
    Led_on(FULL_GREEN_LED_GROUP, FULL_GREEN_LED_PIN, SourceConnection);
    Led_off(FULL_RED_LED_GROUP, FULL_RED_LED_PIN, SourceConnection);
    UART_SendStringPolling((uint8_t*)"PARKING AVAILABLE\n");

}
uint8_t Full_IsActive(void)
{
    return (SpotCounter_GetAvailable() == 0);
}
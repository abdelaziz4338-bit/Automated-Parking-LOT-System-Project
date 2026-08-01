/**
 * @file    Exit_Program.c
 * @author (developer)  
 * @author (reviewer)
 * @brief  
 * @details
 * @version
 * @date
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "Exit_Interface.h"
#include "Exit_Private.h"
#include "Exit_Config.h"

#include <stdint.h>

#include "LCD_Interface.h"
#include "UART_Interface.h"

#include "SpotCounter_Interface.h"
#include "GateController_Interface.h"

#include "Exit_Interface.h"

void Exit_Process()
{
    GateController_OpenExit();

    SpotCounter_DecrementOccupied();

     Lcd_ClearScreen;
    LCD_WriteString("Vehicle Exited", Lcd_4bitMode);

    UART_SendStringPolling("VEHICLE EXITED");

    GateController_CloseExit();
}
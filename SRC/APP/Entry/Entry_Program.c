/**
 * @file    Entry_Program.c
 * @author (developer)  
 * @author (reviewer)
 * @brief  
 * @details
 * @version
 * @date
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "Entry_Interface.h"
#include "Entry_Private.h"
#include "Entry_Config.h"

#include <stdint.h>

#include "LCD_Interface.h"
#include "UART_Interface.h"

#include "SpotCounter_Interface.h"
#include "GateController_Interface.h"
#include "Full_Interface.h"

#include "Entry_Interface.h"

void Entry_Process(void)
{
    if(Full_IsFull() == 0)
    {
        GateController_OpenEntry();

        SpotCounter_IncrementOccupied();

        Lcd_ClearScreen;
        LCD_WriteString("Vehicle Entered", Lcd_4bitMode);

         UART_SendStringPolling("VEHICLE ENTERED");
        
        GateController_CloseEntry();
    }
    else
    {
        Full_Check();
    }
}
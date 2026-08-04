/**
 * @file    Exit_Program.c
 * @author (Developer: Abdulrahman Ali)  
 * @author (Eng /Hesham Ahmed)
 * @brief  
 * @details
 * @version
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "Exit_Interface.h"
#include "Exit_Private.h"
#include "Exit_Config.h"

#include <stdint.h>
#include <util/delay.h>
#include "../../HAL/LED/LED_Interface.h"
#include "../../HAL/LCD/LCD_Interface.h"
#include "../../MCAL/UART/UART_Interface.h"
#include "../ParkingManager/ParkingManager_Interface.h"
#include "../GateController/GateController_Interface.h"
#include "../SpotCounter/SpotCounter_Interface.h"
#include"../FULL/Full_Interface.h"




volatile uint8_t ExitFlag = 0;

void Exit_ISR(void)
{
    ExitFlag = 1;
}

void Exit_Init()
{
    ExitFlag = 0;
}


void Exit_Process()
{
    if(SpotCounter_GetAvailable() == 2)

    {

        LCD_WriteInstruction(Lcd_ClearScreen, Lcd_4bitMode);

        LCD_WriteString(

            (uint8_t*)"PARKING EMPTY",

            Lcd_4bitMode

        );

        UART_SendStringPolling(

            (uint8_t*)"ERROR: PARKING EMPTY\r\n"

        );

        Led_off(Dio_GroupA, Dio_Pin3,SourceConnection);

        Led_on(Dio_GroupA, Dio_Pin4,SourceConnection);

        _delay_ms(1500);

        LCD_WriteInstruction(Lcd_ClearScreen, Lcd_4bitMode);

        LCD_WriteString((uint8_t*)"SYSTEM START",Lcd_4bitMode);


        _delay_ms(1000);

        return;

    }

    // Normal Exit 
    GateController_OpenExit();

    LCD_WriteInstruction(Lcd_ClearScreen, Lcd_4bitMode);
    LCD_GotoXY(0,0);
    LCD_WriteString((uint8_t*)"VEHICLE EXITED",Lcd_4bitMode);

    SpotCounter_Decrement();
    UART_SendStringPolling((uint8_t*)"VEHICLE EXITED\r\n");
    
    _delay_ms(2000);

    GateController_CloseExit();

    if (SpotCounter_Full())
    {
    Full_Activate();
    }
    else
    {
    Full_Deactivate();
    }

    LCD_WriteInstruction(Lcd_ClearScreen,Lcd_4bitMode);
}

uint8_t Exit_IsDetected()
{
    if(ExitFlag == 1)
    {
        ExitFlag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}
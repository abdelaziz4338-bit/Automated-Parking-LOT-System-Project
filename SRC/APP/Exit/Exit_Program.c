/**
 * @file    Exit_Program.c
 * @author (Developer: Abdulrahman Ali)  
 * @author (Eng /Hesham Ahmed)
 * @brief  This file contains the implementation of the Exit module for a parking management system. It defines the functions that handle exit events, including initialization, processing exit requests, checking for exit detection, and managing exit-related interrupts. The Exit module interacts with other components of the system, such as the gate controller, spot counter, and user interface, to facilitate vehicle exits from the parking area.
 * @details This source file implements the core functionality of the Exit module, providing the necessary logic to manage vehicle exits in a parking management system. It includes functions for initializing the module, processing exit events, checking if an exit has been detected, and handling interrupts related to exit events. The implementation ensures that the system responds appropriately to exit requests, updates the spot counter, and communicates with other modules such as the gate controller and user interface components.
 * @version 1.0.0
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "Exit_Interface.h"
#include "Exit_Private.h"
#include <stdint.h>
#include <util/delay.h>
#include "../../HAL/LED/LED_Interface.h"
#include "../../HAL/LCD/LCD_Interface.h"
#include "../../MCAL/UART/UART_Interface.h"
#include "../ParkingManager/ParkingManager_Interface.h"
#include "../Init/Init_Private.h"
#include "../GateController/GateController_Interface.h"
#include "../SpotCounter/SpotCounter_Interface.h"
#include"../FULL/Full_Interface.h"




volatile uint8_t ExitFlag = 0;
/*
 * @brief  Exit interrupt service routine
 * @details This function is called when an exit event is detected.
 */
void Exit_ISR(void)
{
    ExitFlag = 1;
}
/*
 * @brief  Initializes the Exit module
 * @details This function initializes the Exit module and sets the exit flag to 0.
 */
void Exit_Init()
{
    ExitFlag = 0;
}

/**
 * @brief  Processes exit events
 * @details This function handles the logic for processing exit events, including updating the spot counter and controlling the gate.
 */
void Exit_Process()
{
    if(SpotCounter_GetAvailable() == PARKING_CAPACITY)

    {

    LCD_WriteInstruction(Lcd_ClearScreen, Lcd_4bitMode);
    LCD_WriteString( (uint8_t*)"PARKING EMPTY",Lcd_4bitMode);
    UART_SendStringPolling((uint8_t*)"ERROR: PARKING EMPTY\r\n");
    Led_off(Dio_GroupA, Dio_Pin3,SourceConnection);
    Led_on(Dio_GroupA, Dio_Pin4,SourceConnection);
    _delay_ms(1500);
    Led_off(Dio_GroupA, Dio_Pin4,SourceConnection);
    Led_off(Dio_GroupA, Dio_Pin3,SourceConnection);
    LCD_WriteInstruction(Lcd_ClearScreen, Lcd_4bitMode);
    LCD_WriteString((uint8_t*)"SYSTEM START",Lcd_4bitMode);
    _delay_ms(1000);
    return;

    }

/*
 * @brief  Processes exit events
 * @details This function handles the logic for processing exit events, including updating the spot counter and controlling the gate.
 */
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
/*
 * @brief  Checks if an exit event has been detected
 * @details This function checks the exit flag to determine if an exit event has occurred.
 * @return 1 if an exit event is detected, 0 otherwise
 */
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
/**
 * @file    GateController_Program.c
 * @author (Developer: Abdulrahman Ali)  
 * @author (Reviewer:ENG\Hesham Ahmed)
 * @brief  
 * @details
 * @version
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "GateController_Interface.h"
#include "GateController_Private.h"
#include "GateController_Config.h"

#include <stdint.h>

#include "../../HAL/DC_MOTOR/DC_MOTOR_Interface.h"
#include "../../MCAL/UART/UART_Interface.h"

static uint8_t GateState;


void GateController_Init()
{
    DCM_Init();

   DCM_CloseGate();
    
    GateState = GATE_CLOSED;
}


void GateController_OpenEntry()
{
    DCM_OpenGate();
    UART_SendStringPolling((uint8_t*)"ENTRY GATE OPENED\n");
    GateState = GATE_OPEN;
}


void GateController_CloseEntry()
{
    DCM_CloseGate();
    UART_SendStringPolling((uint8_t*)"ENTRY GATE CLOSED\n");
    GateState = GATE_CLOSED;
}

void GateController_OpenExit()
{
    DCM_OpenGate();
    UART_SendStringPolling((uint8_t*)"EXIT GATE OPENED\n");
    GateState = GATE_OPEN;
}

void GateController_CloseExit()
{
    DCM_CloseGate();
    UART_SendStringPolling((uint8_t*)"EXIT GATE CLOSED\n");
    GateState = GATE_CLOSED;
}



uint8_t GateController_GetState()
{
    return GateState;
}
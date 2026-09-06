/**
 * @file    GateController_Program.c
 * @author (Developer: Abdulrahman Ali)  
 * @author (Reviewer:ENG\Hesham Ahmed)
 * @brief  This file contains the implementation of the Gate Controller module, which manages the opening and closing of entry and exit gates in a parking management system. It provides functions to initialize the gate controller, open and close the gates, and retrieve the current state of the gate.
 * @details The Gate Controller module interacts with the DC motor to control the gate's movement and uses UART to send status messages regarding the gate's state. It maintains the current state of the gate (open or closed) and provides an interface for other modules to control the gates without needing to know the internal implementation details.
 * @version 1.0.0
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

/** @brief  Initializes the Gate Controller module */
void GateController_Init()
{
   DCM_Init();
   DCM_CloseGate();
   GateState = GATE_CLOSED;
}

/** @brief  Opens the entry gate */
void GateController_OpenEntry()
{
    DCM_OpenGate();
    UART_SendStringPolling((uint8_t*)"ENTRY GATE OPENED\n");
    GateState = GATE_OPEN;
}

/** @brief  Closes the entry gate */
void GateController_CloseEntry()
{
    DCM_CloseGate();
    UART_SendStringPolling((uint8_t*)"ENTRY GATE CLOSED\n");
    GateState = GATE_CLOSED;
}

/** @brief  Opens the exit gate */
void GateController_OpenExit()
{
    DCM_OpenGate();
    UART_SendStringPolling((uint8_t*)"EXIT GATE OPENED\n");
    GateState = GATE_OPEN;
}

/** @brief  Closes the exit gate */
void GateController_CloseExit()
{
    DCM_CloseGate();
    UART_SendStringPolling((uint8_t*)"EXIT GATE CLOSED\n");
    GateState = GATE_CLOSED;
}


/** @brief  Retrieves the current state of the gate */
uint8_t GateController_GetState()
{
    return GateState;
}
/**
 * @file    GateController_Program.c
 * @author (developer)  
 * @author (reviewer)
 * @brief  
 * @details
 * @version
 * @date
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "GateController_Interface.h"
#include "GateController_Private.h"
#include "GateController_Config.h"

#include <stdint.h>

#include "SERVO_Interface.h"


#include "UART_Interface.h"

#include "GateController_Interface.h"
#include "GateController_Private.h"

void GateController_OpenEntry()
{
    SERVO_Entry_SetAngle(GATE_OPEN_ANGLE);

    UART_SendStringPolling("ENTRY GATE OPENED");
}

void GateController_CloseEntry()
{
    SERVO_Entry_SetAngle(GATE_CLOSED_ANGLE);
}

void GateController_OpenExit()
{
    SERVO_Exit_SetAngle(GATE_OPEN_ANGLE);

    UART_SendStringPolling("EXIT GATE OPENED");
}

void GateController_CloseExit()
{
    SERVO_Exit_SetAngle(GATE_CLOSED_ANGLE);
}
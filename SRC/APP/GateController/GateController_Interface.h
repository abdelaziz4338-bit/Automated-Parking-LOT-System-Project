/**
 * @file    GateController_Interface.h
 * @author (Developer: Abdulrahman Ali)  
 * @author (Reviewer:ENG\Hesham Ahmed)
 * @brief  
 * @details
 * @version
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef GATECONTROLLER_INTERFACE_H
#define GATECONTROLLER_INTERFACE_H

#ifndef GATE_CONTROLLER_H
#define GATE_CONTROLLER_H

#include <stdint.h>



void GateController_Init();

void GateController_OpenEntry();
void GateController_CloseEntry();

void GateController_OpenExit();
void GateController_CloseExit();

uint8_t GateController_GetState();



#endif


#endif /* GATECONTROLLER_INTERFACE_H */

/**
 * @file    GateController_Interface.h
 * @author (Developer: Abdulrahman Ali)  
 * @author (Reviewer:ENG\Hesham Ahmed)
 * @brief This file contains the interface definitions for the Gate Controller module.
 * @details This header file provides the necessary function prototypes and definitions for the Gate Controller module, allowing other modules to interact with the gate control functionality. It defines the functions for initializing the gate controller, opening and closing entry and exit gates, and retrieving the current state of the gate. The interface ensures that other modules can utilize the gate control features without needing to know the internal implementation details.
 * @version 1.0.0
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef GATECONTROLLER_INTERFACE_H
#define GATECONTROLLER_INTERFACE_H



#include <stdint.h>


/** @brief  Initializes the Gate Controller module */
void GateController_Init();

/** @brief  Opens the entry gate */
void GateController_OpenEntry();

/** @brief  Closes the entry gate */
void GateController_CloseEntry();

/** @brief  Opens the exit gate */
void GateController_OpenExit();

/** @brief  Closes the exit gate */
void GateController_CloseExit();

/** @brief  Retrieves the current state of the gate */
uint8_t GateController_GetState();


#endif /* GATECONTROLLER_INTERFACE_H */

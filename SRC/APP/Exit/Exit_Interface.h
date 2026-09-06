/**
 * @file    Exit_Interface.h
 * @author (Developer: Abdulrahman Ali)  
 * @author (Eng /Hesham Ahmed)
 * @brief This file contains the interface definitions for the Exit module of a parking management system. It declares the functions that are available for use by other modules to interact with the Exit module. 
 * @details This header file provides the necessary function prototypes for initializing the Exit module, processing exit events, checking if an exit has been detected, and handling interrupts related to exit events. It serves as the public interface for the Exit module, allowing other components of the parking management system to utilize its functionality without needing to know the internal implementation details.
 * @version 1.0.0
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef EXIT_INTERFACE_H
#define EXIT_INTERFACE_H
#include <stdint.h>
/** @brief  Initializes the Exit module */
void Exit_Init();
/** @brief  Processes exit events */
void Exit_Process();
/** @brief  Checks if an exit event has been detected */
uint8_t Exit_IsDetected();
/** @brief  Exit interrupt service routine */
void Exit_ISR();



#endif /* EXIT_INTERFACE_H */

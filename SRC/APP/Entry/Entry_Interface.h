/**
 * @file    Entry_Interface.h
 * @author (Developer: Abdulrahman Ali)  
 * @author (Eng /Hesham Ahmed)
 * @brief  This file contains the interface definitions for the Entry module of a parking management system. It declares the functions that are available for use by other modules to interact with the Entry module.
 * @details This header file provides the necessary function prototypes for initializing the Entry module, processing entry events, checking for entry detection, and handling entry-related interrupts. It serves as the public interface for the Entry module, allowing other components of the parking management system to utilize its functionality without needing to know the internal implementation details.
 * @version 1.0.0
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef ENTRY_INTERFACE_H
#define ENTRY_INTERFACE_H
#include <stdint.h>

/**
 * @brief  Initializes the Entry module
 */
void Entry_Init();
/**
 * @brief  Processes the entry event
 */
void Entry_Process();
/**
 * @brief  Checks if an entry event has been detected
 * @return uint8_t: 1 if an entry is requested, 0 otherwise
 */
uint8_t Entry_IsDetected();
/**
 * @brief  Interrupt service routine for the entry event
 */
void Entry_ISR();


#endif /* ENTRY_INTERFACE_H */


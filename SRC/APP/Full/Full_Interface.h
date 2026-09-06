/**
 * @file    Full_Interface.h
 * @author (Developer: Abdulrahman Ali)  
 * @author (Reviewer:ENG\Hesham Ahmed)
 * @brief  This file contains the interface definitions for the Full module of a parking management system. It declares the functions that are available for use by other modules to interact with the Full module.
 * @details This header file provides the necessary function prototypes for initializing the Full module, activating and deactivating the full state, and checking if the parking is currently full. It serves as the public interface for the Full module, allowing other components of the parking management system to utilize its functionality without needing to know the internal implementation details.
 * @version 1.0.0
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef FULL_INTERFACE_H
#define FULL_INTERFACE_H
#include <stdint.h>
/** @brief  Initializes the Full module */
void Full_Init();
/** @brief  Activates the full state */ 
void Full_Activate();
/** @brief  Deactivates the full state */
void Full_Deactivate();
/** @brief  Checks if the full state is active */
uint8_t Full_IsActive();

#endif /* FULL_INTERFACE_H */

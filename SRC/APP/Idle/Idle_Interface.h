/**
 * @file    Idle_Interface.h
 * @author (yousef)  
 * @author (Eng/Hesham)
 * @brief  This file contains the public interface for the Idle module, which manages the idle state of a parking system. It provides function prototypes for initializing the module and running the idle state, allowing other modules to interact with the Idle module without needing to know its internal implementation details.
 * @details This header file defines the public interface for the Idle module, enabling other components of the parking management system to utilize its functionality. It includes function prototypes for initializing the Idle module and running the idle state, which involves checking the number of available parking spots and updating the LCD display accordingly. By providing a clear interface, this file promotes modularity and encapsulation within the system.
 * @version 1.0.0
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef IDLE_INTERFACE_H
#define IDLE_INTERFACE_H
/** @brief  Initializes the Idle module */
void Idle_Init();
/** @brief  Runs the idle state */
void Idle_Run();

#endif /* IDLE_INTERFACE_H */

/**
 * @file    Init_Interface.h
 * @author (Developer: Abdulrahman Ali)  
 * @author (Reviewer:ENG\Hesham Ahmed)
 * @brief  This file contains the public interface for the initialization module, which is responsible for setting up the necessary hardware and software components required for the parking management system to operate correctly. It provides function prototypes for initializing the application modules, allowing other modules to interact with the initialization module without needing to know its internal implementation details.
 * @details This header file defines the public interface for the initialization module, enabling other components of the parking management system to utilize its functionality. It includes function prototypes for initializing the application modules, which involves configuring input/output pins, setting up external interrupts, initializing communication protocols, and preparing various modules such as the LCD display, keypad, LED indicators, and parking management functionalities. By providing a clear interface, this file promotes modularity and encapsulation within the system.
 * @version 1.0.0
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef INIT_INTERFACE_H
#define INIT_INTERFACE_H

/** @brief  Initializes the application modules */
void App_Init();


#endif /* INIT_INTERFACE_H */

/**
 * @file    Error_Interface.h
 * @author ( Yousef )  
 * @author (Eng /Hesham Ahmed)
 * @brief  This file contains the interface definitions for the Error module of a parking management system. It declares the functions that are available for use by other modules to interact with the Error module.
 * @details This header file provides the necessary function prototypes for running the error handling routine, which is responsible for displaying an error message on the LCD screen when a system error occurs. It serves as the public interface for the Error module, allowing other components of the parking management system to utilize its functionality without needing to know the internal implementation details.
 * @version 1.0.0
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef ERROR_INTERFACE_H
#define ERROR_INTERFACE_H
#include <stdint.h>


/**
 * @brief  Runs the error handling routine
 * @details This function is responsible for displaying an error message on the LCD screen when a system error occurs.
 */
void Error_Run();



#endif /* ERROR_INTERFACE_H */

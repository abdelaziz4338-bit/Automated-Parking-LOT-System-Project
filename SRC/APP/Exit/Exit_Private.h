/**
 * @file    Exit_Private.h
 * @author (Developer: Abdulrahman Ali)  
 * @author (Eng /Hesham Ahmed)
 * @brief  This file contains the private definitions and declarations for the Exit module of a parking management system. It is intended for internal use within the Exit module and should not be included or accessed by other modules.
 * @details This header file provides the necessary private definitions, constants, and function prototypes that are used internally by the Exit module. It serves as a private interface for the Exit module, allowing the implementation of exit handling functions without exposing them to other components of the parking management system.
 * @version 1.0.0
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef EXIT_PRIVATE_H
#define EXIT_PRIVATE_H
#include <stdint.h>

/** @brief  Exit request constants */
#define EXIT_REQUESTED 1
#define EXIT_NOT_REQUESTED 0
/** @brief  Exit flag */
extern volatile uint8_t ExitFlag;

#endif /* EXIT_PRIVATE_H */

/**
 * @file    Entry_Private.h
 * @author (Developer: Abdulrahman Ali)  
 * @author (Eng /Hesham Ahmed)
 * @brief  This file contains the private definitions and declarations for the Entry module of a parking management system. It defines constants, macros, and external variables that are used internally within the Entry module.
 * @details This header file is intended for internal use within the Entry module and should not be included directly by other modules. It provides the necessary private declarations to support the implementation of the Entry module, including the management of entry events, password verification, and interaction with other components such as the gate controller and spot counter.
 * @version 1.0.0
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef ENTRY_PRIVATE_H
#define ENTRY_PRIVATE_H
#include <stdint.h>

/*
 * @brief  Constants for entry event management
 */
#define ENTRY_REQUESTED 1
#define ENTRY_NOT_REQUESTED 0

/*
 * @brief  External variable for the entry flag
 */
extern volatile uint8_t EntryFlag;

#endif /* ENTRY_PRIVATE_H */

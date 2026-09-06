/**
 * @file    Full_Private.h
 * @author (Developer: Abdulrahman Ali)  
 * @author (Reviewer:ENG\Hesham Ahmed)
 * @brief  This file contains the private definitions and declarations for the Full module of a parking management system. It is intended for internal use within the Full module and should not be included or accessed by other modules.
 * @details This header file provides the necessary private definitions, constants, and function prototypes that are used internally by the Full module. It serves as a private interface for the Full module, allowing the implementation of full state management functions without exposing them to other components of the parking management system.
 * @version 1.0.0
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */
#ifndef FULL_PRIVATE_H
#define FULL_PRIVATE_H
/** @brief  Full module constants */
// Green LED
#define FULL_GREEN_LED_GROUP   Dio_GroupA
#define FULL_GREEN_LED_PIN     Dio_Pin3
/** @brief  Full module constants */
// Red LED
#define FULL_RED_LED_GROUP     Dio_GroupA
#define FULL_RED_LED_PIN       Dio_Pin4

#endif

/**
 * @file    Full_Config.h
 * @author (Developer: Abdulrahman Ali)  
 * @author (Reviewer:ENG\Hesham Ahmed)
 * @brief  This file contains the configuration definitions for the Full module of a parking management system. It defines the constants and settings that are used to configure the behavior of the Full module, including the GPIO pins for the green and red LEDs that indicate the parking status.
 * @details This header file provides the necessary configuration parameters for the Full module, allowing developers to customize the module's behavior according to the specific requirements of the parking management system. It defines the GPIO groups and pins for the green and red LEDs, which are used to visually indicate whether the parking area is full or available. The configuration settings in this file can be adjusted to match the hardware setup of the parking system.
 * @version 1.0.0
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef FULL_CONFIG_H
#define FULL_CONFIG_H
/** @brief  Full module configuration */
#define FULL_GREEN_LED_GROUP Dio_GroupA
#define FULL_GREEN_LED_PIN   Dio_Pin3
/** @brief  Full module configuration */
#define FULL_RED_LED_GROUP   Dio_GroupA
#define FULL_RED_LED_PIN     Dio_Pin4

#endif /* FULL_CONFIG_H */

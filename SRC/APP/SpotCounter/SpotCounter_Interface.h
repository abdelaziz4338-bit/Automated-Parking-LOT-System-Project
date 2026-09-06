/**
 * @file    SpotCounter_Interface.h
* @author (yousef)
 * @author (Eng/Hesham)
 * @brief  This File have the Implementation Function Prototype of Spot Counter module for parking management
 * @details This module is Contains the managing total and occupied spots,
 *              providing initialization, increment, decrement, and status getter functions.
 * @version 1.0.0
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef SPOTCOUNTER_INTERFACE_H
#define SPOTCOUNTER_INTERFACE_H
#include "../../LIB/Definition.h"
#include<stdint.h>

/**
 * @brief Initialize the Spot Counter module with total spots
 */
void SpotCounter_Init(uint8_t Total);

/**
 * @brief Increment the count of occupied spots
 */
void SpotCounter_Increment(void);

/**
 * @brief Decrement the count of occupied spots
 */
void SpotCounter_Decrement(void);

/**
 * @brief Get the number of currently occupied spots
 */
uint8_t SpotCounter_GetOccupied(void);

/**
 * @brief Get the number of available parking spots
 */
uint8_t SpotCounter_GetAvailable(void);

/**
 * @brief Check if the parking lot is fully occupied
 */
uint8_t SpotCounter_Full(void);

#endif /* SPOTCOUNTER_INTERFACE_H */
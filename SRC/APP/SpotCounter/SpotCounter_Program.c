/**
 * @file    SpotCounter_Program.c
 ** @author (yousef)
 * @author (Eng/Hesham)
 * @brief   This File have the Implementation of Spot Counter module for parking management
 * @details This module is responsible for managing total and occupied spots,
 *              providing initialization, increment, decrement, and status getter functions.
 * @version 1.0.0
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "SpotCounter_Interface.h"
#include "SpotCounter_Private.h"
#include <stdint.h>

static uint8_t TotalSpots ;
static uint8_t OccupiedSpots ;


/**
 * @brief   Initialize the Spot Counter module
 * @details Sets the total number of spots available and resets occupied spots to zero.
*/
void SpotCounter_Init(uint8_t Total)
{
TotalSpots = Total ;
OccupiedSpots= 0 ;
}

/**
 * @brief   Increment the count of occupied spots
 * @details Checks if current occupied spots are less than total spots before incrementing.
*/
void SpotCounter_Increment(void)
{
    if(OccupiedSpots < TotalSpots)
    {
    OccupiedSpots++;
    }
}

/**
 * @brief   Decrement the count of occupied spots
 * @details Checks if current occupied spots are greater than zero before decrementing.
*/
void SpotCounter_Decrement(void)
{
    if(OccupiedSpots > 0)
    {
    OccupiedSpots--;
    }
}

/**
 * @brief   Get the number of currently occupied spots
 * @details Returns the private variable holding the count of occupied parking spots.
*/
uint8_t SpotCounter_GetOccupied(void)
{
    return OccupiedSpots ;
}

/**
 * @brief   Get the number of available parking spots
 * @details Calculates and returns the remaining available spots (Total - Occupied).
*/
uint8_t SpotCounter_GetAvailable(void)
{
    return (TotalSpots - OccupiedSpots);
}

/**
 * @brief   Check if the parking lot is fully occupied
 * @details Compares occupied spots with total spots and returns status.
*/
uint8_t SpotCounter_Full(void)
{
    if(OccupiedSpots == TotalSpots)
    {
    return TRUE; 
    }
return FALSE; 
}
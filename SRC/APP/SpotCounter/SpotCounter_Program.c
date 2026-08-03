/**
 * @file    SpotCounter_Program.c
 ** @author (yousef)
 * @author (Eng/Hesham)
 * @brief  
 * @details
 * @version
 * @date
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "SpotCounter_Interface.h"
#include "SpotCounter_Private.h"
#include "SpotCounter_Config.h"
#include <stdint.h>

static uint8_t TotalSpots ;
static uint8_t OccupiedSpots ;

void SpotCounter_Init(uint8_t Total)
{
TotalSpots = Total ;
OccupiedSpots= 0 ;
}
void SpotCounter_Increment(void)
{
    if(OccupiedSpots < TotalSpots)
    {
    OccupiedSpots++;
    }
}
void SpotCounter_Decrement(void)
{
    if(OccupiedSpots > 0)
    {
    OccupiedSpots--;
    }
}
uint8_t SpotCounter_GetOccupied(void)
{
    return OccupiedSpots ;
}
uint8_t SpotCounter_GetAvailable(void)
{
    return (TotalSpots - OccupiedSpots);
}
uint8_t SpotCounter_Full(void)
{
    if(OccupiedSpots == TotalSpots)
    {
    return TRUE; 
    }
return FALSE; 
}
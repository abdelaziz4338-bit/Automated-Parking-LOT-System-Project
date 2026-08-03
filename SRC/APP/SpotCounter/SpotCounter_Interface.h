/**
 * @file    SpotCounter_Interface.h
* @author (yousef)
 * @author (Eng/Hesham)
 * @brief  
 * @details
 * @version
 * @date
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef SPOTCOUNTER_INTERFACE_H
#define SPOTCOUNTER_INTERFACE_H
#include "../../LIB/Definition.h"
#include<stdint.h>

void SpotCounter_Init(uint8_t Total);

void SpotCounter_Increment(void);

void SpotCounter_Decrement(void);

uint8_t SpotCounter_GetOccupied(void);

uint8_t SpotCounter_GetAvailable(void);

uint8_t SpotCounter_Full(void);

#endif /* SPOTCOUNTER_INTERFACE_H */
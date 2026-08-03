/**
 * @file    ParkingManager_Program.c
 * @author (yousef)
 * @author (Eng/Hesham)
 * @brief  
 * @details
 * @version
 * @date
 * @copyright Copyright (c) 2026, Gestell Company
 */
#include "ParkingManager_Interface.h"
#include "ParkingManager_Private.h"
#include "ParkingManager_Config.h"
#include "../Full/Full_Interface.h"
#include "../SpotCounter/SpotCounter_Interface.h"
#include "../Entry/Entry_Interface.h"
#include "../Exit/Exit_Interface.h"

void ParkingManager_Init(uint8_t Capacity){

SpotCounter_Init(Capacity);

}

void ParkingManager_Run(void)
{
if(Entry_IsDetected())
{
Entry_Process();
}
if(Exit_IsDetected())
{
Exit_Process();
}
}

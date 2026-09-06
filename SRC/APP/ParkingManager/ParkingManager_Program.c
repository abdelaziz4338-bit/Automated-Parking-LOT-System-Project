/**
 * @file    ParkingManager_Program.c
 * @author (yousef)
 * @author (Eng/Hesham)
 * @brief  This file contains the implementation of the ParkingManager module, which manages the overall parking system. It provides functions for initializing the module and running the parking management logic, including handling entry and exit events based on sensor detection.
 * @details This source file implements the ParkingManager module, which is responsible for coordinating the parking system's operations. It includes functions to initialize the module with a specified capacity and to run the main parking management logic. The ParkingManager interacts with other modules such as Entry, Exit, and SpotCounter to manage vehicle entry and exit events based on sensor detection. The implementation ensures that the parking system operates efficiently and maintains accurate spot counts.
 * @version 1.0.0
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */
#include "ParkingManager_Interface.h"
#include "ParkingManager_Private.h"
#include "../Full/Full_Interface.h"
#include "../SpotCounter/SpotCounter_Interface.h"
#include "../Entry/Entry_Interface.h"
#include "../Exit/Exit_Interface.h"

/** @brief  Initializes the parking manager module */
void ParkingManager_Init(uint8_t Capacity){
SpotCounter_Init(Capacity);
}

/** @brief  Runs the parking manager logic */
void ParkingManager_Run(void)
{
/*
Checks if a vehicle is detected at the entry sensor. If a vehicle is detected, it calls the Entry_Process function to handle the entry event.
Checks if a vehicle is detected at the exit sensor. If a vehicle is detected, it calls
*/
if(Entry_IsDetected())
{
Entry_Process();
}
if(Exit_IsDetected())
{
Exit_Process();
}
}

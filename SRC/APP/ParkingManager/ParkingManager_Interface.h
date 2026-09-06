/**
 * @file    ParkingManager_Interface.h
 * @author (yousef)  
 * @author (Eng/Hesham)
 * @brief  This file contains the public interface for the ParkingManager module, which manages the overall parking system. It provides function prototypes for initializing the module and running the parking management logic, allowing other modules to interact with the ParkingManager without needing to know its internal implementation details.
 * @details This Source File Provide Function Prototype For ParkingManager module
 * @version 1.0.0
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef PARKINGMANAGER_INTERFACE_H
#define PARKINGMANAGER_INTERFACE_H
#include <stdint.h>

/** @brief  Initializes the parking manager module */
void ParkingManager_Init(uint8_t Capacity);

/** @brief  Runs the parking manager logic */

void ParkingManager_Run();


#endif /* PARKINGMANAGER_INTERFACE_H */

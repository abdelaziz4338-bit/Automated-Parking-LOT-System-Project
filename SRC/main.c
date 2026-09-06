/**
 * @file        main.c
 * @author      (Abdulrahman & yousef)
 * @author      (Eng/Hesham)
 * @brief       Main entry point for the Smart Parking System application
 * @details     Initializes all system peripherals and architectural layers, 
 *              then executes the core application scheduler in a super-loop.
 * @version     1.0.0
 * @date        4/8/2026
 * @copyright   Copyright (c) 2026, Gestell Company
 */

#include "APP/Init/Init_Interface.h"
#include "APP/SpotCounter/SpotCounter_Interface.h"
#include "APP/Idle/Idle_Interface.h"
#include "APP/ParkingManager/ParkingManager_Interface.h"

/**
 * @brief   Application entry point
 * @details Calls the initialization routine and continuously executes 
 *          the parking manager and idle management tasks.
 * @param   void
 * @return  int: Exit status code (0 for normal termination)
*/
int main()
{
/* Initialize system modules and hardware abstractions */
    App_Init();

/* Super-loop for continuous task execution */
    while(1)
    {
        ParkingManager_Run();
        Idle_Run();
    }

    return 0;
}
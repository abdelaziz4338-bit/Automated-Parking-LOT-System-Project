/**
 * @file    Exit_Interface.h
 * @author (Developer: Abdulrahman Ali)  
 * @author (Eng /Hesham Ahmed)
 * @brief  
 * @details
 * @version
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef EXIT_INTERFACE_H
#define EXIT_INTERFACE_H
#include <stdint.h>
void Exit_Init();
void Exit_Process();
uint8_t Exit_IsDetected();
void Exit_ISR();



#endif /* EXIT_INTERFACE_H */

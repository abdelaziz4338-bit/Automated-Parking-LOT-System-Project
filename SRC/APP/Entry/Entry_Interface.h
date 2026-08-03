/**
 * @file    Entry_Interface.h
 * @author (Developer: Abdulrahman Ali)  
 * @author (Eng /Hesham Ahmed)
 * @brief  
 * @details
 * @version
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef ENTRY_INTERFACE_H
#define ENTRY_INTERFACE_H
#include <stdint.h>

void Entry_Init();
void Entry_Process();
uint8_t Entry_IsDetected();
void Entry_ISR();


#endif /* ENTRY_INTERFACE_H */


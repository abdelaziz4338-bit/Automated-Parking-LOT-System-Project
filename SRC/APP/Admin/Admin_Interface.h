/**
 * @file    Admin_Interface.h
 * @author (Developer: Abdulrahman Ali)  
 * @author (Eng /Hesham Ahmed)
 * @brief  
 * @details
 * @version
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef ADMIN_INTERFACE_H
#define ADMIN_INTERFACE_H
#include <stdint.h>


void Admin_Init();

uint8_t Admin_Login();

void Admin_Process();

uint8_t Admin_IsLoggedIn(void);

void Admin_Logout();

#endif /* ADMIN_INTERFACE_H */

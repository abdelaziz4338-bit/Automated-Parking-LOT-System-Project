/**
 * @file    Admin_Interface.h
 * @author (Developer: Abdulrahman Ali)  
 * @author (Eng /Hesham Ahmed)
 * @brief  This file contains the public interface for the Admin module, providing function declarations for admin login, logout, and status checking.
 * @details This header file defines the public functions that can be used by other modules to interact with the Admin module, including initialization, login, logout, and checking if an admin is logged in.
 * @version 1.0.0
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef ADMIN_INTERFACE_H
#define ADMIN_INTERFACE_H
#include <stdint.h>


void Admin_Init();

uint8_t Admin_Login();

void Admin_Process();

uint8_t Admin_IsLoggedIn();

void Admin_Logout();

#endif /* ADMIN_INTERFACE_H */

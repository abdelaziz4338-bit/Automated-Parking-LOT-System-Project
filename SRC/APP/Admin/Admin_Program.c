/**
 * @file    Admin_Program.c
 * @author (developer)  
 * @author (reviewer)
 * @brief  
 * @details
 * @version
 * @date
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "Admin_Interface.h"
#include "Admin_Private.h"
#include "Admin_Config.h"

#include <stdint.h>

#include "LCD_Interface.h"
#include "KPD_Interface.h"
#include "UART_Interface.h"

#include "SpotCounter_Interface.h"
#include "GateController_Interface.h"

#include "Admin_Interface.h"
#include "Admin_Private.h"

static uint8_t Local_Password[] = {'1','2','3','4'};

static uint8_t Admin_CheckPassword()
{
    uint8_t Key;
    uint8_t Index;
    uint8_t Correct = 1;

    Lcd_ClearScreen;
    LCD_WriteString("Password:", Lcd_4bitMode);

    for(Index = 0;
        Index < ADMIN_PASSWORD_LENGTH;
        Index++)
    {
        do
        {
            Key = KeyPad_Getpressedkey();
        }
        while(Key == 0);

        if(Key != Local_Password[Index])
        {
            Correct = 0;
        }
    }

    return Correct;
}

void Admin_Run()
{
    if(Admin_CheckPassword())
    {
        Lcd_ClearScreen;
        LCD_WriteString("ADMIN LOGIN", Lcd_4bitMode);

        UART_SendStringPolling("ADMIN LOGIN");

        /*
         * Admin menu will be implemented here:
         *
         * 1 -> Open Gate
         * 2 -> Close Gate
         * 3 -> Reset Counter
         * 4 -> Change Capacity
         * 5 -> Maintenance
         * 6 -> Clear Fault
         */
    }
    else
    {
        Lcd_ClearScreen;
        LCD_WriteString("Wrong Password", Lcd_4bitMode);
    }
}
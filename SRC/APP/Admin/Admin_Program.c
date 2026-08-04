/**
 * @file    Admin_Program.c
 * @author (developer: Abdulrahman Ali)  
 * @author (reviewer: Hesham Ahmed)
 * @brief  
 * @details
 * @version
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */
#include <stdint.h>
#include "Admin_Interface.h"
#include "Admin_Private.h"
#include <util/delay.h>
#include "../../HAL/KeyPad/KPD_Interface.h"
#include "../../HAL/LCD/LCD_Interface.h"
#include "../../HAL/LED/LED_Interface.h"
#include "../../MCAL/UART/UART_Interface.h"

#include "../SpotCounter/SpotCounter_Interface.h"
#include "../ParkingManager/ParkingManager_Interface.h"
#include "../Gatecontroller/Gatecontroller_Interface.h"
#include "../Error/Error_Interface.h"

static uint8_t AdminLoggedIn;

static uint8_t Password[ADMIN_PASSWORD_LENGTH] ={'1','2','3','4'};


void Admin_Init()
{
    AdminLoggedIn = 0;
}


uint8_t Admin_IsLoggedIn(void)
{
    return AdminLoggedIn;
}


void Admin_Logout()
{
    AdminLoggedIn = 0;
}


uint8_t Admin_Login()
{
    uint8_t Key;
    uint8_t Buffer[ADMIN_PASSWORD_LENGTH];

    uint8_t Index = 0;
    uint8_t Correct = 1;


    LCD_GotoXY(0,0);

    LCD_WriteString( (uint8_t*)"PASSWORD:",Lcd_4bitMode);
       
        


    LCD_GotoXY(0,1);


    while(Index < ADMIN_PASSWORD_LENGTH)
    {
        Key = KeyPad_Getpressedkey();


        if(Key >= '0' && Key <= '9')
        {
            Buffer[Index] = Key;

            LCD_WriteData('*',Lcd_4bitMode);

            Index++;
            _delay_ms(200);
            while(KeyPad_Getpressedkey() != 0xFF);
        }
    }


    for(Index = 0; Index < ADMIN_PASSWORD_LENGTH; Index++)
    {
        if(Buffer[Index] != Password[Index])
        {
            Correct = 0;
        }
    }


    if(Correct)
    {
        AdminLoggedIn = 1;

        LCD_GotoXY(0,0);
        LCD_WriteString( (uint8_t*)"ADMIN LOGIN",Lcd_4bitMode);
        UART_SendStringPolling((uint8_t*)"ADMIN LOGIN\n");
        Led_on(Dio_GroupA, Dio_Pin3 ,SourceConnection);
        return 1;
    }


    AdminLoggedIn = 0;

    LCD_GotoXY(0,0);
    LCD_WriteString((uint8_t*)"WRONG PASSWORD",Lcd_4bitMode);
    Led_on(Dio_GroupA, Dio_Pin4 ,SourceConnection); 
    _delay_ms(1500);
    LCD_WriteInstruction( Lcd_ClearScreen,Lcd_4bitMode);
    LCD_WriteString((uint8_t*)"ERROR",Lcd_4bitMode);

    

    return 0;
}


void Admin_Process()
{
    uint8_t Key;


    if(AdminLoggedIn == 0)
    {
        if(Admin_Login() == 0)
        {
            return;
        }
    }


    while(AdminLoggedIn)
    {
        LCD_GotoXY(0,0);
        LCD_WriteString( (uint8_t*)"A:OPEN B:CLOSE",Lcd_4bitMode);
            
        LCD_GotoXY(1,0);
        LCD_WriteString((uint8_t*)"C:RESET D:EXIT",Lcd_4bitMode);
            
        Key = KeyPad_Getpressedkey();


        if(Key == 'A')
        {
            GateController_OpenEntry();
        }


        else if(Key == 'B')
        {
            GateController_CloseEntry();
        }


        else if(Key == 'C')
        {
            ParkingManager_Run();

            UART_SendStringPolling((uint8_t*)"SYSTEM RESET\n");
                
        }


        else if(Key == 'D')
        {
            Admin_Logout();
        }
    }
}
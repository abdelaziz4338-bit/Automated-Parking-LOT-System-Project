/**
 * @file    Entry_Program.c
 * @author (Developer: Abdulrahman Ali)  
 * @author (Eng /Hesham Ahmed)
 * @brief  
 * @details
 * @version
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */
#include <stdint.h>
#include "Entry_Interface.h"
#include "Entry_Private.h"
#include <util/delay.h>
#include "../../HAL/LCD/LCD_Interface.h"
#include "../../MCAL/UART/UART_Interface.h"
#include "../../HAL/LED/LED_Interface.h"
#include "../../HAL/LCD/LCD_Private.h"
#include "../ParkingManager/ParkingManager_Interface.h"
#include "../GateController/GateController_Interface.h"
#include "../SpotCounter/SpotCounter_Interface.h"
#include"../FULL/Full_Interface.h"
#include"../FULL/Full_Private.h"


volatile uint8_t EntryFlag = 0;

void Entry_Init(void)
{
    EntryFlag = 0;
}

void Entry_Process()
{
    uint8_t Key;

    /* Check Parking Full */

    if(Full_IsActive())
    {
        Full_Activate();

        EntryFlag = 0;

        return;
    }


    /* Show available spaces */

    LCD_WriteInstruction( Lcd_ClearScreen,Lcd_4bitMode);
       
    LCD_WriteString( (uint8_t*)"Available: ",Lcd_4bitMode);
       
    LCD_WriteNumber( SpotCounter_GetAvailable(),Lcd_4bitMode);
       
    LCD_GotoXY(0, 1);
    LCD_WriteInstruction( Lcd_ClearScreen,Lcd_4bitMode);

    LCD_WriteString((uint8_t*)"Press E",Lcd_4bitMode);
       
    /* Wait for E */

    do
    {
        Key = KeyPad_Getpressedkey();

    } while(Key != 'E');


    /* Password */

    LCD_WriteInstruction( Lcd_ClearScreen,Lcd_4bitMode);
    
    LCD_WriteString((uint8_t*)"ENTER PASSWORD",Lcd_4bitMode);
        
    LCD_GotoXY(1, 0);


    uint8_t Password[4];
    uint8_t Index = 0;
    uint8_t Correct = 1;

    while(Index < 4)
    {
        Key = KeyPad_Getpressedkey();

        if(Key >= '0' && Key <= '9')
        {
            Password[Index] = Key;

            LCD_WriteData( '*',Lcd_4bitMode);
               
            Index++;
        }
    }


    /* Check password */

    if(Password[0] != '1' ||
       Password[1] != '2' ||
       Password[2] != '3' ||
       Password[3] != '4')
    {
        Correct = 0;
    }


    if(Correct)
    {
        LCD_WriteInstruction( Lcd_ClearScreen,Lcd_4bitMode);
           
        LCD_WriteString((uint8_t*)"ACCESS GRANTED",Lcd_4bitMode);
          
        GateController_OpenEntry();

        UART_SendStringPolling((uint8_t*)"VEHICLE ENTERED\r\n");
            
        SpotCounter_Increment();
        _delay_ms(2000);
        GateController_CloseEntry();

        if(SpotCounter_Full())
        {
        Full_Activate();
        }
        else
        {
        Full_Deactivate();
        }

        

        EntryFlag = 0;
    }
    else
    {
       Led_off(FULL_GREEN_LED_GROUP, FULL_GREEN_LED_PIN, SourceConnection);
       Led_on(FULL_RED_LED_GROUP, FULL_RED_LED_PIN, SourceConnection);
      LCD_WriteInstruction(Lcd_ClearScreen, Lcd_4bitMode);
      LCD_WriteString((uint8_t*)"WRONG PASSWORD", Lcd_4bitMode);
      _delay_ms(1500);
     LCD_WriteInstruction(Lcd_ClearScreen, Lcd_4bitMode);
      LCD_WriteString((uint8_t*)"ERROR SYSTEM",Lcd_4bitMode);
      UART_SendStringPolling((uint8_t*)" ERROR ENTERN \n");
      _delay_ms(1000);
     LCD_WriteInstruction(Lcd_ClearScreen, Lcd_4bitMode);
      LCD_WriteString((uint8_t*)"SYSTEM WAITING....", Lcd_4bitMode);
        _delay_ms(1500);
      Led_on(Dio_GroupA, Dio_Pin4, SourceConnection);
      Led_off(Dio_GroupA, Dio_Pin3, SourceConnection);
      
    //  _delay_ms(2500);
      
      Led_off(Dio_GroupA, Dio_Pin4, SourceConnection);
      Led_on(Dio_GroupA, Dio_Pin3, SourceConnection);

      LCD_WriteInstruction(Lcd_ClearScreen, Lcd_4bitMode);

      EntryFlag = 0;
    }
}

void Entry_ISR(void)
{
    EntryFlag = 1;
}

uint8_t Entry_IsDetected(void)
{
    return EntryFlag;
}
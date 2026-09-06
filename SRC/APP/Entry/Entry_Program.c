/**
 * @file    Entry_Program.c
 * @author (Developer: Abdulrahman Ali)  
 * @author (Eng /Hesham Ahmed)
 * @brief  This file contains the implementation of the Entry module for a parking management system. It handles the entry process, including password verification and interaction with other modules such as the gate controller and spot counter.
 * @details This module is responsible for managing the entry of vehicles into the parking area. It checks if the parking is full, displays available spaces, prompts for a password, and controls the gate based on the password verification. It also communicates with other modules to update the spot counter and manage the full status of the parking.
 * @version 1.0.0
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

/*
 * Entry_Flag: A flag to indicate if an entry event has been detected.
 */
volatile uint8_t EntryFlag = 0;

void Entry_Init(void)
{
    EntryFlag = 0;
}

/*
 * Entry_Process: This function processes the entry event for a vehicle.
 */
void Entry_Process()
{
 uint8_t Key;

/*
Check if the parking is full. If it is full, activate the full status and return without allowing entry.
*/
    if(Full_IsActive())
    {
        Full_Activate();

        EntryFlag = 0;

        return;
    }


/* 
Display the number of available parking spots on the LCD and prompt the user to press 'E' to proceed with entry.
*/

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


/* 
Prompt the user to enter a password. The system will accept a 4-digit password and display asterisks for each digit entered. After the user enters the password, it will be checked against the predefined password "1234". If the password is correct, access will be granted, and the gate will open. If the password is incorrect, an error message will be displayed, and the system will return to a waiting state.
*/
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


/*
Check if the entered password matches the predefined password "1234". If it does not match, set the Correct flag to 0.
*/

    if(Password[0] != '1' ||
       Password[1] != '2' ||
       Password[2] != '3' ||
       Password[3] != '4')
    {
        Correct = 0;
    }

/*
Check if the entered password is correct. If it is correct, grant access and open the gate. If it is incorrect, display an error message and keep the system in a waiting state.
*/
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
    /*
If the password is incorrect, display an error message, turn on the red LED, and keep the system in a waiting state.
    */
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
    _delay_ms(1500);   
    Led_off(Dio_GroupA, Dio_Pin4, SourceConnection);
    Led_off(Dio_GroupA, Dio_Pin3, SourceConnection);
    LCD_WriteInstruction(Lcd_ClearScreen, Lcd_4bitMode);

    EntryFlag = 0;
    }
}
/*
An interrupt service routine (ISR) for the entry event. When an entry event is detected, this function sets the EntryFlag to 1, indicating that an entry has been requested.
*/
void Entry_ISR(void)
{
    EntryFlag = 1;
}
/*
This function checks if an entry event has been detected by returning the value of the EntryFlag. If EntryFlag is set to 1, it indicates that an entry has been requested; otherwise, it indicates that no entry has been requested.
*/
uint8_t Entry_IsDetected(void)
{
    return EntryFlag;
}
/**
 * @file    Init_Program.c
 * @author (developer)  
 * @author (reviewer)
 * @brief  
 * @details
 * @version
 * @date
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "Init_Interface.h"
#include "Init_Private.h"
#include "Init_Config.h"

#include <stdint.h>


#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/TIMER1/Timer1_Interface.h"
#include "MCAL/UART/UART_Interface.h"
#include "HAL/LED/LED_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/KEYPAD/KPD_Interface.h"
#include "LIB/Bitmath.h"
#include "LIB/Definition.h"

#include "SERVO_Interface.h"

#include "Init_Interface.h"



void APP_Init()
{
    /* Initialize MCAL Drivers */
    DIO_InitPin();
    EXTI_Init();
    TIMER1_Init();
    UART_Init();

    /* Initialize HAL Drivers */
    LCD_Init(Lcd_4bitMode);
    KeyPad_Init();
    Led_Init();
    SERVO_Init();
}
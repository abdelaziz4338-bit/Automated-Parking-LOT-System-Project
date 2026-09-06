/**
 * @file    Init_Program.c
 * @author (Developer: Abdulrahman Ali)  
 * @author (Reviewer:ENG\Hesham Ahmed)
 * @brief  This file contains the implementation of the initialization functions for the parking management system. It includes the App_Init function, which sets up the necessary hardware and software components required for the system to operate correctly. The initialization process involves configuring input/output pins, setting up external interrupts, initializing communication protocols, and preparing various modules such as the LCD display, keypad, LED indicators, and parking management functionalities.
 * @details The App_Init function is responsible for configuring the microcontroller's pins for input and output, enabling pull-up resistors, initializing external interrupts for entry and exit events, and setting up the UART communication with specified parameters. Additionally, it initializes the hardware abstraction layer components like the keypad, LCD display, and LED indicators. The function also prepares the application modules, including the parking manager, gate controller, full state handler, admin interface, and idle state management. Finally, it displays a welcome message on the LCD to indicate that the system has started successfully.
 * @version 1.0.0
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "Init_Interface.h"
#include "Init_Private.h"
#include <util/delay.h>
#include <stdint.h>

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/UART/UART_Interface.h"
#include "../../MCAL/EXTI/EXTI_Interface.h"
#include "../../MCAL/GIE/GIE_Interface.h"
#include "../../HAL/LCD/LCD_Interface.h"
#include "../../HAL/KEYPAD/KPD_Interface.h"
#include "../../HAL/LED/LED_Interface.h"
#include "../../HAL/DC_MOTOR/DC_MOTOR_Interface.h"

#include "../../LIB/Definition.h"
#include "../../LIB/Bitmath.h"

#include "../../MCAL/UART/UART_Private.h"
#include "../../MCAL/EXTI/EXTI_Private.h"


#include "../SpotCounter/SpotCounter_Interface.h"
#include "../ParkingManager/ParkingManager_Interface.h"
#include "../GateController/GateController_Interface.h"
#include "../Full/Full_Interface.h"
#include "../Error/Error_Interface.h"
#include "../Entry/Entry_Interface.h"
#include "../Exit/Exit_Interface.h"
#include "../Idle/Idle_Interface.h"
#include "../Admin/Admin_Interface.h"

/** @brief  Initializes the application modules */
void App_Init()
{
/*
Initial the DIO pins for the Entry and Exit buttons, and enable pull-up resistors for them
*/
    DIO_InitPin(Dio_GroupD, Dio_Pin2, Input); // Set PD2 as INPUT (INT0)
    DIO_InitPin(Dio_GroupD, Dio_Pin3, Input); // Set PD3 as INPUT (INT1)
    DIO_WritePin(Dio_GroupD, Dio_Pin2, High); // Enable Pull-up resistor for PD2
    DIO_WritePin(Dio_GroupD, Dio_Pin3, High); // Enable Pull-up resistor for PD3
/*
Initialize the external interrupts for the Entry and Exit buttons, and set their callback functions
*/
    EXTI_Init(Exti_INT0,Exti_FallingEdge);
    EXTI_Init(Exti_INT1,Exti_FallingEdge);
    EXTI_CallBack(Exti_Interrupt0,Entry_ISR);
    EXTI_CallBack(Exti_Interrupt1,Exit_ISR);
    EXTI_Enable(Exti_INT0);
    EXTI_Enable(Exti_INT1);
    GIE_Enable();



/*
Initialize the UART communication with the specified configuration parameters
*/
Uart_Config_t Uart_Config =
{
    .ModeSelect          = Uart_AsynchronousMode,
    .StopBitSelect       = Uart_1StopBit,
    .ParitySelect        = Uart_ParityDisabled,
    .SizeCharacterSelect = Uart_8BitSize,
    .BaudRate            = 9600,
    .EnbaleSelect        = Uart_EnableRxAndTx,
    .SpeedMode           = Uart_NormalSpeed,
    .InterruptSelect     = Uart_InterruptDisabled
};
UART_Init(Uart_Config);

/** @brief  Initializes the keypad */
    KeyPad_Init();
/** @brief  Initializes the LCD */
    LCD_Init(Lcd_4bitMode);
/** @brief  Initializes the LEDs */
    Led_Init(Dio_GroupA, Dio_Pin3); 
    Led_Init(Dio_GroupA, Dio_Pin4);
    

/** @brief  Initializes the application modules */
    ParkingManager_Init(2);
    Entry_Init();
    Exit_Init();
    GateController_Init();
    Full_Init();
    Admin_Init();
    Idle_Init();


/** @brief  Displays a welcome message on the LCD */
    LCD_WriteInstruction(Lcd_ClearScreen, Lcd_4bitMode);
    LCD_GotoXY(0, 0);
    LCD_WriteString((uint8_t*)"SYSTEM " , Lcd_4bitMode);
    LCD_GotoXY(1, 0);
    LCD_WriteString((uint8_t*)"START " , Lcd_4bitMode);
    _delay_ms(1500);
    LCD_WriteInstruction(Lcd_ClearScreen, Lcd_4bitMode);
    LCD_GotoXY(0, 0);
    LCD_WriteString((uint8_t*)"Welcome to" , Lcd_4bitMode);
    LCD_GotoXY(1, 0);
    LCD_WriteString((uint8_t*)"Gestall Parking", Lcd_4bitMode);
    _delay_ms(2000);


}
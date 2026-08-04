/**
 * @file    Init_Program.c
 * @author (Developer: Abdulrahman Ali)  
 * @author (Reviewer:ENG\Hesham Ahmed)
 * @brief  
 * @details
 * @version
 * @date 4/8/2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "Init_Interface.h"
#include "Init_Private.h"
#include "Init_Config.h"
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

void App_Init()
{
    DIO_InitPin(Dio_GroupD, Dio_Pin2, Input); // Set PD2 as INPUT (INT0)
    DIO_InitPin(Dio_GroupD, Dio_Pin3, Input); // Set PD3 as INPUT (INT1)
    DIO_WritePin(Dio_GroupD, Dio_Pin2, High); // Enable Pull-up resistor for PD2
    DIO_WritePin(Dio_GroupD, Dio_Pin3, High); // Enable Pull-up resistor for PD3

    EXTI_Init(Exti_INT0,Exti_FallingEdge);
    EXTI_Init(Exti_INT1,Exti_FallingEdge);
    EXTI_CallBack(Exti_Interrupt0,Entry_ISR);
    EXTI_CallBack(Exti_Interrupt1,Exit_ISR);
    EXTI_Enable(Exti_INT0);
    EXTI_Enable(Exti_INT1);
    GIE_Enable();




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


    //  HAL Initialization
    KeyPad_Init();

    LCD_Init(Lcd_4bitMode);

    Led_Init(Dio_GroupA, Dio_Pin3); 
    Led_Init(Dio_GroupA, Dio_Pin4);
    

    // Application 
    ParkingManager_Init(2);
    Entry_Init();
    Exit_Init();
    GateController_Init();
    Full_Init();
    Admin_Init();
    Idle_Init();


// Initial the LCD with a welcome message
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
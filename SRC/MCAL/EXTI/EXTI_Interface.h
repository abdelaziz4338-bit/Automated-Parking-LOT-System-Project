#ifndef _EXTI_INTERFACE_H
#define _EXTI_INTERFACE_H
#include <stdint.h>
#include"../../COMMON/Definition.h"
#include"../../COMMON/Bitmath.h"
#include"../Atmega32regmap.h"


void EXTI_Init(uint8_t InterruptName,uint8_t SensConfig);
void EXTI_Enable(uint8_t InterruptName);
void EXTI_Disable(uint8_t InterruptName);
void EXTI0_CallBack(void(*PF)(void));

#endif 

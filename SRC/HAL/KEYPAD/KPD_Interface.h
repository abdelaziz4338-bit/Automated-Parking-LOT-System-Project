#ifndef _KPD_INTERFACE_H
#define _KPD_INTERFACE_H
#pragma once
#include <stdint.h>
#include "../../MCAL/DIO/DIO_Interface.h"
#include"../../COMMON/Definition.h"
#include"../../COMMON/Bitmath.h"
#include "KPD_Private.h"
#include "KPD_Config.h"

void KeyPad_Init();
uint8_t KeyPad_Getpressedkey();



#endif
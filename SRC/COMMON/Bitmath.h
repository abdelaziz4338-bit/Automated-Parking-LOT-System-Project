#ifndef _BITMATH_H
#define _BITMATH_H 

#define SET_BIT(Reg ,Bit ) (Reg |= (1<<(Bit)))
#define CLEAR_BIT(Reg,Bit) (Reg &= ~(1<<Bit))
#define TOG_BIT(Reg,Bit) (Reg ^=(1<<(Bit)))
#define READ_BIT(Reg,Bit) ((Reg>>(Bit))&1)


#endif
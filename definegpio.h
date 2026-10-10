#ifndef     __DEFINEGPIO_H
#define     __DEFINEGPIO_H

#ifdef	__cplusplus
extern "C" {
#endif

    
#include <xc.h>
    
#define _XTAL_FREQ  8000000

#define Input   0x01
#define Output  0x00

#define Logic_Low   0x00
#define Logic_High  0x01
    
#define Analog      0x01    // analog input select
#define Digital     0x00    // digital I/O select
    
#define PULL_UP     0X01
#define PULL_DOWN   0x00




#define Mode_PinD      TRISD   

#define Mode_PinA0      TRISA0
#define Mode_PinA1      TRISA1
#define Mode_PinA2      TRISA2
#define Mode_PinA3      TRISA3

#define Pin_Dig1  RA0               // At Leftmost
#define Pin_Dig2  RA1               // At Left
#define Pin_Dig3  RA2               // At Right
#define Pin_Dig4  RA3               // At Rightmost

#define Mode_PinB0     TRISB0
#define Mode_PinB1     TRISB1
#define Mode_PinA5     TRISA5
#define Mode_PinB4     TRISB4
#define Mode_PinB5     TRISB5
#define Mode_PinB2     TRISB2


#define Pin_ButFORWARD   RB0        // Automatic count_up and count_down but not setting equal mechanics
#define Pin_ButBACK      RB1        // Automatic count_up and count_down but can setting 
#define Pin_Bell         RA5
#define Pin_ButPositive  RB4        // Increase 1 sec for one time press
#define Pin_ButMinus     RB5        // Reduce 1 sec for one time press
#define Pin_Start        RB2

    
#define Analog_Select_High ANSELH
    
#define PullUp_SelectPin0   WPUB0
#define PullUp_SelectPin1   WPUB1
#define PullUp_SelectPin2   WPUB2
#define PullUp_SelectPin4   WPUB4
#define PullUp_SelectPin5   WPUB5
    
#define PULL_UPEnablebits  nRBPU



    
#define Led_OFF     RC0
#define Led_Mode1   RC1
#define Led_Mode2   RC2
    
    
#ifdef	__cplusplus
}
#endif


#endif
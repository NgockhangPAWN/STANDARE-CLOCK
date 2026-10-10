/* 
 * File:   main.c
 * Author: khang
 *
 * Created on October 2, 2026, 12:51 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
 * 
 */


// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include "7_segmentled.h"
#include "definegpio.h"
#include "Defineclock.h"






static void PORTC_Init(void);
static void PORTD_Init(void);   
static void PORTB_Init(void);
static void PORTA_Init(void);



void main(void){
    
    // Config PORT
    PORTC_Init();
    PORTD_Init();
    PORTB_Init();
    PORTA_Init();
    
    
    // Variable
    uint16_t Sec_screen = 0;
    uint8_t sec = 100;
    uint8_t prestart = 1;           // Hold state button when press button
    uint8_t check = 0;              // Check before start count down time setup
    
    
    while(1){     
        CLOCK_Handle();         // Button handle Back and Forward
        switch(modeclk){    
            case OFF:
                // Led indicator
                Led_OFF = 1;
                Led_Mode1 = 0;
                Led_Mode2 = 0;
                LedSegment_SendData(Two,Zero,Two,Six);  // 2026 screen 
                CLOCK_ChooseBF(AutoCouS, AutoCouNS);
                break;
            case AutoCouNS:
                // Led indicator
                Led_OFF = 0;
                Led_Mode1 = 1;
                Led_Mode2 = 0;
                LedSegment_SetupTime(&sec,Count_down);
                CLOCK_ChooseBF(OFF, AutoCouS);
                break;
            case AutoCouS:
                // Led indicator
                Led_OFF = 0;
                Led_Mode1 = 0;
                Led_Mode2 = 1;
                CLOCK_ChooseBF(AutoCouNS, OFF);
                if(!Pin_ButPositive){
                    __delay_ms(200);
                    Sec_screen = (Sec_screen++ > 3600) ? 0 : Sec_screen;
                }
                if(!Pin_ButMinus){
                    __delay_ms(200);
                    Sec_screen = (Sec_screen-- < 0) ? 0 : Sec_screen;
                }
                
                
                
                if(Button_handle( &prestart ,Pin_Start)){
                    flag = 0;
                    check ^= 1;
                }
                if(check){
                    LedSegment_SetupTime(&Sec_screen,Count_down);
                }else{
                    
                    LedSegment_2LeftLed(Sec_screen/60);
                    LedSegment_2RightLed(Sec_screen%60);
                }
                
                break;
        }
    }
    return;
}






void PORTC_Init(void){
    TRISC = 0;
    PORTC = 0;
}

void PORTD_Init(void){
    Mode_PinD = Output;
}
    
void PORTA_Init(void){
    Mode_PinA0 = Output;
    Mode_PinA1 = Output;
    Mode_PinA2 = Output;
    Mode_PinA3 = Output;
    
    Pin_Dig1 = Logic_Low;
    Pin_Dig2 = Logic_Low;
    Pin_Dig3 = Logic_Low;
    Pin_Dig4 = Logic_Low;
}

void PORTB_Init(void){
    Mode_PinB0 = Input;
    Mode_PinB1 = Input;
    Mode_PinA5 = Output;
    Mode_PinB4 = Input;
    Mode_PinB5 = Input;
    Mode_PinB2 = Input;
    
    PORTB = 0;
    
    Analog_Select_High = Digital;
    PULL_UPEnablebits  = 0;
    PullUp_SelectPin1  = PULL_UP;
    PullUp_SelectPin0  = PULL_UP;
    PullUp_SelectPin2  = PULL_UP;
    PullUp_SelectPin4  = PULL_UP;
    PullUp_SelectPin5  = PULL_UP;
   
    
}


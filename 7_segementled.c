/* 
 * File:   7_segementled.c
 * Author: khang
 *
 * Created on October 2, 2026, 1:43 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "7_segmentled.h"
#include "definegpio.h"


const uint8_t number_buffer[10] = { 
    Zero    , 
    One     , 
    Two     , 
    Three   , 
    Four    , 
    Five    , 
    Six     , 
    Seven   , 
    Eight   , 
    Nine
};



void LedSegment_Test(void){
    static status_enum state_led = Count_Up;
    static uint8_t num = 0 ;
    switch(state_led){
        case Count_Up:
            PORTD = number_buffer[num++];
            state_led = (num > 9) ? Count_down : Count_Up;
            __delay_ms(1000);
            break;
        case Count_down:
            num = (num == 10)? 9:num;
            PORTD = number_buffer[--num];
            state_led = (num == 0) ? Count_Up : Count_down;
            if(!num){
                num = 1;
            }
            __delay_ms(1000);
            break;
    }
}



void LedSegment_2LeftLed(uint32_t number){
    PORTD = number_buffer[number/10];
    Dig1 = 1;
    __delay_us(100);
    Dig1 = 0;   
    
    PORTD = number_buffer[number%10];
    Dig2 = 1;
    __delay_us(100);
    Dig2 = 0;
    
}


void LedSegment_2RightLed(uint32_t number){
    PORTD = number_buffer[number/10];
    Dig3 = 1;
    __delay_us(100);
    Dig3 = 0;
    PORTD = number_buffer[number%10];
    Dig4 = 1;
    __delay_us(100);
    Dig4 = 0;
    
}
    
 uint8_t flag = 0;

void LedSegment_SetupTime(uint16_t* time_sec,const status_enum mode){
    uint16_t sec;
    static uint16_t count_time = 0;
    
    if(!mode){
        if(!flag){
            sec = 0;
            flag = 1;
        }
  
        LedSegment_2RightLed(sec%60);       // Min screen
        LedSegment_2LeftLed(sec/60);        // Sec screen
    
        __delay_us(500);                    
    
        if(count_time++ > 220)      // 220 was scaned and approximately 1 sec
        {
            if(sec++ == *time_sec){
                sec = 0;
                Pin_Bell = 1;
                __delay_ms(1000);
                Pin_Bell = 0;
            }
            count_time = 0;
        }
    }else{
        if(!flag){
            sec = *time_sec;
            flag = 1;
        }
        LedSegment_2RightLed(sec%60);       // Min screen
        LedSegment_2LeftLed(sec/60);        // Sec screen
        
         __delay_us(400);                    
    
        if(count_time++ > 220)      // 220 was scaned and approximately 1 sec
        {
            if(sec-- == 0){
                sec = 0;
                flag = 0;
                Pin_Bell = 1;
                __delay_ms(1000);
                Pin_Bell = 0;
            }
            count_time = 0;
            
        }
        
    }
}



void LedSegment_SendData(uint8_t data_1, uint8_t data_2, uint8_t data_3, uint8_t data_4){
    PORTD = data_1;
    Dig1 = 1;
    __delay_us(100);
    Dig1 = 0;
    PORTD = data_2;
    Dig2 = 1;
    __delay_us(100);
    Dig2 = 0;
    PORTD = data_3;
    Dig3 = 1;
    __delay_us(100);
    Dig3 = 0;
    PORTD = data_4;
    Dig4 = 1;
    __delay_us(100);
    Dig4 = 0;
    
}





/*
 * 
 */

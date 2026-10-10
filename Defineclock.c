#include "Defineclock.h"
#include "definegpio.h"
#include "7_segmentled.h"





ModeClock_e modeclk = OFF;

uint8_t Back;
uint8_t Forward;

uint8_t pre_staBACK = 1;
uint8_t pre_staFORWARD = 1;

uint8_t preB0 = 1;
uint8_t preB1 = 1;


uint8_t Button_handle(uint8_t* pre_sta, uint8_t button){
    if(button == 0 && *pre_sta == 1 ){
        __delay_ms(20);
        if(button == 0 && *pre_sta == 1){
            *pre_sta = button;
            return 1;
        }
    }*pre_sta = button;
    return 0;
}


void CLOCK_Handle(void){
    Back = Button_handle(&pre_staBACK,Pin_ButBACK);
    Forward = Button_handle(&pre_staFORWARD,Pin_ButFORWARD);
}

void CLOCK_ChooseBF(ModeClock_e modeback,ModeClock_e modeforward ){
    if(Back){
        flag = 0;
        modeclk = modeback;
    }
    if(Forward){
        flag = 0;
        modeclk = modeforward;
    }
}




#ifndef __DEFINECLOCK_H
#define __DEFINECLOCK_H



#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
    
    


    
    
typedef enum{
    OFF = 0     ,
    AutoCouNS   ,
    AutoCouS    ,
}ModeClock_e;

extern uint8_t Back;
extern uint8_t Forward;
extern ModeClock_e modeclk;

extern uint8_t preB0;
extern uint8_t preB1;





uint8_t Button_handle(uint8_t* pre_sta, uint8_t button);

void CLOCK_Handle(void);
void CLOCK_ChooseBF(ModeClock_e modeback,ModeClock_e modeforward );

    
    
#ifdef	__cplusplus
}
#endif



#endif
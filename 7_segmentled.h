/* 
 * File:   7_segmentled.h
 * Author: khang
 *
 * Created on October 2, 2026, 1:39 PM
 */

#ifndef _SEGMENTLED_H
#define	_SEGMENTLED_H

#ifdef	__cplusplus
extern "C" {
#endif


    
    
//define pin

#define pin_a	RD0
#define pin_b	RD1
#define pin_c	RD2
#define pin_d	RD3
#define pin_e	RD4
#define	pin_f	RD5
#define pin_g	RD6
#define pin_dp	RD7

#define Dig1    RA0
#define Dig2    RA1
#define Dig3    RA2
#define Dig4    RA3
    
    
    
    
// map
//=====================//
//|    -pin_a-	      |//	
//|     |   |	      |//
//|  pin_f  pin_b     |//
//|     |   |         |//
//|    -pin_g-        |//
//| 	|   |         |//
//|  pin_e  pin_c     |//
//| 	|   |         |//
//|    -pin_d-        |//
//|           +pin_dp |//
//=====================//

//Counter number 

//mode of 7-segment Led is commond anode
// 0 -> ON
// 1 -> OFF

//=======================================================================//
//number | pin_dp | pin_g | pin_f | pin_e | pin_d | pin_c | pin_b | pin_a//
//=======================================================================//
// Zero  |   1   |   1   |   0   |   0   |   0   |   0   |   0   |   0   //
// One   |   1   |   1   |   1   |   1   |   1   |   1   |   0   |   0   //
// Two   |   1   |   0   |   1   |   0   |   0   |   1   |   0   |   0   //
// Three |   1   |   0   |   1   |   1   |   0   |   0   |   0   |   0   //
// Four  |   1   |   0   |   0   |   1   |   1   |   0   |   0   |   1   //
// Five  |   1   |   0   |   0   |   1   |   0   |   0   |   1   |   0   //
// Six   |   1   |   0   |   0   |   0   |   0   |   0   |   1   |   0   //
// Seven |   1   |   1   |   1   |   1   |   1   |   0   |   0   |   0   //
// Eight |   1   |   0   |   0   |   0   |   0   |   0   |   0   |   0   //
// Nine  |   1   |   0   |   0   |   1   |   0   |   0   |   0   |   0   //
//=======================================================================//

    
    

#define	Zero	0xC0
#define One     0xF9
#define Two     0xA4
#define Three	0xB0
#define Four	0x99
#define Five	0x92
#define Six     0x82
#define Seven	0xF8
#define Eight	0x80
#define Nine	0x90	
    
    
#define F       0x8E  


typedef enum{
    Count_Up    = 0,
    Count_down     ,
}status_enum;

    
extern const uint8_t number_buffer[10];
extern  uint8_t flag;
    
    
void LedSegment_Test(void);

void LedSegment_2RightLed(uint32_t number);

void LedSegment_2LeftLed(uint32_t number);

void LedSegment_SetupTime(uint16_t* time_sec,const status_enum mode);

void LedSegment_SendData(uint8_t data_1, uint8_t data_2, uint8_t data_3, uint8_t data_4);



#ifdef	__cplusplus
}
#endif

#endif	/* 7_SEGMENTLED_H */


/* Lab 1 first file - ID number 815009698 */ 
#include <p18f452.h>
#include <delays.h>
#include "xlcd_lab1.h"

/* Set configuration bits for use with ICD2 */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000

void DelayFor18TCY(void)
{
    Delay1TCY();
 	Delay1TCY();
    Delay1TCY();
    Delay1TCY();
 	Delay1TCY();
    Delay1TCY();
 	Delay1TCY();
 	Delay1TCY();
 	Delay10TCYx(1);
}
 
void DelayXLCD(void)     // minimum 5ms
{
    Delay1KTCYx(5); 		// Delay of 5ms
                            // Cycles = (TimeDelay * Fosc) / 4
                            // Cycles = (5ms * 4MHz) / 4
                            // Cycles = 5,000

}

void DelayPORXLCD(void)   // minimum 15ms
{
    Delay1KTCYx(15);		// Delay of 15ms
                            // Cycles = (TimeDelay * Fosc) / 4
                            // Cycles = (15ms * 4MHz) / 4
                            // Cycles = 15,000

}
 
 

void main (void)
{ 
    PORTD = 0X00;
    TRISD = 0X00;
    
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while( BusyXLCD() );
    
    SetDDRamAddr(0x43);
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    
    while( BusyXLCD() );
    WriteCmdXLCD( BLINK_ON );
    
    while( BusyXLCD() );
    putrsXLCD("HelloWorld!");
    
    while( BusyXLCD() );
       
    Sleep();
}

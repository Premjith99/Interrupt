/*
 * File:   interrupt1.c
 * Author: Premjith J
 *
 * Created on November 6, 2023, 3:22 PM
 */


#include <xc.h>

void main(void) 
{
    ADCON1=0X0F;
    TRISC=TRISD=0X00;
    GIE=1;
    INT0IE=1;//
    INTEDG0=0;//falling edge (high to low))because of button
    while(1)
    {
        LATD=0xFF;
        for(long i=0;i<100000;i++ );
        LATD=0x00;
        for(long i=0;i<100000;i++ );
    }
          
    return;
}
void __interrupt() isr()//only definition needed
{
    
   
    for(int j=0;j<10;j++)
    {
        LATC=0xFF;
        for(long i=0;i<100000;i++ );
        LATC=0x00;
        for(long i=0;i<100000;i++ );
    }
    INT0IF=0;//otherwise will not come out of the interrupt
    
}
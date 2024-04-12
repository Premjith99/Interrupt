/*
 * File:   interrupt2.c
 * Author: Premjith J
 *
 * Created on November 6, 2023, 4:00 PM
 */


#include <xc.h>
int count=0;
void main()
{
    ADCON1=0X0F;
    TRISC=TRISD=0X00;
    GIE=1;
    INT0IE=1;
    INTEDG0=0;
    while(1)
    {
        RC0=1;
        for(long i=0;i<100000;i++);
        RC0=0;
        for(long i=0;i<100000;i++);
        if(count==1)
        {
            LATD=0xff;
        }
        else if(count==2)
        {
            LATD=0x00;
        }
        else if(count==3)
        {
        LATD=0XFF;
        for(long i=0;i<100000;i++);
        LATD=0X00;
        for(long i=0;i<100000;i++);
        }
    }
}
void __interrupt() isr()
{
    count++;
    if(count==4)
    {
        count=1;
    }
        INT0IF=0;
}
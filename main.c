/*
 * File:   main.c
 * Author: nagay
 *
 * Created on April 15, 2020, 9:38 PM
 */


#include <avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include "DIO.h"
#include "lcd.h"

#define  BUTTON0         0 //port B
#define  BUTTON1         4 //port B
#define  BUTTON2         2 //port D

#define  LED0            2 //port C
#define  LED1            7 //port C
#define  LED2            3 //port D

#define portA            1
#define portB            2
#define portC            3
#define portD            4
char ON0[]="LED 0 is ON";
char OFF0[]="LED 0 is OFF";
char ON1[]="LED 1 is ON";
char OFF1[]="LED 1 is OFF";
char ON2[]="LED 2 is ON";
char OFF2[]="LED 2 is OFF";
char allON[]="All LEDs are ON";
char allOFF[]="All LEDs are OFF";


int main(void) {
    LCD_Init(); //initiate LCD with void fn
    int flag0=0;
    int flag1=0;
    int flag2=0;
    PINBas(BUTTON0,IN);//set pin in port B as input
    PINBas(BUTTON1,IN);
    PINDas(BUTTON2,IN);
    
    PINCas(LED0,OUT);//set pin in port C as output
    PINCas(LED1,OUT);
    PINDas(LED2,OUT);
    
    while (1) {
                                    /*1st*/
        if(isPressedB(BUTTON0))
        {
            flag0 ^=1;
            togglePIN(LED0,portC);
            
            if(flag0)
            {
                LCD_Clear();//clear LCD data
                LCD_String(ON0);
            }
            else
            {
                LCD_Clear();
                LCD_String(OFF0);
                _delay_ms(200);
                LCD_Clear();
            }
            _delay_ms(200);
        }
        
                                    /*2nd*/        
        if(isPressedB(BUTTON1))
        {
            flag1 ^=1;
            togglePIN(LED1,portC);
            
            if(flag1)
            {
                LCD_Clear();//clear LCD data
                LCD_String(ON1);
            }
            else
            {
                LCD_Clear();
                LCD_String(OFF1);
                _delay_ms(200);
                LCD_Clear();   
            }
            _delay_ms(200);
        }
        
                                    /*3rd*/       
        if(isPressedD(BUTTON2))
        {
            flag2 ^=1;
            togglePIN(LED2,portD);
            
            if(flag2)
            {
                LCD_Clear();//clear LCD data
                LCD_String(ON2);
            }
            else
            {
                LCD_Clear();
                LCD_String(OFF2);
                _delay_ms(200);
                LCD_Clear();
            }
            _delay_ms(200);
        }
        
    /*   if((flag0==0)&&(flag1==0)&&(flag2==0))
        {
           LCD_Clear();
           LCD_String(allOFF);
           _delay_ms(500);
           LCD_Clear();
        }
        if((flag0==1)&&(flag1==1)&&(flag2==1))
        {
           LCD_Clear();
           LCD_String(allON);
           _delay_ms(200);
        }*/
             
    }
}









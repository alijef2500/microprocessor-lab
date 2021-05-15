#include <mega32.h>

unsigned char step[4] = {0x09 , 0x05 , 0x06 ,0x0A} ;
int i, time  ; 
bit SWITCH = 0 ;

interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
TCNT0=0x83; 
time++ ;
PORTC.0 =! PORTC.0 ;

   if(time >4)
    {    

    PORTC.1 =! PORTC.1 ;
    time = 0 ;
      
        if(SWITCH == 1)
        {  PORTB = step[i];
            i++ ;

            if(i == 4) i = 0 ;
        }
    }
    
    if(PINC.2 == 0 ) SWITCH = 1 ;
     
}


void main(void)
{
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (1<<CS01) | (1<<CS00);
TCNT0=0x83;
OCR0=0x00;
TIMSK = 0X01 ;


DDRB = 0X0F;
DDRC = 0X03 ;
#asm("sei")



}

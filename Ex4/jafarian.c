#include <mega32a.h>
#include <delay.h>

int i,j,num , min , sec , hour ;
unsigned char seg[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
TCNT1H=0xD8F0 >> 8;
TCNT1L=0xD8F0 & 0xff;

j+= 5 ;
i++ ;

        if(i>=100)
        {
            i = 0 ;
            sec++ ;
            LED =! LED ;
            if(sec  == 60) sec = 0 , min++ ;
            if(min  == 60) min = 0 , hour++ ;
            if(hour == 24) hour = 0  ; 
        }
                                              
            if(j == 10) hour_two = 1,min_one = 0 ,num =( min%10) ,PORTC = seg[num] ;
            if(j == 20) min_one = 1, min_two = 0  ,num = (min/10)  ,PORTC = seg[num] ;
            if(j == 30) min_two = 1, hour_one = 0 ,num = (hour%10) ,PORTC = seg[num] ;
            if(j == 40) j = 0     ,hour_one = 1 ,hour_two = 0 ,num = (hour/10) ,PORTC = seg[num] ;
            
            
            
        
}

void main(void)
{
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (1<<CS11) | (0<<CS10);
TCNT1H=0xD8;
TCNT1L=0xF0;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;
TIMSK = 0X04 ;
#asm("sei")

DDRC = 0XFF ; 
DDRD = 0XFF ;
PORTD = 0XFF; 

hour = 23;
min =59 ;
}

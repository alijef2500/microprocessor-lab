#include <mega32a.h>
#include <delay.h>

    int i ;
    bit x = 0 ;
    
void main(void)
{




DDRB = 0xFF ;  

while (1)
      {
            for(i=0 ; i<500 ; i++)
            {
                delay_ms(1);
            }
            
            x =!x ;
            if(x == 1)PORTB = 0xFF;
            else PORTB = 0x00 ;
      }
}

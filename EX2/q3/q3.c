#include <mega32a.h>
#include <delay.h>

    int i ,num = 1 ;
    bit x ;
void main(void)
{




DDRB = 0xFF ;   
DDRA.0 = 0  ;  

while(1)
{

    while(PINA.0 == 1)
            {
                delay_ms(1);
            }


    while (1)
          {
                for(i=0 ; i<500 ; i++)
                {
                    delay_ms(1);
                }
                
                PORTB = num ;
                
                if(x==0)num = num*2 ;
                else num = num/2    ;
                
                if(num == 128) x = 1 ;
                if(num ==  1 ) x = 0 ;

          }
}

}
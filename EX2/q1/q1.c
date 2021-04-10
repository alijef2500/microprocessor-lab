#include <mega32a.h>
#include <delay.h>

    int i ;
void main(void)
{



DDRA.0 = 1 ; 
while (1)
      {
            for(i=0 ; i<500 ; i++)
            {
                delay_ms(1);
            }
            
            PORTA.0 =! PORTA.0 ;
      }
}

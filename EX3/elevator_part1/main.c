#include <mega32a.h>
#include <delay.h>

unsigned char number[] ={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int a , b ,flor = 1 , hadaf , i,z  , tabaga;

int target[21] ;
bit press ; 


void show(int flor)
{
     {
     a = flor/10 ;
     b = flor%10 ;
     
     tabaga = flor;
     delay_ms(50); 

    dig1 = 0 ; //on
    dig2 = 1 ; //off
    PORTB = number[a];
        
    delay_ms(50);    

    dig1 = 1 ; //off
    dig2 = 0 ; //on
    PORTB = number[b];
    }
     
     
}

void wait(int j)
{
    for (z = 0 ;z<= j ;z++)
    {
        show(flor);
    }
}

void open ()
{
      MOTOR_RIGHT = 1 ; 
      wait(30); // 3 SEC
      MOTOR_RIGHT = 0 ; 
      MOTOR_LEFT = 1  ;
      wait(30);
      MOTOR_LEFT = 0  ;
      
      PORTB.7 = 0 ;
}

void process()
{
 if(press == 1)
    { 
       for(i=1 ; i<21 ;i++)
       {
            if(target[i] == 1)
            {   
                PORTB.7 = 1 ; // LED ON
                hadaf = i ;
                
                if(hadaf < flor)
                    {
                    wait(5);
                        flor-- ;
                    }
                    if(hadaf > flor)
                    {
                    wait(5); // 500ms
                        flor++ ;
                    }    
                    if(hadaf == flor)
                    {    
                        press = 0 ;
                        open() ;
                        target[i] = 0 ;
                    } 
            }
       }

    }     
}


void main(void)
{

DDRB = 0XFF ;

DDRD.4 = 1 ;
DDRD.5 = 1 ;
DDRD.6 = 1 ;
DDRD.7 = 1 ;

while (1)
      {
        process();
        show(flor);
        
        if(f11 == 0)
        {
            target[1] = 1 ;
            press = 1 ;   
        }
        if(f12 == 0)
        {
            target[2] = 1 ;
            press = 1 ;      
        }
        if(f13 == 0)
        {
            target[3] = 1 ;   
            press = 1 ;   
        }
        if(f14 == 0 )
        {
            press = 1 ;   
            target[4] = 1 ;   
        }
        if(f15 == 0)
        {
            press = 1 ;   
            target[5] = 1 ;   
        }
        if(f16 == 0)
        {
            press = 1 ;   
            target[6] = 1 ;   
        }
        if(f17 == 0)
        {
            press = 1 ;   
            target[7] = 1 ;   
        }
        if(f18 == 0)
        {
            press = 1 ;   
            target[8] = 1 ;   
        }
        if(f19 == 0)
        {
            press = 1 ;   
            target[9] = 1 ;   
        }
        if(f110 == 0)
        {
            press = 1 ;   
            target[10] = 1 ;   
        }
        if(f111 == 0)
        {
            press = 1 ;   
            target[11] = 1 ;   
        }
        if(f112 == 0)
        {
            press = 1 ;   
            target[12] = 1 ;   
        }
        if(f113 == 0)
        {
            press = 1 ;   
            target[13] = 1 ;   
        }
        if(f114 == 0)
        {
            press = 1 ;   
            target[14] = 1 ;   
        }
        if(f115 == 0)
        {
            press = 1 ;   
            target[15] = 1 ;   
        }
        if(f116 == 0)
        {
            press = 1 ;   
            target[16] = 1 ;   
        }
        if(f117 == 0)
        {
            press = 1 ;   
            target[17] = 1 ;   
        }
        if(f118 == 0)
        {
            press = 1 ;   
            target[18] = 1 ;   
        }
                
        if(f119 == 0)
        {
            press = 1 ;   
            target[19] = 1 ;   
        }        
        if(f120 == 0)
        {
            press = 1 ;   
            target[20] = 1 ;   
        }        
      }
}

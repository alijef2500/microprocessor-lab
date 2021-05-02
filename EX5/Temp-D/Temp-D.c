

#define ADC_VREF_TYPE ((0<<REFS1) | (0<<REFS0) | (0<<ADLAR))
int z ;
float  cel , F , vol;
unsigned char c[20];
void measure()
{

                ADMUX=(1<<REFS0)|(0<<REFS1); 
                ADCSRA=(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); 
                ADCSRA=(1<<ADEN);
                ADMUX |=0b000;
                ADCSRA|=(1<<ADSC); 
                while(!(ADCSRA & (1<<ADIF))); 
                ADCSRA|=(1<<ADIF);
                
                vol = (3.0*ADCW)/615.0 ;
                
                cel = vol/0.01  ;
                z = cel/1 ;
                F = (z*1.8) + 32 ;
                
                
                
}

void main(void)
{

ADMUX=ADC_VREF_TYPE;
ADCSRA=(1<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
SFIOR=(0<<ADTS2) | (0<<ADTS1) | (0<<ADTS0);

lcd_init(20);

while (1)
      {
            measure();
            if(PINC.0 == 1)
            {
            sprintf(c,"Temp = %4.2f 'F",F);
            }
            else
            {
            sprintf(c,"Temp = %3.0f 'C",cel);            
            }
            lcd_puts(c);
            delay_ms(500);
            lcd_clear();
      }
}

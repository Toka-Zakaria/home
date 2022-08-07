#include"timer0.h"

ISR(TIMER0_OVF_vect)
{

}

void timer0_init_overflow(void)
{
	TCNT0 = 0; 
	TIMSK |= (1<<TOIE0);
  
	/* Configure the timer control register
	 * 1. Non PWM mode FOC0=1
	 * 2. Normal Mode WGM01=0 & WGM00=0
	 * 3. Normal Mode COM00=0 & COM01=0 
	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	 */
	TCCR0 = (1<<FOC0) | (1<<CS02) | (1<<CS00);
}






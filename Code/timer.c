/*
 * timer.c
 *
 *  Created on: Jun 5, 2021
 *      Author: ammar
 */
#include"timer.h"
/*   PWM config
	 * PWM in Timer0
	 * clear on compare
	 * F_CPU / 8
	 */
void Timer0_Init(uint8 duty_cycle)
{
	TCNT0 = 0;

DDRB |= (1<<PB3);

OCR0  = duty_cycle;

TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01) | (1<<CS00);
}

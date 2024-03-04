/*
 * interrupt.c
 *
 *  Created on: Jun 5, 2021
 *      Author: ammar
 */
#include "interrupt.h"

static volatile void (*g_callBackPtr1)(void) = NULL_PTR;

ISR(INT1_vect)
{
	if(g_callBackPtr1 != NULL_PTR)
	{
		(*g_callBackPtr1)();
	}
}
/*
 * interrupt
 * Using interrupt 1
 * Rising Edge
 */
void INTERRUPT_init(void)
{
		CLEAR_BIT(DDRD,PD3);
		SET_BIT(GICR,INT1);
		SET_BIT(MCUCR,ISC10);
		SET_BIT(MCUCR,ISC11);
}
void INTERRUPT_1_callBack(void (*a_ptr)(void))
{
	g_callBackPtr1 = a_ptr;
}



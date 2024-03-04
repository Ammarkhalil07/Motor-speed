/*
 * mini2.c
 *
 *  Created on: Jun 5, 2021
 *      Author: ammar
 */
/*
 * Mini_Project2.c
 *
 *  Created on: Jun 3, 2021
 *      Author: ammar
 */
#include "interrupt.h"
#include "adc.h"
#include "lcd.h"
#include "timer.h"

uint8 Direction_Flag = 0;
void Anticlock_Direction(void)
{
	if(Direction_Flag == 0)
	{
		SET_BIT(PORTB,PB0);
		CLEAR_BIT(PORTB,PB1);
		Direction_Flag = 1;
	}
	else if(Direction_Flag == 1)
	{
		SET_BIT(PORTB,PB1);
		CLEAR_BIT(PORTB,PB0);
		Direction_Flag = 0;
	}
}

int main(void)
{
	uint16 g_adcResult;
	uint16 g_ORC0;
	 /* output */
	SET_BIT(DDRB,PB0);
	SET_BIT(DDRB,PB1);
	/* turn on motor in clockwise */
	SET_BIT(PORTB,PB1);
	CLEAR_BIT(PORTB,PB0);
	/* intialize ADC and interrupt and LCD*/
    ADC_init();
	LCD_init();
	INTERRUPT_init();
	/* Call back interrupt */
	INTERRUPT_1_callBack(Anticlock_Direction);
	/* Enable The i-bit*/
	SREG |= (1<<7);

	LCD_clearScreen();
	LCD_displayString("ADC Value = ");

	while(1)
	{
		g_adcResult = ADC_readChannel(0);
		/* value of OCR0 = adcValue / 4 */
		g_ORC0= ((ADC_readChannel(0))/4);
		/* Enable the timer at value of ORC0 */
		Timer0_Init(g_ORC0);
		/* display adcVaule */
		LCD_goToRowColumn(0,12);

		if(g_adcResult > 1000)
		{
			LCD_intgerToString(g_adcResult);
		}
		else if(g_adcResult >= 100 && g_adcResult < 1000)
		{
			LCD_displayString(" ");
			LCD_intgerToString(g_adcResult);
		}
		else if(g_adcResult >= 10 && g_adcResult < 100)
		{
			LCD_displayString("  ");
			LCD_intgerToString(g_adcResult);
		}
		else if(g_adcResult < 10)
		{
			LCD_displayString("   ");
			LCD_intgerToString(g_adcResult);
		}

	}
}

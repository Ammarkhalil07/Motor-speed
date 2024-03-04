 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#include "adc.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(void)
{
	ADMUX = 0;
	ADCSRA = (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0);
}

uint16 ADC_readChannel(uint8 ch_num)
{
	ADMUX = (ADMUX & 0xE0) | (ch_num & 0x07);
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}

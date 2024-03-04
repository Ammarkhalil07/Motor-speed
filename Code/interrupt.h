/*
 * interrupt.h
 *
 *  Created on: Jun 5, 2021
 *      Author: ammar
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"

void INTERRUPT_init(void);
void INTERRUPT_callBack(void (*a_ptr)(void));


#endif /* INTERRUPT_H_ */

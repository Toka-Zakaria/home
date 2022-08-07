#ifndef SWUART_H
#define SWUART_H

#include"gpio.h" /*contain all gpio decelared*/ 
#include"MC.h"
#include"platform.h" /*contains new data types by typdef (uint32_t , uint8_t,...)*/

void SWUART_init(uint32_t baudrate);

void SWUART_send(uint8_t data);

void SWUART_receive(uint8_t *data);


#endif

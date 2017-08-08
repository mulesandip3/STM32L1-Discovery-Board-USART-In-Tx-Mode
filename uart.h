#ifndef UART_H_
#define UART_H_

#include "main.h"

#define UART_Tx GPIO_Pin_9 
#define UART_Rx GPIO_Pin_10 

void usart_gpio_init(void);
void usart_init(void);
int putchar(uint16_t c);

#endif



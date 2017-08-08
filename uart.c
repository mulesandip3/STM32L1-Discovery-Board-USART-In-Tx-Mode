#include "uart.h"


void usart_gpio_init(void)
{
	GPIO_InitTypeDef GPIO_InitStrucure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 , ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
	// Initialize USART1_Tx
	GPIO_InitStrucure.GPIO_Pin = UART_Tx;
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1);
	GPIO_InitStrucure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStrucure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStrucure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStrucure.GPIO_Speed = GPIO_Speed_40MHz;
	GPIO_Init(GPIOA,&GPIO_InitStrucure);
	// Initialize USART_Rx
	GPIO_InitStrucure.GPIO_Pin = UART_Rx;
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1);
	GPIO_InitStrucure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStrucure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStrucure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStrucure.GPIO_Speed = GPIO_Speed_40MHz;
	GPIO_Init(GPIOA,&GPIO_InitStrucure);
	
}

void usart_init(void)
{
	USART_InitTypeDef  USART_InitStructure;	
	USART_StructInit(&USART_InitStructure);
	USART_InitStructure.USART_Mode =  USART_Mode_Tx;
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(USART1,&USART_InitStructure);
	USART_Cmd(USART1,ENABLE);
}

int putchar(uint16_t c)
{
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
	USART_SendData(USART1,c);
	return 0;
}


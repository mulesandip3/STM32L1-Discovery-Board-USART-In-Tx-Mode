#include "main.h"
int main()
{
	int i=0;
	usart_gpio_init();
	usart_init();
	lcd_init();
	while(i<=10)
	{
		/* Send dummy data */
    USART_SendData(USART1, 'X');
    /* Loop until the end of transmission */
    while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
    {}
		lcd_send_byte(LCD_CMD, 0x01);
		delay_ms(100);
		lcd_send_byte(LCD_CMD, LCD_LINE1);
		lcd_send_byte(LCD_DATA, 'X');
		i++;
		delay_ms(100);
  }
}

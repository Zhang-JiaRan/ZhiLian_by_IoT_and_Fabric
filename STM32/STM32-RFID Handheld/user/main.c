

#include "stm32f10x.h"			         
#include "Delay.h"				
#include "OLED.h"							
#include "rc522_config.h"			
#include "rc522_function.h"	
#include "bsp_SysTick.h"	
#include "Key.h"						
#include "bsp_led.h"				
#include <stdbool.h>					
#include "usart1.h"    			
#include "usart2.h"   			
#include "timer4.h" 
void RFID(void);		
int main(void)			
{
	OLED_Init();
	Usart1_Init(9600);
		
	while(1)
	{
		RFID();
	}
}
void RFID(void)				
{
		SysTick_Init (); 
		RC522_Init (); 
		LED_GPIO_Config();	 	
		GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);
		PcdReset();				
		M500PcdConfigISOType ( 'A' );	
		IC_test();			
}

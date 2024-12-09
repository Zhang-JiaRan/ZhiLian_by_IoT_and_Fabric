#include "bsp_led.h"   

void LED_GPIO_Config(void)
{		
		GPIO_InitTypeDef GPIO_InitStructure;/*定义一个GPIO_InitTypeDef类型的结构体*/
		RCC_APB2PeriphClockCmd( LED1_GPIO_CLK, ENABLE);/*开启LED相关的GPIO外设时钟*/
		GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN;	/*选择要控制的GPIO引脚*/	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;/*设置引脚模式为通用推挽输出*/ 
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; /*设置引脚速率为50MHz */ 
		GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);/*调用库函数，初始化GPIO*/
}

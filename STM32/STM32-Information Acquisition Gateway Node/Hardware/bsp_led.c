#include "bsp_led.h"   

void LED_GPIO_Config(void)
{		
		GPIO_InitTypeDef GPIO_InitStructure;/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		RCC_APB2PeriphClockCmd( LED1_GPIO_CLK, ENABLE);/*����LED��ص�GPIO����ʱ��*/
		GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN;	/*ѡ��Ҫ���Ƶ�GPIO����*/	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;/*��������ģʽΪͨ���������*/ 
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; /*������������Ϊ50MHz */ 
		GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);/*���ÿ⺯������ʼ��GPIO*/
}

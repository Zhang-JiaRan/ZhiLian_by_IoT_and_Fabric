#include "stm32f10x.h"     
#include "stm32f10x_it.h"  
#include "usart1.h"        
#include "usart2.h"      
#include "timer3.h"      
#include "mqtt.h"     
#include "dht22.h"     
#include "AD.h"        
#include "OLED.h"
void USART3_IRQHandler(void)   
{                      
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)   
	{  
		if(connectFlag == 0) 							   
		{                                     
			if(USART3->DR)
			{                                     			
				Usart3_RxBuff[Usart3_RxCounter] = USART3->DR;
				Usart3_RxCounter++; 						
			}					
		}
		else
		{		                                         
			Usart3_RxBuff[Usart3_RxCounter] = USART3->DR;   			
			if(Usart3_RxCounter == 0)
			{    									    												
				TIM_Cmd(TIM4, ENABLE); 
			}
			else																					
			{                        									    
				TIM_SetCounter(TIM4, 0);  
			}	
			Usart3_RxCounter++;         				    
		}
	}
} 
void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
	{                	
		memcpy(&MQTT_RxDataInPtr[2], Usart3_RxBuff, Usart3_RxCounter);  
		MQTT_RxDataInPtr[0] = Usart3_RxCounter/256;                 
		MQTT_RxDataInPtr[1] = Usart3_RxCounter%256;					 
		MQTT_RxDataInPtr += RBUFF_UNIT;                               
		if(MQTT_RxDataInPtr == MQTT_RxDataEndPtr)                     
			MQTT_RxDataInPtr = MQTT_RxDataBuf[0];                    	
		Usart3_RxCounter = 0;                                        
		TIM_SetCounter(TIM3, 0);                                   
		TIM_Cmd(TIM4, DISABLE);                        				
		TIM_SetCounter(TIM4, 0);                        	
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);     		
	}
}
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
		{  
		switch(pingFlag) 				
		{                               
			case 0:						
					MQTT_PingREQ(); 		
					break;
			case 1:				
					TIM3_ENABLE_2S(); 	 
					MQTT_PingREQ();			
					break;
			case 2:						
			case 3:				          
			case 4:				           
					MQTT_PingREQ();  		
					break;
			case 5:						
					connectFlag = 0;        
					TIM_Cmd(TIM3, DISABLE); 			
					break;			
		}
		pingFlag++;           		   	
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update); //清除TIM3溢出中断标志 	
	}
}
extern int mq2;
void TIM2_IRQHandler(void)
{
	u8 humidity;			
	u8 temperature;		
				
	char head1[3];
	char temp[100];		
	char tempAll[100];		
	
	int	dataLen = 0;			
	AD_Init();
	mq2=(int)(0.02417*AD_GetValue());
	if(TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)	
	{ 
		DHT22_Read_Data(&temperature,&humidity);	

		memset(temp,    0, 50);			
		memset(tempAll, 0, 100);			
		memset(head1,   0, 3);			

		OLED_ShowNum(4,1,mq2,2);
		OLED_ShowNum(4,5,temperature,2);
		OLED_ShowNum(4,9,humidity,2);
		sprintf(temp,"{\"MQ\":\"%d\",\"TM\":\"%d\",\"HM\":\"%d\",\"JD\":\"%d\",\"WD\":\"%d\",\"P\":\"%d\",\"F\":\"%d\",\"R\":\"%d\",\"T\":\"%d\"}",mq2, temperature, humidity,100,100,1,1,1,1);

		head1[0] = 0x03; 					
		head1[1] = 0x00; 					
		head1[2] = strlen(temp);  				
		sprintf(tempAll, "%c%c%c%s", head1[0], head1[1], head1[2], temp);
		
		u1_printf("\r\n"); 
		u1_printf("%s\r\n", tempAll + 3);
		
		dataLen = strlen(temp) + 3;
		MQTT_PublishQs0(Data_TOPIC_NAME,tempAll, dataLen);
		
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);   	
	}
}
void NMI_Handler(void)
{
}
void HardFault_Handler(void)
{
  while (1)
  {
  }
}
void MemManage_Handler(void)
{
  while (1)
  {
  }
}

void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}
void UsageFault_Handler(void)
{
  while (1)
  {
  }
}
void SVC_Handler(void)
{
}
void DebugMon_Handler(void)
{
}


/*-------------------------------------------------*/
/*函数名：可挂起的系统服务处理函数                 */
/*参  数：无                                       */
/*返回值：无                                       */
/*-------------------------------------------------*/
void PendSV_Handler(void)
{
}

/*-------------------------------------------------*/
/*函数名：SysTic系统嘀嗒定时器处理函数             */
/*参  数：无                                       */
/*返回值：无                                       */
/*-------------------------------------------------*/
void SysTick_Handler(void)
{
}

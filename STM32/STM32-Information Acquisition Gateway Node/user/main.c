#include "stm32f10x.h"			          
#include "Delay.h"					
#include "OLED.h"							
#include "mlx90614.h"				
#include "dht22.h"						
#include "rc522_config.h"		
#include "rc522_function.h"	
#include "bsp_SysTick.h"			
#include "Key.h"						
#include "bsp_led.h"				
#include <stdbool.h>				
#include "usart1.h"    		
#include "usart2.h"   			
#include "timer2.h"    			
#include "timer3.h"     		
#include "timer4.h"     			
#include "mqtt.h"       		
#include "wifi.h"	     			
#include "control.h"    			
#include "led.h"   					
#include "AD.h"   					
#include "lcd_init.h"
#include "lcd.h"
#include "pic.h"

char *cmdLED_On = "LEDON";     
char *cmdLED_Off = "LEDOFF";    
char *cmdDHT11_On = "DHTON";   
char *cmdDHT11_Off = "DHTOFF";  
char *ledFlag = "LEDOFF";      
int   dhtFlag = 0;		       

u8 temp,humi; 							
float Temperature = 0; 		
int MenuMode,MenuShow;
int KeyNum,MODE,MenuSelect;
uint16_t ADValue;
float Voltage;
int mq2;
long int weidu,jingdu;
int w1,w2,w3,j1,j2,j3;



void Show(void);
void TempShow(void);
void TempAndHumi(void);
void People(void);
void RFID(void);
void MQ2(void);
void WiFi(void);
void Menu(void);

int main(void)			
{
	AD_Init();
	Delay_Init();
	OLED_Init();
	Key_Init();
	DHT22_Init();
	SMBus_Init();	
	Usart1_Init(9600);
	LCD_Init();
	LCD_Fill(0,0,LCD_W,LCD_H,WHITE);

	
	
	
	
	while(1)
	{
		
		Show();
	}
}

void Show(void)				
{
	
		weidu=12123456;
		jingdu=123123456;
		w1=weidu/1000000;
		w2=(weidu%1000000)/1000;
		w3=weidu%1000;
		j1=jingdu/1000000;
		j2=(jingdu%1000000)/1000;
		j3=jingdu%1000;
		DHT22_Read_Data(&temp,&humi);
		ADValue = AD_GetValue();
		Temperature = SMBus_ReadTemp();
		mq2=(int)(99*ADValue / 4096.0);
		LCD_ShowPicture(0,0,24,24,gImage_wendu);
		LCD_ShowIntNum(25,0,temp,2,BLACK,WHITE,24);
		LCD_ShowString(48,0,"`C",BLACK,WHITE,24,0);
		LCD_ShowPicture(86,0,24,24,gImage_shidu);
		LCD_ShowIntNum(112,0,humi,2,BLACK,WHITE,24);
		LCD_ShowString(142,0,"%",BLACK,WHITE,24,0);
		
		LCD_ShowPicture(0,28,24,24,gImage_yanwu);
		LCD_ShowIntNum(25,28,mq2,2,BLACK,WHITE,24);
		LCD_ShowString(53,28,"%",BLACK,WHITE,24,0);
		LCD_ShowPicture(86,28,24,24,gImage_tiwen);
		LCD_ShowIntNum(112,28,temp,2,BLACK,WHITE,24);
		LCD_ShowString(142,28,"C",BLACK,WHITE,24,0);
		
		LCD_ShowPicture(0,56,24,24,gImage_siji);
		LCD_ShowChinese(30,56,"有",BLACK,WHITE,24,0);
		LCD_ShowPicture(86,56,24,24,gImage_huo);
		LCD_ShowChinese(120,56,"无",BLACK,WHITE,24,0);
		
		LCD_ShowPicture(0,90,30,30,gImage_gps);
		LCD_ShowChinese(34,86,"纬度",BLACK,WHITE,16,0);
		LCD_ShowChinese(34,105,"经度",BLACK,WHITE,16,0);
		LCD_ShowIntNum(80,86,w1,2,BLACK,WHITE,16);
		LCD_ShowString(97,86,".",BLACK,WHITE,16,0);
		LCD_ShowIntNum(103,86,w2,3,BLACK,WHITE,16);
		LCD_ShowIntNum(128,86,w3,3,BLACK,WHITE,16);
		
		
		LCD_ShowIntNum(72,105,j1,3,BLACK,WHITE,16);
		LCD_ShowString(97,105,".",BLACK,WHITE,16,0);
		LCD_ShowIntNum(103,105,j2,3,BLACK,WHITE,16);
		LCD_ShowIntNum(128,105,j3,3,BLACK,WHITE,16);
		LCD_DrawLine(0,83,240,83,BLACK);
		LCD_DrawLine(78,0,78,83,BLACK);


}




void TempShow(void)				
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_Out_PP ;
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz ;
	GPIO_Init(GPIOC,&GPIO_InitStructure);	
	GPIO_ResetBits(GPIOC,GPIO_Pin_14);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure3;
	GPIO_InitStructure3.GPIO_Mode =GPIO_Mode_Out_PP ;
	GPIO_InitStructure3.GPIO_Pin =GPIO_Pin_2;
	GPIO_InitStructure3.GPIO_Speed =GPIO_Speed_50MHz ;
	GPIO_Init(GPIOA,&GPIO_InitStructure3);
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	
	SMBus_Init();	
	OLED_ShowString(1,1,"Your Temperature");
	OLED_ShowString(2,1,"CeWen: ");
	Temperature = SMBus_ReadTemp();
	if((int)(Temperature)>=37)
	{
		GPIO_SetBits(GPIOC,GPIO_Pin_14);
		u1_printf("Menu2: Temperature:%2d ,high\r\n",(int)(Temperature));
		GPIO_SetBits(GPIOA,GPIO_Pin_2);
	}
	else
	{
		GPIO_ResetBits(GPIOC,GPIO_Pin_14);	
		u1_printf("Menu2: Temperature:%2d ,low\r\n",(int)(Temperature));
		GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	}
	OLED_ShowNum(2,8,Temperature, 2);	
	OLED_ShowString(2,10," 'C    ");
	OLED_ShowString(3,1,"                ");
	OLED_ShowString(4,1,"                ");
}
void TempAndHumi(void)					
{
	DHT22_Read_Data(&temp,&humi);
	OLED_ShowString(1,1,"Temp And Humi:  ");
	OLED_ShowString(2,1,"WenDu: ");
	OLED_ShowNum(2,8,temp,2);		
	OLED_ShowString(2,10," 'C    ");
	OLED_ShowString(3,1,"ShiDu: ");
	OLED_ShowNum(3,8,humi,2);		
	OLED_ShowString(3,10," %     ");
	OLED_ShowString(4,1,"                ");
	u1_printf("Menu3: Temp:%2d ,Humi:%2d \r\n",temp,humi);
}
void People(void)							
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure1;
	GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure1);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure2;
	GPIO_InitStructure2.GPIO_Mode =GPIO_Mode_Out_PP ;
	GPIO_InitStructure2.GPIO_Pin =GPIO_Pin_13;
	GPIO_InitStructure2.GPIO_Speed =GPIO_Speed_50MHz ;
	GPIO_Init(GPIOC,&GPIO_InitStructure2);
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure3;
	GPIO_InitStructure3.GPIO_Mode =GPIO_Mode_Out_PP ;
	GPIO_InitStructure3.GPIO_Pin =GPIO_Pin_2;
	GPIO_InitStructure3.GPIO_Speed =GPIO_Speed_50MHz ;
	GPIO_Init(GPIOA,&GPIO_InitStructure3);
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	
	OLED_ShowString(1,1,"Whether Someone ");
	OLED_ShowString(2,1,"Is Detected ?   ");
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4) == 0)
	{
		GPIO_SetBits(GPIOC,GPIO_Pin_13);	
		GPIO_SetBits(GPIOA,GPIO_Pin_2);
		OLED_ShowString(3,1,"                ");
		OLED_ShowString(4,1,"True,anyone here");
		u1_printf("Menu4: True,anyone here\r\n");
	}
	else
	{
		GPIO_ResetBits(GPIOC,GPIO_Pin_13);
		GPIO_ResetBits(GPIOA,GPIO_Pin_2);
		OLED_ShowString(3,1,"                ");
		OLED_ShowString(4,1,"False,no one    ");
		u1_printf("Menu4: False,no one\r\n");
	}
}
void RFID(void)							
{
		SysTick_Init (); 
		RC522_Init (); 	
		PWM_Init();
		LED_GPIO_Config();	 		
		GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);
		PcdReset();				
		M500PcdConfigISOType ( 'A' );	
		OLED_ShowString(1,1,"      UPC       ");
		OLED_ShowString(2,1,"Need Your Card! ");
		OLED_ShowString(3,1,"                ");
		OLED_ShowString(4,1,"                ");
		IC_test();	
}
void MQ2(void)
{
		ADValue = AD_GetValue();
		mq2=(int)(99*ADValue / 4096.0);
		Delay_ms(100);

}
void WiFi(void)						
{
	Delay_Init();                    
	Usart1_Init(9600);    
	Usart3_Init(115200);   
	TIM4_Init(500,7200);  
	OLED_ShowString(1,1," Uploading Data ");
	OLED_ShowString(2,1,"  By Your WiFi  ");
	OLED_ShowString(3,1,"                ");
	OLED_ShowString(4,1,"                ");
	WiFi_ResetIO_Init();  
	IoT_Parameter_Init(); 
	while(1)
	{		
		if(connectFlag == 1) 
		{     
			if(MQTT_TxDataOutPtr != MQTT_TxDataInPtr)
			{                
				if((MQTT_TxDataOutPtr[2] == 0x10)||((MQTT_TxDataOutPtr[2] == 0x82)&&(connectPackFlag == 1))||(subcribePackFlag == 1)) 
				{    
					if (MQTT_TxDataOutPtr[2] == 0x30) 
					{	
						u1_printf("send data:0x%x,Push MCU data to server\r\n", MQTT_TxDataOutPtr[2]);	
						u1_printf("\r\n");
					}
					else 
					{
						u1_printf("send data:0x%x\r\n", MQTT_TxDataOutPtr[2]);
					}
					MQTT_TxData(MQTT_TxDataOutPtr);						
					MQTT_TxDataOutPtr += TBUFF_UNIT;				
					if(MQTT_TxDataOutPtr == MQTT_TxDataEndPtr)			
					{ 
						MQTT_TxDataOutPtr = MQTT_TxDataBuf[0];				
					}	
				} 				
			}
			if(MQTT_RxDataOutPtr != MQTT_RxDataInPtr) 
			{												
				u1_printf("Data received:\r\n");
				if(MQTT_RxDataOutPtr[2] == 0x20)
				{             			
					switch(MQTT_RxDataOutPtr[5])
					{					   
						case 0x00 : u1_printf("CONNECT Message Success\r\n");				
										connectPackFlag = 1;					
									break;													                                          
						case 0x01 : u1_printf("Connection rejected, protocol version not supported, ready to restart\r\n");  
									connectFlag = 0;										
									break;													
						case 0x02 : u1_printf("Connection rejected, unqualified client identifier, ready to restart\r\n");
									connectFlag = 0;                                           
									break; 														
						case 0x03 : u1_printf("Connection rejected, server unavailable, ready to restart\r\n");	
									connectFlag = 0;											
									break;													
						case 0x04 : u1_printf("Connection rejected, invalid user name or password, ready to restart\r\n");	
									connectFlag = 0;															
									break;													
						case 0x05 : u1_printf("Connection rejected, unauthorized, ready to restart\r\n");				
									connectFlag = 0;														
									break;													
						default   : u1_printf("Connection rejected, unknown status, ready to restart\r\n");		  
									connectFlag = 0;												
									break;																			
					}				
			    }			
				else if(MQTT_RxDataOutPtr[2] == 0x90)
				{ 
					switch(MQTT_RxDataOutPtr[6])
					{					
						case 0x00 :
						case 0x01 : 
									u1_printf("Subscription succeeded\r\n");		
									subcribePackFlag = 1;			
									pingFlag = 0;					
									TIM3_ENABLE_30S();				
									Send_Data();
									TIM2_ENABLE_10S();
									break;						                                          
						default: 
									u1_printf("Subscription failed, ready to restart\r\n");
									connectFlag = 0;				
									break;													
						}					
			    }
				else if(MQTT_RxDataOutPtr[2] == 0xD0)
				{ 
					u1_printf("PING Message reply\r\n");                                        
					if(pingFlag == 1)
					{                   						       
						 pingFlag = 0;    				       		
					}
					else if(pingFlag > 1)	
					{ 				 								
						pingFlag = 0;     				      		
						TIM3_ENABLE_30S(); 				      	
					}				
				}	
				else if((MQTT_RxDataOutPtr[2] == 0x30))
			    { 
					u1_printf("Server level 0 push\r\n"); 		 
					MQTT_DealPushdata_Qs0(MQTT_RxDataOutPtr);   
				}									
				MQTT_RxDataOutPtr += RBUFF_UNIT;               
				if(MQTT_RxDataOutPtr == MQTT_RxDataEndPtr)    
				{
					MQTT_RxDataOutPtr = MQTT_RxDataBuf[0];               
				}		          
			}
			if(MQTT_CMDOutPtr != MQTT_CMDInPtr)							
			{                             		       
				u1_printf("Command: %s\r\n",&MQTT_CMDOutPtr[2]);         
				
				if(!memcmp(&MQTT_CMDOutPtr[2],cmdLED_On,strlen(cmdLED_On)))
				{                                            
					ledFlag = "LEDON";  								             
				}
				else if(!memcmp(&MQTT_CMDOutPtr[2],cmdLED_Off,strlen(cmdLED_Off))) 
				{ 
					ledFlag = "LEDOFF";                                              
				}
				else if(!memcmp(&MQTT_CMDOutPtr[2],cmdDHT11_On,strlen(cmdDHT11_On)))
				{      
					dhtFlag = 1;                 
					TIM2_ENABLE_10S();        
				}
				else if(!memcmp(&MQTT_CMDOutPtr[2],cmdDHT11_Off,strlen(cmdDHT11_Off)))
				{     
					dhtFlag = 0;                
					TIM_Cmd(TIM2,DISABLE);		
				}								
				else u1_printf("Unknown instruction\r\n");				
			
				MQTT_CMDOutPtr += CBUFF_UNIT;				
				if(MQTT_CMDOutPtr == MQTT_CMDEndPtr)	  
				MQTT_CMDOutPtr = MQTT_CMDBuf[0];		
				Send_Data();			
			}
		}
		else
		{ 
			u1_printf("Need to connect to the server\r\n");                           
			TIM_Cmd(TIM4, DISABLE);                   
			TIM_Cmd(TIM3, DISABLE);                    
			WiFi_RxCounter = 0;                                                
			memset(WiFi_RX_BUF, 0, WiFi_RXBUFF_SIZE);   
			if(WiFi_Connect_IoTServer() == 0)			  
			{   			     
				u1_printf("TCP connection established successfully\r\n");        
				connectFlag = 1;                          
				WiFi_RxCounter = 0;                                           
				memset(WiFi_RX_BUF, 0, WiFi_RXBUFF_SIZE); 
				MQTT_Buff_Init();                                           
			}				
		}
	}
	
}	


void Menu(void)		
	{	
		end:
	if(MenuShow==0)
	{
		if(KeyNum==2)
		{
			MenuMode--;if(MenuMode<0){MenuMode=7;}
		}
		if(KeyNum==3)
		{
			MenuMode++;MenuMode%=8;
		}
		switch(MenuMode)
		{
		case 0:OLED_ShowString(2,1,"1.Welcome You   ");OLED_ShowString(1,1,"Menu1:          ");OLED_ShowString(3,1,"                ");OLED_ShowString(4,1,"                ");if(KeyNum==4){MenuSelect=0;};break;
		case 1:OLED_ShowString(2,1,"2.Temp Show     ");OLED_ShowString(1,1,"Menu2:          ");OLED_ShowString(3,1,"                ");OLED_ShowString(4,1,"                ");if(KeyNum==4){MenuSelect=0;};break;
		case 2:OLED_ShowString(2,1,"3.Temp and Humi ");OLED_ShowString(1,1,"Menu3:          ");OLED_ShowString(3,1,"                ");OLED_ShowString(4,1,"                ");if(KeyNum==4){MenuSelect=0;};break;
		case 3:OLED_ShowString(2,1,"4.People        ");OLED_ShowString(1,1,"Menu4:          ");OLED_ShowString(3,1,"                ");OLED_ShowString(4,1,"                ");if(KeyNum==4){MenuSelect=0;};break;
		case 4:OLED_ShowString(2,1,"5.FAN ON/OFF    ");OLED_ShowString(1,1,"Menu5:          ");OLED_ShowString(3,1,"                ");OLED_ShowString(4,1,"                ");if(KeyNum==4){MenuSelect=0;};break;
		case 5:OLED_ShowString(2,1,"6.LED ON/OFF    ");OLED_ShowString(1,1,"Menu6:          ");OLED_ShowString(3,1,"                ");OLED_ShowString(4,1,"                ");if(KeyNum==4){MenuSelect=0;};break;
		case 6:OLED_ShowString(2,1,"7.RFID          ");OLED_ShowString(1,1,"Menu7:          ");OLED_ShowString(3,1,"                ");OLED_ShowString(4,1,"                ");if(KeyNum==4){MenuSelect=0;};break;	
		case 7:OLED_ShowString(2,1,"8.WiFi          ");OLED_ShowString(1,1,"Menu8:          ");OLED_ShowString(3,1,"                ");OLED_ShowString(4,1,"                ");if(KeyNum==4){MenuSelect=0;};break;	
		}
	}
	if(MODE)
	{	
		switch(MODE)
		{
		case 1:Show();if(KeyNum==4){MODE=9;} break;
		case 2:TempShow();if(KeyNum==4){MODE=9;} break;
		case 3:TempAndHumi();if(KeyNum==4){MODE=9;} break;
		case 4:People();if(KeyNum==4){MODE=9;} break;
		case 5:if(KeyNum==4){MODE=9;} break;
		case 6:if(KeyNum==4){MODE=9;} break;
		case 7:RFID();if(KeyNum==4){MODE=9;} break;
		case 8:WiFi();if(KeyNum==4){MODE=9;} break;
		case 9:MODE=0;MenuShow=0;goto end;break;
		}
	}
	if(KeyNum)
	{
	if(KeyNum==1 && MenuMode==0){MODE=1;MenuShow=1;}
	if(KeyNum==1 && MenuMode==1){MODE=2;MenuShow=1;}
	if(KeyNum==1 && MenuMode==2){MODE=3;MenuShow=1;}
	if(KeyNum==1 && MenuMode==3){MODE=4;MenuShow=1;}
	if(KeyNum==1 && MenuMode==4){MODE=5;MenuShow=1;}
	if(KeyNum==1 && MenuMode==5){MODE=6;MenuShow=1;}
	if(KeyNum==1 && MenuMode==6){MODE=7;MenuShow=1;}
	if(KeyNum==1 && MenuMode==7){MODE=8;MenuShow=1;}
	}
}

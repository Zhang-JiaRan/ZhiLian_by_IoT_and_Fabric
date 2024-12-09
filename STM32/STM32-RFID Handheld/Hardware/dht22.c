#include "stm32f10x.h"                  // Device header
#include "dht22.h"
#include "Delay.h"
#include "sys.h" 

//复位DHT22
void DHT22_Rst(void)	   
{      	
    DHT22_DQ_OUT=0; 	//拉低DQ
    Delay_ms(20);    	//拉低至少18ms
    DHT22_DQ_OUT=1; 	//DQ=1 
	Delay_us(30);     	//主机拉高20~40us
}
//等待DHT22的回应
//返回1:未检测到DHT22的存在
//返回0:存在
u8 DHT22_Check(void) 	   
{   
	u8 retry=100;
   	while ((!DHT22_DQ_IN)&&retry)//DHT22会拉低40~80us
	{
		retry--;
		Delay_us(1);
	};	 
	if(retry<1) return 1;
	else retry=100;
    while (DHT22_DQ_IN&&retry)//DHT22拉低后会再次拉高40~80us
	{
		retry--;
		Delay_us(1);
	};
	if(retry<1) 
		return 1;	    
	return 0;
}

//从DHT22读取一个位
//返回值：1/0
u8 DHT22_Read_Bit(void) 			 
{
 	u8 dat;
 	u8 retry=100;
	while((!DHT22_DQ_IN)&&retry)//等待变为高电平
	{
		retry--;
		Delay_us(1);
	}
	retry=100;
	dat=0;
	Delay_us(30);//等待30us
	if(DHT22_DQ_IN)	
		dat=1;	   
	while(DHT22_DQ_IN&&retry)//等待变低电平
	{
		retry--;
		Delay_us(1);
	}
	return dat;		
}

//从DHT22读取一个字节
//返回值：读到的数据
u8 DHT22_Read_Byte(void)    
{        
    u8 i,dat;
    dat=0;
	for (i=0;i<8;i++) 
	{
   		dat<<=1; 
	    dat|=DHT22_Read_Bit();
    }						    
    return dat;
}
/*

//一次数据
//temp:温度
//hum:湿度
//1成功   0失败
u8 DHT22_Read_Data(u8 *hum1,u8 *hum2,u8 *temp1,u8 *temp2)    
{        
 	u8 buf[5];
	u8 i;
	
	DHT22_Rst();
	if(DHT22_Check()==0)
	{
		for(i=0;i<5;i++)//全部读取  40个
		{
			buf[i]=DHT22_Read_Byte();
		}	
		//数据校核
		if((unsigned char)(buf[0]+buf[1]+buf[2]+buf[3])==buf[4]) //防止超出范围的强制转换
		{
			*hum1=buf[0];
			*hum2=buf[1];
			*temp1=buf[2];
			*temp2=buf[3];		
			return 1;	
		}
	}
	return 0;   
}
*/
//从DHT22读取一次数据
//temp:温度值(范围:0~50°)
//humi:湿度值(范围:20%~90%)
//返回值：0,正常;1,读取失败

u8 DHT22_Read_Data(u8 *temp,u8 *humi)    
{        
 	u8 buf[5];
	u8 i;
	u8 sum;
	//*humi=0;
	//*temp=0;
	DHT22_Rst();
	if(DHT22_Check()==0)
	{
		for(i=0;i<5;i++)
		{
			buf[i]=DHT22_Read_Byte();
		}
		sum = buf[0]+buf[1]+buf[2]+buf[3];
		if(sum == buf[4])
		{
			*humi=(float)((buf[0]<<8)+buf[1])/10;
			*temp=(float)((buf[2]<<8)+buf[3])/10;
		}
		else
		{
			*humi=(float)((buf[0]<<8)+buf[1])/10;
			*temp=(float)((buf[2]<<8)+buf[3])/10;
		}
	}
	else 
	{
		return 1;
	}
	return 0;	    
}
//初始化DHT22的IO口 DQ 同时检测DHT22的存在
//返回1:不存在
//返回0:存在    	 
u8 DHT22_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	
	
 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;				
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD; 		 
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);		
	
	DHT22_Rst();
	return DHT22_Check();
}


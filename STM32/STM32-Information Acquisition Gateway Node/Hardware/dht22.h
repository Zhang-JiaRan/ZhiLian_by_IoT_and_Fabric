#ifndef __DHT22_H
#define __DHT22_H
#include "sys.h" 

#define	DHT22_DQ_OUT PAout(11)  
#define	DHT22_DQ_IN  PAin(11)  

u8 DHT22_Init(void);			
u8 DHT22_Read_Data(u8 *temp,u8 *humi);	
u8 DHT22_Read_Byte(void);		
u8 DHT22_Read_Bit(void);		
u8 DHT22_Check(void);			
void DHT22_Rst(void);	

#endif


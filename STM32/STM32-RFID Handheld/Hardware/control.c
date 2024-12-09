/*-------------------------------------------------*/
/*                                                 */
/*                 控制端口           		   	   */
/*                                                 */
/*-------------------------------------------------*/

//LED控制数据发送给服务器

#include "stm32f10x.h"
#include "control.h"
#include "usart1.h"
#include "mqtt.h"

extern char *ledFlag;               //补光灯状态                   

/*-------------------------------------------------*/
/*函数名：数据长度 length 函数                      */
/*参  数：无                                       */
/*返回值：长度                 				       */
/*-------------------------------------------------*/
int length(int a)
{
	int i = 1;
	while(a/10 != 0)
	{
		i++;
		a = a/10;
	}
	return i;
}

/*-------------------------------------------------*/
/*函数名：发送控制设备数据                          */
/*参  数：无                                       */
/*返回值：							               */
/*-------------------------------------------------*/
void Send_Data(void)
{		
	char  head1[3];
	char  temp[50];          	//定义一个临时缓冲区1,不包括报头
	char  tempAll[100];       	//定义一个临时缓冲区2，包括所有数据

	int   dataLen;     	  	    //报文长度	
	
	memset(temp,       0, 50);  //清空缓冲区1
	memset(tempAll,    0, 100); //清空缓冲区2
	memset(head1,      0, 3);   //清空MQTT头                           						 

	sprintf(temp, "{\"ledFlag\":\"%s\"}", ledFlag);//构建报文
	
	head1[0] = 0x03; //固定报头
	head1[1] = 0x00; //固定报头
	head1[2] = strlen(temp); //剩余长度	
	sprintf(tempAll, "%c%c%c%s", head1[0], head1[1], head1[2], temp);

	dataLen = strlen(temp) + 3;
	u1_printf("%s\r\n", tempAll+3);
	//u1_printf("总长度：%d\r\n",Init_len);
	MQTT_PublishQs0(Data_TOPIC_NAME, tempAll, dataLen); //添加数据，发布给服务器		
}




#ifndef __WIFI_H
#define __WIFI_H

#include "usart2.h"	   	

#define RESET_IO(x)    GPIO_WriteBit(GPIOB, GPIO_Pin_12, (BitAction)x)  //PA4控制WiFi的复位

#define WiFi_printf       u3_printf           //串口2控制 WiFi
#define WiFi_RxCounter    Usart3_RxCounter    //串口2控制 WiFi
#define WiFi_RX_BUF       Usart3_RxBuff       //串口2控制 WiFi
#define WiFi_RXBUFF_SIZE  USART3_RXBUFF_SIZE  //串口2控制 WiFi

#define SSID   "MyIotWiFi"                          //路由器SSID名称
#define PASS   "13181245016"                    //路由器密码

extern int ServerPort;
extern char ServerIP[128];                    //存放服务器IP或是域名

void WiFi_ResetIO_Init(void);
char WiFi_SendCmd(char *cmd, int timeout);
char WiFi_Reset(int timeout);
char WiFi_JoinAP(int timeout);
char WiFi_Connect_Server(int timeout);
char WiFi_Smartconfig(int timeout);
char WiFi_WaitAP(int timeout);
char WiFi_Connect_IoTServer(void);


#endif



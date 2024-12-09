
#ifndef __USART1_H
#define __USART1_H

#include "stdio.h"     
#include "stdarg.h"			
#include "string.h" 


#define USART1_TXBUFF_SIZE   256   		//定义串口1发送缓冲区大小为256字节

void Usart1_Init(unsigned int);     	//串口1 初始化函数
void u1_printf(char*, ...) ;         	//串口1 printf函数

#endif



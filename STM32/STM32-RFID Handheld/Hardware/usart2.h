
#ifndef __USART2_H
#define __USART2_H

#include "stdio.h"      
#include "stdarg.h"		 
#include "string.h"    

#define USART3_TXBUFF_SIZE   1024   		   //���崮��2 ���ͻ�������С 1024�ֽ�
#define USART3_RXBUFF_SIZE   1024              //���崮��2 ���ջ�������С 1024�ֽ�

extern char Usart3_RxCompleted ;               //�ⲿ�����������ļ����Ե��øñ���
extern unsigned int Usart3_RxCounter;          //�ⲿ�����������ļ����Ե��øñ���
extern char Usart3_RxBuff[USART3_RXBUFF_SIZE]; //�ⲿ�����������ļ����Ե��øñ���

void Usart3_Init(unsigned int);       
void u3_printf(char*,...) ;          
void u3_TxData(unsigned char *data);

#endif



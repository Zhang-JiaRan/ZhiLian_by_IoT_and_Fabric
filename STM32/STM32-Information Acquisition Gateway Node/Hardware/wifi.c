
/*-------------------------------------------------*/
/*                                                 */
/*          	 WIFI��ESP8266��Դ�ļ�             */
/*                                                 */
/*-------------------------------------------------*/

#include "stm32f10x.h"  //������Ҫ��ͷ�ļ�
#include "wifi.h"	    //������Ҫ��ͷ�ļ�
#include "Delay.h"	    //������Ҫ��ͷ�ļ�
#include "usart1.h"	    //������Ҫ��ͷ�ļ�

char wifi_mode = 0;     //����ģʽ 0��SSID������д�ڳ�����   1��Smartconfig��ʽ��APP����
	
/*-------------------------------------------------*/
/*����������ʼ��WiFi�ĸ�λIO                       */
/*��  ������                                       */
/*����ֵ����                                       */
/*-------------------------------------------------*/
void WiFi_ResetIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;                    //����һ������IO�˿ڲ����Ľṹ��
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB , ENABLE); //ʹ��PA�˿�ʱ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;               //׼������PA4
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;       //����50Mhz
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   	    //���������ʽ
	GPIO_Init(GPIOB, &GPIO_InitStructure);            	    //����PA4
	RESET_IO(1);                                            //��λIO���ߵ�ƽ
}
/*-------------------------------------------------*/
/*��������WiFi��������ָ��                          */
/*��  ����cmd��ָ��                                */
/*��  ����timeout����ʱʱ�䣨100ms�ı�����          */
/*����ֵ��0����ȷ   ����������                      */
/*-------------------------------------------------*/
char WiFi_SendCmd(char *cmd, int timeout)
{
	WiFi_RxCounter = 0;                           			//WiFi������������������                        
	memset(WiFi_RX_BUF, 0, WiFi_RXBUFF_SIZE);     			//���WiFi���ջ����� 
	WiFi_printf("%s\r\n", cmd);                  			//����ָ��
	while(timeout--)										//�ȴ���ʱʱ�䵽0
	{                           			
		Delay_ms(100);                             		    //��ʱ100ms
		if(strstr(WiFi_RX_BUF, "OK"))              			//������յ�OK��ʾָ��ɹ�
			break;       									//��������whileѭ��
		u1_printf("%d ", timeout);                 			//����������ڵĳ�ʱʱ��
	}			
	u1_printf("\r\n");                          			//���������Ϣ
	if(timeout <= 0)return 1;                    				//���timeout<=0��˵����ʱʱ�䵽�ˣ�Ҳû���յ�OK������1
	else return 0;		         							//��֮����ʾ��ȷ��˵���յ�OK��ͨ��break��������while
}
/*-------------------------------------------------*/
/*��������WiFi��λ                                 */
/*��  ����timeout����ʱʱ�䣨100ms�ı�����          */
/*����ֵ��0����ȷ   ����������                      */
/*-------------------------------------------------*/
char WiFi_Reset(int timeout)
{
	RESET_IO(0);                                    	  //��λIO���͵�ƽ
	Delay_ms(500);                                  		  //��ʱ500ms
	RESET_IO(1);                                   		  //��λIO���ߵ�ƽ	
	while(timeout--)									  //�ȴ���ʱʱ�䵽0 
	{                              		  
		Delay_ms(100);                                 	  //��ʱ100ms
		if(strstr(WiFi_RX_BUF, "ready"))               	  //������յ�ready��ʾ��λ�ɹ�
			break;       						   		  //��������whileѭ��
		u1_printf("%d ", timeout);                     	  //����������ڵĳ�ʱʱ��
	}
	u1_printf("\r\n");                              	  //���������Ϣ
	if(timeout <= 0)return 1;                        		  //���timeout<=0��˵����ʱʱ�䵽�ˣ�Ҳû���յ�ready������1
	else return 0;		         				   		  //��֮����ʾ��ȷ��˵���յ�ready��ͨ��break��������while
}
/*-------------------------------------------------*/
/*��������WiFi����·����ָ��                       */
/*��  ����timeout����ʱʱ�䣨1s�ı�����            */
/*����ֵ��0����ȷ   ����������                     */
/*-------------------------------------------------*/
char WiFi_JoinAP(int timeout)
{		
	WiFi_RxCounter = 0;                                    //WiFi������������������                        
	memset(WiFi_RX_BUF, 0, WiFi_RXBUFF_SIZE);              //���WiFi���ջ����� 
	WiFi_printf("AT+CWJAP=\"%s\",\"%s\"\r\n", SSID, PASS); //����ָ��	
	while(timeout--)									   //�ȴ���ʱʱ�䵽0
	{                                   
		Delay_ms(1000);                             		   //��ʱ1s
		if(strstr(WiFi_RX_BUF, "OK"))   //������յ�WIFI GOT IP��ʾ�ɹ�
			break;       						           //��������whileѭ��
		u1_printf("%d ", timeout);                         //����������ڵĳ�ʱʱ��
	}
	u1_printf("\r\n%s\r\n", WiFi_RX_BUF);
	u1_printf("\r\n");                             	       //���������Ϣ
	if(timeout <= 0)return 1;                              //���timeout<=0��˵����ʱʱ�䵽�ˣ�Ҳû���յ�WIFI GOT IP������1
	return 0;                                              //��ȷ������0
}
/*-------------------------------------------------*/
/*������������TCP��������������͸��ģʽ            */
/*��  ����timeout�� ��ʱʱ�䣨100ms�ı�����        */
/*����ֵ��0����ȷ  ����������                      */
/*-------------------------------------------------*/
char WiFi_Connect_Server(int timeout)
{	
	WiFi_RxCounter=0;                              	//WiFi������������������                        
	memset(WiFi_RX_BUF,0,WiFi_RXBUFF_SIZE);         //���WiFi���ջ�����   
	WiFi_printf("AT+CIPSTART=\"TCP\",\"%s\",%d\r\n", ServerIP, ServerPort);//�������ӷ�����ָ��
	while(timeout--)								//�ȴ���ʱ���
	{                           
		Delay_ms(100);                             	//��ʱ100ms	
		if(strstr(WiFi_RX_BUF, "CONNECT"))          //������ܵ�CONNECT��ʾ���ӳɹ�
			break;                                  //����whileѭ��
		if(strstr(WiFi_RX_BUF, "CLOSED"))           //������ܵ�CLOSED��ʾ������δ����
			return 1;                               //������δ��������1
		if(strstr(WiFi_RX_BUF, "ALREADY CONNECTED"))//������ܵ�ALREADY CONNECTED�Ѿ���������
			return 2;                               //�Ѿ��������ӷ���2
		u1_printf("%d ", timeout);                   //����������ڵĳ�ʱʱ��  
	}
	u1_printf("\r\n");                              //���������Ϣ
	if(timeout <= 0)return 3;                       //��ʱ���󣬷���3
	else                                            //���ӳɹ���׼������͸��
	{
		u1_printf("Successfully connected to the server, ready for transparent transmission\r\n"); //������ʾ��Ϣ
		//u1_printf("���ӷ������ɹ���׼������͸��\r\n"); //������ʾ��Ϣ
		WiFi_RxCounter = 0;                          //WiFi������������������                        
		memset(WiFi_RX_BUF, 0, WiFi_RXBUFF_SIZE);    //���WiFi���ջ�����     
		WiFi_printf("AT+CIPSEND\r\n");               //���ͽ���͸��ָ��
		while(timeout--)							 //�ȴ���ʱ���
		{                            
			Delay_ms(100);                            //��ʱ100ms	
			if(strstr(WiFi_RX_BUF, "\r\nOK\r\n\r\n>"))//���������ʾ����͸���ɹ�
				break;                          	 //����whileѭ��
			u1_printf("%d ", timeout);                //����������ڵĳ�ʱʱ��  
		}
		if(timeout <= 0)return 4;                      //͸����ʱ���󣬷���4	
	}
	return 0;	                                     //�ɹ�����0	
}
/*-------------------------------------------------*/
/*��������WiFi_Smartconfig                         */
/*��  ����timeout����ʱʱ�䣨1s�ı�����            */
/*����ֵ��0����ȷ   ����������                     */
/*-------------------------------------------------*/
char WiFi_Smartconfig(int timeout)
{
	
	WiFi_RxCounter=0;                           		//WiFi������������������                        
	memset(WiFi_RX_BUF,0,WiFi_RXBUFF_SIZE);     		//���WiFi���ջ�����     
	while(timeout--)									//�ȴ���ʱʱ�䵽0
	{                           		
		Delay_ms(1000);                         				//��ʱ1s
		if(strstr(WiFi_RX_BUF, "connected"))    	 		  //������ڽ��ܵ�connected��ʾ�ɹ�
			break;                                  		//����whileѭ��  
		u1_printf("%d ", timeout);                 		//����������ڵĳ�ʱʱ��  
	}	
	u1_printf("\r\n");                          		//���������Ϣ
	if(timeout <= 0)return 1;                     		//��ʱ���󣬷���1
	return 0;                                   		//��ȷ����0
}
/*-------------------------------------------------*/
/*���������ȴ�����·����                           */
/*��  ����timeout����ʱʱ�䣨1s�ı�����            */
/*����ֵ��0����ȷ   ����������                     */
/*-------------------------------------------------*/
char WiFi_WaitAP(int timeout)
{		
	while(timeout--){                               //�ȴ���ʱʱ�䵽0
		Delay_ms(1000);                             		//��ʱ1s
		if(strstr(WiFi_RX_BUF, "WIFI GOT IP"))         //������յ�WIFI GOT IP��ʾ�ɹ�
			break;       						   								  //��������whileѭ��
		u1_printf("%d ", timeout);                     //����������ڵĳ�ʱʱ��
	}
	u1_printf("\r\n");                              //���������Ϣ
	if(timeout <= 0)return 1;                         //���timeout<=0��˵����ʱʱ�䵽�ˣ�Ҳû���յ�WIFI GOT IP������1
	return 0;                                       //��ȷ������0
}
/*-------------------------------------------------*/
/*��������WiFi���ӷ�����                           */
/*��  ������                                       */
/*����ֵ��0����ȷ   ����������                     */
/*-------------------------------------------------*/
char WiFi_Connect_IoTServer(void)
{	
	u1_printf("Preparing to reset the module\r\n");                   //������ʾ����
	//u1_printf("׼����λģ��\r\n");                   //������ʾ����
	if(WiFi_Reset(50))								//��λ��100ms��ʱ��λ���ܼ�5s��ʱʱ��
	{                             
		u1_printf("Reset failed, ready to restart\r\n");	      //���ط�0ֵ������if��������ʾ����
		//u1_printf("��λʧ�ܣ�׼������\r\n");	      //���ط�0ֵ������if��������ʾ����
		return 1;                                   //����1
	}else u1_printf("Reset successful\r\n");                 //������ʾ����
	//u1_printf("��λ�ɹ�\r\n");                 //������ʾ����
	u1_printf("Prepare to set STA mode\r\n");                //������ʾ����
	//u1_printf("׼������STAģʽ\r\n");                //������ʾ����
	if(WiFi_SendCmd("AT+CWMODE=1",50))//����STAģʽ��100ms��ʱ��λ���ܼ�5s��ʱʱ��
	{    
			u1_printf("Failed to set STA mode, ready to restart\r\n");   //���ط�0ֵ������if��������ʾ����
		//u1_printf("����STAģʽʧ�ܣ�׼������\r\n");   //���ط�0ֵ������if��������ʾ����
		return 2;                                   //����2
	}else u1_printf("Successfully set sta mode\r\n");          //������ʾ����
	//u1_printf("����STAģʽ�ɹ�\r\n");          //������ʾ����
	
	if(wifi_mode==0) //�������ģʽ=0��SSID������д�ڳ����� 
	{     
			u1_printf("Ready to cancel automatic connection\r\n");            //������ʾ����
		//u1_printf("׼��ȡ���Զ�����\r\n");            //������ʾ����
		if(WiFi_SendCmd("AT+CWAUTOCONN=0",50))		 //ȡ���Զ����ӣ�100ms��ʱ��λ���ܼ�5s��ʱʱ��
		{       
			u1_printf("Failed to cancel automatic connection, ready to restart\r\n"); //���ط�0ֵ������if��������ʾ����
			//u1_printf("ȡ���Զ�����ʧ�ܣ�׼������\r\n"); //���ط�0ֵ������if��������ʾ����
			return 3;                                  //����3
		}else u1_printf("Automatic connection cancelled successfully\r\n");        //������ʾ����
		//u1_printf("ȡ���Զ����ӳɹ�\r\n");        //������ʾ����
			u1_printf("Preparing to connect to the router\r\n");                //������ʾ����	
		//u1_printf("׼������·����\r\n");                //������ʾ����	
		if(WiFi_JoinAP(30))//����·����,1s��ʱ��λ���ܼ�30s��ʱʱ��
		{     
				u1_printf("Failed to connect to the router, ready to restart\r\n");  //���ط�0ֵ������if��������ʾ����
			//u1_printf("����·����ʧ�ܣ�׼������\r\n");  //���ط�0ֵ������if��������ʾ����
			return 4;                                 //����4	
		}else u1_printf("Successfully connected to the router\r\n");         //������ʾ����			
		//u1_printf("����·�����ɹ�\r\n");         //������ʾ����			
	}
	u1_printf("Prepare to set transparent transmission\r\n");                    //������ʾ����
	//u1_printf("׼������͸��\r\n");                    //������ʾ����
	if(WiFi_SendCmd("AT+CIPMODE=1",50)) 			 //����͸����100ms��ʱ��λ���ܼ�5s��ʱʱ��
	{   
			u1_printf("Failed to set transparent transmission, ready to restart\r\n");       //���ط�0ֵ������if��������ʾ����
		//u1_printf("����͸��ʧ�ܣ�׼������\r\n");       //���ط�0ֵ������if��������ʾ����
		return 8;                                    //����8
	}else u1_printf("Setting transparent transmission succeeded\r\n");              //������ʾ����
	//u1_printf("����͸���ɹ�\r\n");              //������ʾ����
	u1_printf("Preparing to close multiple connections\r\n");                //������ʾ����
	//u1_printf("׼���رն�·����\r\n");                //������ʾ����
	if(WiFi_SendCmd("AT+CIPMUX=0",50)) 				 //�رն�·���ӣ�100ms��ʱ��λ���ܼ�5s��ʱʱ��
	{            
		u1_printf("Failed to close multiple connections, ready to restart\r\n");   //���ط�0ֵ������if��������ʾ����
		//u1_printf("�رն�·����ʧ�ܣ�׼������\r\n");   //���ط�0ֵ������if��������ʾ����
		return 9;                                    //����9
	}else u1_printf("Multiple connections closed successfully\r\n");          //������ʾ����
	//u1_printf("�رն�·���ӳɹ�\r\n");          //������ʾ����
	 u1_printf("Preparing to connect to the server\r\n");                  //������ʾ����
	//u1_printf("׼�����ӷ�����\r\n");                  //������ʾ����
	if(WiFi_Connect_Server(100))      				 //���ӷ�������100ms��ʱ��λ���ܼ�10s��ʱʱ��
	{            
		u1_printf("Failed to connect to the server, ready to restart\r\n");     //���ط�0ֵ������if��������ʾ����
		//u1_printf("���ӷ�����ʧ�ܣ�׼������\r\n");     //���ط�0ֵ������if��������ʾ����
		return 10;                                   //����10
	}else u1_printf("Successfully connected to the server\r\n");            //������ʾ����	
	//u1_printf("���ӷ������ɹ�\r\n");            //������ʾ����	
	return 0;                                        //��ȷ����0
}
	

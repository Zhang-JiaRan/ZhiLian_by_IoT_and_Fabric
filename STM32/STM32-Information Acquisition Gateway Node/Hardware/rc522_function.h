#ifndef __RC522_FUNCTION_H
#define	__RC522_FUNCTION_H


#include "stm32f10x_it.h"


#define          macDummy_Data              0x00

void  IC_test(void);
void PWM_Init(void);

void             PcdReset                   ( void );                       //复位
void             M500PcdConfigISOType       ( u8 type );                    //工作方式
char             PcdRequest                 ( u8 req_code, u8 * pTagType ); //寻卡
char             PcdAnticoll                ( u8 * pSnr);                   //读卡号
char             PcdHalt                      ( void );
char             PcdSelect                    ( uint8_t * pSnr );
char             PcdAuthState                 ( uint8_t ucAuth_mode, uint8_t ucAddr, uint8_t * pKey, uint8_t * pSnr );
char             WriteAmount                  ( uint8_t ucAddr, uint32_t pData );
char             ReadAmount                   ( uint8_t ucAddr, uint32_t *pData );
#endif /* __RC522_FUNCTION_H */


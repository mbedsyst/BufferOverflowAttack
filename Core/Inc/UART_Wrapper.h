#ifndef INC_UART_WRAPPER_H_
#define INC_UART_WRAPPER_H_

#include "stm32f4xx_hal.h"  // Change according to your STM32 family

void UART_SendString(const char *str);
void UART_ReceiveString(char *buffer, uint16_t maxLen);

#endif /* INC_UART_WRAPPER_H_ */

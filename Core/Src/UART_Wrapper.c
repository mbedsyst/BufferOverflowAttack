#include "UART_Wrapper.h"

extern UART_HandleTypeDef huart2;  // Using USART2 for example

static void UART_SendChar(char c)
{
    HAL_UART_Transmit(&huart2, (uint8_t *)&c, 1, HAL_MAX_DELAY);
}

void UART_SendString(const char *str)
{
    while (*str) {
        UART_SendChar(*str++);
    }
}

static char UART_ReceiveChar(void)
{
    char c;
    HAL_UART_Receive(&huart2, (uint8_t *)&c, 1, HAL_MAX_DELAY);
    return c;
}

void UART_ReceiveString(char *buffer, uint16_t maxLen)
{
    uint16_t i = 0;
    char c;
    while (i < maxLen - 1)
    {
        c = UART_ReceiveChar();
        if (c == '\n' || c == '\r') break;
        buffer[i++] = c;
    }
    buffer[i] = '\0';
}

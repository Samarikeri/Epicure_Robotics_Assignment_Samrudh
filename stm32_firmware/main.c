#include "main.h"
#include <string.h>
#include <stdio.h>

char rxBuf[64];
int rxIndex = 0;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART2)
    {
        if (rxBuf[rxIndex] == '\n') {
            rxBuf[rxIndex] = '\0';
            processCommand(rxBuf);
            rxIndex = 0;
        } else {
            rxIndex++;
        }

        HAL_UART_Receive_IT(&huart2, (uint8_t*)&rxBuf[rxIndex], 1);
    }
}

void processCommand(char *cmd)
{
    if (strncmp(cmd, "led:on", 6) == 0) {
        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
    }

    else if (strncmp(cmd, "led:off", 7) == 0) {
        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
    }

    else if (strncmp(cmd, "motor:", 6) == 0) {
        int steps, dir;
        sscanf(cmd, "motor:%d:%d", &steps, &dir);
        
            if(dir == 1)
                HAL_GPIO_WritePin(DIR_GPIO_Port, DIR_Pin, GPIO_PIN_SET);
            else
                HAL_GPIO_WritePin(DIR_GPIO_Port, DIR_Pin, GPIO_PIN_RESET);

        for(int i=0; i<steps; i++) {
            HAL_GPIO_WritePin(STEP_GPIO_Port, STEP_Pin, GPIO_PIN_SET);
            HAL_Delay(2);
            HAL_GPIO_WritePin(STEP_GPIO_Port, STEP_Pin, GPIO_PIN_RESET);
            HAL_Delay(2);
        }
    }
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART2_UART_Init();

    HAL_UART_Receive_IT(&huart2, (uint8_t*)&rxBuf[0], 1);

    while (1)
    {
    }
}

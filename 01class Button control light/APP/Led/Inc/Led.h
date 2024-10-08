#ifndef __LED_H__
#define __LED_H__
#include "gpio.h"


#define LED_BLUE_ON  HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, GPIO_PIN_RESET)
#define LED_BLUE_OFF HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, GPIO_PIN_SET)


#endif
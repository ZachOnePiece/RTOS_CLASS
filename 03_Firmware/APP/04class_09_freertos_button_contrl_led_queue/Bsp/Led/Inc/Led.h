/*
 * Copyright (c) 2024 by One_Piece, All Rights Reserved. 
 * @Author: One_Piece
 * @Date: 2024-10-23 23:25:14
 * @LastEditors: One_Piece
 * @LastEditTime: 2024-11-17 10:32:00
 * @FilePath: \APP\04class_09_freertos_button_contrl_led\Bsp\Led\Inc\Led.h
 * @Version: 1.0 2024
 * @Description: 
 * 
 */


#ifndef __LED_H__
#define __LED_H__
#include "gpio.h"
#include "FreeRTOS.h"
#include "cmsis_os.h"
#define LED_BLUE_ON  HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, GPIO_PIN_RESET)
#define LED_BLUE_OFF HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, GPIO_PIN_SET)
#define LED_LIGHT_ON_TIME_1S 10

extern void led_func(void *argument);
extern osMessageQueueId_t key_signal_queueHandle;

#endif
/*
 * Copyright (c) 2024 by One_Piece, All Rights Reserved. 
 * @Author: One_Piece
 * @Date: 2024-10-23 23:25:14
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-11-18 00:38:26
 * @FilePath: \RTOS_CLASS\03_Firmware\APP\05class_10_freertos_short_long_button\Bsp\Led\Src\Led.c
 * @Version: 1.0 2024
 * @Description: 
 * 
 */


#include "Led.h"
#include "Key.h"
#define LED_LIGHT_ON_TIME_1S 10

/**
 * @description: 
 * @param {void} *argument
 * @return {*}
 */
void led_func(void *argument)
{
    uint8_t get_key_value = 0u;
    int tick = 0u;
    for(;;)
    {
        if(osOK == osMessageQueueGet(key_signal_queueHandle,&get_key_value,NULL,KEY_QUEUE_NOT_WAITING))
        {
            printf("led task get key value:%d\r\n",get_key_value);
            if(KEY_PRESSED == get_key_value)
            {
                LED_BLUE_Toggle;
            }
            else
            {
                LED_BLUE_Toggle;
                osDelay(500);
                LED_BLUE_Toggle;
                osDelay(500);
                LED_BLUE_Toggle;
                osDelay(500);
            }
        }
        else
        {
            /*no code*/
        }
        osDelay(100);
    }
    
}
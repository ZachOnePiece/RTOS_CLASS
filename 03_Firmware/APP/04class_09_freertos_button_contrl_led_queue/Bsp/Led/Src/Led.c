/*
 * Copyright (c) 2024 by One_Piece, All Rights Reserved. 
 * @Author: One_Piece
 * @Date: 2024-10-23 23:25:14
 * @LastEditors: One_Piece
 * @LastEditTime: 2024-11-17 12:18:58
 * @FilePath: \04class_09_freertos_button_contrl_led\Bsp\Led\Src\Led.c
 * @Version: 1.0 2024
 * @Description: 
 * 
 */


#include "Led.h"
#include "Key.h"
#define LED_LIGHT_ON_TIME_1S 10


void led_func(void *argument)
{
    uint16_t get_key_value = 0u;
    int tick = 0u;
    for(;;)
    {
        if(osOK == osMessageQueueGet(key_signal_queueHandle,&get_key_value,NULL,KEY_QUEUE_NOT_WAITING))
        {
            printf("led task get key value:%d\r\n",get_key_value);
            if(KEY_PRESSED == get_key_value)
            {
                
                tick = LED_LIGHT_ON_TIME_1S;//1s
            }
            else
            {
                tick = 0;
            }
        }
        else
        {
            /*no code*/
        }

        if(0 < tick)
        {
            LED_BLUE_ON;
        }
        else
        {
            LED_BLUE_OFF;
        }
        tick = tick-- > 0 ? tick : 0;
        osDelay(100);
    }
    
}
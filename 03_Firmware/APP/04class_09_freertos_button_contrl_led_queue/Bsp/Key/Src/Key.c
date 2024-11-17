/*
 * Copyright (c) 2024 by One_Piece, All Rights Reserved. 
 * @Author: One_Piece
 * @Date: 2024-10-23 23:25:14
 * @LastEditors: One_Piece
 * @LastEditTime: 2024-11-17 11:53:52
 * @FilePath: \04class_09_freertos_button_contrl_led\Bsp\Key\Src\Key.c
 * @Version: 1.0 2024
 * @Description: 
 * 
 */
#include "Key.h"

/**
 * @brief Instantiates the bsp_led_handler_t target.
 * 
 * Steps:
 *  1.doing the specific operations
 *  
 * @param[in] void 
 * 
 * @return led_handler_status_t : Status of the function.
 * 
 * */
key_status_t key_scan(key_press_status_t * key_value)
{
    
    uint32_t counter = 0;
    key_press_status_t key_status_value = KEY_NOT_PRESSED;
    
    while (counter < 1000){
        //2.如果按键（PA0)的电平为低，则说明按键被按下了。
        //2.1  如果按键被按下，则发送对应的消息队列
        if(KEY_USER_STATUS == GPIO_PIN_RESET)
        {
            key_status_value = KEY_PRESSED;
            *key_value = key_status_value;
            return KEY_OK;
        }
        //2.2 如果按键没有被按下
        counter++;
    }
    *key_value = key_status_value;
    
    return KEY_ERRORTIMEOUT;//始终没有按键被按下，返回超时
}

/**
 * @description: 
 * @param {void} *argument
 * @return {*}
 */
void key_funciton(void *argument)
{
    uint16_t key_value = 0;
    key_status_t  ket_ret          =          KEY_OK;
    key_press_status_t key_statues = KEY_NOT_PRESSED;
    for(;;)
    {
        ket_ret = key_scan(&key_statues);
        if( KEY_OK == ket_ret)
        {
            if ( KEY_PRESSED == key_statues )
            {
                key_value = KEY_PRESSED;
                if(osOK == osMessageQueuePut(key_signal_queueHandle, &key_value, KEY_MSG_QUEUE_PRIO, KEY_QUEUE_NOT_WAITING))
                {
                    printf("key task put value:%d\r\n",key_value);    
                }
                else
                {
                    /*no code*/
                }
            }
            else
            {
                /*no code*/
            }
        }
        else
        {
            /*no code*/
        }
        osDelay(100);
    }
}
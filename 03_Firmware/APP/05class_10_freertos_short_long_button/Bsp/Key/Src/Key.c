/*
 * Copyright (c) 2024 by One_Piece, All Rights Reserved. 
 * @Author: One_Piece
 * @Date: 2024-10-23 23:25:14
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-11-18 00:29:05
 * @FilePath: \RTOS_CLASS\03_Firmware\APP\05class_10_freertos_short_long_button\Bsp\Key\Src\Key.c
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
 * @return {*}
 */
key_press_status_t key_scan_status_type(void)
{
    static key_press_status_t status = KEY_NOT_PRESSED;
    static int count = 0;
    switch (status)
    {
        case KEY_NOT_PRESSED:
            if(GPIO_PIN_RESET == KEY_USER_STATUS)
            {
                status = KEY_DELAY_PRESSED;
            }
            else
            {
                status = KEY_NOT_PRESSED;
                count = 0;
            }
            break;
        case KEY_DELAY_PRESSED://消抖
            count++;
            if(count >= 10)
            {
                if(GPIO_PIN_RESET == KEY_USER_STATUS)
                {
                    status = KEY_500MS_PRESSED;
                }
                else
                {
                    status = KEY_NOT_PRESSED;
                }
            }
            else
            {
                /*no code*/
            }

            break;
        case KEY_500MS_PRESSED://区间来判断是短按还是长按
            count++;
            if(count > 500)
            {
                count = 0;
                status = KEY_DOUBLE_PRESSED;
            }
            else
            {
                /*no code*/
            }
            if(GPIO_PIN_SET == KEY_USER_STATUS)//500ms内按下就是短按
            {
                count = 0;
                status = KEY_PRESSED;
            }
            else
            {
                /*no code*/
            }

            break;
        case KEY_PRESSED:
            if(GPIO_PIN_SET == KEY_USER_STATUS)
            {
                count = 0;
                status = KEY_NOT_PRESSED;
            }
            else
            {
                /*no code*/
            }
            break;
        case KEY_DOUBLE_PRESSED:
            if(GPIO_PIN_SET == KEY_USER_STATUS)
            {
                count = 0;
                status = KEY_NOT_PRESSED;
            }
            else
            {
                /*no code*/
            }

            break;
        default:
            break;
    }
    return status;
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
        key_statues = key_scan_status_type();
        if(KEY_DOUBLE_PRESSED == key_statues || KEY_PRESSED == key_statues)
        {
            if(osOK == osMessageQueuePut(key_signal_queueHandle, (uint8_t*)&key_statues, KEY_MSG_QUEUE_PRIO, KEY_QUEUE_NOT_WAITING))
            {
                printf("key task put value:%d\r\n",key_statues);    
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
        

        osDelay(1);
    }
}
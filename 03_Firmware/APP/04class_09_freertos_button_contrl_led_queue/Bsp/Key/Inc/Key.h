/*
 * Copyright (c) 2024 by One_Piece, All Rights Reserved. 
 * @Author: One_Piece
 * @Date: 2024-10-23 23:25:13
 * @LastEditors: One_Piece
 * @LastEditTime: 2024-11-17 11:37:01
 * @FilePath: \04class_09_freertos_button_contrl_led\Bsp\Key\Inc\Key.h
 * @Version: 1.0 2024
 * @Description: 
 * 
 */
#ifndef __KEY_H__
#define __KEY_H__

#include "gpio.h"
#include "FreeRTOS.h"
#include "cmsis_os.h"

typedef enum
{
  KEY_OK                = 0,           /* Operation completed successfully.  */
  KEY_ERROR             = 1,           /* Run-time error without case matched*/
  KEY_ERRORTIMEOUT      = 2,           /* Operation failed with timeout      */
  KEY_ERRORRESOURCE     = 3,           /* Resource not available.            */
  KEY_ERRORPARAMETER    = 4,           /* Parameter error.                   */
  KEY_ERRORNOMEMORY     = 5,           /* Out of memory.                     */
  KEY_ERRORISR          = 6,           /* Not allowed in ISR context         */
  KEY_RESERVED          = 0x7FFFFFFF   /* Reserved                           */
} key_status_t;

typedef enum
{
  KEY_PRESSED           = 0,           /* Operation completed successfully.  */
  KEY_NOT_PRESSED       = 1,           /* Run-time error without case matched*/
} key_press_status_t;

#define KEY_USER_STATUS HAL_GPIO_ReadPin(KEY_USER_GPIO_Port,KEY_USER_Pin)
#define KEY_MSG_QUEUE_PRIO 0u
#define KEY_QUEUE_NOT_WAITING 0u

/**
 * @brief: 
 * @param {void} *argument
 * @return {*}
 */
extern void key_funciton(void *argument);

extern osMessageQueueId_t key_signal_queueHandle;

#endif
/*
 * Copyright (c) 2024 by zach, All Rights Reserved. 
 * @Author: zach
 * @Date: 2024-11-17 20:53:48
 * @FilePath: \RTOS_CLASS\03_Firmware\APP\05class_10_freertos_short_long_button\Bsp\Key\Inc\Key.h
 * @Version: 1.0 
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
  KEY_DELAY_PRESSED     = 2,
  KEY_LONG_PRESSED      = 3,
  KEY_DOUBLE_PRESSED    = 4,
  KEY_500MS_PRESSED     = 5,
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
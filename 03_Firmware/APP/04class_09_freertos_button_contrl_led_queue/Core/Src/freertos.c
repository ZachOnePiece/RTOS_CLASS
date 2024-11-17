/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#include "Key.h"
#include "Led.h"
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usart.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef StaticQueue_t osStaticMessageQDef_t;
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for led_task */
osThreadId_t led_taskHandle;
const osThreadAttr_t led_task_attributes = {
  .name = "led_task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityBelowNormal,
};
/* Definitions for key_task */
osThreadId_t key_taskHandle;
const osThreadAttr_t key_task_attributes = {
  .name = "key_task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityBelowNormal1,
};
/* Definitions for key_signal_queue */
osMessageQueueId_t key_signal_queueHandle;
uint8_t key_signal_queueBuffer[ 16 * sizeof( uint16_t ) ];
osStaticMessageQDef_t key_signal_queueControlBlock;
const osMessageQueueAttr_t key_signal_queue_attributes = {
  .name = "key_signal_queue",
  .cb_mem = &key_signal_queueControlBlock,
  .cb_size = sizeof(key_signal_queueControlBlock),
  .mq_mem = &key_signal_queueBuffer,
  .mq_size = sizeof(key_signal_queueBuffer)
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void led_func(void *argument);
void key_funciton(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of key_signal_queue */
  key_signal_queueHandle = osMessageQueueNew (16, sizeof(uint16_t), &key_signal_queue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of led_task */
  led_taskHandle = osThreadNew(led_func, NULL, &led_task_attributes);

  /* creation of key_task */
  key_taskHandle = osThreadNew(key_funciton, NULL, &key_task_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    //printf("hell");
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_led_func */
/**
* @brief Function implementing the led_task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_led_func */
// void led_func(void *argument)
// {
//   /* USER CODE BEGIN led_func */
//   /* Infinite loop */
//   for(;;)
//   {
//     osDelay(1);
//   }
//   /* USER CODE END led_func */
// }

/* USER CODE BEGIN Header_key_funciton */
/**
* @brief Function implementing the key_task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_key_funciton */
// void key_funciton(void *argument)
// {
//   /* USER CODE BEGIN key_funciton */
//   /* Infinite loop */
//   for(;;)
//   {
//     osDelay(1);
//   }
//   /* USER CODE END key_funciton */
// }

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */


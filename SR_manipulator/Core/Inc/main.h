/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define AUDIO_RST_Pin GPIO_PIN_3
#define AUDIO_RST_GPIO_Port GPIOE
#define MAG_INT_Pin GPIO_PIN_1
#define MAG_INT_GPIO_Port GPIOC
#define MAG_DRDY_Pin GPIO_PIN_2
#define MAG_DRDY_GPIO_Port GPIOC
#define VLCD_Pin GPIO_PIN_3
#define VLCD_GPIO_Port GPIOC
#define PRZYCISK_srodek_Pin GPIO_PIN_0
#define PRZYCISK_srodek_GPIO_Port GPIOA
#define PRZYCISK_lewy_Pin GPIO_PIN_1
#define PRZYCISK_lewy_GPIO_Port GPIOA
#define PRZYCISK_prawy_Pin GPIO_PIN_2
#define PRZYCISK_prawy_GPIO_Port GPIOA
#define PRZYCISK_gora_Pin GPIO_PIN_3
#define PRZYCISK_gora_GPIO_Port GPIOA
#define MFX_WAKEUP_Pin GPIO_PIN_4
#define MFX_WAKEUP_GPIO_Port GPIOA
#define PRZYCISK_dol_Pin GPIO_PIN_5
#define PRZYCISK_dol_GPIO_Port GPIOA
#define SEG23_Pin GPIO_PIN_6
#define SEG23_GPIO_Port GPIOA
#define SEG0_Pin GPIO_PIN_7
#define SEG0_GPIO_Port GPIOA
#define SEG22_Pin GPIO_PIN_4
#define SEG22_GPIO_Port GPIOC
#define SEG1_Pin GPIO_PIN_5
#define SEG1_GPIO_Port GPIOC
#define SEG21_Pin GPIO_PIN_0
#define SEG21_GPIO_Port GPIOB
#define SEG2_Pin GPIO_PIN_1
#define SEG2_GPIO_Port GPIOB
#define LED_czerwony_Pin GPIO_PIN_2
#define LED_czerwony_GPIO_Port GPIOB
#define LED_zielony_Pin GPIO_PIN_8
#define LED_zielony_GPIO_Port GPIOE
#define SERVO1_PWM_Pin GPIO_PIN_9
#define SERVO1_PWM_GPIO_Port GPIOE
#define SERVO2_PWM_Pin GPIO_PIN_11
#define SERVO2_PWM_GPIO_Port GPIOE
#define SERVO3_PWM_Pin GPIO_PIN_13
#define SERVO3_PWM_GPIO_Port GPIOE
#define SERVO4_PWM_Pin GPIO_PIN_14
#define SERVO4_PWM_GPIO_Port GPIOE
#define SEG20_Pin GPIO_PIN_12
#define SEG20_GPIO_Port GPIOB
#define SEG3_Pin GPIO_PIN_13
#define SEG3_GPIO_Port GPIOB
#define SEG19_Pin GPIO_PIN_14
#define SEG19_GPIO_Port GPIOB
#define SEG4_Pin GPIO_PIN_15
#define SEG4_GPIO_Port GPIOB
#define SEG18_Pin GPIO_PIN_8
#define SEG18_GPIO_Port GPIOD
#define SEG5_Pin GPIO_PIN_9
#define SEG5_GPIO_Port GPIOD
#define SEG17_Pin GPIO_PIN_10
#define SEG17_GPIO_Port GPIOD
#define SEG6_Pin GPIO_PIN_11
#define SEG6_GPIO_Port GPIOD
#define SEG16_Pin GPIO_PIN_12
#define SEG16_GPIO_Port GPIOD
#define SEG7_Pin GPIO_PIN_13
#define SEG7_GPIO_Port GPIOD
#define SEG15_Pin GPIO_PIN_14
#define SEG15_GPIO_Port GPIOD
#define SEG8_Pin GPIO_PIN_15
#define SEG8_GPIO_Port GPIOD
#define SEG14_Pin GPIO_PIN_6
#define SEG14_GPIO_Port GPIOC
#define SEG9_Pin GPIO_PIN_7
#define SEG9_GPIO_Port GPIOC
#define SEG13_Pin GPIO_PIN_8
#define SEG13_GPIO_Port GPIOC
#define OTG_FS_PowerSwitchOn_Pin GPIO_PIN_9
#define OTG_FS_PowerSwitchOn_GPIO_Port GPIOC
#define COM0_Pin GPIO_PIN_8
#define COM0_GPIO_Port GPIOA
#define COM1_Pin GPIO_PIN_9
#define COM1_GPIO_Port GPIOA
#define COM2_Pin GPIO_PIN_10
#define COM2_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define SEG10_Pin GPIO_PIN_15
#define SEG10_GPIO_Port GPIOA
#define OTG_FS_OverCurrent_Pin GPIO_PIN_10
#define OTG_FS_OverCurrent_GPIO_Port GPIOC
#define OTG_FS_VBUS_Pin GPIO_PIN_11
#define OTG_FS_VBUS_GPIO_Port GPIOC
#define EXT_RST_Pin GPIO_PIN_0
#define EXT_RST_GPIO_Port GPIOD
#define MEMS_SCK_Pin GPIO_PIN_1
#define MEMS_SCK_GPIO_Port GPIOD
#define GYRO_INT1_Pin GPIO_PIN_2
#define GYRO_INT1_GPIO_Port GPIOD
#define MEMS_MISO_Pin GPIO_PIN_3
#define MEMS_MISO_GPIO_Port GPIOD
#define MEMS_MOSI_Pin GPIO_PIN_4
#define MEMS_MOSI_GPIO_Port GPIOD
#define USART_TX_Pin GPIO_PIN_5
#define USART_TX_GPIO_Port GPIOD
#define USART_RX_Pin GPIO_PIN_6
#define USART_RX_GPIO_Port GPIOD
#define GYRO_CS_Pin GPIO_PIN_7
#define GYRO_CS_GPIO_Port GPIOD
#define M3V3_REG_ON_Pin GPIO_PIN_3
#define M3V3_REG_ON_GPIO_Port GPIOB
#define SEG11_Pin GPIO_PIN_4
#define SEG11_GPIO_Port GPIOB
#define SEG12_Pin GPIO_PIN_5
#define SEG12_GPIO_Port GPIOB
#define GYRO_INT2_Pin GPIO_PIN_8
#define GYRO_INT2_GPIO_Port GPIOB
#define COM3_Pin GPIO_PIN_9
#define COM3_GPIO_Port GPIOB
#define XL_CS_Pin GPIO_PIN_0
#define XL_CS_GPIO_Port GPIOE
#define XL_INT_Pin GPIO_PIN_1
#define XL_INT_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

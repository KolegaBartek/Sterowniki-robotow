/**
  ******************************************************************************
<<<<<<<< HEAD:manipulator/manipulator/Core/Inc/tim.h
  * File Name          : TIM.h
  * Description        : This file provides code for the configuration
  *                      of the TIM instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
========
  * @file    hsensor.h
  * @author  MCD Application Team
  * @brief   This header file contains the functions prototypes for the
  *          Humidity Sensor driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/BSP/Components/Common/hsensor.h
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
<<<<<<<< HEAD:manipulator/manipulator/Core/Inc/tim.h
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __tim_H
#define __tim_H
========

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HSENSOR_H
#define __HSENSOR_H

>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/BSP/Components/Common/hsensor.h
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
<<<<<<<< HEAD:manipulator/manipulator/Core/Inc/tim.h
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern TIM_HandleTypeDef htim1;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_TIM1_Init(void);

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */
========
#include <stdint.h>

/** @addtogroup BSP
  * @{
  */

/** @addtogroup Components
  * @{
  */
    
/** @addtogroup HSENSOR
  * @{
  */

/** @defgroup HSENSOR_Exported_Types
  * @{
  */ 

/** @defgroup HSENSOR_Driver_structure  Humidity Sensor Driver structure
  * @{
  */
typedef struct
{
  void       (*Init)(uint16_t); 
  uint8_t    (*ReadID)(uint16_t);
  float      (*ReadHumidity)(uint16_t); 
}HSENSOR_DrvTypeDef;
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/BSP/Components/Common/hsensor.h

#ifdef __cplusplus
}
#endif
<<<<<<<< HEAD:manipulator/manipulator/Core/Inc/tim.h
#endif /*__ tim_H */

/**
  * @}
  */

/**
  * @}
  */
========

#endif /* __HSENSOR_H */
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/BSP/Components/Common/hsensor.h

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

/**
  ******************************************************************************
<<<<<<<< HEAD:manipulator/manipulator/Core/Inc/gpio.h
  * File Name          : gpio.h
  * Description        : This file contains all the functions prototypes for
  *                      the gpio
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
========
  * @file    psensor.h
  * @author  MCD Application Team
  * @brief   This header file contains the functions prototypes for the
  *          Pressure Sensor driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/BSP/Components/Common/psensor.h
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
<<<<<<<< HEAD:manipulator/manipulator/Core/Inc/gpio.h
#ifndef __gpio_H
#define __gpio_H
========
#ifndef __PSENSOR_H
#define __PSENSOR_H

>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/BSP/Components/Common/psensor.h
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
<<<<<<<< HEAD:manipulator/manipulator/Core/Inc/gpio.h
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_GPIO_Init(void);

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
    
/** @addtogroup PSENSOR
  * @{
  */

/** @defgroup PSENSOR_Exported_Types
  * @{
  */ 

/** @defgroup PSENSOR_Driver_structure  Pressure Sensor Driver structure
  * @{
  */
typedef struct
{  
  void       (*Init)(uint16_t);
  uint8_t    (*ReadID)(uint16_t);
  float      (*ReadPressure)(uint16_t);
}PSENSOR_DrvTypeDef;
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
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/BSP/Components/Common/psensor.h

#ifdef __cplusplus
}
#endif
<<<<<<<< HEAD:manipulator/manipulator/Core/Inc/gpio.h
#endif /*__ pinoutConfig_H */

/**
  * @}
  */

/**
  * @}
  */
========

#endif /* __PSENSOR_H */
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/BSP/Components/Common/psensor.h

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

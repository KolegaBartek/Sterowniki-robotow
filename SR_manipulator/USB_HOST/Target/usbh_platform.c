/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : usbh_platform.c

  * @brief          : This file implements the USB platform
  ******************************************************************************
  * @attention
  *
<<<<<<<< HEAD:manipulator/manipulator/USB_HOST/Target/usbh_platform.c
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
========
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/USB_HOST/Target/usbh_platform.c
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "usbh_platform.h"

/* USER CODE BEGIN INCLUDE */

/* USER CODE END INCLUDE */

/**
  * @brief  Drive VBUS.
  * @param  state : VBUS state
  *          This parameter can be one of the these values:
  *           - 1 : VBUS Active
  *           - 0 : VBUS Inactive
  */
void MX_DriverVbusFS(uint8_t state)
{
  uint8_t data = state;
  /* USER CODE BEGIN PREPARE_GPIO_DATA_VBUS_FS */
  if(state == 0)
  {
    /* Drive high Charge pump */
<<<<<<<< HEAD:manipulator/manipulator/USB_HOST/Target/usbh_platform.c
    data = GPIO_PIN_SET;
========
    data = GPIO_PIN_RESET;
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/USB_HOST/Target/usbh_platform.c
  }
  else
  {
    /* Drive low Charge pump */
<<<<<<<< HEAD:manipulator/manipulator/USB_HOST/Target/usbh_platform.c
    data = GPIO_PIN_RESET;
========
    data = GPIO_PIN_SET;
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/USB_HOST/Target/usbh_platform.c
  }
  /* USER CODE END PREPARE_GPIO_DATA_VBUS_FS */
  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,(GPIO_PinState)data);
}

<<<<<<<< HEAD:manipulator/manipulator/USB_HOST/Target/usbh_platform.c
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
========
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/USB_HOST/Target/usbh_platform.c

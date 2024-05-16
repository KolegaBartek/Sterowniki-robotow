/**
  ******************************************************************************
  * @file    stm32l4xx_hal_dma_ex.c
  * @author  MCD Application Team
  * @brief   DMA Extension HAL module driver
  *         This file provides firmware functions to manage the following
  *         functionalities of the DMA Extension peripheral:
  *           + Extended features functions
  *
<<<<<<<< HEAD:manipulator/manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
========
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
  @verbatim
  ==============================================================================
                        ##### How to use this driver #####
  ==============================================================================
  [..]
  The DMA Extension HAL driver can be used as follows:

   (+) Configure the DMA_MUX Synchronization Block using HAL_DMAEx_ConfigMuxSync function.
   (+) Configure the DMA_MUX Request Generator Block using HAL_DMAEx_ConfigMuxRequestGenerator function.
       Functions HAL_DMAEx_EnableMuxRequestGenerator and HAL_DMAEx_DisableMuxRequestGenerator can then be used
       to respectively enable/disable the request generator.

   (+) To handle the DMAMUX Interrupts, the function  HAL_DMAEx_MUX_IRQHandler should be called from
       the DMAMUX IRQ handler i.e DMAMUX1_OVR_IRQHandler.
       As only one interrupt line is available for all DMAMUX channels and request generators , HAL_DMAEx_MUX_IRQHandler should be
       called with, as parameter, the appropriate DMA handle as many as used DMAs in the user project
      (exception done if a given DMA is not using the DMAMUX SYNC block neither a request generator)

     -@-  In Memory-to-Memory transfer mode, Multi (Double) Buffer mode is not allowed.
     -@-  When Multi (Double) Buffer mode is enabled, the transfer is circular by default.
     -@-  In Multi (Double) buffer mode, it is possible to update the base address for
          the AHB memory port on the fly (DMA_CM0ARx or DMA_CM1ARx) when the channel is enabled.


  @endverbatim
  ******************************************************************************
<<<<<<<< HEAD:manipulator/manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
========
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

#if defined(DMAMUX1)

/** @addtogroup STM32L4xx_HAL_Driver
  * @{
  */

/** @defgroup DMAEx DMAEx
  * @brief DMA Extended HAL module driver
  * @{
  */

#ifdef HAL_DMA_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private Constants ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/** @defgroup DMAEx_Exported_Functions DMAEx Exported Functions
  * @{
  */

/** @defgroup DMAEx_Exported_Functions_Group1 DMAEx Extended features functions
 *  @brief   Extended features functions
 *
@verbatim
 ===============================================================================
                #####  Extended features functions  #####
 ===============================================================================
    [..]  This section provides functions allowing to:

    (+) Configure the DMAMUX Synchronization Block using HAL_DMAEx_ConfigMuxSync function.
    (+) Configure the DMAMUX Request Generator Block using HAL_DMAEx_ConfigMuxRequestGenerator function.
       Functions HAL_DMAEx_EnableMuxRequestGenerator and HAL_DMAEx_DisableMuxRequestGenerator can then be used
       to respectively enable/disable the request generator.

@endverbatim
  * @{
  */


/**
  * @brief  Configure the DMAMUX synchronization parameters for a given DMA channel (instance).
  * @param  hdma pointer to a DMA_HandleTypeDef structure that contains
  *              the configuration information for the specified DMA channel.
  * @param  pSyncConfig : pointer to HAL_DMA_MuxSyncConfigTypeDef : contains the DMAMUX synchronization parameters
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMAEx_ConfigMuxSync(DMA_HandleTypeDef *hdma, HAL_DMA_MuxSyncConfigTypeDef *pSyncConfig)
{
  /* Check the parameters */
  assert_param(IS_DMA_ALL_INSTANCE(hdma->Instance));

  assert_param(IS_DMAMUX_SYNC_SIGNAL_ID(pSyncConfig->SyncSignalID));

  assert_param(IS_DMAMUX_SYNC_POLARITY(pSyncConfig-> SyncPolarity));
  assert_param(IS_DMAMUX_SYNC_STATE(pSyncConfig->SyncEnable));
  assert_param(IS_DMAMUX_SYNC_EVENT(pSyncConfig->EventEnable));
  assert_param(IS_DMAMUX_SYNC_REQUEST_NUMBER(pSyncConfig->RequestNumber));

  /*Check if the DMA state is ready */
<<<<<<<< HEAD:manipulator/manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
  if(hdma->State == HAL_DMA_STATE_READY)
========
  if (hdma->State == HAL_DMA_STATE_READY)
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
  {
    /* Process Locked */
    __HAL_LOCK(hdma);

    /* Set the new synchronization parameters (and keep the request ID filled during the Init)*/
<<<<<<<< HEAD:manipulator/manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
    MODIFY_REG( hdma->DMAmuxChannel->CCR, \
               (~DMAMUX_CxCR_DMAREQ_ID) , \
               ((pSyncConfig->SyncSignalID) << DMAMUX_CxCR_SYNC_ID_Pos) | ((pSyncConfig->RequestNumber - 1U) << DMAMUX_CxCR_NBREQ_Pos) | \
               pSyncConfig->SyncPolarity | ((uint32_t)pSyncConfig->SyncEnable << DMAMUX_CxCR_SE_Pos) | \
                 ((uint32_t)pSyncConfig->EventEnable << DMAMUX_CxCR_EGE_Pos));
========
    MODIFY_REG(hdma->DMAmuxChannel->CCR, \
               (~DMAMUX_CxCR_DMAREQ_ID), \
               ((pSyncConfig->SyncSignalID) << DMAMUX_CxCR_SYNC_ID_Pos) | ((pSyncConfig->RequestNumber - 1U) << DMAMUX_CxCR_NBREQ_Pos) | \
               pSyncConfig->SyncPolarity | ((uint32_t)pSyncConfig->SyncEnable << DMAMUX_CxCR_SE_Pos) | \
               ((uint32_t)pSyncConfig->EventEnable << DMAMUX_CxCR_EGE_Pos));
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c

    /* Process UnLocked */
    __HAL_UNLOCK(hdma);

    return HAL_OK;
  }
  else
  {
    /*DMA State not Ready*/
    return HAL_ERROR;
  }
}

/**
  * @brief  Configure the DMAMUX request generator block used by the given DMA channel (instance).
  * @param  hdma pointer to a DMA_HandleTypeDef structure that contains
  *              the configuration information for the specified DMA channel.
  * @param  pRequestGeneratorConfig : pointer to HAL_DMA_MuxRequestGeneratorConfigTypeDef :
  *         contains the request generator parameters.
  *
  * @retval HAL status
  */
<<<<<<<< HEAD:manipulator/manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
HAL_StatusTypeDef HAL_DMAEx_ConfigMuxRequestGenerator (DMA_HandleTypeDef *hdma, HAL_DMA_MuxRequestGeneratorConfigTypeDef *pRequestGeneratorConfig)
========
HAL_StatusTypeDef HAL_DMAEx_ConfigMuxRequestGenerator(DMA_HandleTypeDef *hdma, HAL_DMA_MuxRequestGeneratorConfigTypeDef *pRequestGeneratorConfig)
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
{
  /* Check the parameters */
  assert_param(IS_DMA_ALL_INSTANCE(hdma->Instance));

  assert_param(IS_DMAMUX_REQUEST_GEN_SIGNAL_ID(pRequestGeneratorConfig->SignalID));

  assert_param(IS_DMAMUX_REQUEST_GEN_POLARITY(pRequestGeneratorConfig->Polarity));
  assert_param(IS_DMAMUX_REQUEST_GEN_REQUEST_NUMBER(pRequestGeneratorConfig->RequestNumber));

  /* check if the DMA state is ready
     and DMA is using a DMAMUX request generator block
  */
<<<<<<<< HEAD:manipulator/manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
  if((hdma->State == HAL_DMA_STATE_READY) && (hdma->DMAmuxRequestGen != 0U))
========
  if ((hdma->State == HAL_DMA_STATE_READY) && (hdma->DMAmuxRequestGen != 0U))
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
  {
    /* Process Locked */
    __HAL_LOCK(hdma);

    /* Set the request generator new parameters */
    hdma->DMAmuxRequestGen->RGCR = pRequestGeneratorConfig->SignalID | \
<<<<<<<< HEAD:manipulator/manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
                                  ((pRequestGeneratorConfig->RequestNumber - 1U) << DMAMUX_RGxCR_GNBREQ_Pos)| \
                                  pRequestGeneratorConfig->Polarity;
   /* Process UnLocked */
   __HAL_UNLOCK(hdma);

   return HAL_OK;
 }
 else
 {
   return HAL_ERROR;
 }
========
                                   ((pRequestGeneratorConfig->RequestNumber - 1U) << DMAMUX_RGxCR_GNBREQ_Pos) | \
                                   pRequestGeneratorConfig->Polarity;
    /* Process UnLocked */
    __HAL_UNLOCK(hdma);

    return HAL_OK;
  }
  else
  {
    return HAL_ERROR;
  }
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
}

/**
  * @brief  Enable the DMAMUX request generator block used by the given DMA channel (instance).
  * @param  hdma pointer to a DMA_HandleTypeDef structure that contains
  *              the configuration information for the specified DMA channel.
  * @retval HAL status
  */
<<<<<<<< HEAD:manipulator/manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
HAL_StatusTypeDef HAL_DMAEx_EnableMuxRequestGenerator (DMA_HandleTypeDef *hdma)
========
HAL_StatusTypeDef HAL_DMAEx_EnableMuxRequestGenerator(DMA_HandleTypeDef *hdma)
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
{
  /* Check the parameters */
  assert_param(IS_DMA_ALL_INSTANCE(hdma->Instance));

  /* check if the DMA state is ready
     and DMA is using a DMAMUX request generator block
  */
<<<<<<<< HEAD:manipulator/manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
  if((hdma->State != HAL_DMA_STATE_RESET) && (hdma->DMAmuxRequestGen != 0))
========
  if ((hdma->State != HAL_DMA_STATE_RESET) && (hdma->DMAmuxRequestGen != 0))
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
  {

    /* Enable the request generator*/
    hdma->DMAmuxRequestGen->RGCR |= DMAMUX_RGxCR_GE;

<<<<<<<< HEAD:manipulator/manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
   return HAL_OK;
 }
 else
 {
   return HAL_ERROR;
 }
========
    return HAL_OK;
  }
  else
  {
    return HAL_ERROR;
  }
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
}

/**
  * @brief  Disable the DMAMUX request generator block used by the given DMA channel (instance).
  * @param  hdma pointer to a DMA_HandleTypeDef structure that contains
  *              the configuration information for the specified DMA channel.
  * @retval HAL status
  */
<<<<<<<< HEAD:manipulator/manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
HAL_StatusTypeDef HAL_DMAEx_DisableMuxRequestGenerator (DMA_HandleTypeDef *hdma)
========
HAL_StatusTypeDef HAL_DMAEx_DisableMuxRequestGenerator(DMA_HandleTypeDef *hdma)
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
{
  /* Check the parameters */
  assert_param(IS_DMA_ALL_INSTANCE(hdma->Instance));

  /* check if the DMA state is ready
     and DMA is using a DMAMUX request generator block
  */
<<<<<<<< HEAD:manipulator/manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
  if((hdma->State != HAL_DMA_STATE_RESET) && (hdma->DMAmuxRequestGen != 0))
========
  if ((hdma->State != HAL_DMA_STATE_RESET) && (hdma->DMAmuxRequestGen != 0))
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
  {

    /* Disable the request generator*/
    hdma->DMAmuxRequestGen->RGCR &= ~DMAMUX_RGxCR_GE;

    return HAL_OK;
  }
  else
  {
    return HAL_ERROR;
  }
}

/**
  * @brief  Handles DMAMUX interrupt request.
  * @param  hdma pointer to a DMA_HandleTypeDef structure that contains
  *              the configuration information for the specified DMA channel.
  * @retval None
  */
void HAL_DMAEx_MUX_IRQHandler(DMA_HandleTypeDef *hdma)
{
  /* Check for DMAMUX Synchronization overrun */
<<<<<<<< HEAD:manipulator/manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
  if((hdma->DMAmuxChannelStatus->CSR & hdma->DMAmuxChannelStatusMask) != 0U)
========
  if ((hdma->DMAmuxChannelStatus->CSR & hdma->DMAmuxChannelStatusMask) != 0U)
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
  {
    /* Disable the synchro overrun interrupt */
    hdma->DMAmuxChannel->CCR &= ~DMAMUX_CxCR_SOIE;

    /* Clear the DMAMUX synchro overrun flag */
    hdma->DMAmuxChannelStatus->CFR = hdma->DMAmuxChannelStatusMask;

    /* Update error code */
    hdma->ErrorCode |= HAL_DMA_ERROR_SYNC;

<<<<<<<< HEAD:manipulator/manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
    if(hdma->XferErrorCallback != NULL)
========
    if (hdma->XferErrorCallback != NULL)
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
    {
      /* Transfer error callback */
      hdma->XferErrorCallback(hdma);
    }
  }

<<<<<<<< HEAD:manipulator/manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
  if(hdma->DMAmuxRequestGen != 0)
  {
   /* if using a DMAMUX request generator block Check for DMAMUX request generator overrun */
    if((hdma->DMAmuxRequestGenStatus->RGSR & hdma->DMAmuxRequestGenStatusMask) != 0U)
========
  if (hdma->DMAmuxRequestGen != 0)
  {
    /* if using a DMAMUX request generator block Check for DMAMUX request generator overrun */
    if ((hdma->DMAmuxRequestGenStatus->RGSR & hdma->DMAmuxRequestGenStatusMask) != 0U)
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
    {
      /* Disable the request gen overrun interrupt */
      hdma->DMAmuxRequestGen->RGCR &= ~DMAMUX_RGxCR_OIE;

      /* Clear the DMAMUX request generator overrun flag */
      hdma->DMAmuxRequestGenStatus->RGCFR = hdma->DMAmuxRequestGenStatusMask;

      /* Update error code */
      hdma->ErrorCode |= HAL_DMA_ERROR_REQGEN;

<<<<<<<< HEAD:manipulator/manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
      if(hdma->XferErrorCallback != NULL)
========
      if (hdma->XferErrorCallback != NULL)
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
      {
        /* Transfer error callback */
        hdma->XferErrorCallback(hdma);
      }
    }
  }
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_DMA_MODULE_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

#endif /* DMAMUX1 */
<<<<<<<< HEAD:manipulator/manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
========
>>>>>>>> bceb7f419866e076b447dddfbb9c82c1b5c03c72:SR_manipulator/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c

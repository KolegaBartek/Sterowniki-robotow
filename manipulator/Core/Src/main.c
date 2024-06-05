/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "lcd.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stm32l476g_discovery_glass_lcd.h"
#include "stm32l476g_discovery_compass.h"
#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"
#include "filtr.h"
#include "math.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define MIDDLE HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)
#define LEFT HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)
#define RIGHT HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2)
#define UP HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3)
#define DOWN HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)

#define ZAKRES_CM_GORA 15
#define ZAKRES_CM_DOL 0
#define ZAKRES_GORA 16000
#define ZAKRES_DOL -16000

#define L1 8.70
#define L2 6.40
#define L3 12.70
#define X_CONST 15.0

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
// zmienne z akcelemetru
int16_t pDataXYZ[3];
float x, y;

// zmienne do przycisków
uint8_t click;
int last;
int odczyt[4], current[4];

// zmienne do wyświetlenia
char buf[16];

//zmienne do przegubow
int16_t theta1, theta2, theta3;
int16_t theta1_, theta2_, theta3_;
lowpass_filter_t filter_theta1= {0};
lowpass_filter_t filter_theta2= {0};
lowpass_filter_t filter_theta3= {0};

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int _write(int file, char *ptr, int len){
	HAL_UART_Transmit(&huart2, (uint8_t*)ptr, len, 50);
	return len;
}

float skaluj_na_cm(int16_t wartosc){

	 return ZAKRES_CM_DOL + (ZAKRES_CM_GORA - ZAKRES_CM_DOL) *
	 ((float)wartosc - ZAKRES_DOL) / (ZAKRES_GORA - ZAKRES_DOL);
}

float skaluj_PWM1(int16_t wartosc){

	 return abs(500 + (2500 - 500) * (float)wartosc / 180);
}

float skaluj_PWM2(int16_t wartosc){

	 return abs(600 + (1500 - 600) * ((float)wartosc - 0) / (60 - 0));
}

float skaluj_PWM3(int16_t wartosc){

	 return abs(1500 - abs(700 + (1500 - 700) * (float)wartosc / 80)) + 700;
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_LCD_Init();
  MX_SPI2_Init();
  MX_USART2_UART_Init();
  MX_TIM1_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */
  BSP_LCD_GLASS_Init();
  BSP_COMPASS_Init();
  filter_lowpass_init(&filter_theta1);
  filter_lowpass_init(&filter_theta2);
  filter_lowpass_init(&filter_theta3);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1); //chwytak - PB6
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2); //theta1 - PE11
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3); //theta2 - PE13
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4); //theta3 - PE14

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  /*
	   * display LCD
	   */

		if(UP){
			click++;
		}

		if(DOWN){
			click--;
		}

		BSP_LCD_GLASS_Clear();
		switch(click%3){
		  case 0:
			sprintf(buf, "th1:%d", theta1);
			BSP_LCD_GLASS_DisplayString((uint8_t*)&buf);
			break;
		  case 1:
		    sprintf(buf, "th2:%d", theta2);
			BSP_LCD_GLASS_DisplayString((uint8_t*)&buf);
			break;
		  case 2:
			sprintf(buf, "th3:%d", theta3);
			BSP_LCD_GLASS_DisplayString((uint8_t*)&buf);
			break;
		}
		HAL_Delay(200);

	  /*
	   * Actuators - joints
	   */

	  BSP_COMPASS_AccGetXYZ(pDataXYZ);

	  y = skaluj_na_cm(pDataXYZ[1]);

	  theta1 = abs(atan2(pDataXYZ[1], pDataXYZ[0])*180/M_PI);
	  theta3 = acos((pow(y,2) + pow(X_CONST,2) - pow(L2,2) - pow(L3,2))/(2 * L3 * L2))*180/M_PI;
	  theta2 = abs(atan2(y, X_CONST)*180/M_PI) + asin((sin(theta3) * L2)/(sqrt(pow(y,2) + pow(X_CONST,2))))*180/M_PI;

	  //printf("theta1: %d\r\n\n", theta1);
	  //printf("theta2: %d\r\n\n", theta2);
	  //printf("theta3: %d\r\n\n", theta3);

	  //first one
	  theta1_ = filter_lowpass(skaluj_PWM1(theta1), &filter_theta1);
	  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, theta1_);

	  // second one
	  theta2_ = filter_lowpass(skaluj_PWM2(theta2), &filter_theta2);
	  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, theta2_);

	  // third one
	  theta3_ = filter_lowpass(skaluj_PWM3(theta3), &filter_theta3);
	  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, theta3_);

	  last = HAL_GetTick();
	  if(RIGHT == GPIO_PIN_SET){odczyt[2] = 1;}
		if(!(RIGHT == GPIO_PIN_SET) && odczyt[2] == 1){
			odczyt[2] = 0;
			current[2] = HAL_GetTick();
			if((current[2] - last) < 50){
				__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 500);
				HAL_Delay(200);
				last = current[2];
			}
		}

		last = HAL_GetTick();

		if(LEFT == GPIO_PIN_SET){odczyt[3] = 1;}
				if(!(LEFT == GPIO_PIN_SET) && odczyt[3] == 1){
					odczyt[3] = 0;
					current[3] = HAL_GetTick();
					if((current[3] - last) < 50){
						__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 2000);
						HAL_Delay(200);
						last = current[3];
					}
				}
		}

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_LSE
                              |RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 36;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC|RCC_PERIPHCLK_USART2;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Enable MSI Auto calibration
  */
  HAL_RCCEx_EnableMSIPLLMode();
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

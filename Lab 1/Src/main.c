/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#define ARM_MATH_CM4
#include "arm_math.h"

#include "lab1math.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define ITM_Port32(n) (*((volatile unsigned long *) (0xE0000000+4*n)))
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  /* USER CODE BEGIN 2 */

  // part 1: element-wise multiplication
  // define our variables and array
  float f1000_array[1000] = {47.68, 26.67, 64.09, 31.60, 25.83, 87.41, 67.60, 59.67, 43.07, 97.64, 71.48, 87.47, 20.74, 34.73, 19.57, 33.93, 15.06, 25.16, 36.89, 83.33, 3.50, 33.62, 40.05, 24.90, 35.29, 21.04, 39.92, 54.97, 34.18, 41.72, 67.35, 67.68, 98.41, 19.76, 52.58, 4.89, 79.51, 55.49, 84.28, 2.99, 12.81, 97.55, 24.99, 29.49, 23.48, 93.33, 81.25, 84.78, 93.46, 72.15, 13.79, 30.22, 70.75, 32.81, 67.36, 15.36, 25.08, 47.37, 47.70, 94.24, 30.44, 86.61, 7.47, 46.06, 73.97, 69.03, 75.98, 50.23, 58.21, 76.42, 15.18, 63.36, 82.14, 72.56, 60.64, 33.72, 4.37, 72.86, 55.78, 14.17, 9.64, 50.81, 2.67, 28.42, 35.68, 53.96, 75.15, 44.47, 57.25, 85.13, 80.87, 93.26, 77.22, 24.22, 81.69, 39.69, 79.69, 97.55, 90.13, 20.72, 61.22, 17.63, 40.56, 7.63, 45.31, 64.60, 32.89, 99.17, 68.49, 84.84, 54.03, 33.07, 68.14, 96.35, 38.63, 87.22, 27.35, 95.21, 91.27, 77.18, 12.24, 73.53, 3.88, 42.45, 1.16, 32.81, 67.44, 89.77, 17.87, 25.24, 30.13, 67.06, 4.87, 40.62, 31.72, 6.23, 18.95, 99.02, 30.57, 22.90, 44.83, 70.36, 99.26, 34.43, 97.37, 17.92, 60.66, 83.19, 25.38, 78.02, 7.13, 32.98, 78.94, 78.89, 50.85, 91.80, 22.50, 44.70, 39.35, 51.54, 83.55, 95.43, 93.26, 54.91, 29.67, 87.91, 32.33, 66.09, 93.72, 20.07, 11.40, 10.54, 20.59, 69.29, 84.31, 45.22, 52.47, 46.29, 56.82, 92.96, 18.83, 12.14, 92.64, 32.93, 72.31, 89.08, 23.84, 59.78, 33.81, 19.63, 2.08, 85.04, 56.26, 50.64, 97.82, 55.37, 54.47, 68.55, 82.26, 6.11, 33.91, 70.47, 40.01, 18.34, 96.85, 19.27, 89.14, 11.87, 51.20, 3.45, 15.64, 82.28, 78.51, 22.50, 53.62, 32.11, 15.21, 7.42, 52.73, 48.56, 5.90, 64.40, 48.35, 63.35, 53.98, 81.87, 50.55, 2.45, 66.14, 67.10, 34.36, 27.86, 61.01, 60.27, 72.12, 1.11, 54.17, 78.66, 86.55, 4.42, 67.81, 31.26, 12.51, 82.37, 25.53, 66.48, 33.39, 19.61, 68.14, 43.21, 69.44, 56.92, 98.21, 49.36, 3.99, 25.29, 31.48, 0.28, 53.98, 61.48, 73.44, 67.80, 61.94, 19.14, 71.26, 10.42, 58.31, 24.40, 11.55, 83.62, 29.02, 98.34, 75.56, 95.94, 18.00, 62.82, 62.61, 97.71, 67.34, 79.27, 76.87, 14.35, 56.43, 27.62, 4.06, 65.68, 53.32, 80.15, 31.53, 82.54, 22.94, 78.57,
  90.21, 33.69, 96.96, 66.15, 70.34, 71.97, 0.37, 51.87, 29.09, 31.10, 50.47, 10.93, 20.08, 83.79, 76.87, 25.83, 53.42, 69.67, 78.61, 75.15, 95.33, 36.52, 84.42, 15.53, 58.01, 95.63, 16.10, 37.41, 80.76, 93.80, 88.29, 63.42, 12.71, 60.12, 48.81, 86.49, 16.02, 1.79, 3.21, 51.96, 51.13, 37.01, 57.88, 52.02, 9.68, 56.47, 75.56, 19.59, 23.69, 48.95, 59.77, 32.46, 26.82, 16.74, 66.86, 53.63, 46.40, 20.60, 14.96, 56.83, 51.51, 65.68, 18.60, 81.05, 82.23, 87.48, 68.81, 72.10, 56.99, 96.86, 64.91, 73.01, 93.36, 27.56, 34.92, 91.31, 63.34, 1.16, 45.91, 75.16, 5.55, 36.70, 15.89, 1.11, 45.31, 53.97, 82.02, 57.28, 5.87, 99.81, 18.82, 51.64, 22.30, 0.07, 16.87, 24.14, 93.89, 48.96, 50.46, 64.51, 83.33, 76.72, 65.50, 98.85, 18.02, 59.99, 48.35, 27.93, 62.05, 84.35, 99.17, 67.20, 89.99, 14.77, 39.17, 3.15, 51.50, 18.67, 61.44, 69.89, 81.37, 81.29, 22.56, 21.50, 80.19, 41.63, 2.03, 55.73, 9.10, 58.43, 39.66, 54.79, 26.73, 30.26, 74.33, 36.27, 26.69, 94.18, 40.28, 48.46, 68.99, 64.21, 82.24, 39.28, 44.70, 63.63, 37.72, 7.32, 80.26, 22.02, 89.69, 49.62, 58.06, 8.89, 4.17, 38.12, 66.97, 59.28, 36.70, 54.29, 50.20, 6.05, 31.73, 74.03, 53.34, 26.90, 49.44, 29.27, 59.47, 2.80, 40.87, 58.82, 62.45, 83.46, 23.10, 94.51, 2.87, 94.97, 89.19, 81.83, 72.12, 24.83, 92.43, 63.39, 8.63, 9.23, 86.52, 64.28, 47.12, 64.75, 49.23, 19.48, 17.17, 6.60, 52.85, 27.81, 90.18, 65.70, 25.90, 39.21, 66.50, 32.69, 96.51, 25.61, 94.14, 14.52, 42.05, 84.97, 81.04, 76.92, 88.16, 31.25, 69.92, 1.45, 3.52, 33.20, 23.22, 38.33, 90.40, 44.67, 17.08, 78.66, 55.17, 62.20, 32.82, 37.08, 18.85, 88.06, 41.12, 37.62, 36.56, 87.84, 39.53, 66.11, 69.99, 3.37, 94.75, 93.88, 30.43, 41.83, 32.45, 24.85, 54.68, 55.31, 45.35, 27.89, 38.17, 79.37, 39.42, 53.45, 46.66, 41.76, 6.82, 63.52, 39.29, 17.86, 72.22, 26.14, 95.60, 61.03, 72.79, 99.45, 15.40, 86.39, 9.37, 13.01, 85.93, 25.23, 46.80, 94.93, 71.37, 66.11, 41.27, 43.85, 54.85, 22.36, 49.00, 82.21, 1.49, 14.20, 72.82, 44.99, 83.66, 2.15, 73.93, 99.53, 66.76, 25.92, 39.00, 83.00, 52.82, 83.50, 4.20, 25.36, 76.72, 98.56
  , 66.12, 98.53, 10.16, 67.71, 40.41, 83.90, 44.38, 17.14, 26.27, 55.17, 88.94, 8.97, 37.45, 38.82, 48.14, 61.66, 65.14, 42.12, 13.85, 56.29, 3.65, 4.28, 26.63, 71.45, 42.65, 47.98, 35.39, 78.03, 35.34, 18.79, 10.49, 58.41, 33.64, 10.02, 11.30, 21.49, 83.18, 3.83, 62.34, 98.00, 73.65, 89.30, 16.00, 30.22, 3.18, 34.56, 52.55, 73.97, 89.17, 0.80, 82.41, 82.23, 24.22, 95.51, 72.57, 88.05, 32.17, 20.18, 42.53, 61.90, 67.08, 48.21, 79.48, 24.27, 28.82, 78.24, 88.49, 31.19, 5.52, 82.70, 77.73, 2.63, 31.29, 78.17, 38.70, 49.40, 92.02, 22.14, 44.02, 30.70, 43.67, 55.57, 20.56, 97.24, 49.39, 58.70, 1.41, 57.91, 38.84, 53.06, 9.98, 77.89, 9.35, 8.56, 75.73, 76.28, 20.59, 94.17, 32.44, 16.10, 26.58, 38.21, 17.99, 83.39, 7.99, 1.50, 2.79, 84.98, 44.90, 31.27, 89.46, 53.60, 59.02, 95.59, 71.88, 8.49, 57.56, 88.04, 0.00, 5.10, 62.35, 46.18, 27.15, 21.62, 72.80, 15.94, 20.62, 78.20, 86.16, 40.20, 15.71, 77.00, 30.56, 38.81, 20.16, 60.79, 78.11, 16.15, 32.64, 57.88, 79.78, 89.45, 21.43, 7.46, 15.41, 19.68, 5.04, 94.49, 81.36, 91.67, 60.42, 62.31, 43.85, 36.16, 31.81, 67.10, 32.29, 20.32, 67.07, 68.78, 79.61, 82.46, 81.14, 66.30, 74.57, 42.43, 38.55, 66.48, 11.00, 91.56, 13.53, 15.57, 32.92, 55.19, 65.52, 24.66, 53.55, 63.31, 16.95, 39.90, 48.23, 40.94, 45.27, 18.46, 83.33, 98.17, 58.14, 60.38, 13.38, 26.11, 99.34, 8.11, 27.15, 87.72, 71.41, 95.35, 85.89, 40.14, 36.50, 40.07, 73.23, 68.35, 11.44, 21.26, 3.42, 64.88, 7.58, 62.31, 19.49, 29.98, 88.76, 92.67, 33.70, 93.18, 31.64, 87.72, 9.61, 68.86, 1.23, 33.44, 28.32, 42.21, 2.98, 51.07, 64.79, 81.88, 27.01, 54.18, 22.13, 93.92, 32.24, 15.86, 82.80, 46.93, 28.66, 4.42, 38.16, 38.45, 50.10, 34.57, 71.30, 90.52, 61.61, 10.34, 54.43, 5.07, 74.61, 41.74, 16.03, 16.81, 85.88, 40.07, 62.27, 30.42, 35.83, 89.09, 51.15, 58.37, 49.92, 71.36, 66.56, 9.55, 75.93, 54.06, 1.28, 79.28, 17.80, 44.04, 47.61, 36.71, 25.85, 14.87, 48.41, 81.56, 82.84, 68.39, 68.00, 96.92, 50.42, 17.40, 96.55, 48.90, 67.62, 93.49, 60.48, 5.31, 55.31, 0.38, 11.73, 7.94, 22.22, 45.72, 49.58, 50.33, 60.42, 86.17,
  38.93, 43.17, 93.18, 22.82, 73.07, 71.53, 92.16, 96.95, 76.88, 98.30, 7.69, 19.28, 90.90, 41.14, 7.92, 15.05, 33.62, 21.38, 93.58, 12.28, 59.13, 26.26, 14.48, 50.97, 81.73, 60.97, 0.74, 33.95, 9.78, 97.38, 70.55, 45.36, 58.44, 81.14, 39.60, 87.28, 87.82, 91.56, 25.32, 11.60, 82.52, 89.00, 50.59, 72.76, 64.44, 81.57, 14.86, 26.22, 53.19, 46.71, 46.46, 83.53, 23.63, 57.80, 20.24, 47.81, 65.13, 74.32, 62.42, 60.35, 59.35, 47.24, 85.79, 52.00, 44.34, 60.21, 69.87, 27.18, 69.10, 89.49, 29.91, 59.84, 38.09, 40.29, 22.26, 6.18, 49.89, 35.80, 34.73, 29.54, 26.10, 75.06, 96.37, 33.65, 56.73, 81.31, 31.15, 73.96, 25.48, 99.81, 20.67, 15.00, 24.18, 78.33, 5.03, 5.88, 27.09, 54.40, 58.54, 34.14, 94.98, 14.18, 60.95, 46.25, 72.81, 85.04, 43.42, 57.28, 78.05, 1.55, 42.48, 39.09, 63.32, 25.75, 44.54, 37.87};
  float products[1000];

  // part 2: standard deviation
  float stdC = 0;
  float stdAsm = 0;
  float stdCMSIS = 0;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	ITM_Port32(31) = 1;
	// cMult is about 35,000 cycles per call
	for (uint32_t i = 0; i < 1000; i++)
		cMult(f1000_array, f1000_array, 1000, products);
	ITM_Port32(31) = 2;
	//asmMult is about 14,000 cycles per call
	for (uint32_t i = 0; i < 1000; i++)
		asmMult(f1000_array, f1000_array, 1000, products);
	ITM_Port32(31) = 3;
	// arm_mult_f32 is about 7,000 cycles per call
	for (uint32_t i = 0; i < 1000; i++)
		arm_mult_f32(f1000_array, f1000_array, products, 1000);
	ITM_Port32(31) = 4;
	// cStd is about 83,000 cycles per call
	for (uint32_t i = 0; i < 1000; i++)
		cStd(f1000_array, 1000, &stdC);
	ITM_Port32(31) = 5;
	// asmStd is about 37,000 cycles per call
	for (uint32_t i = 0; i < 1000; i++)
		asmStd(f1000_array, 1000, &stdAsm);
	ITM_Port32(31) = 6;
	// arm_std_f32 is about 6,600 cycles per call
	for (uint32_t i = 0; i < 1000; i++)
		arm_std_f32(f1000_array, 1000, &stdCMSIS);
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
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
  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

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

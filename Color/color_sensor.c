/*
* Module : Color Sensor
*
* File Name : color_sensor.c
*
* Author : al-sakka
*
*/

#include "color_sensor.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
*******************************************************************************/

/**
 * @brief  Initializes the ADC for the color sensor.
 * @param  hadc: Pointer to the ADC handle
 */
void COLOR_SENSOR_Init(ADC_HandleTypeDef *hadc)
{
    ADC_ChannelConfTypeDef sConfig = {0};

    sConfig.Channel = COLOR_SENSOR_ADC_CHANNEL;
    sConfig.Rank = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLETIME_71CYCLES_5;  // Suitable for STM32F103C8T6

    HAL_ADC_ConfigChannel(hadc, &sConfig);
}

/**
 * @brief  Reads the grayscale value from the sensor.
 * @param  hadc: Pointer to the ADC handle
 */
uint8_t COLOR_SENSOR_ReadGrayscale(ADC_HandleTypeDef *hadc)
{
    HAL_ADC_Start(hadc);
    HAL_ADC_PollForConversion(hadc, HAL_MAX_DELAY);
    uint32_t adc_value = HAL_ADC_GetValue(hadc);
    HAL_ADC_Stop(hadc);

    return (uint8_t)((adc_value * (100)) / COLOR_SENSOR_MAX_VALUE);
}
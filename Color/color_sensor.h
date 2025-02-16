/**
 * Module : Color Sensor
 *
 * File Name : color_sensor.h
 *
 * Author : al-sakka
 *
 * Description: This grayscale sensor can measure the intensity of light from black to white.
 * A gray scale also known as black-and-white, is composed exclusively of shades of gray,
 * varying from black at the weakest intensity to white at the strongest.
 * Its connected LED will let you compare and provide some reflective feedback to analyze
 * gray-scale light ranges.
 * Different colors will apply but only grayscale values will be outputted.
 */

#ifndef COLOR_SENSOR_H_
#define COLOR_SENSOR_H_

#include "stm32f1xx_hal.h"  /* STM32F103 HAL library */

/*******************************************************************************
*                                Definitions                                  *
*******************************************************************************/

/*
#define COLOR_SENSOR_PORT (GPIOB)
#define COLOR_SENSOR_PIN (GPIO_PIN_0)
*/

#define COLOR_SENSOR_ADC_CHANNEL (ADC_CHANNEL_8)  /* PB0 -> ADC12_IN8 */
#define COLOR_SENSOR_ADC_RESOLUTION (4095)        /* 12-bit ADC */
#define COLOR_SENSOR_MAX_VALUE  (4095)            /* ADC full-scale value */

/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/

/**
 * @brief  Initializes the ADC for the color sensor.
 * @param  hadc: Pointer to the ADC handle
 */
void COLOR_SENSOR_Init(ADC_HandleTypeDef *hadc);

/**
 * @brief  Reads the grayscale value from the sensor.
 * @param  hadc: Pointer to the ADC handle
 */
uint8_t COLOR_SENSOR_ReadGrayscale(ADC_HandleTypeDef *hadc);

#endif  /* COLOR_SENSOR_H_ */
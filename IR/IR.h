#ifndef IR_H
#define IR_H

typedef enum
{
    FORWARD,
    LEFT,
    RIGHT,
    BACKWARD,
    STOP
} IRStatus;

#define LEFT_SENSOR  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)
#define RIGHT_SENSOR HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)

IRStatus Get_IR_Status(void);

#endif /*Guard*/
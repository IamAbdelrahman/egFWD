/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: GPIO_Lcfg.h
 *	@brief This file includes the implementation for the GPIO peripheral
 *	configuration
 *
 *****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "GPIO_Cfg.h"

/*- GLOBAL STATIC VARIABLES
-----------------------------------------------------------------------*/
/*- GPIO CONFIGURATION TABLE */
const static ST_GPIOConfig_t configGpio[] = {
    GPIOA0, GPIOA1, GPIOA2, GPIOA3, GPIOA4, GPIOA5, GPIOA6, GPIOA7,
    GPIOB0, GPIOB1, GPIOB2, GPIOB3, GPIOB4, GPIOB5, GPIOB6, GPIOB7,
    GPIOC0, GPIOC1, GPIOC2, GPIOC3, GPIOC4, GPIOC5, GPIOC6, GPIOC7,
    GPIOD0, GPIOD1, GPIOD2, GPIOD3, GPIOD4, GPIOD5, GPIOD6, GPIOD7,
};

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
vuint32_t configSizeGpio = sizeof(configGpio) / sizeof(configGpio[0]);

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
const ST_GPIOConfig_t *const GPIO_ConfigGet(void) {
  return (ST_GPIOConfig_t *const) & configGpio[0];
}

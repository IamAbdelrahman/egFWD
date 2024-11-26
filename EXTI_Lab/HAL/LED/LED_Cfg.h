/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: LED_Cfg.h
 *	@brief This module contains interface definitions for the
 *   LED configuration.
 *****************************************************************************/

#ifndef CFG_LED_CFG_H_
#define CFG_LED_CFG_H_

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "GPIO.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/
#define LEDS (3U)

/*- DEFINE LED CONFIGURATION */
#define LEDPA1                                                                 \
  (ST_LEDConfig_t) { &GPIOA1, LOW }
#define LEDPA3                                                                 \
  (ST_LEDConfig_t) { &GPIOA3, LOW }
#define LEDPA7                                                                \
  (ST_LEDConfig_t) { &GPIOA7, LOW }

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/
typedef struct {
  ST_GPIOConfig_t *pLedCfg;
  EN_PIN_STATE_t ledState;
} ST_LEDConfig_t;

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: LED_ConfigGet
 * Syntax: const ST_LEDConfig_t *const LED_ConfigGet(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: A helper function to initialize the LED based on a config
 * table.
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: const ST_LEDConfig_t* const
 *************************************************************************/
ST_LEDConfig_t *const LED_ConfigGet(void);

#endif /* CFG_LED_CFG_H_ */

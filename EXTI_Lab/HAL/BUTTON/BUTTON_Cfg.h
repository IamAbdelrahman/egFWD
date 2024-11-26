/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: BUTTON_Cfg.h
 *   @brief This module contains interface definitions for the
 *   BUTTON configuration.
 *
 *****************************************************************************/

#ifndef CFG_BUTTON_CFG_H_
#define CFG_BUTTON_CFG_H_

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "GPIO.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/
/*- DEFINE BUTTON CONFIGURATION */
#define BUTTONPD2                                                              \
  (ST_BUTTONConfig_t) { &GPIOD2, LOW }

#define BUTTONPC1                                                              \
  (ST_BUTTONConfig_t) { &GPIOC1, LOW }
/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/
typedef struct {
  ST_GPIOConfig_t *pButtonCfg;
  EN_PIN_STATE_t buttonState;
} ST_BUTTONConfig_t;

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: BUTTON_ConfigGet
 * Syntax: const ST_BUTTONConfig_t *const BUTTON_ConfigGet(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: A helper function to initialize the BUTTON based on a config
 * table.
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: const ST_BUTTONConfig_t* const
 *************************************************************************/
ST_BUTTONConfig_t *const BUTTON_ConfigGet(void);

#endif /* CFG_BUTTON_CFG_H_ */

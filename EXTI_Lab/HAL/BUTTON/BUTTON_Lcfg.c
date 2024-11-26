/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: BUTTON_Lcfg.c
 *  @brief This module contains the implementation for the BUTTON configuration
 *
 *****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "BUTTON_Cfg.h"

/*- LOCAL MACROS
-----------------------------------------------------------------------*/

/*- LOCAL DATATYPES
-----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------*/

/*- GLOBAL STATIC VARIABLES
-----------------------------------------------------------------------*/
static const ST_BUTTONConfig_t configButton[] = {BUTTONPD2, BUTTONPC1};

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
vuint8_t configSizeButton = sizeof(configButton) / sizeof(configButton[0]);

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
ST_BUTTONConfig_t *const BUTTON_ConfigGet(void) {
  return (ST_BUTTONConfig_t *const) & configButton[0];
}

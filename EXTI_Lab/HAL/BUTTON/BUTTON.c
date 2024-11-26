/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: BUTTON.c
 * 	@brief The implementation for the BUTTON driver
 *
 *****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "BUTTON.h"

/*- LOCAL MACROS
-----------------------------------------------------------------------*/

/*- LOCAL DATATYPES
-----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------*/

/*- GLOBAL STATIC VARIABLES
-----------------------------------------------------------------------*/

/*- GLOBAL EXTERN VARIABLES
-----------------------------------------------------------------------*/
extern vuint8_t configSizeButton;

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
void BUTTON_Init(void) {
  const ST_BUTTONConfig_t *const pButton = BUTTON_ConfigGet();
  vuint8_t i = 0;
  for (i = 0; i < configSizeButton; i++)
    GPIO_Init(pButton[i].pButtonCfg, configSizeButton);
}

EN_PIN_STATE_t BUTTON_Read(ST_BUTTONConfig_t *pButton) {
  pButton->buttonState = GPIO_PinRead(pButton->pButtonCfg->portNumber,
                                      pButton->pButtonCfg->pinNumber);
  return (pButton->buttonState);
}

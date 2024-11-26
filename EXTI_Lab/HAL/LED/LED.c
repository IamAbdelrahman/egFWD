/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 * @file LED.c
 * @brief The implementation for the LED driver
 *
 ****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "LED.h"

/*- LOCAL MACROS
-----------------------------------------------------------------------*/

/*- LOCAL VARIABLES
-----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------*/

/*- GLOBAL STATIC VARIABLES
-----------------------------------------------------------------------*/

/*- GLOBAL EXTERN VARIABLES
-----------------------------------------------------------------------*/
extern vuint8_t configSizeLed;

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
void LED_Init(void) {
  const ST_LEDConfig_t *const pLed = LED_ConfigGet();
  vuint8_t i = 0;
  for (i = 0; i < configSizeLed; i++) {
    GPIO_Init(pLed[i].pLedCfg, 1);
  }
}

void LED_Control(ST_LEDConfig_t *const pLed) {
  switch (pLed->ledState) {
  case HIGH:
    GPIO_PinWrite(pLed->pLedCfg->portNumber, pLed->pLedCfg->pinNumber, HIGH);
    break;
  case LOW:
    GPIO_PinWrite(pLed->pLedCfg->portNumber, pLed->pLedCfg->pinNumber, LOW);
    break;
  case TOGGLE:
    GPIO_PinToggle(pLed->pLedCfg->portNumber, pLed->pLedCfg->pinNumber);
    break;
  default:
    // Handle undefined states if necessary
    break;
  }
}

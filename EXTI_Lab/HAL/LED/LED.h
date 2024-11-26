/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 * @file LED.h
 * @brief The interface definition for the LED driver
 * @description This is the header file for the definition of the interface
 * for the LED driver connected to the MCU.
 *****************************************************************************/
#ifndef INC_LED_H_
#define INC_LED_H_

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "LED_Cfg.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: LED_Init
 * Syntax: void LED_Init(ST_LEDConfig_t *pLED)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Initialize LED
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void LED_Init(void);

/************************************************************************
 * Service Name: LED_Control
 * Syntax: void LED_Control(const ST_LEDConfig_t *pLED)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Control LED
 * @param (in): pLed a pointer to the LEDConfig structure
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void LED_Control(ST_LEDConfig_t *pLed);

#endif /* INC_LED_H_ */

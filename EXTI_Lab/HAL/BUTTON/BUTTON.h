/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: BUTTON.h
 *   @brief The interface definition for the BUTTON Driver
 *
 * 	@description This is the header file for the definition of the interface
 *for the BUTTON driver connected to the microcontroller
 *****************************************************************************/

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "BUTTON_Cfg.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: BUTTON_Init
 * Syntax: void BUTTON_Init(ST_BUTTONConfig_t *pBUTTON)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Initialize BUTTON
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void BUTTON_Init(void);

/************************************************************************
 * Service Name: BUTTON_Read
 * Syntax: EN_PIN_STATE_t BUTTON_Read(ST_BUTTONConfig_t *pBUTTON)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Read the state of a BUTTON
 * @param (in): pButton a pointer to the button structure
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
EN_PIN_STATE_t BUTTON_Read(ST_BUTTONConfig_t *pButton);

#endif /* INC_BUTTON_H_ */

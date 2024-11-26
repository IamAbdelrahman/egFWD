/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: APP.h
 *	@brief The interface definition for the application Driver
 *
 *	@details: This is the header file for the definition of the interface
 *	for the application driver connected to the microcontroller
 *****************************************************************************/

#ifndef APP_H_
#define APP_H_

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "USART.h"
#include "LCD.h"

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: APP_Init
 * Synatax: void APP_Init(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Initialize the application
 * PRE-CONDITION: MCAL layer is configured and initialized
 * POST-CONDITION: The APP is initialized
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void APP_Init(void);

/************************************************************************
 * Service Name: APP_Start
 * Synatax: void APP_Start(void)
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * @description: Start the application
 * PRE-CONDITION: The APP is initialized
 * POST-CONDITION: APP starts
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void APP_Start(void);

#endif /* APP_H_ */
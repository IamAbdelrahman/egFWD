/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 * 	@file: UART.h
 * 	@brief The interface definition for the UART.
 *
 * 	@details: This is the header file for the definition of the interface
 *	for a UART peripheral on a standard microcontroller.
 *****************************************************************************/

#ifndef INCLUDES_USART_H_
#define INCLUDES_USART_H_
/*- INCLUDES
-----------------------------------------------------------------------*/
#include "GPIO.h"
#include "USART_Cfg.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: UART_Init
 * Syntax: void UART_Init(const ST_UARTConfig_t* const configPtr)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Initialize UART module.
 * @param (in): configPtr a pointer to UART_Config struct
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void UART_Init(ST_UARTConfig_t *const configPtr);

/************************************************************************
 * Service Name: UART_SendData
 * Syntax: void UART_SendData(vuint16_t* pBuffer)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Send data by UART module.
 * @param (in): pBuffer a pointer to a buffer that stores the sent data
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void UART_SendData(vuint16_t *pBuffer);

/************************************************************************
 * Service Name: UART_ReceiveData
 * Syntax: void UART_ReceiveData(vuint16_t* pBuffer)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Receive data by UART module.
 * @param (in): pBuffer a pointer to a buffer that stores the sent data
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void UART_ReceiveData(vuint16_t *pBuffer);

/*
 * TODO
 * void USART_Init() 		- Using the Synchronous Mode
 */

#endif /* INCLUDES_USART_H_ */
/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: UART_Cfg.h
 *	@brief This module contains interface definitions for the
 *	UART configuration related to the ATmega32 MCU.
 *
 *	@details: This is the header file for the definition of the
 *	interface for retrieving the UART configuration table.
 *****************************************************************************/
#ifndef INCLUDES_USART_CFG_H_
#define INCLUDES_USART_CFG_H_

/*- INCLUDES
 -----------------------------------------------------------------------*/
#include "GPIO_Cfg.h"

/*- GLOBAL MACROS
 -----------------------------------------------------------------------*/
#define UART_CFG                                                               \
  (ST_UARTConfig_t) {                                                          \
    &GPIOD0, &GPIOD1, NO_PARITY, ONE_STOP_BIT, EIGHT_BITS, TX_RX_MODE,         \
        BAUD_RATE_115200, UART_IRQ_DISABLE                                     \
  }

/*- GLOBAL TYPEDEFS
 -----------------------------------------------------------------------*/
typedef enum { NO_PARITY = 0, PARITY_ODD, PARITY_EVEN } EN_PARITY_t;

typedef enum { ONE_STOP_BIT, TWO_STOP_BITS } EN_STOP_BIT_t;

typedef enum {
  FIVE_BITS,
  SIX_BITS,
  SEVEN_BITS,
  EIGHT_BITS,
  NINE_BITS
} EN_PAYLOAD_LENGTH_t;

typedef enum { TX_MODE, RX_MODE, TX_RX_MODE } EN_UART_MODE_t;

typedef enum {
  BAUD_RATE_2400 = 2400,
  BAUD_RATE_9600 = 9600,
  BAUD_RATE_19200 = 19200,
  BAUD_RATE_57600 = 57600,
  BAUD_RATE_115200 = 115200,
  BAUD_RATE_230400 = 230400,
  BAUD_RATE_460800 = 460800,
  BAUD_RATE_921600 = 921600,
  BAUD_RATE_2250000 = 2250000,
  BAUD_RATE_4500000 = 4500000,
} EN_BAUD_RATE_t;

typedef enum {
  UART_IRQ_DISABLE = -1,
  UART_IRQ_TXC,
  UART_IRQ_TXE,
  UART_IRQ_RXC
} EN_UART_IRQ_t;

typedef struct {
  ST_GPIOConfig_t *const pSetTxPin;
  ST_GPIOConfig_t *const pSetRxPin;
  EN_PARITY_t parityCheck;
  EN_STOP_BIT_t stopBit;
  EN_PAYLOAD_LENGTH_t payLoadSize;
  EN_UART_MODE_t Mode;
  EN_BAUD_RATE_t Baud;
  EN_UART_IRQ_t Irq;
  void (*callBackFunctionUart)(void);
} ST_UARTConfig_t;

/*- GLOBAL VARIABLES
 -----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
 -----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: UART_ConfigGet
 * Syntax: const ST_GPIOConfig_t *const UART_ConfigGet(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: A helper function to initialize the UART based on a config
 * table.
 * PRE-CONDITION: Config table needs to populated (configUsart > 0)
 * PRE-CONDITION: NUMBER_OF_PORTS > 0 && NUMBER_OF_PINS_PER_PORT > 0
 * PRE-CONDITION: The MCU clock must be configured and enabled
 * POST-CONDITION: A const pointer to the first member of the config table is
 * returned
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: const ST_GPIOConfig_t* const
 *************************************************************************/
ST_UARTConfig_t *const UART_ConfigGet(void);

#endif /* INCLUDES_USART_CFG_H_ */

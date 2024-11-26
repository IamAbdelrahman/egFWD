/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: GPIO.h
 * 	@brief The interface definition for the GPIO.
 *
 *	@details: This is the header file for the definition of the interface
 *      for a GPIO peripheral on a standard microcontroller.
 *****************************************************************************/

#ifndef INCLUDES_GPIO_H_
#define INCLUDES_GPIO_H_

/*- INCLUDES
 -----------------------------------------------------------------------*/
#include "GPIO_Cfg.h"

/*- GLOBAL MACROS
 -----------------------------------------------------------------------*/
/*- USED PINS ACCORDING TO THE APPLICATION */
#define NUMBER_OF_USED_PINS (12UL)

#define TYPE vuint8_t

/*- APIs PROTOTYPES
 -----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: GPIO_Init
 * Syntax: void GPIO_Init(const ST_GPIOConfig_t *configPtr)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Initialize the GPIO based on the config table defined in
 * GPIO_Cfg
 * PRE-CONDITION: Config table needs to populated (configGpio > 0)
 * PRE-CONDITION: NUMBER_OF_PORTS > 0 && NUMBER_OF_PINS_PER_PORT > 0
 * PRE-CONDITION: The MCU clock must be configured and enabled
 * POST-CONDITION: The GPIO is initialized and set up with the defined
 *configuration
 * @param (in): configPtr a pointer to GPIO_Config struct
 * @param (in): configSize represents how many pins are configured
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void GPIO_Init(const ST_GPIOConfig_t *const configPtr, vuint8_t configSize);

/************************************************************************
 * Service Name: GPIO_PinRead
 * Syntax: EN_PIN_STATE_t GPIO_PinRead(EN_GPIOX_t portNumber, EN_GPIO_PIN_t
 * pinNumber)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Read the state of a GPIO channel (pin)
 * PRE-CONDITION: The GPIO is configured and initialized
 * POST-CONDITION: The channel (pin) state is returned
 * @param (in): portNumber to be set by the user
 * @param (in): pinNumber to be set by the user
 * @param (inout): None
 * @param (out): None
 * @return: EN_PIN_STATE_t an enum state is returned
 *************************************************************************/
EN_PIN_STATE_t GPIO_PinRead(EN_GPIOX_t portNumber, EN_GPIO_PIN_t pinNumber);

/************************************************************************
 * Service Name: GPIO_PinWrite
 * Syntax: void GPIO_PinWrite(EN_GPIOX_t portNumber, EN_GPIO_PIN_t pinNumber,
 * EN_PIN_STATE_t state)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Write the state of a GPIO channel (pin) as either logic high or
 *low PRE-CONDITION: The GPIO is configured and initialized POST-CONDITION: The
 *channel (pin) has a logic level (1 or 0)
 * @param (in): portNumber to be set by the user
 * @param (in): pinNumber to be set by the user
 * @param (in): pinState the pin level as either logic high or low
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void GPIO_PinWrite(EN_GPIOX_t portNumber, EN_GPIO_PIN_t pinNumber,
                   EN_PIN_STATE_t pinState);

/************************************************************************
 * Service Name: GPIO_PinToggle
 * Syntax: void GPIO_PinToggle(EN_GPIOX_t portNumber, EN_GPIO_PIN_t pinNumber)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Toggle the state of a channel (pin) as either logic high or low
 * PRE-CONDITION: The GPIO is configured and initialized
 * POST-CONDITION: The channel (pin) changes its logic level
 * @param (in): port number to be set by the user
 * @param (in): pinNumber to be set by the user
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void GPIO_PinToggle(EN_GPIOX_t portNumber, EN_GPIO_PIN_t pinNumber);

/************************************************************************
 * Service Name: GPIO_Reset
 * Syntax: void GPIO_Reset(EN_GPIOX_t portNumber)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Reset all the GPIO registers
 * PRE-CONDITION: The GPIO is configured and initialized
 * POST-CONDITION: The GPIO registers are reset
 * @param (in): portNumber to be set by the user
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void GPIO_Reset(EN_GPIOX_t portNumber);

/************************************************************************
 * Service Name: GPIO_PortRead
 * Syntax: vuint16_t GPIO_PortRead(EN_GPIOX_t portNumber)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Read the IDR register in the GPIO
 * PRE-CONDITION: The GPIO is configured and initialized
 * POST-CONDITION: The IDR register content is returned
 * @param (in): portNumber to be set by the user
 * @param (inout): None
 * @param (out): None
 * @return: volatile unsigned int
 *************************************************************************/
vuint8_t GPIO_PortRead(EN_GPIOX_t portNumber);

/************************************************************************
 * Service Name: GPIO_PortWrite
 * Syntax: void GPIO_PortWrite(EN_GPIOX_t portNumber, vuint16_t portValue)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Write to the ODR register in the GPIO
 * PRE-CONDITION: The GPIO is configured and initialized
 * POST-CONDITION: The ODR register in the GPIO has a new value
 * @param (in): portNumber to be set by the user
 * @param (in): portValue is the value to be set by the user
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void GPIO_PortWrite(EN_GPIOX_t portNumber, vuint16_t portValue);

#endif /* INCLUDES_GPIO_H_ */

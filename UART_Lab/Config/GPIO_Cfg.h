/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: GPIO_Cfg.h
 *	@brief This module contains interface definitions for the
 *	GPIO configuration related to the ATmega32 MCU.
 *
 *	@details: This is the header file for the definition of the
 *	interface for retrieving the GPIO configuration table.
 *****************************************************************************/

#ifndef INCLUDES_GPIO_CFG_H_
#define INCLUDES_GPIO_CFG_H_

/*- INCLUDES
 -----------------------------------------------------------------------*/
#include "ATmega32.h"

/*- GLOBAL MACROS
 -----------------------------------------------------------------------*/
/*- NUMBER OF PORTS IN THIS PACKAGE */
#define NUMBER_OF_PORTS (4UL)

/*- NUMBER OF PINS PER PORT */
#define NUMBER_OF_PINS_PER_PORT (8U)

/*- SFIOR REGISTER PUD BIT NO */
#define PUD (2U)

/*- GPIO PINS CONFIGURATION */
#define GPIOA0                                                                 \
  (ST_GPIOConfig_t) { PORTA, Pin0, GPIO_OUTPUT }
#define GPIOA1                                                                 \
  (ST_GPIOConfig_t) { PORTA, Pin1, GPIO_OUTPUT }
#define GPIOA2                                                                 \
  (ST_GPIOConfig_t) { PORTA, Pin2, GPIO_OUTPUT }
#define GPIOA3                                                                 \
  (ST_GPIOConfig_t) { PORTA, Pin3, GPIO_OUTPUT }
#define GPIOA4                                                                 \
  (ST_GPIOConfig_t) { PORTA, Pin4, GPIO_OUTPUT }
#define GPIOA5                                                                 \
  (ST_GPIOConfig_t) { PORTA, Pin5, GPIO_OUTPUT }
#define GPIOA6                                                                 \
  (ST_GPIOConfig_t) { PORTA, Pin6, GPIO_OUTPUT }
#define GPIOA7                                                                 \
  (ST_GPIOConfig_t) { PORTA, Pin7, GPIO_OUTPUT }
#define GPIOB0                                                                 \
  (ST_GPIOConfig_t) { PORTB, Pin0, GPIO_OUTPUT }
#define GPIOB1                                                                 \
  (ST_GPIOConfig_t) { PORTB, Pin1, GPIO_OUTPUT }
#define GPIOB2                                                                 \
  (ST_GPIOConfig_t) { PORTB, Pin2, GPIO_OUTPUT }
#define GPIOB3                                                                 \
  (ST_GPIOConfig_t) { PORTB, Pin3, GPIO_OUTPUT }
#define GPIOB4                                                                 \
  (ST_GPIOConfig_t) { PORTB, Pin4, GPIO_INPUT_FLOATING }
#define GPIOB5                                                                 \
  (ST_GPIOConfig_t) { PORTB, Pin5, GPIO_INPUT_FLOATING }
#define GPIOB6                                                                 \
  (ST_GPIOConfig_t) { PORTB, Pin6, GPIO_INPUT_FLOATING }
#define GPIOB7                                                                 \
  (ST_GPIOConfig_t) { PORTB, Pin7, GPIO_INPUT_FLOATING }
#define GPIOC0                                                                 \
  (ST_GPIOConfig_t) { PORTC, Pin0, GPIO_OUTPUT }
#define GPIOC1                                                                 \
  (ST_GPIOConfig_t) { PORTC, Pin1, GPIO_INPUT_FLOATING }
#define GPIOC2                                                                 \
  (ST_GPIOConfig_t) { PORTC, Pin2, GPIO_INPUT_FLOATING }
#define GPIOC3                                                                 \
  (ST_GPIOConfig_t) { PORTC, Pin3, GPIO_INPUT_FLOATING }
#define GPIOC4                                                                 \
  (ST_GPIOConfig_t) { PORTC, Pin4, GPIO_INPUT_FLOATING }
#define GPIOC5                                                                 \
  (ST_GPIOConfig_t) { PORTC, Pin5, GPIO_INPUT_FLOATING }
#define GPIOC6                                                                 \
  (ST_GPIOConfig_t) { PORTC, Pin6, GPIO_INPUT_FLOATING }
#define GPIOC7                                                                 \
  (ST_GPIOConfig_t) { PORTC, Pin7, GPIO_INPUT_FLOATING }
#define GPIOD0                                                                 \
  (ST_GPIOConfig_t) { PORTD, Pin0, GPIO_INPUT_FLOATING }
#define GPIOD1                                                                 \
  (ST_GPIOConfig_t) { PORTD, Pin1, GPIO_OUTPUT }
#define GPIOD2                                                                 \
  (ST_GPIOConfig_t) { PORTD, Pin2, GPIO_INPUT_FLOATING }
#define GPIOD3                                                                 \
  (ST_GPIOConfig_t) { PORTD, Pin3, GPIO_INPUT_FLOATING }
#define GPIOD4                                                                 \
  (ST_GPIOConfig_t) { PORTD, Pin4, GPIO_INPUT_FLOATING }
#define GPIOD5                                                                 \
  (ST_GPIOConfig_t) { PORTD, Pin5, GPIO_INPUT_FLOATING }
#define GPIOD6                                                                 \
  (ST_GPIOConfig_t) { PORTD, Pin6, GPIO_INPUT_FLOATING }
#define GPIOD7                                                                 \
  (ST_GPIOConfig_t) { PORTD, Pin7, GPIO_INPUT_FLOATING }

/*- GLOBAL TYPEDEFS
 -----------------------------------------------------------------------*/
/*- GPIO PORTS */
typedef enum {
  PORTA = 0,
  PORTB,
  PORTC,
  PORTD,
} EN_GPIOX_t;

/*- GPIO PINS STATE */
typedef enum {
  GPIO_INPUT_FLOATING,
  GPIO_INPUT_PULLUP,
  GPIO_OUTPUT
} EN_GPIO_PIN_STATE_t;

/*- GPIO PINS NUMBERS */
typedef enum {
  Pin0 = 0,
  Pin1,
  Pin2,
  Pin3,
  Pin4,
  Pin5,
  Pin6,
  Pin7 = 7
} EN_GPIO_PIN_t;

/*- PIN LEVEL */
typedef enum { LOW = 0, HIGH, TOGGLE } EN_PIN_STATE_t;

/*- GPIO CONFIGURATION */
typedef struct {
  EN_GPIOX_t portNumber;
  EN_GPIO_PIN_t pinNumber;
  EN_GPIO_PIN_STATE_t pinState;
} ST_GPIOConfig_t;

/*- APIs PROTOTYPES
 -----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: GPIO_ConfigGet
 * Syntax: const ST_GPIOConfig_t* const GPIO_ConfigGet(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: A helper function to initialize the GPIO based on a config
 * table.
 * PRE-CONDITION: Config table needs to populated (configGpio > 0)
 * PRE-CONDITION: NUMBER_OF_PORTS > 0 && NUMBER_OF_PINS_PER_PORT > 0
 * PRE-CONDITION: The MCU clock must be configured and enabled
 * POST-CONDITION: A const pointer to the first member of the config table is
 * returned
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: const ST_GPIOConfig_t* const
 *************************************************************************/
const ST_GPIOConfig_t *const GPIO_ConfigGet(void);

#endif /* INCLUDES_GPIO_CFG_H_ */
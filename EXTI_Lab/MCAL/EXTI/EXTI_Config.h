/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file EXTI_Config.h
 * @brief This module contains interface definitions for the
 *  EXTI configuration related to the LQFP48 package.
 *
 * This is the header file for the definition of the
 * interface for retrieving the external interrupt peripheral configuration
 * table
 * @author Abdelrahman Kamal
 *
 */
#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/**********************************************************************
 * Includes
 **********************************************************************/
#include "GPIO_Config.h"

/**********************************************************************
 * Typedefs
 **********************************************************************/
/**
 * Defines an enumerated list of all the External Interrupts
 * in ATmega32 MCU.
 */
typedef enum { INT0, INT1, INT2 } EN_IRQ_t;

typedef enum { LOW_STATE, RISING, FALLING, RISING_FALLING } EN_EXTI_Trigger_t;

typedef enum { IRQ_DISABLE, IRQ_ENABLE } EN_EXTI_IRQ_State_t;

typedef struct {
  EN_GPIOX_t EXTI_Port;
  EN_GPIOPin_t EXTI_Pin;
  vuint8_t EXTI_Input_Number;
  EN_IRQ_t IRQ_Number;
  void (*CallbackFunction)(void);
} ST_EXTI_Mapping_t;

typedef struct {
  ST_EXTI_Mapping_t EXTI_PIN;
  EN_EXTI_Trigger_t EXTI_Trigger;
  EN_EXTI_IRQ_State_t EXTI_IRQ;
} ST_EXTI_PINConfig_t;

/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/
#define EXTI0 	0U
#define EXTI1 	1U
#define EXTI2 	2U

// @ref EXTI_PIN
// EXTI0
#define EXTI0PD2                                                               \
  (ST_EXTI_Mapping_t) { PORTD, Pin2, EXTI0, INT0 }

// EXTI1
#define EXTI1PD3                                                               \
  (ST_EXTI_Mapping_t) { PORTD, Pin3, EXTI1, INT1 }

// EXTI2
#define EXTI2PB2                                                               \
  (ST_EXTI_Mapping_t) { PORTB, Pin2, EXTI2, INT2 }

// EXTI_Cfg
#define EXTI0_CFG                                                              \
  (ST_GPIOConfig_t) { PORTD, Pin2, GPIO_INPUT_FLOATING }
#define EXTI1_CFG                                                              \
  (ST_GPIOConfig_t) { PORTD, Pin3, GPIO_INPUT_FLOATING }
#define EXTI2_CFG                                                              \
  (ST_GPIOConfig_t) { PORTB, Pin2, GPIO_INPUT_FLOATING }

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
const ST_GPIOConfig_t *const EXTI_ConfigGet(void);

#endif /* EXTI_CONFIG_H_ */

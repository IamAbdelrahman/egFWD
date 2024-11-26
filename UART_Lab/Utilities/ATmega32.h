/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file ATmega32.h
 * @brief This header file Header specifies the MCU device header
 *
 * The file defines generic macros and base addresses for memories, peripheral
 * registers and bus peripheral
 * @author Abdelrahman Kamal
 *
 */

#ifndef ATMEGA32_H
#define ATMEGA32_H

/*- INCLUDES
 -----------------------------------------------------------------------*/
#include "Macros.h"
#include "Platform_Types.h"
#include <util/delay.h>

/*- GLOBAL MACROS
 -----------------------------------------------------------------------*/
#define F_CPU 8000000UL // 8 MHz
/*- PERIPHERALS BASE ADDRESSES */
#define GPIOA_BASE 0x39U
#define GPIOB_BASE 0x36U
#define GPIOC_BASE 0x33U
#define GPIOD_BASE 0x30U
#define EXTI_BASE 0x54U
#define GIC_BASE 0x5AU
#define USART_BASE 0x2AU
#define UBRRL (*((vuint8_t *)0x29U))
#define UBRRH (*((vuint8_t *)0x40U))
#define SFIOR (*((vuint8_t *)0x50U))
#define SREG (*((vuint8_t *)0x5FU))

/*- PERIPHERALS INSTANCES */
#define GPIOA (ST_GPIO_t *)(GPIOA_BASE)
#define GPIOB (ST_GPIO_t *)(GPIOB_BASE)
#define GPIOC (ST_GPIO_t *)(GPIOC_BASE)
#define GPIOD (ST_GPIO_t *)(GPIOD_BASE)
#define EXTI (ST_EXTI_t *)(EXTI_BASE)
#define GIC (ST_GIC_t *)(GIC_BASE)
#define USART (ST_USART_t *)(USART_BASE)

/*- GLOBAL TYPEDEFS
 -----------------------------------------------------------------------*/
/*- Peripheral register: GPIO */
typedef struct {
  vuint8_t PIN;
  vuint8_t DDR;
  vuint8_t PORT;
} ST_GPIO_t;

/*- Peripheral register: GIC */
typedef struct {
  vuint8_t GIFR;
  vuint8_t GICR;
} ST_GIC_t;

/*- Peripheral register: EXTI */
typedef struct {
  vuint8_t MCUCSR;
  vuint8_t MCUCR;
} ST_EXTI_t;

/*- Peripheral register: USART */
typedef struct {
  vuint8_t UCSRB;
  vuint8_t UCSRA;
  vuint8_t UDR;
  vuint8_t RESERVED[19];
  vuint8_t UCSRC;
} ST_USART_t;

/**************************************/
#endif /* ATMEGA32_H */
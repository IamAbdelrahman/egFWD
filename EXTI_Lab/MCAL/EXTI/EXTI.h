/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file EXTI.h
 * @brief The interface definition for the EXTI
 *
 * This is the header file for the definition of the interface for a EXTI
 * peripheral on a standard microcontroller.
 * @author Abdelrahman Kamal
 *
 */

#ifndef EXTI_H_
#define EXTI_H_
/**********************************************************************
 * Includes
 **********************************************************************/
#include "EXTI_Config.h"
/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/
/* Set Global Interrupt, Set the I-bit in status register to 1 */
#define sei() 		__asm__ __volatile__("sei" ::: "memory")

/* Clear Global Interrupt, Set the I-bit in status register to 0 */
#define cli() 		__asm__ __volatile__("cli" ::: "memory")

/* ISR definition */
#define ISR(INT_VECT)                                                          \
  void INT_VECT(void) 	__attribute__((signal, used));                           \
  void INT_VECT(void)

#define INT0_VECT 	__vector_1
#define INT1_VECT 	__vector_2
#define INT2_VECT 	__vector_3
/**********************************************************************
 * Typedefs
 **********************************************************************/

/**
 * Define an enumerated table of MCUCR bits
 */
typedef enum { ISC00, ISC01, ISC10, ISC11, SM0, SM1, SM2, SE } EN_MCUCR_t;

/**
 * Define an enumerated table of MCUCR bits
 */
typedef enum {
  PORF,
  EXTRF,
  BORF,
  WDRF,
  JTRF,
  ISC2 = 6,
  JTD,
} EN_MCUCSR_t;

/**
 * Define an enumerated table of GICR bits
 */
typedef enum { IVCE, IVSEL, INTE2 = 5, INTE0, INTE1 } EN_GICR_t;

/**
 * Define an enumerated table of GIFR bits
 */
typedef enum { INTF2 = 5, INTF0, INTF1 } EN_GIFR_t;
/**********************************************************************
 * Function Prototypes
 **********************************************************************/
void GIC_enableIRQ(void);
void GIC_disableIRQ(void);
void GIC_clearPendingIRQ(EN_IRQ_t IRQn);
void EXTI_Init(ST_EXTI_PINConfig_t *EXTI_Config);
void EXTI_Update(ST_EXTI_PINConfig_t *EXTI_Config);
void EXTI_Reset(void);

#endif /* EXTI_H_ */

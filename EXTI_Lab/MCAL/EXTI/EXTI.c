/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file EXTI.c
 * @brief The implementation for the EXTI peripheral.
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "EXTI.h"

/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/
/**********************************************************************
 * Typedefs
 **********************************************************************/

/**********************************************************************
 * Module Variables
 **********************************************************************/
/**
 * Define const pointers to EXTI and GIC registers
 */
ST_EXTI_t *const pEXTI = EXTI;
ST_GIC_t *const pGIC = GIC;

/**
 * Declare the EXTI_ConfigSize
 */
extern vuint32_t EXTI_ConfigSize;
/**
 * Declare an array of 3 global pointers to function
 * takes void and returns void.
 */
void (*gPf_IRQ_Callback[3])(void);

/**********************************************************************
 * Function Definitions
 **********************************************************************/

/**********************************************************************
 * Function :GIC_enableIRQ()
 *
 * Description:
 *
 * This function is used to enable an interrupt signal
 * @param void
 * @return void
 **********************************************************************/
inline void GIC_enableIRQ(void) { sei(); }

/**********************************************************************
 * Function :GIC_disableIRQ()
 *
 * Description:
 *
 * This function is used to disable an interrupt signal
 * @param  void
 * @return void
 **********************************************************************/
inline void GIC_disableIRQ(void) { cli(); }

void GIC_clearPendingIRQ(EN_IRQ_t IRQn) {
  switch (IRQn) {
  case INT0:
    SET_BIT(pGIC->GIFR, INTF0);
    break;
  case INT1:
    SET_BIT(pGIC->GIFR, INTF1);
    break;
  case INT2:
    SET_BIT(pGIC->GIFR, INTF2);
    break;
  default:
    break;
  }
}

/**********************************************************************
 * Function :EXTI_Init()
 *
 * Description:
 *
 * This function is used to initialize the EXTI peripheral through:-
 * a) specifing/configuring the port number and pin number as input floating 
 * b) clearing all trigger state in MCUCR and MCUCSR registers
 * c) checking for each type of external interrupt, then check for the trigger
 * state to select it. 
 * d) initializing the global pointer to function with the
 * EXTI_Input_Number as an index with the matched address of the callback
 * function. 
 * f) enable/disable the interrupt in the GICR register and the
 * global interrupt too.
 *
 * PRE-CONDITION: EXTI is configured.
 *
 * POST-CONDITION: The EXTI peripheral is set up with the configuration settings
 * and is initialized.
 *
 * @param EXTI_Config is a pointer to the EXTI_PINConfig structure.
 *
 * @return void
 **********************************************************************/
void EXTI_Init(ST_EXTI_PINConfig_t *EXTI_Config) {
  const ST_GPIOConfig_t *const pConfig_EXTI = EXTI_ConfigGet();
  GPIO_Init(pConfig_EXTI);

  vuint8_t i = 0, PortNumber = 0, PinNumber = 0;
  for (i = 0; i < EXTI_ConfigSize; i++) {
    PortNumber = pConfig_EXTI[i].Port % NUMBER_OF_PORTS;
    PinNumber = pConfig_EXTI[i].Pin % NUMBER_OF_PINS_PER_PORT;
    EXTI_Config->EXTI_PIN.EXTI_Port = PortNumber;
    EXTI_Config->EXTI_PIN.EXTI_Pin = PinNumber;

    CLR_NIBBLE(pEXTI->MCUCR, ISC00);
    CLR_BIT(pEXTI->MCUCSR, ISC2);

    if (EXTI_Config->EXTI_PIN.IRQ_Number == INT0) {
      if (EXTI_Config->EXTI_Trigger == RISING) {
        SET_BIT(pEXTI->MCUCR, ISC00);
        SET_BIT(pEXTI->MCUCR, ISC01);
      } else if (EXTI_Config->EXTI_Trigger == FALLING) {
        CLR_BIT(pEXTI->MCUCR, ISC00);
        SET_BIT(pEXTI->MCUCR, ISC01);
      } else if (EXTI_Config->EXTI_Trigger == RISING_FALLING) {
        SET_BIT(pEXTI->MCUCR, ISC00);
        CLR_BIT(pEXTI->MCUCR, ISC01);
      } else if (EXTI_Config->EXTI_Trigger == LOW_STATE) {
        CLR_BIT(pEXTI->MCUCR, ISC00);
        CLR_BIT(pEXTI->MCUCR, ISC01);
      }
      if (EXTI_Config->EXTI_IRQ == IRQ_ENABLE) {
        SET_BIT(pGIC->GICR, INTE0);
        GIC_enableIRQ();
      } else if (EXTI_Config->EXTI_IRQ == IRQ_DISABLE) {
        CLR_BIT(pGIC->GICR, INTE0);
        GIC_disableIRQ();
      }
    }

    else if (EXTI_Config->EXTI_PIN.IRQ_Number == INT1) {
      if (EXTI_Config->EXTI_Trigger == RISING) {
        SET_BIT(pEXTI->MCUCR, ISC10);
        SET_BIT(pEXTI->MCUCR, ISC11);
      } else if (EXTI_Config->EXTI_Trigger == FALLING) {
        CLR_BIT(pEXTI->MCUCR, ISC10);
        SET_BIT(pEXTI->MCUCR, ISC11);
      } else if (EXTI_Config->EXTI_Trigger == RISING_FALLING) {
        SET_BIT(pEXTI->MCUCR, ISC10);
        CLR_BIT(pEXTI->MCUCR, ISC11);
      } else if (EXTI_Config->EXTI_Trigger == LOW_STATE) {
        CLR_BIT(pEXTI->MCUCR, ISC10);
        CLR_BIT(pEXTI->MCUCR, ISC11);
      }
      if (EXTI_Config->EXTI_IRQ == IRQ_ENABLE) {
        SET_BIT(pGIC->GICR, INTE1);
        GIC_enableIRQ();
      } else if (EXTI_Config->EXTI_IRQ == IRQ_DISABLE) {
        CLR_BIT(pGIC->GICR, INTE1);
        GIC_disableIRQ();
      }
    }

    else if (EXTI_Config->EXTI_PIN.IRQ_Number == INT2) {
      if (EXTI_Config->EXTI_Trigger == RISING) {
        SET_BIT(pEXTI->MCUCSR, ISC2);
      } else if (EXTI_Config->EXTI_Trigger == FALLING) {
        CLR_BIT(pEXTI->MCUCSR, ISC2);
      }
      if (EXTI_Config->EXTI_IRQ == IRQ_ENABLE) {
        SET_BIT(pGIC->GICR, INTE2);
        GIC_enableIRQ();
      } else if (EXTI_Config->EXTI_IRQ == IRQ_DISABLE) {
        CLR_BIT(pGIC->GICR, INTE2);
        GIC_disableIRQ();
      }
    }

    gPf_IRQ_Callback[EXTI_Config->EXTI_PIN.EXTI_Input_Number] =
        EXTI_Config->EXTI_PIN.CallbackFunction;
  }
}

/**********************************************************************
 * Function :EXTI_Update()
 *
 * Description:
 *
 * This function is used to update the states of the EXTI peripheral.
 *
 * PRE-CONDITION: EXTI is configured and initialized
 *
 * POST-CONDITION: The EXTI peripheral is set up with the configuration and is
 *initiailized. settings.
 * @param EXTI_Config is a pointer to the EXTI_PINConfig structure.
 *
 * @return void
 **********************************************************************/
void EXTI_Update(ST_EXTI_PINConfig_t *EXTI_Config) { EXTI_Init(EXTI_Config); }

/**********************************************************************
 * Function :EXTI_Reset()
 *
 * Description:
 *
 * This function is used to reset the EXTI peripheral
 *
 * PRE-CONDITION: EXTI is configured and initialized
 *
 * POST-CONDITION: The EXTI peripheral is reset.
 * @param void
 *
 * @return void
 **********************************************************************/
void EXTI_Reset(void) {
  GIC_disableIRQ();
  CLR_BIT(pGIC->GICR, INTE0);
  CLR_BIT(pGIC->GICR, INTE1);
  CLR_BIT(pGIC->GICR, INTE2);
  CLR_NIBBLE(pEXTI->MCUCR, ISC00);
  CLR_BIT(pEXTI->MCUCSR, ISC2);
}

ISR(INT0_VECT) {
  SET_BIT(pGIC->GIFR, INTF0);
  gPf_IRQ_Callback[0]();
}

ISR(INT1_VECT) {
  SET_BIT(pGIC->GIFR, INTF1);
  gPf_IRQ_Callback[1]();
}

ISR(INT2_VECT) {
  SET_BIT(pGIC->GIFR, INTF2);
  gPf_IRQ_Callback[2]();
}

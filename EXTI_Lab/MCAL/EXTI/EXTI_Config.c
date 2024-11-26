
/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file EXTI.Config.c
 * @brief This module contains the implementation for the EXTI peripheral
 * configuration
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "EXTI_Config.h"

/**********************************************************************
 * Module Variable Definitions
 **********************************************************************/
/**
 * The following array contains the configuration data for each GPIO peripheral
 * pin. Each row represents a single pin. Each column is representing a member
 * of the GPIOConfig_t structure. This table is read in by EXIT_Init(), where
 * each pin is then set up based on this table.
 */
const ST_GPIOConfig_t EXTIConfig[] = {EXTI0_CFG, EXTI1_CFG, EXTI2_CFG};

vuint32_t EXTI_ConfigSize = sizeof(EXTIConfig) / sizeof(EXTIConfig[0]);
/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function : EXTI_ConfigGet()
 *
 * This function is used to initialize the EXTI based on the configuration
 * table defined in gpio_cfg module.
 *
 * PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
 * PRE-CONDITION: NUMBER_OF_PINS_PER_PORT > 0
 * PRE-CONDITION: NUMBER_OF_PORTS > 0
 * PRE-CONDITION: The MCU clocks must be configured and enabled.
 *
 * POST-CONDITION: A constant pointer to the first member of the
 * configuration table will be returned.
 *
 ** @return A pointer to the configuration table.

 **********************************************************************/
const ST_GPIOConfig_t *const EXTI_ConfigGet(void) {
  return (ST_GPIOConfig_t *const) & EXTIConfig[0];
}

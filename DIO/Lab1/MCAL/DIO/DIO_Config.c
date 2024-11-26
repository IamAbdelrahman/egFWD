/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file DIO_Config.c
 * @brief This module contains the implementation for the DIO peripheral configuration
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "DIO_Config.h"

/**********************************************************************
 * Module Variable Definitions
 **********************************************************************/
/**
 * The following array contains the configuration data for each GPIO peripheral pin.
 * Each row represents a single pin. Each column is representing a member of the GpioConfig_t structure.
 * This table is read in by DIO_Init(), where each pin is then set up based on this table.
 */
const DIOConfig_t DIOConfig[] = {
/*   PORT            PIN					STATE			*/
    {PORTA,         Pin4,               DIO_OUTPUT},
    {PORTB,         Pin0,               DIO_OUTPUT}
};

vuint32_t ConfigSize = sizeof(DIOConfig) / sizeof(DIOConfig[0]);
/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function : Dio_ConfigGet()
 *
 * This function is used to initialize the DIO based on the configuration
 * table defined in dio_config module.
 *
 * PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
 *
 * POST-CONDITION: A constant pointer to the first member of the
 * configuration table will be returned.
 *
 ** @return A pointer to the configuration table.

 **********************************************************************/
const DIOConfig_t * const DIO_ConfigGet(void) {
	return (DIOConfig_t *const)&DIOConfig[0];
}



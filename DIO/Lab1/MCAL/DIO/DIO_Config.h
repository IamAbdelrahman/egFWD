/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file DIO_Config.h
 * @brief This module contains interface definitions for the
 *  DIO configuration related to the ATmega32 MCU.
 *
 * This is the header file for the definition of the
 *  interface for retrieving the descriptive input/output configuration table
 * @author Abdelrahman Kamal
 *
 */
#ifndef DIO_CONFIG_H
#define	DIO_CONFIG_H

#include "ATmega32.h"
/**********************************************************************
 * Preprocessor Constants
 **********************************************************************/
/**
 * Defines the number of pins on each processor port.
 */
#define NUMBER_OF_PINS_PER_PORT 8U

/**
 * Defines the number of ports on this processor's package.
 */
#define NUMBER_OF_PORTS 		2U

/** PUD bit in SFIOR register **/
#define PUD                     2U
/**********************************************************************
 * Typedefs
 **********************************************************************/

/**
 * Defines an enumerated list of all the ports on the MCU
 * device.
 */
typedef enum {
    PORTA = 0, PORTB
} DIOPORTX_t;

/**
 * Defines the possible states for a digital I/O pin.
 */
typedef enum {
    DIO_INPUT_FLOATING,
    DIO_INPUT_PULLUP,
    DIO_OUTPUT
} DIOPinState_t;

/**
 * Defines an enumerated list of all the channels (pins) on the MCU
 * device.
 */
typedef enum {
    /** DIO Pins */
    Pin0 = 0,
    Pin1,
    Pin2,
    Pin3,
    Pin4,
    Pin5,
    Pin6,
    Pin7 = 7
} DIOPin_t;

/**
 * Defines DIO configuration table?s elements that are
 used by DIO_Init() to configure the DIO peripheral.
 */
typedef struct {
    DIOPORTX_t Port;
    DIOPin_t Pin;
    DIOPinState_t State;
} DIOConfig_t;

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
const DIOConfig_t * const DIO_ConfigGet(void);


#endif	/* DIO_CONFIG_H */


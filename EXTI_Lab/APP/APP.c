/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: APP.c
 *	@brief The implementation of the application driver
 *  @description: Using an external interrupt to control LEDs
 *
 *****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "APP.h"

/*- LOCAL MACROS
-----------------------------------------------------------------------*/
#define LED_STATES  (4U)

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
vuint8_t ledCount = 0;
ST_LEDConfig_t* pLED;

/*- GLOBAL EXTERN VARIABLES
-----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------*/
void EXTI0_ISR (void);

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/
void EXTI0_ISR (void) {
    ledCount = (++ledCount) % LED_STATES;
}

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
void APP_Init(void) {
    EXTI_ConfigGet()->CallbackFunction = EXTI0_ISR;
    EXTI_Init(EXTI_ConfigGet());
    LED_Init();
    BUTTON_Init();
    pLED = LED_ConfigGet();
}

void APP_Start(void) {
    vuint8_t i = 0;
    switch (ledCount) {
        /* LEDs are off */
        case 0:
            for (i = 0; i < LEDS; i++) {
                pLED[i].ledState = LOW;
                LED_Control(&pLED[i]);
            }
            break;
        /* LED1 is on */
        case 1:
            pLED[0].ledState = HIGH;
            LED_Control(&pLED[0]);
            break;
        /* LED2 is on */
        case 2:
            pLED[1].ledState = HIGH;
            LED_Control(&pLED[1]);
            break;
        /* LED3 is on */
        case 3:
            pLED[2].ledState = HIGH;
            LED_Control(&pLED[2]);
            break;
        default:
            break;
    }
}
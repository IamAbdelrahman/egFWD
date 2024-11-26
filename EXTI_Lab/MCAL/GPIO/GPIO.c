/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: GPIO.c
 *	@brief The implementation for the GPIO.
 *
 *****************************************************************************/

/*- INCLUDES
 -----------------------------------------------------------------------*/
#include "GPIO.h"

/*- LOCAL MACROS
 -----------------------------------------------------------------------*/

/*- GLOBAL STATIC VARIABLES
 -----------------------------------------------------------------------*/
static vuint8_t Flag = true;

/*- GLOBAL VARIABLES
 -----------------------------------------------------------------------*/
/*- DEFINE AN ARRAY OF GPIO INSTANCES */
const ST_GPIO_t *const GPIOx[NUMBER_OF_PORTS] = {GPIOA, GPIOB, GPIOC, GPIOD};

/*- DEFINE A TABLE OF POINTER TO THE INPUT PINS ADDRESS REGISTER */
TYPE volatile *dataIn[NUMBER_OF_PORTS];

/*- DEFINE A TABLE OF POINTER TO THE DATA REGISTER */
TYPE volatile *Data[NUMBER_OF_PORTS];

/*- DEFINE A TABLE OF POINTER TO THE DATA DIRECTION REGISTER */
TYPE volatile *dataDir[NUMBER_OF_PORTS];

/*- GLOBAL EXTERN VARIABLES
-----------------------------------------------------------------------*/
extern vuint32_t configSizeGpio;

/*- LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------*/
void InitArrays(void);
static inline void NOP(void);

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/
void InitArrays(void) {
  for (int i = 0; i < NUMBER_OF_PORTS; ++i) {
    Data[i] = (TYPE *)&GPIOx[i]->PORT;
    dataDir[i] = (TYPE *)&GPIOx[i]->DDR;
    dataIn[i] = (TYPE *)&GPIOx[i]->PIN;
  }
  Flag = false;
}

static inline void NOP(void) { ; };

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
void GPIO_Init(const ST_GPIOConfig_t *const configPtr, vuint8_t configSize) {
  if (Flag)
    InitArrays();
  vuint8_t i = 0, portNum = 0, pinNum = 0;
  for (i = 0; i < configSize; i++) {
    portNum = configPtr[i].portNumber % NUMBER_OF_PORTS;
    pinNum = configPtr[i].pinNumber % NUMBER_OF_PINS_PER_PORT;
    if (configPtr[i].pinState == GPIO_INPUT_FLOATING) {
      CLR_BIT(*(dataDir[portNum]), pinNum);
      CLR_BIT(*(Data[portNum]), pinNum);
    } else if (configPtr[i].pinState == GPIO_INPUT_PULLUP) {
      CLR_BIT(SFIOR, PUD);
      CLR_BIT(*(dataDir[portNum]), pinNum);
      SET_BIT(*(Data[portNum]), pinNum);
    } else if (configPtr[i].pinState == GPIO_OUTPUT) {
      SET_BIT(*(dataDir[portNum]), pinNum);
    }
  }
}

EN_PIN_STATE_t GPIO_PinRead(EN_GPIOX_t portNumber, EN_GPIO_PIN_t pinNumber) {
  return (READ_BIT(*(dataIn[portNumber]), pinNumber));
}

void GPIO_PinWrite(EN_GPIOX_t portNumber, EN_GPIO_PIN_t pinNumber,
                   EN_PIN_STATE_t pinState) {
  if (pinState == HIGH) {
    SET_BIT(*(Data[portNumber]), pinNumber);
  } else if (pinState == LOW) {
    CLR_BIT(*(Data[portNumber]), pinNumber);
  }
}

void GPIO_PinToggle(EN_GPIOX_t portNumber, EN_GPIO_PIN_t pinNumber) {
  TOGGLE_BIT(*(Data[portNumber]), pinNumber);
}

void GPIO_Reset(EN_GPIOX_t portNumber) {
  *(Data[portNumber]) = 0x00;
  *(dataDir[portNumber]) = 0x00;
}

vuint8_t GPIO_PortRead(EN_GPIOX_t portNumber) {
  return (vuint8_t)(*dataIn[portNumber]);
}

void GPIO_PortWrite(EN_GPIOX_t portNumber, vuint16_t portValue) {
  *(Data[portNumber]) = portValue;
}
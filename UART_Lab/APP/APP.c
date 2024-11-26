/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: APP.c
 *	@brief The implementation of the application driver
 *  @description: A simple echo-application provided by egFWD scholarship
 *
 *****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "APP.h"

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
vuint16_t data;

/*- GLOBAL EXTERN VARIABLES
-----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
void APP_Init(void) {
    UART_Init(UART_ConfigGet());
    LCD_Init();
}

void APP_Start(void) {
    UART_ReceiveData(&data);
    LCD_WriteChar((vuint8_t)data);
    UART_SendData(&data);
}
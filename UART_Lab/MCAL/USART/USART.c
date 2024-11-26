/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: USART.c
 *	@brief The implementation for the USART peripheral
 *
 *****************************************************************************/

/*- INCLUDES
 -----------------------------------------------------------------------*/
#include "USART.h"
#include "EXTI.h"

/*- LOCAL MACROS
 -----------------------------------------------------------------------*/
#define USARTDIV(Fosc, Baud) (((Fosc) / (16.0F * Baud)) - 1)

/*- GLOBAL VARIABLES
 -----------------------------------------------------------------------*/
void (*gPf_IRQ_Callback_Usart)(void) = NULL;

typedef struct {
  vuint8_t payLoad_9 : 1;
  vuint8_t pollingTx : 1;
  vuint8_t pollingRx : 1;
  vuint8_t Parity : 1;
} ST_Flags_t;

ST_Flags_t Flag = {0U, 0U, 0U, 0U};

/*- GLOBAL STATIC VARIABLES
 -----------------------------------------------------------------------*/
/*- DEFINE A POINTER TO USART  */
static ST_USART_t *const pUSART = USART;

/*- GLOBAL EXTERN VARIABLES
 -----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
 -----------------------------------------------------------------------*/
void CalculateBaud(EN_BAUD_RATE_t);
void USART_Flush(void);

/*- LOCAL FUNCTIONS IMPLEMENTATION
 -----------------------------------------------------------------------*/
void CalculateBaud(EN_BAUD_RATE_t Baud) {
  volatile float Div = USARTDIV(F_CPU, Baud);
  vuint16_t baudValue = 0;
  if (Div - (vuint16_t)Div >= 0.5) {
    baudValue = (vuint16_t)Div + 1;
    UBRRL = (vuint8_t)baudValue;
    CLR_BIT(pUSART->UCSRC, 7);
    UBRRH = (vuint8_t)(baudValue >> 8);
  } else {
    baudValue = (vuint16_t)Div;
    UBRRL = (vuint8_t)baudValue;
    CLR_BIT(pUSART->UCSRC, 7);
    UBRRH = (vuint8_t)(baudValue >> 8);
  }
}

void USART_IRQHandler(void) { gPf_IRQ_Callback_Usart(); }

void USART_Flush(void) {
  vuint8_t dummy;
  while (READ_BIT(pUSART->UCSRA, 7))
    dummy = pUSART->UDR;
}

/*- APIs IMPLEMENTATION
 -----------------------------------------------------------------------*/
void UART_Init(ST_UARTConfig_t *const configPtr) {
  /*- Set the UART pins */
  GPIO_Init(configPtr->pSetTxPin, 1);
  GPIO_Init(configPtr->pSetRxPin, 1);

  /*- Configure the UART mode
   * NOTE: TXC must be cleared before the transmission starts.
   * */
  switch (configPtr->Mode) {
  case TX_MODE:
    SET_BIT(pUSART->UCSRB, 3);
    SET_BIT(pUSART->UCSRA, 6);
    break;
  case RX_MODE:
    SET_BIT(pUSART->UCSRB, 4);
    break;
  case TX_RX_MODE:
    SET_BIT(pUSART->UCSRB, 3);
    SET_BIT(pUSART->UCSRB, 4);
    break;
  default:
    break;
  }

  /*- Configure the UART parity */
  switch (configPtr->parityCheck) {
    SET_BIT(pUSART->UCSRC, 7);
  case NO_PARITY:
    CLR_2BITS(pUSART->UCSRC, 4);
    Flag.Parity = 0;
    break;
  case PARITY_ODD:
    SET_2BITS(pUSART->UCSRC, 4);
    Flag.Parity = 1;
    break;
  case PARITY_EVEN:
    WRITE_2BITS(pUSART->UCSRC, 0b10, 4);
    Flag.Parity = 1;
    break;
  default:
    break;
  }

  /*- Configure the UART stop bits */
  switch (configPtr->stopBit) {
    SET_BIT(pUSART->UCSRC, 7);
  case ONE_STOP_BIT:
    CLR_BIT(pUSART->UCSRC, 3);
    break;
  case TWO_STOP_BITS:
    SET_BIT(pUSART->UCSRC, 3);
    break;
  default:
    break;
  }

  /*- Configure the UART payload length */
  switch (configPtr->payLoadSize) {
    SET_BIT(pUSART->UCSRC, 7);
  case FIVE_BITS:
    CLR_2BITS(pUSART->UCSRC, 1);
    CLR_BIT(pUSART->UCSRB, 2);
    break;
  case SIX_BITS:
    WRITE_2BITS(pUSART->UCSRC, 0b01, 1);
    CLR_BIT(pUSART->UCSRB, 2);
    break;
  case SEVEN_BITS:
    WRITE_2BITS(pUSART->UCSRC, 0b10, 1);
    CLR_BIT(pUSART->UCSRB, 2);
    break;
  case EIGHT_BITS:
    SET_2BITS(pUSART->UCSRC, 1);
    CLR_BIT(pUSART->UCSRB, 2);
    break;
  case NINE_BITS:
    SET_2BITS(pUSART->UCSRC, 1);
    SET_BIT(pUSART->UCSRB, 2);
    Flag.payLoad_9 = 1;
    break;
  default:
    break;
  }

  /*- Calculate the UART baud rate */
  CalculateBaud(configPtr->Baud);

  /* Configure UART IRQ */
  gPf_IRQ_Callback_Usart = configPtr->callBackFunctionUart;
  switch (configPtr->Irq) {
  case UART_IRQ_DISABLE:
    CLR_3BITS(pUSART->UCSRB, 5);
    cli();
    Flag.pollingTx = 1U;
    Flag.pollingRx = 1U;
    break;
  case UART_IRQ_TXC:
    SET_BIT(pUSART->UCSRB, 6);
    sei();
    break;
  case UART_IRQ_TXE:
    SET_BIT(pUSART->UCSRB, 5);
    sei();
    break;
  case UART_IRQ_RXC:
    SET_BIT(pUSART->UCSRB, 7);
    sei();
    break;
  default:
    break;
  }
}

void UART_SendData(vuint16_t *pBuffer) {
  /* Wait for empty transmitter buffer */
  if (Flag.pollingTx) {
    while (!READ_BIT(pUSART->UCSRA, 5))
      ;
  }

  if (Flag.payLoad_9) {
    WRITE_BIT(pUSART->UCSRB, READ_BIT(*pBuffer, 8), 0);
    pUSART->UDR = (*pBuffer & (vuint8_t)0XFF);
  } else {
    pUSART->UDR = (*pBuffer & (vuint8_t)0XFF);
  }
}

void UART_ReceiveData(vuint16_t *pBuffer) {
  /* Wait for data to be received completely */
  if (Flag.pollingRx) {
    while (!READ_BIT(pUSART->UCSRA, 7))
      ;
  }
  /* Check the error flags first before reading the data */
  if (READ_3BITS(pUSART->UCSRA, 2)) {
    USART_Flush();
    *pBuffer = -1;
    return;
  }

  if (Flag.payLoad_9) {
    vuint8_t resH = READ_BIT(pUSART->UCSRB, 1);
    vuint8_t resL = (pUSART->UDR & (vuint16_t)0XFF);
    *pBuffer = (resL | (resH << 8));
  } else {
    *pBuffer = (pUSART->UDR & (vuint16_t)0XFF);
  }
}
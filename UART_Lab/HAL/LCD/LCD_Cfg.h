/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: LCD_Cfg.h
 *	@brief This module contains interface definitions for the
 *   LCD configuration.
 *****************************************************************************/

#ifndef CFG_LCD_CFG_H_
#define CFG_LCD_CFG_H_

/*- INCLUDES
 -----------------------------------------------------------------------*/
#include "GPIO.h"

/*- GLOBAL MACROS
 -----------------------------------------------------------------------*/
/*- LCD PORT */
#define LCD_DATA_PORT PORTA
#define LCD_COMMAND_PORT PORTB

/*- LCD CONTROL PINS */
#define RS Pin1
#define RW Pin2
#define EN Pin3

/*- LCD INSTRUCTION SET */
#define LCD_FUNCTION_8BIT_2LINES (0x38)
#define LCD_FUNCTION_8BIT_1LINES (0x30)
#define LCD_FUNCTION_4BIT_2LINES (0x28)
#define LCD_FUNCTION_4BIT_1LINES (0x20)
#define LCD_MOVE_DISP_RIGHT (0x1C)
#define LCD_MOVE_DISP_LEFT (0x18)
#define LCD_MOVE_CURSOR_RIGHT (0x14)
#define LCD_MOVE_CURSOR_LEFT (0x10)
#define LCD_DISP_OFF (0x08)
#define LCD_DISP_ON_CURSOR (0x0E)
#define LCD_DISP_ON_CURSOR_BLINK (0x0F)
#define LCD_DISP_ON_BLINK (0x0D)
#define LCD_DISP_ON (0x0C)
#define LCD_ENTRY_DEC (0x04)
#define LCD_ENTRY_DEC_SHIFT (0x05)
#define LCD_ENTRY_INC_ (0x06)
#define LCD_ENTRY_INC_SHIFT (0x07)
#define LCD_BEGIN_AT_FIRST_ROW (0x80)
#define LCD_BEGIN_AT_SECOND_ROW (0xC0)
#define LCD_CLEAR_SCREEN (0x01)

/*- LCD MODES */
#define DATA_SHIFT_8_MODE (0U)
#define DATA_SHIFT_4_MODE (4U)
#define EIGHT_BIT_MODE (1U)
/* #define FOUR_BIT_MODE            (1U) */

/*- LCD PINS CONFIGURATION */
#define LCD_COMMAND_RS                                                         \
  (ST_GPIOConfig_t) { LCD_COMMAND_PORT, RS, GPIO_OUTPUT }
#define LCD_COMMAND_RW                                                         \
  (ST_GPIOConfig_t) { LCD_COMMAND_PORT, RW, GPIO_OUTPUT }
#define LCD_COMMAND_EN                                                         \
  (ST_GPIOConfig_t) { LCD_COMMAND_PORT, EN, GPIO_OUTPUT }

#ifdef EIGHT_BIT_MODE
#define LCD_DATA0                                                              \
  (ST_GPIOConfig_t) { LCD_DATA_PORT, Pin0, GPIO_OUTPUT }
#define LCD_DATA1                                                              \
  (ST_GPIOConfig_t) { LCD_DATA_PORT, Pin1, GPIO_OUTPUT }
#define LCD_DATA2                                                              \
  (ST_GPIOConfig_t) { LCD_DATA_PORT, Pin2, GPIO_OUTPUT }
#define LCD_DATA3                                                              \
  (ST_GPIOConfig_t) { LCD_DATA_PORT, Pin3, GPIO_OUTPUT }
#define LCD_DATA4                                                              \
  (ST_GPIOConfig_t) { LCD_DATA_PORT, Pin4, GPIO_OUTPUT }
#define LCD_DATA5                                                              \
  (ST_GPIOConfig_t) { LCD_DATA_PORT, Pin5, GPIO_OUTPUT }
#define LCD_DATA6                                                              \
  (ST_GPIOConfig_t) { LCD_DATA_PORT, Pin6, GPIO_OUTPUT }
#define LCD_DATA7                                                              \
  (ST_GPIOConfig_t) { LCD_DATA_PORT, Pin7, GPIO_OUTPUT }
#define LCD_PINS 12
#endif

#ifdef FOUR_BIT_MODE
#define LCD_DATA4                                                              \
  (ST_GPIOConfig_t) { LCD_DATA_PORT, Pin4, GPIO_OUTPUT }
#define LCD_DATA5                                                              \
  (ST_GPIOConfig_t) { LCD_DATA_PORT, Pin5, GPIO_OUTPUT }
#define LCD_DATA6                                                              \
  (ST_GPIOConfig_t) { LCD_DATA_PORT, Pin6, GPIO_OUTPUT }
#define LCD_DATA7                                                              \
  (ST_GPIOConfig_t) { LCD_DATA_PORT, Pin7, GPIO_OUTPUT }
#define LCD_PINS 7
#endif

#define LCDCFG                                                                 \
  (ST_LCDConfig_t) {                                                           \
    &LCD_COMMAND_RS, &LCD_COMMAND_RW, &LCD_COMMAND_EN, &LCD_DATA0, &LCD_DATA1, \
        &LCD_DATA2, &LCD_DATA3, &LCD_DATA4, &LCD_DATA5, &LCD_DATA6, &LCD_DATA7 \
  }

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/
typedef struct {
  ST_GPIOConfig_t *pLcdCfg[LCD_PINS];
} ST_LCDConfig_t;

/*- GLOBAL VARIABLES
 -----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: LCD_ConfigGet
 * Syntax: const ST_LCDConfig_t *const LCD_ConfigGet(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: A helper function to initialize the LCD based on a config
 * table.
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: const ST_LCDConfig_t* const
 *************************************************************************/
const ST_LCDConfig_t *const LCD_ConfigGet(void);

#endif /* CFG_LCD_CFG_H_ */

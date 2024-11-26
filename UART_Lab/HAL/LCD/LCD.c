/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 * @file LCD.c
 * @brief The implementation for the LCD driver
 *
 ****************************************************************************/

/*- INCLUDES
 -----------------------------------------------------------------------*/
#include "LCD.h"
#include <stdio.h>

/*- LOCAL MACROS
 -----------------------------------------------------------------------*/

/*- LOCAL DATATYPES
 -----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
 -----------------------------------------------------------------------*/
void LCD_XY(vuint8_t, vuint8_t);
void SetCursor(vuint8_t);

/*- GLOBAL STATIC VARIABLES
 -----------------------------------------------------------------------*/
/*- DEFINE ARRAY OF BITMAPS OF SHAPES */
static vuint8_t Bell[8] = {0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x04, 0x00};
/* TODO
 * HEART, SPEAKER, SMILE, AND MUSIC
 */

/*- GLOBAL EXTERN VARIABLES
 -----------------------------------------------------------------------*/
extern vuint8_t configSizeLcd;
extern TYPE volatile *Data[NUMBER_OF_PORTS];
extern TYPE volatile *dataDir[NUMBER_OF_PORTS];

/*- LOCAL FUNCTIONS IMPLEMENTATION
 -----------------------------------------------------------------------*/

void LCD_XY(vuint8_t Line, vuint8_t Pos) {
  if (Line == 1) {
    if (Pos < 16 && Pos >= 0) {
      LCD_SendCmd(LCD_BEGIN_AT_FIRST_ROW + Pos);
    }
  }
  if (Line == 2) {
    if (Pos < 16 && Pos >= 0) {
      LCD_SendCmd(LCD_BEGIN_AT_SECOND_ROW + Pos);
    }
  }
}

void SetCursor(vuint8_t Counter) {
  if (Counter == 16) {
    LCD_XY(2, 0);
  } else if (Counter == 32) {
    LCD_ClearScreen();
    LCD_XY(1, 0);
    Counter = 0;
  }
}

/*- APIs IMPLEMENTATION
 -----------------------------------------------------------------------*/
void LCD_Kick(void) {
  GPIO_PinWrite(LCD_COMMAND_PORT, EN, HIGH);
  _delay_ms(50);
  GPIO_PinWrite(LCD_COMMAND_PORT, EN, LOW);
  _delay_ms(50);
}

void LCD_Init(void) {
  vuint8_t i = 0;
  for (i = 0; i < configSizeLcd; i++)
    GPIO_Init(LCD_ConfigGet()->pLcdCfg[i], 1);
  _delay_ms(50);
#ifdef EIGHT_BIT_MODE
  LCD_SendCmd(LCD_FUNCTION_8BIT_2LINES);
  LCD_SendCmd(LCD_DISP_ON_CURSOR);
  LCD_SendCmd(LCD_ENTRY_INC_);
  LCD_SendCmd(LCD_BEGIN_AT_FIRST_ROW);
  LCD_ClearScreen();
#endif

#ifdef FOUR_BIT_MODE
  LCD_SendCmd(0x02);
  LCD_SendCmd(LCD_FUNCTION_4BIT_2LINES);
  LCD_SendCmd(LCD_DISP_ON_CURSOR);
  LCD_SendCmd(LCD_ENTRY_INC_);
  LCD_SendCmd(LCD_BEGIN_AT_FIRST_ROW);
  LCD_ClearScreen();
#endif
}

void LCD_SendCmd(vuint8_t cmd) {
  GPIO_PinWrite(LCD_COMMAND_PORT, RS, LOW);
  GPIO_PinWrite(LCD_COMMAND_PORT, RW, LOW);
#ifdef EIGHT_BIT_MODE
  *(Data[LCD_DATA_PORT]) = (*(Data[LCD_DATA_PORT]) & 0xFF00) | cmd;
  _delay_ms(1);
  LCD_Kick();
#endif

#ifdef FOUR_BIT_MODE
  /** Sending the upper nibble **/
  *(Data[LCD_DATA_PORT]) = (*(Data[LCD_DATA_PORT]) & 0xFF0F) | (cmd & 0xF0);
  _delay_ms(10);
  LCD_Kick();
  /** Sending the lower nibble **/
  *(Data[LCD_DATA_PORT]) = (*(Data[LCD_DATA_PORT]) & 0xFF0F) | (cmd << 4);
  _delay_ms(10);
  LCD_Kick();
#endif
}

void LCD_WriteChar(vuint8_t chr) {
  GPIO_PinWrite(LCD_COMMAND_PORT, RS, HIGH);
  GPIO_PinWrite(LCD_COMMAND_PORT, RW, LOW);
#ifdef EIGHT_BIT_MODE
  *(Data[LCD_DATA_PORT]) = (*(Data[LCD_DATA_PORT]) & 0xFF00) | chr;
  _delay_ms(1);
  LCD_Kick();
#endif

#ifdef FOUR_BIT_MODE
  /** Sending the upper nibble **/
  *(Data[LCD_DATA_PORT]) = (*(Data[LCD_DATA_PORT]) & 0xFF0F) | (chr & 0xF0);
  _delay_ms(10);
  LCD_Kick();
  /** Sending the lower nibble **/
  *(Data[LCD_DATA_PORT]) = (*(Data[LCD_DATA_PORT]) & 0xFF0F) | (chr << 4);
  _delay_ms(10);
  LCD_Kick();
  count_char++;
#endif
}

void LCD_WriteString(vuint8_t *Str) {
  vuint16_t i = 0, count = 0;
  for (i = 0; Str[i] != 0; i++) {
    LCD_WriteChar(Str[i]);
    count++;
    SetCursor(count);
  }
}

void LCD_ClearScreen() { LCD_SendCmd(LCD_CLEAR_SCREEN); }

void LCD_CreateShape(EN_Shapes_t Shape, vuint8_t Location) {
  vuint8_t *Pattern;
  switch (Shape) {
  case BELL:
    Pattern = Bell;
    break;
  default:
    break;
  }
  vuint8_t i = 0;
  LCD_SendCmd(0x40 + (Location * 8)); /** Send the address of CGRAM **/
  for (i = 0; i < 8; i++) {
    LCD_WriteChar(Pattern[i]); /** Pass the bytes of Pattern on LCD **/
  }
  LCD_SendCmd(LCD_BEGIN_AT_FIRST_ROW);
  LCD_WriteChar(0);
  _delay_ms(1);
}

void LCD_WriteInt(vint32_t Num) {
  vint8_t Size = 0, i;
  vuint8_t Str[10];
  if (Num > 0) {
    while (Num != 0) {
      Str[Size++] = Num % 10;
      Num /= 10;
    }
    for (i = Size - 1; i >= 0; i--)
      LCD_WriteChar(Str[i] + 48);
  } else if (Num < 0) {
    Num *= -1;
    while (Num != 0) {
      Str[Size++] = Num % 10;
      Num /= 10;
    }
    LCD_WriteChar('-');
    for (i = Size - 1; i >= 0; i--)
      LCD_WriteChar(Str[i] + 48);
  } else {
    LCD_WriteChar(48);
  }
}

void LCD_WriteFloat(float realNum) {
  float floatPart = realNum - (vint32_t)realNum;
  vint32_t intPart = realNum - floatPart;
  LCD_WriteInt(intPart);
  LCD_WriteChar('.');
  LCD_WriteInt(floatPart * 10000);
}

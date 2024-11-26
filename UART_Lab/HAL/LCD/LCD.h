/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 * @file LCD.h
 * @brief The interface definition for the LCD driver
 * @description This is the header file for the definition of the interface
 * for the LCD driver connected to the MCU.
 *****************************************************************************/

#ifndef INC_LCD_H_
#define INC_LCD_H_

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "LCD_Cfg.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/
/*- DEFINE SOME SHAPES CREATED ON LCD */
typedef enum { BELL, HEART, SPEAKER, MUSIC, SMILE } EN_Shapes_t;

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: LCD_Kick
 * Syntax: void LCD_Kick(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Run/Enable the LCD
 * PRE-CONDITION: LCD is initialized
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void LCD_Kick(void);

/************************************************************************
 * Service Name: LCD_Init
 * Syntax: void LCD_Init(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Initialize LCD.
 * @param (in):
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void LCD_Init(void);

/************************************************************************
 * Service Name: LCD_SendCmd
 * Syntax: void LCD_SendCmd(vuint8_t Cmd)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Send commands to LCD
 * @param (in): cmd the command sent to LCD
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void LCD_SendCmd(vuint8_t Cmd);

/************************************************************************
 * Service Name: LCD_WriteChar
 * Syntax: void LCD_WriteChar(vuint8_t Char)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Write a character on LCD
 * @param (in): Char the character sent to LCD
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void LCD_WriteChar(vuint8_t Char);

/************************************************************************
 * Service Name: LCD_WriteString
 * Syntax: void LCD_WriteString(vuint8_t *Str)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Write a String on LCD
 * @param (in): Str a pointer to character sent to LCD
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void LCD_WriteString(vuint8_t *Str);

/************************************************************************
 * Service Name: LCD_ClearScreen
 * Syntax: void LCD_ClearScreen(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Clear LCD
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void LCD_ClearScreen(void);

/************************************************************************
 * Service Name: LCD_CreateShape
 * Syntax: void LCD_CreateShape(EN_Shapes_t Shape, vuint8_t Location)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Create custome shapes on LCD
 * @param (in): Shape an enum represents the custome shape
 * @param (in): Location expresses the address of the CGRAM
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void LCD_CreateShape(EN_Shapes_t Shape, vuint8_t Location);

/************************************************************************
 * Service Name: LCD_WriteInt
 * Syntax: void LCD_WriteInt(vint32_t Num)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Write integer numbers on LCD
 * @param (in): Num an integer displayed on LCD
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void LCD_WriteInt(vint32_t Num);

/************************************************************************
 * Service Name: LCD_WriteFloat
 * Syntax: void LCD_WriteFloat(float realNum)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Write floating-point numbers on LCD
 * @param (in): realNum a float number displayed on LCD
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void LCD_WriteFloat(float realNum);

#endif /* INC_LCD_H_ */

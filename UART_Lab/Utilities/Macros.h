/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/******************************************************************************
 * @file Macros.h
 * @brief Header file that defines generic macros for MCU applications.
 *
 * @details This file provides a set of generic macros that are commonly used
 * in microcontroller applications for bit manipulation and other basic
 *operations. These macros enhance code readability and maintainability.
 ******************************************************************************/

#ifndef MACROS_H_
#define MACROS_H_

/*- GLOBAL MACROS
 -----------------------------------------------------------------------*/
#define NULL ((void *)0U)
/* The following macros perform various bitwise operations on registers.
 ******************************************************************************/

/**
 * @brief Sets a specific bit in a register.
 * @param REG The register to modify.
 * @param BIT_NUM The bit number to set.
 */
#define SET_BIT(REG, BIT_NUM) (REG |= (1U << BIT_NUM))

/**
 * @brief Clears a specific bit in a register.
 * @param REG The register to modify.
 * @param BIT_NUM The bit number to clear.
 */
#define CLR_BIT(REG, BIT_NUM) (REG &= ~(1U << BIT_NUM))

/**
 * @brief Toggles a specific bit in a register.
 * @param REG The register to modify.
 * @param BIT_NUM The bit number to toggle.
 */
#define TOGGLE_BIT(REG, BIT_NUM) (REG ^= (1U << BIT_NUM))

/**
 * @brief Writes a value to a specific bit in a register.
 * @param REG The register to modify.
 * @param VALUE The value to set the nibble to.
 * @param POSITION The position of the nibble to modify.
 */
#define WRITE_BIT(REG, VALUE, POSITION)                                        \
  (REG = (REG & ~(0b1U << POSITION)) | ((VALUE & 0b1) << POSITION))
/**
 * @brief Reads a specific bit in a register.
 * @param REG The register to read.
 * @param BIT_NUM The bit number to read.
 * @return The value of the bit (0 or 1).
 */
#define READ_BIT(REG, BIT_NUM) ((REG & (1U << BIT_NUM)) >> BIT_NUM)

/**
 * @breif Sets specific two bits in a register
 * @param REG The register to modify.
 * @param POSITION The position of the nibble to set.
 */
#define SET_2BITS(REG, POSITION) (REG |= (0b11U) << POSITION)

/**
 * @breif Clears specific two bits in a register
 * @param REG The register to modify.
 * @param POSITION The position of the nibble to set.
 */

#define CLR_2BITS(REG, POSITION) (REG &= ~(0b11U) << POSITION)

/**
 * @brief Reads a specific two bits in a register.
 * @param REG The register to read.
 * @param POSITION The starting bit position within the REG (0-6).
 * @return The value of the two bits.
 */
#define READ_2BITS(REG, POSITION) (((REG) >> (POSITION)) & 0x03U)

/**
 * @brief Writes a value to specific two bits in a register.
 * @param REG The register to modify.
 * @param VALUE The value to set the nibble to.
 * @param POSITION The position of the nibble to modify.
 */
#define WRITE_2BITS(REG, VALUE, POSITION)                                      \
  (REG = (REG & ~(0b11U << POSITION)) | ((VALUE & 0b11) << POSITION))
/**
 * @breif Sets specific three bits in a register
 * @param REG The register to modify.
 * @param POSITION The position of the nibble to set.
 */

#define SET_3BITS(REG, POSITION) (REG |= (0b111U) << POSITION)

/**
 * @breif Clears specific three bits in a register
 * @param REG The register to modify.
 * @param POSITION The position of the nibble to set.
 */

#define CLR_3BITS(REG, POSITION) (REG &= ~(0b111U) << POSITION)

/**
 * @brief Reads a specific three bits in a register.
 * @param REG The register to read.
 * @param POSITION The starting bit position within the REG (0-5).
 * @return The value of the three bits.
 */
#define READ_3BITS(REG, POSITION) (((REG) >> (POSITION)) & 0x07U)

/**
 * @brief Writes a value to specific three bits in a register.
 * @param REG The register to modify.
 * @param VALUE The value to set the nibble to.
 * @param POSITION The position of the nibble to modify.
 */

#define WRITE_3BITS(REG, VALUE, POSITION)                                      \
  (REG = (REG & ~(0b111U << POSITION)) | ((VALUE & 0b111) << POSITION))

/**
 * @brief Sets a nibble (4 bits) in a register.
 * @param REG The register to modify.
 * @param POSITION The position of the nibble to set.
 */
#define SET_NIBBLE(REG, POSITION) (REG |= (0XFU << POSITION))

/**
 * @brief Clears a nibble (4 bits) in a register.
 * @param REG The register to modify.
 * @param POSITION The position of the nibble to clear.
 */
#define CLR_NIBBLE(REG, POSITION) (REG &= ~(0XFU << POSITION))

/**
 * @brief Reads a specific nibble in a register.
 * @param REG The register to read.
 * @param POSITION The starting bit position within the REG (0-4).
 * @return The value of the nibble.
 */
#define READ_NIBBLE(REG, POSITION) (((REG) >> (POSITION)) & 0x0FU)

/**
 * @brief Writes a value of a nibble (4 bits) in a register.
 * @param REG The register to modify.
 * @param VALUE The value to set the nibble to.
 * @param POSITION The position of the nibble to modify.
 */
#define WRITE_NIBBLE_VALUE(REG, VALUE, POSITION)                               \
  (REG = (REG & ~(0xFU << POSITION)) | ((VALUE & 0xF) << POSITION))

/**
 * @brief Swaps the upper and lower nibbles of a byte.
 * @param REG The byte to modify.
 * @return The byte with swapped nibbles.
 */
#define SWAP_NIBBLES(REG) (((REG & 0X0FU) << 4U) | ((REG & 0XF0U) >> 4U))

/**
 * @brief Swaps the two bytes in a 16-bit register.
 * @param REG The 16-bit register to modify.
 * @return The register with swapped bytes.
 */
#define SWAP_BYTES(REG) (((REG & 0X00FFU) << 8U) | ((REG & 0XFF00U) >> 8U))

/**
 * @brief Swaps the endianness of a 32-bit register.
 * @param REG The 32-bit register to modify.
 * @return The register with swapped endianness.
 */
#define SWAP_ENDIANS(REG)                                                      \
  (((REG & 0X000000FFU) << 24U) | ((REG & 0X0000FF00U) << 8U) |                \
   ((REG & 0X00FF0000U) >> 8U) | ((REG & 0xFF000000U) >> 24U))

/**
 * @brief Returns number of 1s based on N.
 * @param N The number of 1s to return
 */
#define N_1BITS(N) ((1U << N) - 1)

/**
 * @brief Writes a value of n bits in a register.
 * @param REG The register to modify.
 * @param VALUE The value to set the n bits to.
 * @param POSITION The starting position of the n bits to modify.
 */
#define WRITE_VALUE(REG, VALUE, POSITION)                                      \
  (REG = (REG & ~(N_1BITS(POSITION) << POSITION)) | (VALUE << POSITION))
/**
 * @brief Returns the minimum of two values.
 * @param X First value.
 * @param Y Second value.
 * @return The minimum of X and Y.
 */
#define MIN(X, Y) ((X) > (Y) ? (Y) : (X))

/**
 * @brief Returns the maximum of two values.
 * @param X First value.
 * @param Y Second value.
 * @return The maximum of X and Y.
 */
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

/**
 * @brief Defines a macro for equality check.
 */
#define EQUAL ==

#endif /* MACROS_H_ */
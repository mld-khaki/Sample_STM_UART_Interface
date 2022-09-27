/******************************************************************************
// Copyright (c) 2022 Milad Khaki
// This UART library is a public API that can be used to configure, open, close, 
// read, write to an STM32 microcontroller. The library is intended to hide the 
// low-level implementation of a UART
// Consumers of it need not worry about low-level drivers, ucontroller register 
// settings, underlying private functions and structures, etc. 
// This library is designed considering multiple consumers and it can be used 
// to connect to multiple different UARTs.
*******************************************************************************/

#ifndef _STM_UART_HPP_
#define _STM_UART_HPP_

#include <STM_UART_Def.h>   //definitions file

typedef struct
{
    uint32_t BaudRate;                  // This member configures the UART communication baud rate.
                                        // The baud rate register is computed using the following formula:

    uint32_t WordLength;                // Specifies the number of data bits transmitted or received in a frame.
                                        // This parameter can be a value of @ref UARTEx_Word_Length. */

    uint8_t StopBits;                   // Specifies the number of stop bits transmitted.

    bool Parity;                        // Specifies the parity mode.

} STM_UART_InitTypeDef;

//STM STATUS CODE definitions
#define  STM_UART_ERROR_NONE             (0b00000000)    /*!< No error                */
#define  STM_UART_ERROR_PE               (0b00000001)    /*!< Parity error            */
#define  STM_UART_ERROR_NE               (0b00000010)    /*!< Noise error             */
#define  STM_UART_ERROR_FE               (0b00000100)    /*!< Frame error             */
#define  STM_UART_ERROR_ORE              (0b00001000)    /*!< Overrun error           */
#define  STM_UART_ERROR_DMA              (0b00010000)    /*!< DMA transfer error      */
#define  STM_UART_ERROR_RTO              (0b00100000)    /*!< Receiver Timeout error  */

#endif


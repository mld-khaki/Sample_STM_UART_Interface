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

//STM COMMUNICATION CODE definitions
typedef enum _Def_STM_COM_CODE
{
    STM_UART_COM_NONE =            (0b00000000),    /* No error                */
    STM_UART_COM_PE =              (0b00000001),    /* Parity error            */
    STM_UART_COM_NE =              (0b00000010),    /* Noise error             */
    STM_UART_COM_FE =              (0b00000100),    /* Frame error             */
    STM_UART_COM_RTO =             (0b00100000)    /* Receiver Timeout error  */
} STM_COM_CODE;

//STM STATUS CODE definitions
typedef enum _Def_STM_RET_STATUS
{
    STM_UART_STATUS_OPEN =            (0b00000000),    /* Port is open and available            */
    STM_UART_STATUS_BUSY =            (0b00000001),    /* Port is busy and not available, but hardware is responsive            */
    STM_UART_STATUS_TIMEOUT =         (0b00000010),    /* Port is no responding, hardware status is unknown*/
    STM_UART_STATUS_LOCKED =          (0b00000100),    /* Port is locked (lock bit or register?! (maybe), interrupt is being serviced */
    STM_UART_STATUS_CLOSED =          (0b00001000)     /* Port is closed and needs to be reinitialized */
} STM_RET_STATUS;

class STM_UART
{
public:
    // main default constructor 
    STM_UART();
    
    // virtual desctructor
    virtual ~STM_UART();

     /**
     * command to Open a serial connection.
     *
     * It opens a serial connection on a given port with a given baudrate; given that the connection
     * was not previously opened.
     *
     * 
     * STM_UART_ERROR_NONE if the port is opened correctly.
     *     * Return is the port could not be opened.
     *     * ReturnCode::RETURN_CODE_ILLEGAL_OPERATION if a previous call to open was performed in the
     *       same EasyNmea instance, regardless of the port.
     */
    STM_RET_STATUS Open(STM_UART_InitTypeDef Config);
    
    // check whether the serial port in question is opened
    STM_RET_STATUS    isOpen();
    
    // finalize transfer and close the UART port
    STM_RET_STATUS    Close();

    // read a batch of data through Buffer from the port, return read buffer size in BufferLen, 
    // the function returns if port is not ready
    STM_COM_CODE    Try_ReadNextBatch(char * Buffer, int & BufferLen)

    // read a batch of data through Buffer from the port, return read buffer size in BufferLen, 
    // the function continues to check until the timeout is reached (value is in second(s)
    STM_COM_CODE    Wait_ReadNextBatch(char * Buffer, int & BufferLen, uint32_t TimeOut_Sec)
    
    // send a batch of data through Buffer from the port, return read buffer size in BufferLen, 
    // the function returns if port is not ready
    STM_COM_CODE    Try_SendNextBatch(char * Buffer, int & BufferLen, uint32_t SendPackageSize)

    // send a batch of data through Buffer from the port, return actual send buffer size in BufferLen, 
    // size of the buffer is determined
    // the function continues to check until the timeout is reached (value is in second(s)
    STM_COM_CODE    Wait_SendNextBatch(char * Buffer, uint32_t & BufferLen, uint32_t TimeOut_Sec, uint32_t SendPackageSize)
    
}




#endif

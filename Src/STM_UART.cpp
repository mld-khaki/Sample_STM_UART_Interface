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

#include <iostream>
#define MicrocontrollerType 

using namespace std;

STM_UART::STM_UART() 
{
    
}

STM_UART::~STM_UART()
{
    
}

STM_RET_CODE STM_UART::Open(
    const char * serial_port
    unsigned long baudrate) 
{
    /*
        Send the required parameters to the implementation 
        baudrate (will be checked to be standard values i.e. 300, 600, 1200, 1800, 2400, 4800, 7200,... 115,200)
    
    */
    return Implementation->Open(serial_port, baudrate);
}

bool    STM_UART::isOpen()
{
    return Implementation->isOpen();
}

STM_RET_CODE STM_UART::Close()
{
    return Implementation->Close();
}

STM_RET_CODE    STM_UART::Try_ReadNextBatch(char * Buffer, int & BufferLen)
{
    return Implementation->y_ReadNextBatch(Buffer, BufferLen);
}

STM_RET_CODE STM_UART::Wait_ReadNextBatch(char * Buffer, int & BufferLen)
{
    return Implementation->Wait_ReadNextBatch(char * Buffer, int & BufferLen)
}


int main()
{
    cout<<"Hello World";

    return 0;
}

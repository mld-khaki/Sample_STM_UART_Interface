/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

STM_UART::STM_UART() 
{
    
}

STM_UART::~STM_UART()
{
    
}

STM_RET_STATUS STM_UART::OOpen(STM_UART_InitTypeDef Config) 
{
    /*
        Send the required parameters to the implementation 
        baudrate (will be checked to be standard values i.e. 300, 600, 1200, 1800, 2400, 4800, 7200,... 115,200)
    
    */
    return Implementation->Open(Config);
}

STM_RET_STATUS    STM_UART::isOpen()
{
    return Implementation->isOpen();
}

STM_RET_STATUS STM_UART::Close()
{
    return Implementation->Close();
}

STM_COM_CODE    STM_UART::Try_ReadNextBatch(char * Buffer, int & BufferLen)
{
    return Implementation->y_ReadNextBatch(Buffer, BufferLen);
}

STM_COM_CODE    STM_UART::Wait_ReadNextBatch(char * Buffer, int & BufferLen, uint32_t TimeOutSec)
{
    return Implementation->Wait_ReadNextBatch(char * Buffer, int & BufferLen)
}

STM_COM_CODE    Try_SendNextBatch(char * Buffer, int & BufferLen, uint32_t SendPackageSize)
{
    return Implementation->Try_SendNextBatch(char * Buffer, int & BufferLen)
}

STM_COM_CODE    STM_UART::Wait_SendNextBatch(char * Buffer, uint32_t & BufferLen, uint32_t TimeOut_Sec, uint32_t SendPackageSize)
{
    return Implementation->Wait_SendNextBatch(char * Buffer, uint32_t & BufferLen, uint32_t TimeOut_Sec, uint32_t SendPackageSize)
}



# Sample_STM_UART_Interface
just a sample interface implementation of UART for STM32 microcontrollers
  - This API implementation is only considering the asynchronous communication between UARTs
  - It is assumed that the actual GPIO pins and UART ports are fixed and defined in the other implemented headers (so we do not need to define them during the initialization and just selecting the port will be enough
  - At this stage it would not be prudent to implement DMA based set of functions (that just get the data and gradually send it and won't get the CPU time). It would require more analysis and ensuring that the device is capable of handling such functionality.

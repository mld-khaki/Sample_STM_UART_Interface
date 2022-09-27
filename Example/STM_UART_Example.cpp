/* this sample code is acting as both example and test function */ 


#include <STM_UART/STM_UART.hpp>

void main()
{
  /*
   * Executable arguments:
   *    'serial_port' is the port used to established a serial connection with the NMEA device
   *    'baudrate' is the bit-transmission speed of the communication. It must be set to whatever
   *               the NMEA device is using.
   *    'output_file' is the file to which the received samples will be logged.
   */
  char serial_port[16] = "UART1";
  uint32_t baudrate = 115200;
  STD_UART testUART;

  STM_UART_InitTypeDef  UARTConf;
  UARTConf.BaudRate = 115200;
  UARTConf.WordLength = 32;
  UARTConf.StopBits = 1;
  UARTConf.Parity = true;

  if (testUART.Open(UARTConf) == STD_COM_CODE::STM_UART_STATUS_OPEN)
  {
    for (auto iCtr = 1; iCtr < 100; iCtr++)
    {
       // send and receive data here...
    }
  }
  else
  {
      // Check for the errors here
  }
}

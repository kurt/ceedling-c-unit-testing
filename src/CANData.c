#include "CANData.h"


uint16_t parseCANData(){
   uint16_t DataIn;
   uint16_t dataOut=4;
   uint8_t baudrate = 9600;
   DataIn = spi_readData(dataOut, baudrate);
   return DataIn -10; 
}

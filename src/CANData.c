#include "CANData.h"
#include "spi.h"

uint16_t parseCANData(){
   uint16_t DataIn;
   uint16_t dataOut=4;
   uint16_t baudrate = 9600;
   DataIn = spi_readData(dataOut, baudrate);
   //printf("The alarm is on");
   // the following two lines create a memory leak on purpose!
   //char *memoryArea = malloc(10);
   //char *newArea = malloc(10);
   return DataIn -10; 
}

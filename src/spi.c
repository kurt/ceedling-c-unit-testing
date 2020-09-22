#include "spi.h"


uint16_t spi_readData(uint16_t dataOut, uint16_t baudrate){
    uint16_t RandomData =100; 
    checkBaudRate(baudrate);
    uint16_t data = dataOut;
    return RandomData;
}


bool checkBaudRate(uint16_t baudrate){
    if(baudrate != 9600){
        printf("Baud Rate %d is Incorrect!\n",baudrate);
        return 0;
    }
    else{
        return 1;
    }
}

# ifndef spi_H
# define spi_H

# include <stdint.h>
# include <stdio.h> 
#include <stdbool.h>
uint16_t spi_readData(uint16_t dataOut, uint16_t baudrate);
bool checkBaudRate(uint16_t baudrate);
# endif // i2c_H

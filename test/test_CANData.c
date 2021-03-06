#include "unity.h"

#include "CANData.h"
#include "mock_spi.h"
void setUp(void)
{
}

void tearDown(void)
{
}

void test_CANData_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement CANData");
}

void test_CANData_Parser(void){
  uint16_t baudrate = 9600;
  uint16_t data_out = 4;
  //char *memoryArea = malloc(10);
  //char *newArea = malloc(10);

  spi_readData_ExpectAndReturn(data_out,baudrate,100);
  uint16_t parsedData = parseCANData();
  TEST_ASSERT_EQUAL_UINT16(90,parsedData);
}

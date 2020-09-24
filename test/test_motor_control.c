#include "unity.h"

#include "motor_control.h"
#include "mock_spi.h"
void setUp(void)
{
}

void tearDown(void)
{
}

void test_motor_control_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement motor_control");
}


void test_readEncoder(void){
  uint16_t ret_val=100;
  for (float test=100.0; test>=0; test--){
    spi_readData_ExpectAndReturn(0x6, 9600,ret_val);
    TEST_ASSERT_EQUAL_FLOAT(test,readEncoder());
    ret_val-=1;
  }
}

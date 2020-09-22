#include "unity.h"

#include "spi.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_spi_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement spi");
}


void test_CheckBaudRate(){
   uint16_t baud = 9600;
   uint16_t b2= 100;
   //checkBaudRate_ExpectAndReturn(baud,1)
   TEST_ASSERT_TRUE(checkBaudRate(baud));
   
   TEST_ASSERT_FALSE(checkBaudRate(b2));
}

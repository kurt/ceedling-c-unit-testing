#include "build/temp/_test_CANData.c"
#include "build/test/mocks/mock_spi.h"
#include "src/CANData.h"
#include "/var/lib/gems/2.4.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void test_CANData_NeedToImplement(void)

{

    UnityIgnore( (("Need to Implement CANData")), (UNITY_UINT)(15));

}



void test_CANData_Parser(void){

  uint8_t baudrate = 9600;

  uint8_t data_out = 4;





  spi_readData_CMockExpectAndReturn(23, data_out, baudrate, 100);

  uint16_t parsedData = parseCANData();

  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((90)), (UNITY_INT)(UNITY_UINT16)((parsedData)), (

 ((void *)0)

 ), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_UINT16);

}

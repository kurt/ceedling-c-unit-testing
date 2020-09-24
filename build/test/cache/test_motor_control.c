#include "build/temp/_test_motor_control.c"
#include "build/test/mocks/mock_spi.h"
#include "src/motor_control.h"
#include "/var/lib/gems/2.4.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void test_motor_control_NeedToImplement(void)

{

    UnityIgnore( (("Need to Implement motor_control")), (UNITY_UINT)(15));

}





void test_readEncoder(void){

  uint16_t ret_val=100;

  for (float test=100.0; test>=0; test--){

    spi_readData_CMockExpectAndReturn(22, 0x6, 9600, ret_val);

    UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((test)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((test))), (UNITY_FLOAT)((UNITY_FLOAT)((readEncoder()))), ((

   ((void *)0)

   )), (UNITY_UINT)((UNITY_UINT)(23)));

    ret_val-=1;

  }

}

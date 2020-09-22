#include "build/temp/_test_tempsensor.c"
#include "build/test/mocks/mock_i2c.h"
#include "src/tempsensor.h"
#include "/var/lib/gems/2.4.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"
void setUp(void)

{

}



void tearDown(void)

{

}



void test_tempsensor_NeedToImplement(void)

{

    UnityIgnore( (("Need to Implement tempsensor")), (UNITY_UINT)(14));

}



void test_whenTempRegisterReadsMaxValue_thenTheTempIsTheMaxValue(void)

{

 uint8_t tempRegisterAddress = 0x03;

 float expectedTemperature = 104.6f;

 float tolerance = 0.1f;





 i2c_readRegister_CMockExpectAndReturn(24, tempRegisterAddress, 0x3ff);





 float actualTemperature = tempSensor_getTemperature();

 UnityAssertFloatsWithin((UNITY_FLOAT)((tolerance)), (UNITY_FLOAT)((expectedTemperature)), (UNITY_FLOAT)((actualTemperature)), (

((void *)0)

), (UNITY_UINT)(28));

}



void test_whenTempRegisterReadsMinValue_thenTheTempIsTheMinValu(void){

 uint8_t tempRegisterAddress = 0x03;

 float expectedTemperature = -100.0f;

 float tolerance = 0.1f;



 i2c_readRegister_CMockExpectAndReturn(36, tempRegisterAddress, 0x0);



 float actualTemperature = tempSensor_getTemperature();

 UnityAssertFloatsWithin((UNITY_FLOAT)((tolerance)), (UNITY_FLOAT)((expectedTemperature)), (UNITY_FLOAT)((actualTemperature)), (

((void *)0)

), (UNITY_UINT)(39));

}

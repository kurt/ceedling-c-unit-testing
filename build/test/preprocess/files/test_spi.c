#include "build/temp/_test_spi.c"
#include "src/spi.h"
#include "/var/lib/gems/2.4.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"




void setUp(void)

{

}



void tearDown(void)

{

}



void test_spi_NeedToImplement(void)

{

    UnityIgnore( (("Need to Implement spi")), (UNITY_UINT)(15));

}





void test_CheckBaudRate(){

   uint16_t baud = 9600;

   uint16_t b2= 100;



   do {if ((checkBaudRate(baud))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(23)));}} while(0);

   do {if (!(checkBaudRate(b2))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(24)));}} while(0);

}

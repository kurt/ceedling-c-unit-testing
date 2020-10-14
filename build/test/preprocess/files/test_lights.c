#include "build/temp/_test_lights.c"
#include "src/lights.h"
#include "/var/lib/gems/2.4.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"




void setUp(void)

{



  int global_var=10;

}



void tearDown(void)

{

}



void test_lights_NeedToImplement(void)

{

    UnityIgnore( (("Need to Implement lights")), (UNITY_UINT)(17));

}



void test_WhenTheHeadlightSwitchIsOff_ThenTheHeadLightsAreOff(void)

{



 lights_SetHeadlightSwitchOff();



 UnityAssertEqualNumber((UNITY_INT)((

0

)), (UNITY_INT)((lights_AreHeadlightsOn())), (

((void *)0)

), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_INT);

}



void test_setup(void){



   printf("Test is Added Kurt");

   UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)(((10))), (

  ((void *)0)

  ), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_INT);





}

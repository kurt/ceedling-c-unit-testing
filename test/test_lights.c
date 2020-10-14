#include "unity.h"
#include <stdio.h>
#include "lights.h"

void setUp(void)
{
  #define THIS (10)
  int global_var=10;
}

void tearDown(void)
{
}

void test_lights_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement lights");
}

void test_WhenTheHeadlightSwitchIsOff_ThenTheHeadLightsAreOff(void)
{
 // When the headlight switch is off...
 lights_SetHeadlightSwitchOff();
 // then the headlights are off.
 TEST_ASSERT_EQUAL(false, lights_AreHeadlightsOn());
}

void test_setup(void){
   //extern  int global_var;
   printf("Test is Added Kurt");
   TEST_ASSERT_EQUAL(10,THIS);
   //printf("The global var is %d",global_var);

}

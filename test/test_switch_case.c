#include "unity.h"

#include "switch_case.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_switch_case_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement switch_case");
}


void test_if_else_emergency(void){

    float test_val = 1000000;
    if_else(test_val);
}

void test_if_else_hot(void){

    float test_val = 555;
    if_else(test_val);
}

void test_if_else_warm(void){

    float test_val = 200;
    if_else(test_val);
}

void test_if_else_normal(void){

    float test_val = 80;
    if_else(test_val);
}

void test_if_else_cold(void){

    float test_val = -30;
    if_else(test_val);
}

void test_if_else_frozen(void){

    float test_val = -500;
    if_else(test_val);
}

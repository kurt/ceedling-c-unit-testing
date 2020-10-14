#include "unity.h"

#include "global_variables.h"
#include "global_variable_creator2.c"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_global_variables_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement global_variables");
}


void test_grab_global_variable(){
    grab_global_variable();
}

void test_pass_global_variable(){
    extern int global_var2;
    pass_global_variable(global_var2);
}

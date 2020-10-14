#include "@@@@global_variable_creator2.c"
#include "src/global_variable_creator2.c"
#include "build/temp/_test_global_variables.c"
#include "src/global_variables.h"
#include "/var/lib/gems/2.4.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"




void setUp(void)

{

}



void tearDown(void)

{

}



void test_global_variables_NeedToImplement(void)

{

    UnityIgnore( (("Need to Implement global_variables")), (UNITY_UINT)(16));

}





void test_grab_global_variable(){

    grab_global_variable();

}



void test_pass_global_variable(){

    extern int global_var2;

    pass_global_variable(global_var2);

}

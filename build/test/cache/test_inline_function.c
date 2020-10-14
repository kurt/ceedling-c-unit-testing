#include "build/temp/_test_inline_function.c"
#include "src/inline_function.h"
#include "/var/lib/gems/2.4.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"








void setUp(void)

{

}



void tearDown(void)

{

}



void test_inline_func(void)

{

    int return_val;

    return_val = inline_func();

    printf("%d\n",return_val);

}

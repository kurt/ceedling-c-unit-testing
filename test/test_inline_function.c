#include "unity.h"
#include <stdio.h>
#include "inline_function.h"



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

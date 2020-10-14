#include "global_variables.h"
#include "global_variable_creator.c"
#include <stdio.h>






void grab_global_variable(){
  extern int global_var;
  printf("Global Var is: %d",global_var);
}


void pass_global_variable(int variable){
  printf("Global Var is: %d",variable);

}

#include "switch_case.h"

/*
void switch_case(float temperature){
    switch(temperature) {
      case (temperature > 1000) :
         printf("Heat is too much sending error!\n" );
         //signal(SIGINT, signalHandler); 
         break;
      case (temperature> 500) :
         printf("Temperature is getting too hot initializing emergency cool\n" );
         break;
      case (temperature> 100) :
         printf("Temperature is a bit hot but ok\n" );
         break;
      case (temperature>0) :
         printf("Temperature is in normal operating range\n" );
         break;
      case (temperature>-40) :
         printf("This is very cold special operations taken\n");
      default :
         printf("Invalid operating temperature\n" );
   }

}*/


void if_else(float temperature){
   if (temperature>1000){
       printf("Heat is too much sending error!\n" );
   }
   else if(temperature> 500){
       printf("Temperature is getting too hot initializing emergency cool\n" );
   }
   else if(temperature> 100){
       printf("Temperature is a bit hot but ok\n" );
   }
   else if (temperature>0){
       printf("Temperature is in normal operating range\n" );
   }
   else if (temperature>-40){
        printf("This is very cold special operations taken\n");
   }
   else{
        printf("Invalid operating temperature\n" );
   }
}

#include "motor_control.h"

/*
void pid(float setpoint){
        
   float kp=1;
   float ki=100;
   float kd=22;
   float error;   
   float current_speed = readEncoder();
   error = setpoint - current_speed;
   derror= current_speed - prev_speed;
   ierror=derror*
   while(1){
       u=-kp*error -ki*ierror - kd*derror; 
   }
}*/

float readEncoder(){
    uint16_t spi_data;
    spi_data = spi_readData(0x6, 9600);
    return (float) spi_data;
}

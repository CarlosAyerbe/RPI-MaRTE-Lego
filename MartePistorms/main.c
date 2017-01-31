#include "marte_pistorms.h"
#include "bcm2835.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define GYRO (BANK_B & PORT_1)
#define TOUCH (BANK_A & PORT_1)


int main(int argc, char **argv) {
  
    pistorms_init();
    char *GYRO_id;
    GYRO_id = pistorms_get_device_id(GYRO);
    
    if(strcmp(GYRO_id, GYRO_SENSOR_ID) != 0){
	
	printf("Error ID:%s",GYRO_id);
  
    }else{
    
	printf("ID Correcto:%s", GYRO_id);
  
    }
    
    GYRO_id = pistorms_get_device_id(GYRO);
    int GYRO_mode;
    GYRO_mode = pistorms_sensor_get_mode(GYRO);
    printf("Gyro Mode:%d", GYRO_mode);
    
    pistorms_sensor_set_mode(GYRO,RATE);
    GYRO_mode = pistorms_sensor_get_mode(GYRO);
    printf("Gyro Mode:%d", GYRO_mode);
    
  /*  char *TOUCH_id;
    pistorms_port_set_type_sensor(TOUCH,TOUCH_TYPE);
    
    TOUCH_id = pistorms_get_device_id(TOUCH);
    
    if(strcmp(TOUCH_id, TOUCH_SENSOR_ID) != 0){
	
	printf("Error ID:%s",TOUCH_id);
  
    }else{
    
	printf("ID Correcto:%s", TOUCH_id);
  
    }*/
    
 
    
}

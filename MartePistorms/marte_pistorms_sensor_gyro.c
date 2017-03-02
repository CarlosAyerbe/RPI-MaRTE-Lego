/**
 * @file marte_pistorms_sensor_gyro.c
 * @author Carlos Ayerbe González
 * @date 8 Feb 2017
 * @brief Driver for control the Gyro of EV3 Sensor.
 * @version 1.0
 *
 */

#include "marte_pistorms.h"
#include "marte_pistorms_sensor_gyro.h"
#include "marte_pistorms_sensors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


char *angle_data;
char *rate_data;

/*
 * Detects if the Gyro Sensor is connect correctly.
 * */
int pistorms_sensor_proof_gyro(int connector_id){
  
    char *GYRO_id;
    GYRO_id = pistorms_get_device_id(connector_id);
    
    if(strcmp(GYRO_id, GYRO_SENSOR_ID) != 0){
	
	printf("Error ID:%s",GYRO_id);
	return 0;
  
    }else{
    
	printf("ID Correcto:%s", GYRO_id);
	return 1;
  
    }
 }
 
/*
 * Gyro Sensor keeps track of the total rotation angle in degrees 
 * */
short pistorms_gyroAngleEV3(int connector_id){
  
  pistorms_sensor_set_mode(connector_id,ANGLE);
  int x;
    int y;
     for (x=0; x<1000; x++){
       for (y=0; y<10000; y++){
	 
      }
      y=0;
       
      }
  
    angle_data = pistorms_sensor_read(connector_id);
  
   unsigned short value = angle_data[0] + (angle_data[1] << 8);
   short angle_final = (short)value;
   return angle_final;
}


/*
 * Detects rotational motion on a single axis
 * */
short pistorms_gyroRateEV3(int connector_id){
  
  pistorms_sensor_set_mode(connector_id,RATE);
  int x;
    int y;
     for (x=0; x<1000; x++){
       for (y=0; y<10000; y++){
	 
      }
      y=0;
       
      }
  rate_data = pistorms_sensor_read(connector_id);
  
  unsigned short value = rate_data[0] + (rate_data[1] << 8);
  short rate_final = (short)value;
  return rate_final;
  
  
}
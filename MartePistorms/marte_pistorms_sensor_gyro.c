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
 * Gyro Sensor keeps track of the total rotation angle in degrees 
 * */
char * pistorms_gyroAngleEV3(int connector_id){
  
  pistorms_sensor_set_mode(connector_id,ANGLE);
  int x;
    int y;
     for (x=0; x<1000; x++){
       for (y=0; y<10000; y++){
	 
      }
      y=0;
       
      }
  angle_data = pistorms_sensor_read(connector_id);
  return angle_data;
}


/*
 * Detects rotational motion on a single axis
 * */
char * pistorms_gyroRateEV3(int connector_id){
  
  pistorms_sensor_set_mode(connector_id,RATE);
  int x;
    int y;
     for (x=0; x<1000; x++){
       for (y=0; y<10000; y++){
	 
      }
      y=0;
       
      }
  rate_data = pistorms_sensor_read(connector_id);
  return rate_data;
  
  
}
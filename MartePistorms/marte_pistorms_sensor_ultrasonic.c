/**
 * @file marte_pistorms_sensor_ultrasonic.c
 * @author Carlos Ayerbe González
 * @date 8 Feb 2017
 * @brief Driver for control the Ultrasonic of EV3 Sensor.
 * @version 1.0
 *
 */

#include "marte_pistorms.h"
#include "marte_pistorms_sensor_ultrasonic.h"
#include "marte_pistorms_sensors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


char *cm_data;
char *inches_data;

/*
 * Obtains the distance to an object in front of it in centimeters.
 * */
char * pistorms_ultrasonicDistanceCM(int connector_id){
  
  pistorms_sensor_set_mode(connector_id,PROXIMITY_CENTIMETERS);
  int x;
    int y;
     for (x=0; x<1000; x++){
       for (y=0; y<10000; y++){
	 
      }
      y=0;
       
      }
  cm_data = pistorms_sensor_read(connector_id);
  return cm_data;
}


/*
 * Obtains the distance to an object in front of it in inches.
 * */
char * pistorms_ultrasonicDistanceIN(int connector_id){
  
  pistorms_sensor_set_mode(connector_id,PROXIMITY_INCHES);
  int x;
    int y;
     for (x=0; x<1000; x++){
       for (y=0; y<10000; y++){
	 
      }
      y=0;
       
      }
  inches_data = pistorms_sensor_read(connector_id);
  return inches_data;
  
  
}

/*
 * Detect another Ultrasonic Sensor operating nearby.
 * */
int pistorms_ultrasonicPresence(int connector_id){
  
  int value = 0;
  char *presence;
  pistorms_sensor_set_mode(connector_id,PRESENCE);
  presence = pistorms_sensor_read(connector_id);
  value = presence[0];
  return value;
  
}
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


char *mm_data;
char *inches_data;


/*
 * Detects if the Ultrasonic Sensor is connect correctly.
 * */
int pistorms_sensor_proof_ultrasonic(int connector_id){
  
    char *ULTRASONIC_id;
    ULTRASONIC_id = pistorms_get_device_id(connector_id);
    
    if(strcmp(ULTRASONIC_id, ULTRASONIC_SENSOR_ID) != 0){
	
	printf("Error ID:%s",ULTRASONIC_id);
	return 0;
  
    }else{
    
	printf("ID Correcto:%s", ULTRASONIC_id);
	return 1;
  
    }
}
 
/*
 * Obtains the distance to an object in front of it in milimeters.
 * */
int pistorms_ultrasonicDistanceMM(int connector_id){
  
  pistorms_sensor_set_mode(connector_id,PROXIMITY_CENTIMETERS);
   
      int x;
      int y;
      for (x=0; x<1000; x++){
	for (y=0; y<10000; y++){
	  
	}
	y=0;
	
	}
	
  mm_data = pistorms_sensor_read(connector_id);
  unsigned int mm =  mm_data[0] + ( mm_data[1] << 8);
  
  return mm;
}


/*
 * Obtains the distance to an object in front of it in inches.
 * */
int pistorms_ultrasonicDistanceIN(int connector_id){
  
  pistorms_sensor_set_mode(connector_id,PROXIMITY_INCHES);
  
  
    int x;
    int y;
     for (x=0; x<1000; x++){
       for (y=0; y<10000; y++){
	 
      }
      y=0;
       
      }
      
  inches_data = pistorms_sensor_read(connector_id);

  unsigned int in =  inches_data[0] + (inches_data[1] << 8);
  return in;
  
  
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
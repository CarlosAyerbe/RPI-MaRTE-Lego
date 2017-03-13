/**
 * @file marte_pistorms_sensor_ultrasonic.c
 * @author Carlos Ayerbe González
 * @date 8 Feb 2017
 * @brief Driver for control the Ultrasonic of EV3 Sensor.
 * @version 1.0
 *
 */


#include "bcm2835.h"
#include "marte_pistorms.h"
#include "marte_pistorms_sensors.h"
#include "marte_pistorms_sensor_ultrasonic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define DBG
#include "marte_pistorms_internal.h"


char *cm_data;
char *inches_data;
static int ultrasonic_mode = PROXIMITY_CENTIMETERS;
static int presence_mode = -1;

/*
 * Detects if the Ultrasonic Sensor is connect correctly.
 * */
int pistorms_sensor_ultrasonic_configure(int connector_id){
  
  
  pistorms_port_set_type_sensor(connector_id,EV3_TYPE);
  
  char *ULTRASONIC_id;
  ULTRASONIC_id = pistorms_get_device_id(connector_id);
  
  if(strcmp(ULTRASONIC_id, ULTRASONIC_SENSOR_ID) != 0){
    
    printf_dbg("Error ID:%s",ULTRASONIC_id);
    return PISTORMS_ERROR_SENSOR_ID;
    
  }else{
    
    printf_dbg("ID Correcto:%s", ULTRASONIC_id);
    return PISTORMS_REASON_OK;
    
  }
}

/*
 * Obtains the distance to an object in front of it in centimeters.
 * */
float pistorms_ultrasonic_distance_CM(int connector_id){
  
  pistorms_sensor_set_mode(connector_id,PROXIMITY_CENTIMETERS);
  
  float cm_final;
  
  cm_data = pistorms_sensor_read(connector_id);
  unsigned int cm =  cm_data[0] + ( cm_data[1] << 8);
  
  cm_final = (float)cm/10.0;
  return cm_final;
}


/*
 * Obtains the distance to an object in front of it in inches.
 * */
float pistorms_ultrasonic_distance_IN(int connector_id){
  
  pistorms_sensor_set_mode(connector_id,PROXIMITY_INCHES);
  
  float in_final;
  
  inches_data = pistorms_sensor_read(connector_id);
  
  unsigned int in =  inches_data[0] + (inches_data[1] << 8);
  
  in_final = (float)in/10.0;
  
  return in_final;
  
  
}

/*
 * Detect another Ultrasonic Sensor operating nearby.
 * */
int pistorms_ultrasonic_presence(int connector_id){
  
  int value = 0;
  char *presence;
  
  if(presence_mode != PRESENCE){
    
    pistorms_sensor_set_mode(connector_id,PRESENCE);
    presence_mode = PRESENCE;
    
  }
  presence = pistorms_sensor_read(connector_id);
  value = presence[0];
  return value;
}

/*
 * Obtain the measure of  distance to an object in front of it
 * */
float pistorms_ultrasonic_read_distance(int connector_id, int mode){
  
  float cm_final;
  float in_final;
  
  if(mode != ultrasonic_mode){
    
    if(mode == PROXIMITY_CENTIMETERS){
      
      printf_dbg("First CM");
      pistorms_sensor_set_mode(connector_id,PROXIMITY_CENTIMETERS);
      ultrasonic_mode = PROXIMITY_CENTIMETERS;
      
    }else if(mode == INCHES){
      
      printf_dbg("First Inches");
      pistorms_sensor_set_mode(connector_id,PROXIMITY_INCHES);
      ultrasonic_mode = PROXIMITY_INCHES;
      
    }else{
      
      printf_dbg("ERROR MODE");
      return PISTORMS_ERROR_WRONG_CONNECTOR_ID;
    }
  }
  
  cm_data = pistorms_sensor_read(connector_id);
  unsigned int cm =  cm_data[0] + ( cm_data[1] << 8);
  
  cm_final = (float)cm/10.0;
  return cm_final;
}


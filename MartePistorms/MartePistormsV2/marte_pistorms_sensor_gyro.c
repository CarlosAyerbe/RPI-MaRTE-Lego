/**
 * @file marte_pistorms_sensor_gyro.c
 * @author Carlos Ayerbe González
 * @date 8 Feb 2017
 * @brief Driver for control the Gyro of EV3 Sensor.
 * @version 1.0
 *
 */

#include "bcm2835.h"
#include "marte_pistorms.h"
#include "marte_pistorms_sensors.h"
#include "marte_pistorms_sensor_gyro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define DBG
#include "marte_pistorms_internal.h"

char *angle_data;
char *rate_data;
char *gyro_data;
static int gyro_mode = ANGLE;

/*
 * Detects if the Gyro Sensor is connect correctly.
 * */
int pistorms_sensor_gyro_configure(int connector_id){
  
  pistorms_port_set_type_sensor(connector_id,EV3_TYPE);
  
  char *GYRO_id;
  GYRO_id = pistorms_get_device_id(connector_id);
  
  if(strcmp(GYRO_id, GYRO_SENSOR_ID) != 0){
    
    printf_dbg("Error ID:%s",GYRO_id);
    return PISTORMS_ERROR_SENSOR_ID;
    
  }else{
    
    printf_dbg("ID Correcto:%s", GYRO_id);
    return PISTORMS_REASON_OK;
    
  }
}

/*
 * Gyro Sensor keeps track of the total rotation angle in degrees 
 * */
short pistorms_gyro_angle(int connector_id){
  
  pistorms_sensor_set_mode(connector_id,ANGLE);
  
  angle_data = pistorms_sensor_read(connector_id);
  
  unsigned short value = angle_data[0] + (angle_data[1] << 8);
  short angle_final = (short)value;
  return angle_final;
}


/*
 * Detects rotational motion on a single axis
 * */
short pistorms_gyro_rate(int connector_id){
  
  pistorms_sensor_set_mode(connector_id,RATE);
  
  rate_data = pistorms_sensor_read(connector_id);
  
  unsigned short value = rate_data[0] + (rate_data[1] << 8);
  short rate_final = (short)value;
  return rate_final;
  
  
}

/*
 *  Read data of the Gyro Sensor depends on the mode.
 * */
short pistorms_gyro_read(int connector_id, int mode){
  
  if(mode != gyro_mode){
    
    if(mode == ANGLE){
      
      printf_dbg("First ANGLE");
      pistorms_sensor_set_mode(connector_id,ANGLE);
      gyro_mode = ANGLE;
      
    }else if(mode == RATE){
      
      printf_dbg("First RATE");
      pistorms_sensor_set_mode(connector_id,RATE);
      gyro_mode = RATE;
      
    }else{
      
      printf_dbg("ERROR MODE");
      return PISTORMS_ERROR_WRONG_CONNECTOR_ID;
    }
  }
  
  gyro_data = pistorms_sensor_read(connector_id);
  
  unsigned short gyro =  gyro_data[0] + ( gyro_data[1] << 8);
  short gyro_final = (short)gyro;
  
  return gyro_final;
}



/**
 * @file marte_pistorms_sensors.c
 * @author Carlos Ayerbe González
 * @date 6 Feb 2017
 * @brief Drivers for sensors from Pistorms + Raspberry PI model B.
 * @version 1.0
 * 
 */

#include "marte_pistorms_sensors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

char sensor_data[32] = {0};
int data;

/*
 * Configure the Sensor Type Modes.
 * */
int pistorms_port_set_type_sensor(int connector_id, int type){
  
    char bufType[2];
    bufType[0] = 0;
    bufType[1] = type;	/**< Value of Type mode */
    
  //  if (!initialized) {
   //   return PISTORMS_ERROR_NOT_CONNECTOR;
   // }
  
    _set_active_bank(connector_id);
    
     if (connector_id = PORT_1){
	bufType[0] = PORT_TYPE_1;
       
    }else if (connector_id = PORT_2){
	bufType[0] = PORT_TYPE_2;
      
    } else {
      return PISTORMS_ERROR_NOT_CONNECTOR;
      
    }
    
 
    data = bcm2835_i2c_write(bufType,2);
    //bcm2835_i2c_read_register_rs(&type,bufT,1);
   // printf("Type : %d\n",bufT[0]);
    return data;
   
   
}

/*
 * Obtain the mode of EV3 Sensor Modes (Color,Gyro,Infrared,Proximiy)
 * */
int pistorms_sensor_get_mode(int connector_id){
  
    int value = 0;
    char bufSensorMode[10] = {0};
    char sensorMode; 
  
   // if (!initialized) {
//	return PISTORMS_ERROR_NOT_CONNECTOR;
   // }
    
     _set_active_bank(connector_id);
    
     if (connector_id = PORT_1){
	sensorMode = PORT_1_MODE;
       
    }else if (connector_id = PORT_2){
	sensorMode = PORT_2_MODE;
      
    } else {
      return PISTORMS_ERROR_NOT_CONNECTOR;
      
    }
  
    bcm2835_i2c_read_register_rs(&sensorMode,bufSensorMode,1);/**< Read number of bytes of the requerided register*/
    value = bufSensorMode[0];
    return value;
 
}
  

/*
 * Set the mode of EV3 Sensor Modes (Color,Gyro,Infrared,Proximiy)
 * */
int pistorms_sensor_set_mode(int connector_id, int mode){
  
  //  if (!initialized) {
   //   return PISTORMS_ERROR_NOT_CONNECTOR;
   // }
    char bufMode[2];
    bufMode[0] =0;
    bufMode[1] = mode;
    
     _set_active_bank(connector_id);
    
     if (connector_id = PORT_1){
	bufMode[0] = PORT_1_MODE;
       
    }else if (connector_id = PORT_2){
	bufMode[0] = PORT_2_MODE;
      
    } else {
      return PISTORMS_ERROR_NOT_CONNECTOR;
      
    }
    
     data = bcm2835_i2c_write(bufMode,2);
     return data;
 
}  


char * pistorms_sensor_read(int connector_id){
  
    //char bufSensorData[32] = {0};
    char sensorData;
    
  //  if (!initialized) {
   //   return PISTORMS_ERROR_BAD_CONNECTOR;
    //}
   
     _set_active_bank(connector_id);
    
     if (connector_id = PORT_1){
	sensorData = PORT_1_DATA;
       
    }else if (connector_id = PORT_2){
	sensorData = PORT_2_DATA;
      
    } else {
      return PISTORMS_ERROR_BAD_CONNECTOR;
      
    }
  
    bcm2835_i2c_read_register_rs(&sensorData,sensor_data,4);
    return sensor_data;
  
  
}

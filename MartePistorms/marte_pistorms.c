/**
 * @file marte_pistorms.c
 * @author Carlos Ayerbe González
 * @date 17 Jan 2017
 * @brief Drivers for sensors and motors from Pistorms + Raspberry PI model B.
 * @version 1.0
 *
 */

#include "marte_pistorms.h"
#include "bcm2835.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static char initialized = 0;
static char end = 0;
static char active_bank = -1;
static char sensor_data[32] = {0};
char bufSensorID[10] = {0};
int data;


/*
 * Initialise bcm2835 and I2C
 * */
int pistorms_init(void){
  
  if(bcm2835_init() && bcm2835_i2c_begin()){ /**< Initialise bcm2835 and I2C*/
    
      initialized = 1;
      
  }else{
      
      initialized = 0;
  
  }
}


/*
 * Close bcm2835 and I2C
 * */
int pistorms_close(void){
  
  bcm2835_i2c_end();
  
  if(bcm2835_close()){
    
      end = 1;
      
  }else{
      
      end = 0;
  
  }
}

/*
 * Set the specific connector (Bank and Port).
 * */
char _set_active_bank(int connector_id){
  
     printf("Primer active_bank == %x\n", active_bank);
    if(connector_id == (BANK_A & (PORT_1 || PORT_2))){
	if(active_bank == BANK_A){
	   printf("Mismo active_bank A== %x\n", active_bank);
	  return active_bank;
	  
	}else{
	   printf("Slave Address = A\n");
	  bcm2835_i2c_setSlaveAddress(BANK_A_ADDR);
	  active_bank = BANK_A;
	  return active_bank;
	  
	}
	    
      
    }else if(connector_id == (BANK_B & (PORT_1 || PORT_2))){
      if(active_bank == BANK_B){
	 printf("Mismo active_bank B== %x\n", active_bank);
	return active_bank;
	
      }else{
	 printf("Slave Address = B\n");
	bcm2835_i2c_setSlaveAddress(BANK_B_ADDR);
	active_bank = BANK_B;
	return active_bank;
	
      }
      
    }
    printf("ERROR active_bank == %x\n", active_bank);
    return active_bank;
  
}

/*
 * Obtains the ID of the device that is plugged in the correct Bank and Port
 * */
char * pistorms_get_device_id(int connector_id){
  
     if (!initialized) {
	return PISTORMS_ERROR_NOT_INITIALIZED;
    }
    
    _set_active_bank(connector_id);
    
    char sensorID; 
    if (connector_id = PORT_1){
	sensorID = PORT_1_SENSOR_ID;
    }else if (connector_id = PORT_2){
	sensorID = PORT_2_SENSOR_ID;
    } else {
      return PISTORMS_ERROR_BAD_CONNECTOR;
    }
    bcm2835_i2c_read_register_rs(&sensorID,bufSensorID,8);/**< Read number of bytes of the requerided register*/
    return bufSensorID;
    
	
}

/*
 * Configure the Sensor Type Modes.
 * */
int pistorms_port_set_type_sensor(int connector_id, int type){
  
    //char bufT[10] = {0};
    //char type = 0x6F;
    
    char bufType[2];
    bufType[0] = 0;
    bufType[1] = type;	/**< Value of Type mode */
    
    if (!initialized) {
      return PISTORMS_ERROR_NOT_CONNECTOR;
    }
  
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
  
    if (!initialized) {
	return PISTORMS_ERROR_NOT_CONNECTOR;
    }
    
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
  
    if (!initialized) {
      return PISTORMS_ERROR_NOT_CONNECTOR;
    }
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


int pistorms_sensor_read(int connector_id){
  
    //char bufSensorData[32] = {0};
    char sensorData;
    
    if (!initialized) {
      return PISTORMS_ERROR_NOT_CONNECTOR;
    }
   
     _set_active_bank(connector_id);
    
     if (connector_id = PORT_1){
	sensorData = PORT_1_DATA;
       
    }else if (connector_id = PORT_2){
	sensorData = PORT_2_DATA;
      
    } else {
      return PISTORMS_ERROR_NOT_CONNECTOR;
      
    }
  
    data = bcm2835_i2c_read_register_rs(&sensorData,sensor_data,32);
    return data;
  
  
}
  

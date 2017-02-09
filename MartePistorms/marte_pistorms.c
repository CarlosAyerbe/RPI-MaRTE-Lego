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
char bufSensorID[16] = {0};


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
  
     //printf("Primer active_bank == %x\n", active_bank);
    if(connector_id == (BANK_A & (PORT_1 || PORT_2))){
	if(active_bank == BANK_A){
	  // printf("Mismo active_bank A== %x\n", active_bank);
	  return active_bank;
	  
	}else{
	  // printf("Slave Address = A\n");
	  bcm2835_i2c_setSlaveAddress(BANK_A_ADDR);
	  active_bank = BANK_A;
	  return active_bank;
	  
	}
	    
      
    }else if(connector_id == (BANK_B & (PORT_1 || PORT_2))){
      if(active_bank == BANK_B){
	// printf("Mismo active_bank B== %x\n", active_bank);
	return active_bank;
	
      }else{
	// printf("Slave Address = B\n");
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
    bcm2835_i2c_read_register_rs(&sensorID,bufSensorID,16);/**< Read number of bytes of the requerided register*/
    return bufSensorID;
    
	
}

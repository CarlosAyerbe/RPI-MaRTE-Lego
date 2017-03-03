/**
 * @file marte_pistorms_sensor_touch.c
 * @author Carlos Ayerbe González
 * @date 6 Feb 2017
 * @brief Driver for control the Touch of EV3 Sensor.
 * @version 1.0
 *
 */

#include "bcm2835.h"
#include "marte_pistorms.h"
#include "marte_pistorms_sensor_touch.h"
#include "marte_pistorms_sensors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


/*
 * Detects if the Touch Sensor is connect correctly.
 * */
int pistorms_sensor_proof_touch(int connector_id){
  
  //pistorms_port_set_type_sensor(connector_id,TOUCH_TYPE);
  
  char *TOUCH_id;
  TOUCH_id = pistorms_get_device_id(connector_id);
  
  if(strcmp(TOUCH_id, TOUCH_SENSOR_ID) != 0){
    
    printf("Error ID:%s",TOUCH_id);
    return 0;
    
  }else{
    
    printf("ID Correcto:%s", TOUCH_id);
    return 1;
    
  }
}

/*
 *  Check if the sensor is touched.
 * */
int pistorms_isTouchedEV3(int connector_id){
  
  char *istouched;
  int value = 0;
  
  istouched = pistorms_sensor_read(connector_id);
  value = istouched[0];
  return value;
  
}

/*
 * Count how many times the sensor was touched
 * */
int pistorms_numTouchesEV3(int connector_id){
  
  char *numTouches;
  int count = 0;
  
  numTouches = pistorms_sensor_read(connector_id);
  count = numTouches[1];
  return count;
}

/*
 * Reset the count
 * */
void pistorms_resetTouchesEV3(int connector_id){
  
  char bufReset[2];
  bufReset[0] = 0;
  bufReset[1] = 0;
  
  _set_active_bank(connector_id);
  
  if((connector_id == BANK_A_PORT_1) ||(connector_id == BANK_B_PORT_1)){
    bufReset[0] = PORT_1_DATA_RESET;
    
  }else if((connector_id == BANK_A_PORT_2) ||(connector_id == BANK_B_PORT_2)){
    bufReset[0] = PORT_2_DATA_RESET;
    
  } else {
    printf(PISTORMS_ERROR_BAD_CONNECTOR);
    
  }
  bcm2835_i2c_write(bufReset,2);
  
}
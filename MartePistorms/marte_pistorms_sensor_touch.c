/**
 * @file marte_pistorms_sensor_touch.c
 * @author Carlos Ayerbe González
 * @date 6 Feb 2017
 * @brief Driver for control the Touch of EV3 Sensor.
 * @version 1.0
 *
 */

#include "marte_pistorms.h"
#include "marte_pistorms_sensor_touch.h"
#include "marte_pistorms_sensors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


/*
 *  Check if the sensor is touched.
 * */
int pistorms_isTouchedEV3(int connector_id){
  
    char *istouched;
    int value = 0;
    
   // if (!initialized) {
    //  return PISTORMS_ERROR_NOT_CONNECTOR;
    //}
   
   
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
    
    //if (!initialized) {
    //  return PISTORMS_ERROR_NOT_CONNECTOR;
   // }
   
   
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
    //if (!initialized) {
  //    printf(PISTORMS_ERROR_BAD_CONNECTOR);
   // }
   
    _set_active_bank(connector_id);
     
    if (connector_id = PORT_1){
	bufReset[0] = PORT_1_DATA_RESET;
       
    }else if (connector_id = PORT_2){
	bufReset[0] = PORT_2_DATA_RESET;
      
    } else {
      printf(PISTORMS_ERROR_BAD_CONNECTOR);
      
    }
    bcm2835_i2c_write(bufReset,2);
     
}
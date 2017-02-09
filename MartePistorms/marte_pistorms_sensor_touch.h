/**
 * @file marte_pistorms_sensor_touch.h
 * @author Carlos Ayerbe González
 * @date 6 Feb 2017
 * @brief Driver for control the Touch of EV3 Sensor.
 * @version 1.0
 *
 * This is a C library for Raspberry Pi (RPi). It provides control over touch sensor.
 * This sensor gives us if the sensor is touched or not, and the number of times it 
 * has been touched .
 * 
 */


/* Defines for MARTE_PISTORMS_SENSOR_TOUCH*/
#ifndef MARTE_PISTORMS_SENSOR_TOUCH
#define MARTE_PISTORMS_SENSOR_TOUCH

#include "marte_pistorms_sensors.h"

/**
* @brief check if the sensor is touched
* @param connector_id Bank and Port to plug the sensor
* @return  true if it is touched
* 
* Check if the sensor is touched, if it is pressed the function returns True, 
* if not, it returns False.
*/
int pistorms_isTouchedEV3(int connector_id);

/**
* @brief Count how many times the sensor was touched
* @param connector_id Bank and Port to plug the sensor
* @return  count of touches since last reset (or power on)
* 
* With PiStorms it is possible to count how many times the sensor was touched.
* This count is maintained since the PiStorms was powered on. You can reset this 
* count with \ref pistorms_resetTouchesEV3.
*/
int pistorms_numTouchesEV3(int connector_id);

/**
* @brief Reset the count
* @param connector_id Bank and Port to plug the sensor
* 
* With this function, is possible reset the count of touches.
*/
void pistorms_resetTouchesEV3(int connector_id);


#endif /* MARTE_PISTORMS_SENSOR_TOUCH */
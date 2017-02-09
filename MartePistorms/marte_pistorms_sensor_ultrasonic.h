/**
 * @file marte_pistorms_sensor_ultrasonic.h
 * @author Carlos Ayerbe González
 * @date 8 Feb 2017
 * @brief Driver for control the Ultrasonic of EV3 Sensor.
 * @version 1.0
 *
 * This is a C library for Raspberry Pi (RPi). It provides control over ultrasonic sensor.
 * This sensor gives us 
 * 
 */


/* Defines for MARTE_PISTORMS_SENSOR_ULTRASONIC*/
#ifndef MARTE_PISTORMS_SENSOR_ULTRASONIC
#define MARTE_PISTORMS_SENSOR_ULTRASONIC

#include "marte_pistorms_sensors.h"

/**
* @brief Ultrasonic sensor can measure the distance to an object in front of it
* @param connector_id Bank and Port to plug the sensor
* @return  distance to an object in centimeters.
* 
* The detectable distance is between 3 and 250 centimeters 
* (with an accuracy of +/- 1 centimeters).
* A value of 255 centimeters means the sensor is not able to detect any 
* object in front of it.
*/
char * pistorms_ultrasonicDistanceCM(int connector_id);

/**
* @brief Ultrasonic sensor can measure the distance to an object in front of it
* @param connector_id Bank and Port to plug the sensor
* @return  distance to an object in inches.
* 
* The measurable distance is between 1 and 99 inches 
* (with an accuracy of +/- 0.394 inches).
* A value of 100 inches means the sensor is not able to detect any 
* object in front of it.
*/
char * pistorms_ultrasonicDistanceIN(int connector_id);

/**
* @brief Ultrasonic sensor can detect another Ultrasonic Sensor operating nearby.
* @param connector_id Bank and Port to plug the sensor
* @return  1 if there is another Ultrasonic sensor, or 0 if not.
* 
* In Presence Mode, this sensor can detect another Ultrasonic Sensor
* operating nearby. When listening for presence, the sensor detects
* sound signals but does not send them.
*/
int pistorms_ultrasonicPresence(int connector_id);


#endif /* MARTE_PISTORMS_SENSOR_GYRO */
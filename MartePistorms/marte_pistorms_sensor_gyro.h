/**
 * @file marte_pistorms_sensor_gyro.h
 * @author Carlos Ayerbe González
 * @date 8 Feb 2017
 * @brief Driver for control the Gyro of EV3 Sensor.
 * @version 1.0
 *
 * This is a C library for Raspberry Pi (RPi). It provides control over gyro sensor.
 * This sensor gives us 
 * 
 */


/* Defines for MARTE_PISTORMS_SENSOR_GYRO*/
#ifndef MARTE_PISTORMS_SENSOR_GYRO
#define MARTE_PISTORMS_SENSOR_GYRO

#include "marte_pistorms_sensors.h"


/**
* @brief Detects if the Gyro Sensor is connect correctly.
* @param connector_id Bank and Port to plug the sensor
* @return  0 if there is an error, or 1 if the sensor is correct.
* 
* If the Gyro sensor is connect, the function is going to return 1 if it is connect correctly
* or 0 if it isn't.
* 
*/
int pistorms_sensor_proof_ultrasonic(int connector_id);

/**
* @brief Gyro Sensor keeps track of the total rotation angle  in degrees.
* @param connector_id Bank and Port to plug the sensor
* @return  the angle in degrees.
* 
* You can use this rotation angle to detect, for example,
* how far your robot has turned. This feature means you are able to
* program turns (on the axis the Gyro Sensor is measuring) with an
* accuracy of +/- 3 degrees for a 90-degree turn.
*/
short pistorms_gyroAngleEV3(int connector_id);

/**
* @brief Detects rotational motion on a single axis.
* @param connector_id Bank and Port to plug the sensor
* @return  the rotational speed in degrees per second
* 
* If you rotate the Gyro Sensor in the direction
* of the arrows on the case of the sensor, the sensor can detect
* the rate of rotation in degrees per second. (The sensor can measure
* a maximum rate of spin of 440 degrees per second
*/
short pistorms_gyroRateEV3(int connector_id);




#endif /* MARTE_PISTORMS_SENSOR_GYRO */
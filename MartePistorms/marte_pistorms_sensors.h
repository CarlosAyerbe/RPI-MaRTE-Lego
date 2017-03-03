/**
 * @file marte_pistorms_sensors.h
 * @author Carlos Ayerbe González
 * @date 6 Feb 2017
 * @brief Drivers for sensors from Pistorms + Raspberry PI model B.
 * @version 1.0
 *
 * This is a C library for Raspberry Pi (RPi). It provides control and functions
 * for using sensors in Pistorms brick. 
 */


/* Defines for MARTE_PISTORMS_SENSORS */
#ifndef MARTE_PISTORMS_SENSORS 
#define MARTE_PISTORMS_SENSORS 

#include "marte_pistorms.h"
/**
 * @brief Determine sensor type on the specified port.
 * @param connector_id Bank and Port to plug the Touch sensor
 * @param type the type of the sensor which is plugged.
 * @return reason see \ref bcm2835I2CReasonCodes
 * 
 * Configure the type mode on the specified port.
 * Default Type Modes in Pistorms is EV3 ----> value 19. So it is neccesary to change this value to use
 * other types of sensors.
 * 
 */
int pistorms_port_set_type_sensor(int connector_id,int type);

/**
 * @brief Obtain the mode that the EV3 Sensor is running.
 * @param connector_id Bank and Port to plug the EV3 sensor
 * @return value depends on the mode of the sensor(value ---> 0,1 or 2)
 * 
 * Gets the  mode of EV3 Sensor. 
 * Default mode is 0 for all EV3 Sensors.
 * Gyro Sensor --- 
 * 		|--->value = 0 -> ANGLE
 * 		|--->value = 1 -> RATE
 * Color Sensor --- 
 * 		  |--->value = 0 -> REFLECTED_LIGHT
 * 		  |--->value = 1 -> AMBIENT_LIGHT
 * 		  |--->value = 2 -> MEASURE_COLOR
 * Infrared Sensor --- 
 * 		    |--->value = 0 -> PROXIMITY
 * 		    |--->value = 1 -> BEACON
 * 		    |--->value = 2 -> REMOTE
 * Ultrasonic Sensor --- 
 * 		      |--->value = 0 -> PROXIMITY_CENTIMETERS
 * 		      |--->value = 1 -> PROXIMITY_INCHES
 * 		      |--->value = 2 -> PRESENCE
 */
int pistorms_sensor_get_mode(int connector_id);

/**
 * @brief Set the mode for the EV3 Sensor.
 * @param connector_id Bank and Port to plug the EV3 sensor
 * @param mode Mode of the Sensor
 * @return reason see \ref bcm2835I2CReasonCodes
 * 
 * Gets the  mode of EV3 Sensor. 
 * Default mode is 0 for all EV3 Sensors.
 * Gyro Sensor --- 
 * 		|--->value = 0 -> ANGLE
 * 		|--->value = 1 -> RATE
 * Color Sensor --- 
 * 		  |--->value = 0 -> REFLECTED_LIGHT
 * 		  |--->value = 1 -> AMBIENT_LIGHT
 * 		  |--->value = 2 -> MEASURE_COLOR
 * Infrared Sensor --- 
 * 		    |--->value = 0 -> PROXIMITY
 * 		    |--->value = 1 -> BEACON
 * 		    |--->value = 2 -> REMOTE
 * Ultrasonic Sensor --- 
 * 		      |--->value = 0 -> PROXIMITY_CENTIMETERS
 * 		      |--->value = 1 -> PROXIMITY_INCHES
 * 		      |--->value = 2 -> PRESENCE
 */
int pistorms_sensor_set_mode(int connector_id, int mode);

/**
 * @brief Read the data of EV3 sensors.
 * @param connector_id Bank and Port to plug the EV3 sensor
 * @return the buffer with the data which the sensor is reading.
 * 
 * Gets the data that the sensor is reading in real time.
 * The functions is going to rreturn the buffer with this information
 * 
 */
char * pistorms_sensor_read(int connector_id);


#endif /* MARTE_PISTORMS_SENSORS */
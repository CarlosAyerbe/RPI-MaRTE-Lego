/**
 * @file marte_pistorms_brick.h
 * @author Carlos Ayerbe González
 * @date 9 Feb 2017
 * @brief Driver for control the brick of Pistorms.
 * @version 1.0
 *
 * This is a C library for Raspberry Pi (RPi). It provides control over brick of Pistorms.
 * This sensor gives us the control of the leds, GO button , battery voltage and screen.
 * 
 */


/* Defines for MARTE_PISTORMS_BRICK*/
#ifndef MARTE_PISTORMS_BRICK
#define MARTE_PISTORMS_BRICK

#include "marte_pistorms_sensors.h"

/**
* @brief 
* @param connector_id 
* @return  
* 
* 
* 
*/
void pistorms_brick_led_On(int connector_id, int red, int green, int blue);

/**
* @brief 
* @param connector_id 
* @return  
* 
*
*/
void pistorms_brick_led_Off(int connector_id);



/**
* @brief 
* @param connector_id 
* 
* 
*/
char * pistorms_brick_get_firmware_version(int connector_id);

/**
* @brief 
* @param connector_id 
* 
* 
*/
char * pistorms_brick_get_vendor_id(int connector_id);


/**
* @brief 
* @param connector_id 
* 
* 
*/
char * pistorms_brick_get_device_id(int connector_id);

/**
* @brief 
* 
* 
* 
*/
char * pistorms_brick_get_battery_voltage(void);


/**
* @brief 
* 
* 
*/
int pistorms_brick_get_key_press_value(void);

/**
* @brief 
* 
* 
*/
int pistorms_brick_get_key_press_count(void);

/**
* @brief 
* 
* 
*/
void pistorms_brick_reset_key_press_count(void);

/**
* @brief 
* 
* 
*/
int pistorms_brick_touch_screec_X_asis(void);

/**
* @brief 
* 
* 
*/
int pistorms_brick_touch_screec_Y_asis(void);


#endif /* MARTE_PISTORMS_BRICK */
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
 * @brief Sets the I2C slave address.
 * @param bank_id Bank to configure.
 * @return  the value of active_bank
 * 
 * Sets the I2C slave address (BANK_A or BANKB_B).
 * But if the current slave address is the same than the connector_id, the function
 * doesn't set again the slave address because it is not neccessary.
 */
char _set_active_bank_brick(int bank_id);

/**
 * @brief Writes to the specified RGB LED. 
 * @param bank_id the Bank
 *
 * Turn on the led of the specified Bank.
 * Writes to the specified RGB LED.
 * 
 * 
 */
void pistorms_brick_led_On(int bank_id, int red, int green, int blue);

/**
 * @brief Turn off the led.
 * @param bank_id the Bank
 * 
 * Turn off the led of the specified Bank.
 * 
 */
void pistorms_brick_led_Off(int bank_id);



/**
 * @brief Returns the PiStorms firmware version
 * @param bank_id the Bank
 * @return  the PiStorms firmware version. 
 * 
 * 
 * Returns the PiStorms firmware version of the Bank selected.
 * 
 */
char * pistorms_brick_get_firmware_version(int bank_id);

/**
 * @brief Returns the PiStorms vendor ID.
 * @param bank_id the Bank
 * @return the PiStorms vendor ID.
 * 
 * Returns the PiStorms vendor ID.
 * 
 */
char * pistorms_brick_get_vendor_id(int bank_id);


/**
 * @brief Returns the PiStorms device ID.
 * @param bank_id the Bank
 * @return the PiStorms device ID.
 * 
 * Returns the PiStorms device ID.
 * 
 */
char * pistorms_brick_get_device_id(int bank_id);

/**
 * @brief Obtains the input battery voltage. 
 * @return input battery voltage. 
 * 
 * Returns the input battery voltage. 
 * 
 */
int pistorms_brick_get_battery_voltage(void);


/**
 * @brief Check if any button GO is pressed
 * @return 1 if it is pressed or 0 if not.
 * 
 */
int pistorms_brick_get_key_press_value(void);

/**
 * @brief Obatins the GO button press count. 
 * @return GO button press count. 
 * 
 * Returns the number of times that GO button is pressed.
 * 
 */
int pistorms_brick_get_key_press_count(void);

/**
 * @brief Resets the GO button press count. 
 * 
 * Change the count of GO button to 0. 
 * 
 */
void pistorms_brick_reset_key_press_count(void);

/**
 * @brief Obtain the value of the X asis
 * @return the value of the X asis.
 * 
 * If the touch screen is touched, this function is going
 * to return the value of the X asis
 * 
 */
char * pistorms_brick_touch_screen_X_asis(void);

/**
 * 
 * @brief Obtain the value of the Y asis
 * @return the value of the Y asis.
 * 
 * If the touch screen is touched, this function is going
 * to return the value of the Y asis
 * 
 * 
 */
char * pistorms_brick_touch_screen_Y_asis(void);

/**
 * @brief Detects if touchsreen is Touched.
 * @return 0 if screen is not touched or 1 if it is touched.
 * 
 * Detects if touchsreen is Touched.
 */
int pistorms_brick_screen_is_touched(void);


#endif /* MARTE_PISTORMS_BRICK */
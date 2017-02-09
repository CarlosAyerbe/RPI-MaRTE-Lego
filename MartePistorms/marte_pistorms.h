/**
 * @file marte_pistorms.h
 * @author Carlos Ayerbe González
 * @date 17 Jan 2017
 * @brief Drivers for sensors and motors from Pistorms + Raspberry PI model B.
 * @version 1.0
 *
 * This is a C library for Raspberry Pi (RPi). It provides access to 
 * GPIO and other IO functions on the Broadcom BCM 2835 chip,
 * allowing access to the GPIO pins on the 26 pin IDE plug on the RPi board so you can control and interface with various external devices.
 * It provides functions for reading digital inputs and setting digital outputs, using I2C.
 */



/* Defines for MARTE_PISTORMS */
#ifndef MARTE_PISTORMS
#define MARTE_PISTORMS


#define PORT_1 1
#define PORT_2 2

/*! Addreses of Pistorms' Banks */
#define BANK_A	1
#define BANK_B	2
#define BANK_A_ADDR	0x1a
#define BANK_B_ADDR	0x1b


/*! I2C Registers for Sensor Modes */
#define  PORT_TYPE_1	0x6F
#define  PORT_TYPE_2  	0xA3

/*! Registers for EV3 Sensors  */
#define PORT_1_READY		0x70
#define PORT_1_SENSOR_ID	0x71
#define PORT_1_MODE		0x81
#define PORT_1_DATA		0x83
#define PORT_1_DATA_RESET	0x84

#define PORT_2_READY		0xA4
#define PORT_2_SENSOR_ID	0xA5	
#define PORT_2_MODE		0xB5
#define PORT_2_DATA		0xB7
#define PORT_2_DATA_RESET	0xB8

/*! IDs of EV3 Sensors  */
#define GYRO_SENSOR_ID		"GYRO-RATE"
#define TOUCH_SENSOR_ID		"Touch"
#define ULTRASONIC_SENSOR_ID	"US-DIST-CM"

/* Sensor Type Modes */
#define PS_SENSOR_TYPE_EV3_SWITCH 18
#define TOUCH_TYPE		18
#define EV3_TYPE		19

/* Modes of EV3 Sensors */

/* Color */
#define REFLECTED_LIGHT	0
#define AMBIENT_LIGHT	1
#define MEASURE_COLOR	2

/* Gyro */
#define ANGLE		0
#define RATE		1

/* Infrared */
#define PROXIMITY	0
#define BEACON		1
#define REMOTE		2

/* Ultrasonic */
#define PROXIMITY_CENTIMETERS	0
#define PROXIMITY_INCHES	1
#define PRESENCE		2


/* Reason codes */
#define PISTORMS_ERROR_NOT_INITIALIZED  "ERROR"
#define PISTORMS_ERROR_NOT_CONNECTOR	0x01
#define PISTORMS_ERROR_BAD_CONNECTOR	"ERROR"

/*I2C Registers for Buttons and LEDs*/
#define PISTORMS_LED_RED_VALUE		0xD7
#define PISTORMS_LED_GREEN_VALUE	0xD8
#define PISTORMS_LED_BLUE_VALUE		0xD9
#define PISTORMS_INPUT_BUTTON_VALUE	0xDA
#define PISTORMS_INPUT_BUTTON_COUNT	0xDB
#define PISTORMS_INPUT_TOUCH_SCREEN_X	0xE3
#define PISTORMS_INPUT_TOUCH_SCREEN_Y	0xE5
#define PISTORMS_INPUT_BATTERY_VOLTAGE	0x6E

/**
* @brief Initialise the bcm2835 library and start I2C operations 
* @return  return 1 if successful else 0
* 
* Initialise the bcm2835 calling the function bcm2835_init() and start I2C 
* operations calling bcm2835_i2c_begin(), if there is some error the
* function is going to return 0 , if not the function is going to return 1.
* 
*/
int pistorms_init(void);


/**
* @brief Close the bcm2835 library and end I2C operations 
* @return  return 1 if successful else 0
* 
* Close the bcm2835 calling the function bcm2835_close() and end I2C 
* operations calling bcm2835_i2c_end(), if there is some error the
* function is going to return 0 , if not the function is going to return 1.
* 
*/
int pistorms_close(void);


/**
* @brief Sets the I2C slave address.
* @param connector_id Bank and Port to plug the sensor
* @return  the value of active_bank, -1 if is incorrect
* 
* Sets the I2C slave address (BANK_A or BANKB_B).
* But if the current slave address is the same than the connector_id, the function
* doesn't set again the slave address because it is not neccessary.
*/
char _set_active_bank(int connector_id);


/**
* @brief Obtain the ID of the sensor
* @param connector_id Bank and Port to plug the sensor
* @return  the ID of the sensor if it is plugged in,if not error. 
* 
* Obtains the ID of the Sensor which is plugged in the correct port of the Pistorms.
* For a correct result, it is neccesary to indicate the bank and port that the sensor
* is plugged in. If the sensor is connected in other port or bank, the function returns
* an error.
* 
*/
char * pistorms_get_device_id(int connector_id);



#endif /* MARTE_PISTORMS */
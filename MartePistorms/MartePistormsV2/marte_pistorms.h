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


/*! Addreses of Pistorms' Banks */
#define BANK_A	1
#define BANK_B	2
#define BANK_A_ADDR	0x1a
#define BANK_B_ADDR	0x1b

#define BANK_A_PORT_1 1
#define BANK_A_PORT_2 2
#define BANK_B_PORT_1 3
#define BANK_B_PORT_2 4

/*! \brief PistormsCodes  
 P istorms codes for the re*sult of some functions   
 */

#define PISTORMS_REASON_OK			1 /*!< Success */
#define PISTORMS_ERROR_WRONG_CONNECTOR_ID	-1 /*!< Incorrect Port or Bank */
#define PISTORMS_INITIALIZATION_OK		1 /*!< Initialization success */
#define PISTORMS_ERROR_INITIALIZATION		0 /*!< Can not be initialize */
#define PISTORMS_CLOSE_OK			1 /*!< Close success */
#define PISTORMS_ERROR_CLOSE			0 /*!< Can not close */
#define PISTORMS_ERROR_SENSOR_ID		0 /*!< Wrong sensro ID */
#define PISTORMS_ERROR_BAD_CONNECTOR		"ERROR" /*!< Incorrect Port or Bank */
#define PISTORMS_ERROR_NOT_INITIALIZED  	"ERROR" /*!< Can not be initialize */



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
int _set_active_bank(int connector_id);


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
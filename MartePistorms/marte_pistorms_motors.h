/**
 * @file marte_pistorms_motors.h
 * @author Carlos Ayerbe González
 * @date 16 Feb 2017
 * @brief Drivers for motors from Pistorms + Raspberry PI model B.
 * @version 1.0
 *
 * This is a C library for Raspberry Pi (RPi). It provides control and functions
 * for using motors in Pistorms brick. 
 */


/* Defines for MARTE_PISTORMS_MOTORS*/
#ifndef MARTE_PISTORMS_MOTORS 
#define MARTE_PISTORMS_MOTORS 

#include "marte_pistorms.h"

/**
 * @brief  Sets the I2C slave address.
 * @param connector_id Bank to plug the motors
 * @return the value of active_bank, -1 if is incorrect
 * 
 * 
 * Sets the I2C slave address (BANK_A or BANKB_B).
 * But if the current slave address is the same than the connector_id, the function
 * doesn't set again the slave address because it is not neccessary.
 * 
 * */
char _set_sync_bank(int bank_id);

/**
 * @brief Turn on the motor with an indicated configuration
 * @param connector_id Bank and Port to plug the motor
 * @param go indicate the mode that the motor is going to run
 * 
 * This function power up the motor with a specified configuration.
 * It is necessary say which parameters you have changed:
 * 	For example if you want to run the motor for 5 seconds with 50 of speed you have to do:
 * 
 * 		1º Call the function pistorms_motor_run_secs(int connector_id, int time)
 * 		2º Call the function  pistorms_motor_set_speed(int connector_id,int speed)
 * 		3º Call this function pistorms_motor_go(int connector_id, SPEED_GO | TIME_GO)
 * 		
 * 		The param char go have different values : see \ref pistorms.h
 * 
 *		SPEED_GO
 *		RAMP_SPEED		
 *		CHANGE_BASED_ON_ENCODER	
 *		ENCODER_GO		
 *		BRAKE_FLOAT_MOVEMENT	
 *		ENCODER_ACTIVE_FEEDBACK	
 *		TIME_GO			
 *		MOTOR_GO		
 *
 */
void pistorms_motor_go(int connector_id, char go);

/**
 * @brief Obtains the current encoder position of the motor
 * @param connector_id Bank and Port to plug the motor
 * @return  the current encoder position of the motor.
 * 
 * Returns the current encoder position of the motor.
 * When the motor rotates clockwise, the position will increase.
 * Likewise, rotating counter-clockwise causes the position to decrease. 
 */
long pistorms_motor_get_pos(int connector_id);

/**
 * @brief Set up the encoder of the motor with a new position
 * @param connector_id Bank and Port to plug the motor
 * @param long The position that the encoder of the motor is going to achieve.
 *  
 * The encoder of the motor is going to have a new value.
 *
 */
void pistorms_motor_set_pos(int connector_id, long pos);

/**
 * @brief Resets the encoder position of the specified motor.
 * @param connector_id Bank and Port to plug the motor
 * 
 * The encoder of the motor is going to be 0.
 * When the motor rotates clockwise, the position will increase. 
 * Likewise, rotating counter-clockwise causes the position to decrease. 
 */
void pistorms_motor_reset_pos(int connector_id);

/**
 * @brief Reset all Encoder values and motor parameters.
 * @param bank_id Bank with the motors.
 * 
 * Reset all Encoder values and motor parameters. (This
 * does not reset the PID parameters).
 *
 */
void pistorms_motor_reset_all_parameters(int bank_id);

/**
 * @brief  Run the motor at a set speed for an unlimited duration
 * @param connector_id Bank and Port to plug the motor
 * @param speed 	The speed at which to turn the motor.
 * 
 *  Run the motor at a set speed for an unlimited duration
 *  The value of speed is from 1 to 100. The max power is 100. It is like
 *  the percentage of the motor's power.
 */
void pistorms_motor_set_speed(int connector_id,int speed);

/**
 * @brief Run motor in time mode
 * @param connector_id Bank and Port to plug the motor
 * @param time Secs that the motor is going to run
 *
 * Run the motor for a specific time in seconds. 
 * To run the motor in time mode, it is neccesary to specified the speed to with the function \ref pistorms_motor_set_speed
 */
void pistorms_motor_set_secs(int connector_id, int time);

/**
 * @brief Stop the motor smoothly with float
 * @param connector_id Bank and Port to plug the motor
 * 
 * Stop the motor smoothly with float.
 * This function only goes with Large Motor, if it is used for Medium Motor it will stop as a break.
 */
void pistorms_motor_float(int connector_id);

/**
 * @brief Stop both the motors of said bank at the same time motors are stopped smoothly with float
 * @param bank_id the Bank
 *  
 * Motors are stopped smoothly with float You can call this function on any motor of that bank and it will
 * work on both motors of that bank. 
 * This function only goes with Large Motor, if it is used for Medium Motor it will stop as a break.
 */
void pistorms_motor_float_sync(int bank_id);

/**
 * @brief Stop the motor abruptly with brake
 * @param connector_id Bank and Port to plug the motor
 * 
 * 
 * Stop the motor abruptly with brake. 
 */
void pistorms_motor_break(int connector_id);

/**
 * @brief Stop both the motors of said bank at the same time motors are stopped abruptly with a brake
 * @param bank_id the Bank
 * 
 * 
 * Motors are stopped with a brake. You can call this function on any motor of that bank and it will 
 * work on both motors of that bank.
 */
void pistorms_motor_break_sync(int bank_id);




#endif /* MARTE_PISTORMS_MOTORS */
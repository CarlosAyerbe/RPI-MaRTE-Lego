/**
 * @file marte_pistorms_brick.c
 * @author Carlos Ayerbe González
 * @date 9 Feb 2017
 * @brief Driver for control the Touch of EV3 Sensor.
 * @version 1.0
 *
 */

#include "marte_pistorms.h"
#include "marte_pistorms_brick.h"
#include "marte_pistorms_sensors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static char active_brick_bank = -1;
/*
 * Set the specific connector (Bank)
 * */
char _set_active_bank_brick(int bank_id){
  
     //printf("Primer active_bank == %x\n", active_bank);
    if(bank_id== BANK_A){
	if(active_brick_bank == BANK_A){
	  // printf("Mismo active_bank A== %x\n", active_bank);
	  return active_brick_bank;
	  
	}else{
	  // printf("Slave Address = A\n");
	  bcm2835_i2c_setSlaveAddress(BANK_A_ADDR);
	  active_brick_bank = BANK_A;
	  return active_brick_bank;
	  
	}
	    
      
    }else if(bank_id == BANK_B){
      if(active_brick_bank == BANK_B){
	// printf("Mismo active_bank B== %x\n", active_bank);
	return active_brick_bank;
	
      }else{
	// printf("Slave Address = B\n");
	bcm2835_i2c_setSlaveAddress(BANK_B_ADDR);
	active_brick_bank = BANK_B;
	return active_brick_bank;
	
      }
      
    }
    printf("ERROR active_bank == %x\n", active_brick_bank);
    return active_brick_bank;
  
}
/*
 *  
 * */
void pistorms_brick_led_On(int bank_id, int red, int green, int blue){
  
      _set_active_bank_brick(bank_id);
      
      char bufLedRed[2];
      bufLedRed[0]=PISTORMS_LED_RED_VALUE;
      bufLedRed[1]=red;
      
      bcm2835_i2c_write(bufLedRed,2);
      
      char bufLedGreen[2];
      bufLedGreen[0]=PISTORMS_LED_GREEN_VALUE;
      bufLedGreen[1]=green;
      
      bcm2835_i2c_write(bufLedGreen,2);
      
      char bufLedBlue[2];
      bufLedBlue[0]=PISTORMS_LED_BLUE_VALUE;
      bufLedBlue[1]=blue;
      
      bcm2835_i2c_write(bufLedBlue,2);
    
    
}


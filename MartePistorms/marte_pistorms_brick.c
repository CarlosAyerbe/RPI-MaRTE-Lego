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
char bufData[32] = {0};

/*
 * Set the specific connector (Bank).
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
 * Turn on the LEDs
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

/*
 * Turn off the LEDs
 * */
void pistorms_brick_led_Off(int bank_id){
  
  _set_active_bank_brick(bank_id);
  
  char bufLedRed[2];
  bufLedRed[0]=PISTORMS_LED_RED_VALUE;
  bufLedRed[1]= 0;
  
  bcm2835_i2c_write(bufLedRed,2);
  
  char bufLedGreen[2];
  bufLedGreen[0]=PISTORMS_LED_GREEN_VALUE;
  bufLedGreen[1]= 0;
  
  bcm2835_i2c_write(bufLedGreen,2);
  
  char bufLedBlue[2];
  bufLedBlue[0]=PISTORMS_LED_BLUE_VALUE;
  bufLedBlue[1]= 0;
  
  bcm2835_i2c_write(bufLedBlue,2);
  
  
}

/*
 * Read the firmware version of the i2c device. 
 * */
char * pistorms_brick_get_firmware_version(int bank_id){
  
  _set_active_bank_brick(bank_id);
  
  char firmwareVersion = PISTORMS_FIRMWARE_VERSION;
  char bufFirmware[10] = {0};
  
  bcm2835_i2c_read_register_rs(&firmwareVersion,bufData,8);
  return bufData;
  
  
}

/*
 * Read the vendor name of the i2c device. 
 * */
char * pistorms_brick_get_vendor_id(int bank_id){
  
  _set_active_bank_brick(bank_id);
  
  char vendorID = PISTORMS_VENDOR_ID;
  char bufVendorID[10] = {0};
  
  bcm2835_i2c_read_register_rs(&vendorID,bufData,8);
  return bufData;
  
}

/*
 * Read the i2c device id. 
 * */
char * pistorms_brick_get_device_id(int bank_id){
  
  _set_active_bank_brick(bank_id);
  
  char deviceID = PISTORMS_DEVICE_ID;
  char bufDeviceID[10] = {0};
  
  bcm2835_i2c_read_register_rs(&deviceID,bufData,8);
  return bufData;
  
}

/*
 * Reads the battery of the Pistorms.
 * */
int pistorms_brick_get_battery_voltage(void){
  
  char batteryVol = PISTORMS_INPUT_BATTERY_VOLTAGE;
  char bufBatteryVol[10] = {0};
  int battery;
  
  bcm2835_i2c_read_register_rs(&batteryVol,bufBatteryVol,1);
  battery = bufBatteryVol[0];
  return battery;
  
}


/*
 * Reads if the button GO is pressed.
 * */
int pistorms_brick_get_key_press_value(void){
  
  
  char valueButton = PISTORMS_INPUT_BUTTON_VALUE;
  char bufValue[10] = {0};
  int value;
  
  bcm2835_i2c_read_register_rs(&valueButton,bufValue,1);
  value = bufValue[0];
  return value;
  
}

/*
 * Obtains the times that the button GO is pressed.
 * */
int pistorms_brick_get_key_press_count(void){
  
  char countButton = PISTORMS_INPUT_BUTTON_COUNT;
  char bufCount[10] = {0};
  int count;
  
  bcm2835_i2c_read_register_rs(&countButton,bufCount,1);
  count = bufCount[0];
  return count;
  
}

/*
 * Reset the count of the button GO.
 * */
void pistorms_brick_reset_key_press_count(void){
  
  char bufReset[2];
  bufReset[0]=PISTORMS_INPUT_BUTTON_COUNT;
  bufReset[1]= 0;
  
  bcm2835_i2c_write(bufReset,2);
}

/*
 * Reads the x-coordinate of the touchscreen press
 * */ 
char bufAsisX[10] = {0};
char * pistorms_brick_touch_screen_X_asis(void){
  
  char asis_X = PISTORMS_INPUT_TOUCH_SCREEN_X;
  int x;
  
  bcm2835_i2c_read_register_rs(&asis_X,bufAsisX,2);
  
  return bufAsisX;
}

/*
 * Reads the y-coordinate of the touchscreen press
 * */
char bufAsisY[10] = {0};
char * pistorms_brick_touch_screen_Y_asis(void){
  
  char asis_Y = PISTORMS_INPUT_TOUCH_SCREEN_Y;
  int y;
  
  bcm2835_i2c_read_register_rs(&asis_Y,bufAsisY,2);
  
  return bufAsisY;
  
} 

/*
 * Detects touchscreen is touched.
 * */
int pistorms_brick_screen_is_touched(void){
  
  char *x;
  char *y;
  
  x = pistorms_brick_touch_screen_X_asis();
  y = pistorms_brick_touch_screen_Y_asis();
  
  if((x[0] == 0) && (y[0] ==0)){
    
    return 0;
    
  }else{
    
    return 1;
    
  }
  
  
}





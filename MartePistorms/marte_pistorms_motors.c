/**
 * @file marte_pistorms_motors.c
 * @author Carlos Ayerbe González
 * @date 16 Feb 2017
 * @brief Drivers for motors from Pistorms + Raspberry PI model B.
 * @version 1.0
 * 
 */

#include "marte_pistorms_motors.h"
#include "marte_pistorms.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

char motor_data[32] = {0};
int data;
static char sync_bank = -1;


/*
 * Set the specific Bank
 * */
char _set_sync_bank(int bank_id){
    
  // printf("Primer sync_bank == %x\n", sync_bank);
    if(bank_id == BANK_A) {
    
	if(sync_bank == BANK_A){
	  // printf("Mismo sync_bank A== %x\n", sync_bank);
	  return sync_bank;
	  
	}else{
	 //  printf("Slave Address = A\n");
	  bcm2835_i2c_setSlaveAddress(BANK_A_ADDR);
	  sync_bank = BANK_A;
	  return sync_bank;
	  
	}
	    
      
    }else if(bank_id == BANK_B) {
      if(sync_bank == BANK_B){
	// printf("Mismo sync_bank B== %x\n", sync_bank);
	return sync_bank;
	
      }else{
	// printf("Slave Address = B\n");
	bcm2835_i2c_setSlaveAddress(BANK_B_ADDR);
	sync_bank = BANK_B;
	return sync_bank;
	
      }
      
    }
    printf("ERROR sync_bank == %x\n", sync_bank);
    return sync_bank;
  
}

/*
 * Turn on the motor with an indicated configuration
 * */
void pistorms_motor_go(int connector_id, char go ){
  
	 _set_active_bank(connector_id);
      
	char go_motor = go | MOTOR_GO;
	
	char writeGo[2];
	writeGo[0] = 0;
	writeGo[1] = go_motor;
      
      if((connector_id == BANK_A_PORT_1) ||(connector_id == BANK_B_PORT_1)){
	
	  writeGo[0] = PISTORMS_MOTOR_1_COMMAND_REGISTER_A;
	
	
      }else if((connector_id == BANK_A_PORT_2) ||(connector_id == BANK_B_PORT_2)){
	
	  writeGo[0] = PISTORMS_MOTOR_2_COMMAND_REGISTER_A;
	
      } else {
	printf("Error");
	
      }
     
	bcm2835_i2c_write(writeGo,2);
  
}

/*
 * Obtains the current encoder position of the motor
 * */
long pistorms_motor_get_pos(int connector_id){
  
      char target = 0;
	
      _set_active_bank(connector_id);
      
     if((connector_id == BANK_A_PORT_1) ||(connector_id == BANK_B_PORT_1)){
     
	target = PISTORMS_MOTOR_1_ENCODER_POSITION;
	
	
      }else if((connector_id == BANK_A_PORT_2) ||(connector_id == BANK_B_PORT_2)){
	
	 target = PISTORMS_MOTOR_2_ENCODER_POSITION;
	
      } else {
	
	  printf("Error");
      
      }
      
      bcm2835_i2c_read_register_rs(&target,motor_data,4);
      
      unsigned long value = motor_data[0] + (motor_data[1] << 8) + (motor_data[2] << 16) + (motor_data[3] << 24);
      long pos_final = (long)value;
      return pos_final;
}

/*
 * Set up the encoder of the motor with a new position
 * */
void pistorms_motor_set_pos(int connector_id, long pos){
  
      
      
      char* final_pos = (char*)&pos;
    
      char writeTarget[5];
      writeTarget[0] = 0;
      writeTarget[1] = final_pos[0];
      writeTarget[2] = final_pos[1];
      writeTarget[3] = final_pos[2];
      writeTarget[4] = final_pos[3];
         
      _set_active_bank(connector_id);
      
      
      if((connector_id == BANK_A_PORT_1) ||(connector_id == BANK_B_PORT_1)){
     
	  writeTarget[0] = PISTORMS_MOTOR_1_ENCODER_TARGET;
	
      }else if((connector_id == BANK_A_PORT_2) ||(connector_id == BANK_B_PORT_2)){
	
	   writeTarget[0] =  PISTORMS_MOTOR_2_ENCODER_TARGET;
	
      } else {
	  printf("Error");
      
      }
     
      bcm2835_i2c_write(writeTarget,5);
      
}

/*
 * Resets the encoder position of the specified motor.
 * */
void pistorms_motor_reset_pos(int connector_id){
  
  
     char writeCMD[2];
     writeCMD[0] = PISTORMS_MOTOR_COMMANDS;
     writeCMD[1] = 0;
     
     _set_active_bank(connector_id);
     
      if((connector_id == BANK_A_PORT_1) ||(connector_id == BANK_B_PORT_1)){
      
      writeCMD[1] = PISTORMS_MOTOR_1_ENCODER_RESET;
	  
	  
      }else if((connector_id == BANK_A_PORT_2) ||(connector_id == BANK_B_PORT_2)){
	  
      writeCMD[1] = PISTORMS_MOTOR_2_ENCODER_RESET;
	  
      } else {
	printf("Error");
	
      }
      
      bcm2835_i2c_write(writeCMD,2);
}


/*
 * Resets all parameters of the specified motor.
 * */
void pistorms_motor_reset_all_parameters(int bank_id){
  
   
      char writeCMD[2];
      writeCMD[0] = PISTORMS_MOTOR_COMMANDS;
      writeCMD[1] = PISTORMS_MOTORS_PARAMETERS_RESET;
	
      _set_sync_bank(bank_id);
      
      bcm2835_i2c_write(writeCMD,2);
}
  
/*
 * Run the motor at a set speed for an unlimited duration
 * */
void pistorms_motor_set_speed(int connector_id,int speed){
  
    char writeSpeed[2];
    writeSpeed[0] = 0;
    writeSpeed[1] = speed;

    _set_active_bank(connector_id);
    
    if((connector_id == BANK_A_PORT_1) ||(connector_id == BANK_B_PORT_1)){
	
      writeSpeed[0] = PISTORMS_MOTOR_1_SPEED;
	
    }else if((connector_id == BANK_A_PORT_2) ||(connector_id == BANK_B_PORT_2)){
	
      writeSpeed[0] = PISTORMS_MOTOR_2_SPEED;
	
    } else {
      printf("Error");
      
    }
    
      bcm2835_i2c_write(writeSpeed,2);
     
}	

/*
 * Run motor in time mode
 * */
void pistorms_motor_set_secs(int connector_id, int time){
  
      char writeTime[2];
      writeTime[0] = 0;
      writeTime[1] = time;
  
      _set_active_bank(connector_id);
    
      if((connector_id == BANK_A_PORT_1) ||(connector_id == BANK_B_PORT_1)){
	
	  writeTime[0] = PISTORMS_MOTOR_1_TIME;
	  
	  
      }else if((connector_id == BANK_A_PORT_2) ||(connector_id == BANK_B_PORT_2)){
	  
	  writeTime[0] = PISTORMS_MOTOR_2_TIME;
	  
      } else {
	printf("Error");
	
      }
      
      bcm2835_i2c_write(writeTime,2);
      
}


/*
 * Stop the motor smoothly with float
 * */
void pistorms_motor_float(int connector_id){
  
  
      char writeCMD[2];
      writeCMD[0] = PISTORMS_MOTOR_COMMANDS;
      writeCMD[1] = 0;
      
      _set_active_bank(connector_id);
      
       if((connector_id == BANK_A_PORT_1) ||(connector_id == BANK_B_PORT_1)){
	  
	    writeCMD[1] = PISTORMS_MOTOR_1_FLOAT;
	    
	}else if((connector_id == BANK_A_PORT_2) ||(connector_id == BANK_B_PORT_2)){
	    
	    writeCMD[1] = PISTORMS_MOTOR_2_FLOAT;
	    
	} else {
	  printf("Error");
	
	}
	
      bcm2835_i2c_write(writeCMD,2);
  
}

/*
 * Stop both the motors of said bank at the same time motors are stopped smoothly with float
 * */
void pistorms_motor_float_sync(bank_id){
  
  
      char writeCMD[2];
      writeCMD[0] = PISTORMS_MOTOR_COMMANDS;
      writeCMD[1] = PISTORMS_MOTORS_SYNC_FLOAT;
	
      _set_sync_bank(bank_id);
      
      bcm2835_i2c_write(writeCMD,2);
}

/*
 * Stop the motor abruptly with brake
 * */
void pistorms_motor_break(int connector_id){
  
      char writeCMD[2];
      writeCMD[0] = PISTORMS_MOTOR_COMMANDS;
      writeCMD[1] = 0;
      
      _set_active_bank(connector_id);
      
       if((connector_id == BANK_A_PORT_1) ||(connector_id == BANK_B_PORT_1)){
	  
	    writeCMD[1] = PISTORMS_MOTOR_1_BREAK;
	    
	}else if((connector_id == BANK_A_PORT_2) ||(connector_id == BANK_B_PORT_2)){
	    
	    writeCMD[1] = PISTORMS_MOTOR_2_BREAK;
	    
	} else {
	  printf("Error");
	
    }
      bcm2835_i2c_write(writeCMD,2);
}

/*
 * Stop both the motors of said bank at the same time motors are stopped abruptly with a brake
 * */
void pistorms_motor_break_sync(int bank_id){
  
      
      char writeCMD[2];
      writeCMD[0] = PISTORMS_MOTOR_COMMANDS;
      writeCMD[1] = PISTORMS_MOTORS_SYNC_BREAK;
      
     _set_sync_bank(bank_id);
      
      bcm2835_i2c_write(writeCMD,2);
}


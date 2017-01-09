#include "bcm2835.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//BANK A & BANK B
#define PISTORMS_BANK_A_ADDR	0x1a
#define PISTORMS_BANK_B_ADDR	0x1b

typedef enum {
    NO_ACTION,
    I2C_BEGIN,
    I2C_END
} i2c_init;

uint8_t slave_address = PISTORMS_BANK_A_ADDR;
uint8_t data;

int main(int argc, char **argv) {

	char target,speed,time,status,task,regA,bat;

	target = 0x52;
	speed =	0x64;
	time = 0x47;
	status = 0x5A;
	task = 0x5C;
	regA = 0x49;
	bat = 0x6E;
	
	

	char bufTarget[10] = {0};
	char bufSpeed[10] = {0};
	char bufTime[10] = {0};
	char bufStatus[10] = {0};
	char bufTask[10] = {0};
	char bufRegA[10] = {0};
	char bufBat[10] = {0};

	char writeTarget[5];
	writeTarget[0] = 0x42;
	writeTarget[1] = 1;
	writeTarget[2] = 1;
	writeTarget[3] = 1;
	writeTarget[4] = 1;

	char writeSpeed[2];
	writeSpeed[0] = 0x46;
	writeSpeed[1] = 150;

	char writeTime[2];
	writeTime[0] = 0x47;
	writeTime[1] = 6;
	
	char writeRegA[2];
	writeRegA[0] = 0x49;
	writeRegA[1] = 0xC0;
	
	char writeCMD[2];
	writeCMD[0] = 0x41;
	writeCMD[1] = 0x61;

    	if (!bcm2835_init())
    	{
      	printf("bcm2835_init failed. Are you running as root??\n");
      	return 1;
    	}
		
	if (!bcm2835_i2c_begin())
    	{
	printf("bcm2835_i2c_begin failed. Are you running as root??\n");
	return 1;
    	}
	
	while(1){

	printf("Running...");
	//Asigno slave Bank A
	bcm2835_i2c_setSlaveAddress(0x1a);

	//bcm2835_i2c_read_register_rs(&target,bufTarget,4);
	//bcm2835_i2c_read_register_rs(&speed,bufSpeed,1);
	//bcm2835_i2c_read_register_rs(&time,bufTime,1);
	bcm2835_i2c_read_register_rs(&status,bufStatus,1);
	//bcm2835_i2c_read_register_rs(&task,bufTask,1);
	bcm2835_i2c_read_register_rs(&regA,bufRegA,1);
	bcm2835_i2c_read_register_rs(&bat,bufBat,1);
	
	//printf("Encoder Target for Motor:%d,%d,%d,%d \n", bufTarget[0],bufTarget[1],bufTarget[2],bufTarget[3]);
	//printf("Speed for Motor:%d,%d -- ", bufSpeed[0],bufSpeed[1]);
	//printf("Time for Motor:%d --", bufTime[0]);
	printf("Status for Motor:%d --", bufStatus[0]);
	//printf("Task for Motor:%d --", bufTask[0]);
	printf("Registro A:%d --", bufRegA[0]);
	printf("Voltage Battery:%d --", bufBat[0]);
	
	
/*
	bcm2835_i2c_write(writeTarget,5);*/
	bcm2835_i2c_write(writeSpeed,2);
	bcm2835_i2c_write(writeTime,2);
	bcm2835_i2c_write(writeRegA,2);
	
	//bcm2835_i2c_read_register_rs(&target,bufTarget,4);
	bcm2835_i2c_read_register_rs(&speed,bufSpeed,2);
	//bcm2835_i2c_read_register_rs(&time,bufTime,1);
	bcm2835_i2c_read_register_rs(&status,bufStatus,1);
	//bcm2835_i2c_read_register_rs(&task,bufTask,1);
	bcm2835_i2c_read_register_rs(&regA,bufRegA,1);
	
	//printf("Encoder Target for Motor:%d,%d,%d,%d \n", bufTarget[0],bufTarget[1],bufTarget[2],bufTarget[3]);
	printf("Speed for Motor:%d,%d ", bufSpeed[0],bufSpeed[1]);
	//printf("Time for Motor:%d \n", bufTime[0]);
	//printf("Status for Motor:%d \n", bufStatus[0]);
	//printf("Task for Motor:%d \n", bufTask[0]);
	printf("Registro A:%d \n", bufRegA[0]);
	
	char countButton = 0xDB;
	char button[10] = {0};
	
	bcm2835_i2c_read_register_rs(&countButton,button,1);
	
	//if (button[0] == 1){
	    
	    //bcm2835_i2c_write(writeCMD,2);
	    
	    char bufCount[2];
	    bufCount[0] = 0xDB;
	    bufCount[1] = 0;
	
	    char writeSpeed[2];
	    writeSpeed[0] = 0x4E;
	    writeSpeed[1] = 150;

	    char writeTime[2];
	    writeTime[0] = 0x4F;
	    writeTime[1] = 6;
	  
	    char writeRegA[2];
	    writeRegA[0] = 0x51;
	    writeRegA[1] = 0xC0;
	    
	    
	    bcm2835_i2c_write(writeSpeed,2);
	    bcm2835_i2c_write(writeTime,2);
	    bcm2835_i2c_write(writeRegA,2);
	    
	    bcm2835_i2c_write(bufCount,2);
	      
	    int x;
	    int y;
	    for (x=0; x<1000; x++){
		    for (y=0; y<10000; y++){
		    }
		    y=0;
	    }

	    x=0;
	    y=0;
	    
	    //bcm2835_i2c_write(writeCMD,2);
	    
	//}
	
	//bcm2835_i2c_write(writeCMD,2);
	
	
	for (x=0; x<1000; x++){
		for (y=0; y<10000; y++){
		}
		y=0;
	}

	x=0;
	y=0;
	
	}
	
	
			
	//Cierre de I2C y bcm2835		
	bcm2835_i2c_end();	
    	bcm2835_close();
    	printf("... done!\n");
    	return 0;
}

#include "bcm2835.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define NXT_I2C_ID_STR_LEN 8
#define NXT_I2C_FW_VER_REG	0x00
#define NXT_I2C_VEND_ID_REG	0x08
#define NXT_I2C_PROD_ID_REG	0x10

#define PISTORMS_BANK_A_ADDR	0x1a
#define PISTORMS_BANK_B_ADDR	0x1b

#define PS_SENSOR_PORT_1_REG	0x6F


typedef enum {
    NO_ACTION,
    I2C_BEGIN,
    I2C_END
} i2c_init;

//uint16_t clk_div = BCM2835_I2C_CLOCK_DIVIDER_150;
//uint16_t clk_div = BCM2835_I2C_CLOCK_DIVIDER_2500;

//uint8_t slave_address = PISTORMS_BANK_A_ADDR + NXT_I2C_VEND_ID_REG;
//uint8_t slave_address = PISTORMS_BANK_A_ADDR + 0x42;

//uint8_t slave_address = 0x34 + NXT_I2C_VEND_ID_REG;
//uint8_t slave_address = 26
//uint8_t slave_address = 0x34;
uint8_t slave_address = PISTORMS_BANK_A_ADDR;
//uint8_t slave_address2 = 0x36 + 0x10;


//uint32_t len = 32;
uint8_t data;
//char wbuf[32];

//char buf[5];
//char sbuf[1];

int main(int argc, char **argv) {

	char cmd;
	char cmd2;
	char v[10] = {0};
	char d[10] = {0};
	cmd = 0x08;
	cmd2= 0x10;
	//buf[0] = 0x08;
	//buf[1] = 0x09;
	//buf[2] = 0x0a;
	//sbuf[1] = 0x08;
    	printf("Running ... \n");
    	
    	if (!bcm2835_init())
    	{
      	printf("bcm2835_init failed. Are you running as root??\n");
      	return 1;
    	}

  		
	printf("Inicialización BCM. \n");

		if (!bcm2835_i2c_begin())
    		{
		printf("bcm2835_i2c_begin failed. Are you running as root??\n");
		return 1;
    		}

		printf("Inicialización I2C. \n");
		
		//bcm2835_delayMicroseconds(100);


		printf("Delay 1. \n");

		bcm2835_i2c_setSlaveAddress(slave_address);
    		//bcm2835_i2c_setClockDivider(clk_div);	

    		fprintf(stderr, "Slave address set to: %x\n", slave_address);
		//fprintf(stderr, "Clock divider set to: %d\n", clk_div);

		/*
		data = bcm2835_i2c_write(wbuf, len);
    		printf("Write Result = %d\n", data);

    		data = bcm2835_i2c_read(wbuf, len);
    		printf("Read result= %d\n", data);  
		*/

		//bcm2835_delayMicroseconds(5);
		data = bcm2835_i2c_write(&cmd, 1);
    		printf("Write Result = %d\n", data);
		
		//bcm2835_delayMicroseconds(5);
		data = bcm2835_i2c_read(v, 8);
    		printf("Read result= %d\n", data); 

		printf("Vendor ID= %s\n", v);
	

		data = bcm2835_i2c_write(&cmd2, 1);
    		printf("Write Result = %d\n", data);
		
		//bcm2835_delayMicroseconds(5);
		data = bcm2835_i2c_read(d, 8);
    		printf("Read result= %d\n", data); 

		printf("Device ID= %s\n", d);

		int x;
		int y;
		for (x=0; x<1000; x++){
			for (y=0; y<10000; y++){
			}
		y=0;
		}
		

		
		bcm2835_i2c_end();

		
		
	
    	bcm2835_close();
    	printf("... done!\n");
    	return 0;
   
}

#include "bcm2835.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MODE_READ 0
#define MODE_WRITE 1
#define MAX_LEN 32
#define PIN RPI_GPIO_P1_11
#define PIN2 RPI_GPIO_P1_12

typedef enum {
    NO_ACTION,
    I2C_BEGIN,
    I2C_END
} i2c_init;

uint16_t clk_div = BCM2835_I2C_CLOCK_DIVIDER_150;
//uint16_t clk_div2 = BCM2835_I2C_CLOCK_DIVIDER_626;
uint16_t clk_div2 = BCM2835_I2C_CLOCK_DIVIDER_2500;

uint8_t slave_address = 0x000c;
uint8_t slave_address2 = 0x000d;
uint8_t  mode = MODE_READ;
uint32_t len = 32;

char wbuf[MAX_LEN];
char buf[MAX_LEN];
int i;
uint8_t data;

int main(int argc, char **argv) {

    printf("Running ... \n");
    
    
    if (!bcm2835_init())
    {
      printf("bcm2835_init failed. Are you running as root??\n");
      return 1;
    }
   //PIN 11 output   
   bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);
   bcm2835_gpio_fsel(PIN2, BCM2835_GPIO_FSEL_OUTP);
   bcm2835_gpio_write(PIN, HIGH);
   bcm2835_gpio_write(PIN2, HIGH);
    
    if (!bcm2835_i2c_begin())
    {
	printf("bcm2835_i2c_begin failed. Are you running as root??\n");
	return 1;
    }
   
    while(1){

	bcm2835_i2c_setSlaveAddress(slave_address);
    	bcm2835_i2c_setClockDivider(clk_div);


    	bcm2835_gpio_write(PIN, HIGH);
    	uint8_t value = bcm2835_gpio_lev(PIN);
    	printf("read from pin 11: %d\n", value);
    
    	fprintf(stderr, "Clock divider set to: %d\n", clk_div);
    	fprintf(stderr, "Slave address set to: %d\n", slave_address);
   
	int x;
	int y;
	for (x=0; x<1000; x++){
		for (y=0; y<10000; y++){
		}
		y=0;
	}

	
      	bcm2835_gpio_write(PIN, LOW);


 	bcm2835_i2c_end(); 

	if (!bcm2835_i2c_begin())
    	{
		printf("bcm2835_i2c_begin failed. Are you running as root??\n");
		return 1;
    	}
	bcm2835_i2c_setSlaveAddress(slave_address2);
    	bcm2835_i2c_setClockDivider(clk_div2);
   	
	bcm2835_gpio_write(PIN2, HIGH);
   	uint8_t value2 = bcm2835_gpio_lev(PIN2);
    	printf("read from pin 12: %d\n", value2);
    	
    	fprintf(stderr, "Clock divider set to: %d\n", clk_div2);
    	fprintf(stderr, "Slave address set to: %d\n", slave_address2);

        int u;
	int z;
	for (u=0; u<1000; u++){
		for (z=0; z<10000; z++){
		}
		z=0;
	}
    
    	for (i=0; i<MAX_LEN; i++) buf[i] = 'n';
    	data = bcm2835_i2c_read(buf, len);
    	printf("Read Result = %d\n", data);   
    	for (i=0; i<MAX_LEN; i++) {
    		if(buf[i] != 'n') printf("Read Buf[%d] = %x\n", i, buf[i]);
	}
	    
    
  
    	data = bcm2835_i2c_write(wbuf, len);
    	printf("Write Result = %d\n", data);
    
    

	bcm2835_gpio_write(PIN2, LOW);

    // This I2C end is done after a transfer if specified
    bcm2835_i2c_end(); 

  }
    bcm2835_close();
    printf("... done!\n");
    return 0;
   
}


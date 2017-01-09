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

	char redLed,greenLed,blueLed;
	char valueButton = 0xDA;
	char countButton = 0xDB;
	char ejeX = 0xE3;
	char ejeY = 0xE5;

	char button1[10] = {0};
	char button2[10] = {0};
	char buttonV[10] = {0};
	char bufX[10] = {0};

	char led[10] = {0};
	
	
	char bufLed[2];
	bufLed[0] = 0xD7;
	bufLed[1] = 255;

	char bufLedG[2];
	bufLedG[0] = 0xD8;
	bufLedG[1] = 255;
	
	char bufLedB[2];
	bufLedB[0] = 0xD9;
	bufLedB[1] = 255;

	char bufCount[2];
	bufCount[0] = 0xDB;
	bufCount[1] = 0;
	
	redLed = 0xD7;
	greenLed = 0xD8;
	blueLed = 0xD9;

    	
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

	
	//Slave Bank A
	//bcm2835_i2c_setSlaveAddress(slave_address);
	//bcm2835_i2c_write(bufCount,2);
	/*while(1){
	bcm2835_i2c_read_register_rs(&valueButton,buttonV,1);
	printf("Value Button =%d\n",buttonV[0]);
	bcm2835_i2c_read_register_rs(&countButton,button,1);
	printf("Count Button =%d\n",button[0]);	
	//bcm2835_i2c_read_register_rs(&ejeX,button,1);
	//printf("X Value =%d\n",button[0]);	
	//bcm2835_i2c_read_register_rs(&ejeY,button,1);
	//printf("Y value =%d\n",button[0]);
	int x;
	int y;
		for (x=0; x<1000; x++){
			for (y=0; y<10000; y++){
			}
			y=0;
		}

		x=0;
		y=0;
	
	}*/
	bcm2835_i2c_setSlaveAddress(slave_address);

	while(1){
		
		//bcm2835_i2c_setSlaveAddress(slave_address);
		bcm2835_i2c_write(bufCount,2);
		
		//bcm2835_i2c_read_register_rs(&countButton,button,1);
		printf("Running \n");
		//printf("Count Button Inicial =%d",button[0]);

		bcm2835_i2c_read_register_rs(&ejeX,bufX,1);
		//printf("X Value Inicial =%d  ",bufX[0]);
		

		printf("Pulse boton GO   ");
		
		int x;
		int y;
		for (x=0; x<1000; x++){
			for (y=0; y<10000; y++){
			}
			y=0;
		}

		x=0;
		y=0;
		


		if(bufX[0] != 0){
	
			//Slave bank B			
			bcm2835_i2c_setSlaveAddress(0x1b);
			printf("Bank B:   ");
			bcm2835_i2c_read_register_rs(&countButton,button2,1);
			//printf("Count Button =%d",button2[0]);

			//bcm2835_i2c_read_register_rs(&ejeX,bufX,1);
			//printf("X Value =%d  ",bufX[0]);
			
			if(button2[0] == 1){
			
				//Enciende Red led
				bufLed[1] = 255;
				bcm2835_i2c_write(bufLed,2);
				bufLedG[1] = 0;
				bcm2835_i2c_write(bufLedG,2);
				bufLedB[1] = 0;
				bcm2835_i2c_write(bufLedB,2);
				//Contador a 0
				bcm2835_i2c_write(bufCount,2);
			
	
			}else if(button2[0] == 2){
			
				//Enciende Green led
				bufLed[1] = 0;
				bcm2835_i2c_write(bufLed,2);
				bufLedG[1] = 255;
				bcm2835_i2c_write(bufLedG,2);
				bufLedB[1] = 0;
				bcm2835_i2c_write(bufLedB,2);
				//Contador a 0
				bcm2835_i2c_write(bufCount,2);
			

			}else if(button2[0] == 3){
			
				//Enciende Blue led
				bufLed[1] = 0;
				bcm2835_i2c_write(bufLed,2);
				bufLedG[1] = 0;
				bcm2835_i2c_write(bufLedG,2);
				bufLedB[1] = 250;
				bcm2835_i2c_write(bufLedB,2);
				//Contador a 0
				bcm2835_i2c_write(bufCount,2);
			}else{
				printf("No ha pulsado ");
		
			}
/*
			for (x=0; x<1000; x++){
				for (y=0; y<10000; y++){
				}
				y=0;
			}

			x=0;
			y=0;*/

			//Contador a 0	
			bcm2835_i2c_write(bufCount,2);

			
		}else{
		
			//Slave Bank A
			bcm2835_i2c_setSlaveAddress(0x1a);
			printf("Bank A:   ");
			bcm2835_i2c_read_register_rs(&countButton,button1,1);
			//printf("Count Button =%d",button1[0]);
	
			//bcm2835_i2c_read_register_rs(&ejeX,bufX,1);
			//printf("X Value =%d  ",bufX[0]);
			/*
			int x;
			int y;
			for (x=0; x<1000; x++){
				for (y=0; y<10000; y++){
				}
				y=0;
			}

			x=0;
			y=0;*/

			//bcm2835_i2c_read_register_rs(&countButton,button,1);
			//printf("Count Button =%d  ",button[0]);

			if(button1[0] == 1){
			
				//Enciende Red led
				bufLed[1] = 255;
				bcm2835_i2c_write(bufLed,2);
				bufLedG[1] = 0;
				bcm2835_i2c_write(bufLedG,2);
				bufLedB[1] = 0;
				bcm2835_i2c_write(bufLedB,2);
				//Contador a 0
				bcm2835_i2c_write(bufCount,2);
		
	
			}else if(button1[0] == 2){
			
				//Enciende Green led
				bufLed[1] = 0;
				bcm2835_i2c_write(bufLed,2);
				bufLedG[1] = 255;
				bcm2835_i2c_write(bufLedG,2);
				bufLedB[1] = 0;
				bcm2835_i2c_write(bufLedB,2);
				//Contador a 0
				bcm2835_i2c_write(bufCount,2);
			
			}else if(button1[0] == 3){
			
				//Enciende Blue led
				bufLed[1] = 0;
				bcm2835_i2c_write(bufLed,2);
				bufLedG[1] = 0;
				bcm2835_i2c_write(bufLedG,2);
				bufLedB[1] = 250;
				bcm2835_i2c_write(bufLedB,2);
				//Contador a 0
				bcm2835_i2c_write(bufCount,2);

			}else{

				printf("No ha pulsado");
		
			}

			//bcm2835_i2c_read_register_rs(&countButton,button1,1);
			//printf("Count Button =%d",button[0]);
/*
			for (x=0; x<1000; x++){
				for (y=0; y<10000; y++){
				}
			y=0;
			}

			x=0;
			y=0;*/

			
		}
	}
	
		
	//Cierre de I2C y bcm2835		
	bcm2835_i2c_end();	
    	bcm2835_close();
    	printf("... done!\n");
    	return 0;
}

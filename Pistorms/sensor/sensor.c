#include "bcm2835.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// EV3 Sensor
#define  PS_S1EV_Ready  0x70
#define  PS_S1EV_SensorID  0x71
#define  PS_S1EV_Mode  0x81
#define  PS_S1EV_Length  0x82
#define  PS_S1EV_Data  0x83

//Sensor 1
#define  PS_S1_Mode  0x6F

//Tipo Ev3
#define PS_SENSOR_TYPE_EV3  19

//Gyro Sensor EV3
#define PS_SENSOR_MODE_EV3_GYRO_ANGLE  0x00
#define PS_SENSOR_MODE_EV3_GYRO_RATE  0x01

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

uint8_t i2c_write(char reg, char * buf, int len) {
	uint8_t ret;

	// select register	
	ret = bcm2835_i2c_write(&reg, 1);
	if (ret != BCM2835_I2C_REASON_OK) {
		return ret;
	}

	// write data
	ret = bcm2835_i2c_write(buf, len);
	if (ret != BCM2835_I2C_REASON_OK) {
		return ret;
	}

	return BCM2835_I2C_REASON_OK;
}



int main(int argc, char **argv) {

	char ready, sensorID,sensorMode,sensorLen,sensorData,typeMode,redLed;
	
	char r[10] = {0};
	char s[10] = {0};
	//char m[10] = {0};
	char m = 0;
	char m2[10] = {0};
	char l[10] = {0};
	char d[34] = {0};
	char t = 0;
	char t2[10] = {0};
	char led[10] = {0};
	
	char buf = 0x01;
	char bufMode[2];
	bufMode[0] = 0x81;
	bufMode[1] = 0x01;

	//char bufType[2];
	//bufType[0] = 0x6F;
	//bufType[1] = 19;

	char bufLed[4];
	bufLed[0] = 0xD7;
	bufLed[1] = 255;
	bufLed[2] = 0;
	bufLed[3] = 0;
	

	
	ready = PS_S1EV_Ready;
	sensorID = PS_S1EV_SensorID;
	sensorMode = PS_S1EV_Mode ;
	sensorLen =  PS_S1EV_Length;
	sensorData =  PS_S1EV_Data;
	typeMode = PS_S1_Mode;
	redLed = 0xD7;

	//m[0] = PS_SENSOR_MODE_EV3_GYRO_ANGLE;
	m =  PS_SENSOR_MODE_EV3_GYRO_ANGLE;
	t = PS_SENSOR_TYPE_EV3;
    	
    	if (!bcm2835_init())
    	{
      	printf("bcm2835_init failed. Are you running as root??\n");
      	return 1;
    	}
		
	//printf("Inicialización BCM. \n");

	if (!bcm2835_i2c_begin())
    	{
	printf("bcm2835_i2c_begin failed. Are you running as root??\n");
	return 1;
    	}

	
	//Slave Bank A
	bcm2835_i2c_setSlaveAddress(slave_address);			
    	
		/*Programa de prueba de Leds*/

		//Red Led
			bcm2835_i2c_read_register_rs(&redLed,led,1);
			printf("Red Led =%d\n",led[0]);
			
			data = bcm2835_i2c_write(bufLed,4);
			
			bcm2835_i2c_read_register_rs(&redLed,led,1);
			printf("Red Led =%d,%d\n",led[0],led[1],led[2],led[3]);




		//Sensor Type Mode
	
			bcm2835_i2c_read_register_rs(&typeMode,t2,1);
			printf("Sensor Mode EV3 =%d\n",t2[0]);
	
			//data = bcm2835_i2c_write(bufType,2);
			//printf("Write Result =%d\n",data);

			//bcm2835_i2c_read_register_rs(&typeMode,t2,1);
			//printf("Mode Gyro Sensor =%d\n",t2[0]);
			
			
	
		//Sensor 1 Ready
			data = bcm2835_i2c_write(&ready, 1);
    			//printf("Write Result =%d\n",data);
		
			data = bcm2835_i2c_read(r, 1);
    			//printf("Read result=%d\n",data); 

			printf("Gyro Sensor Ready=%d\n",r[0]);
	
		//Sensor 1 ID
			data = bcm2835_i2c_write(&sensorID, 1);		
			data = bcm2835_i2c_read(s, 8);

			printf("Gyro Sensor ID=%s\n",s);

		//Sensor Mode

			bcm2835_i2c_read_register_rs(&sensorMode,m2,1);
			printf("Mode Gyro Sensor =%d\n",m2[0]);

			data = bcm2835_i2c_write(bufMode,2);
			printf("Write Result =%d\n",data);

			bcm2835_i2c_read_register_rs(&sensorMode,m2,1);
			printf("Mode Gyro Sensor =%d\n",m2[0]);
		
		//Sensor Length	
		
			data = bcm2835_i2c_read_register_rs(&sensorLen,l,1);
			printf("Gyro Angle Length =%d\n",l[0]);

		//Sensor Data	
			while (1){

				data = bcm2835_i2c_read_register_rs(&sensorData,d,32);
				printf("Gyro Angle Data =%d,%d\n",d[0],d[1]);
	
				//Operaciones para generar tiempo
				int x;
				int y;
				for (x=0; x<1000; x++){
					for (y=0; y<10000; y++){
					}
				y=0;
				}
				}

	//Cierre de I2C y bcm2835		
	bcm2835_i2c_end();	
    	bcm2835_close();
    	printf("... done!\n");
    	return 0;
}

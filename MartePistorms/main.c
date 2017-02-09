#include "marte_pistorms.h"
#include "marte_pistorms_sensors.h"
//#include "marte_pistorms_sensor_touch.h"
#include "marte_pistorms_sensor_gyro.h"
//#include "marte_pistorms_sensor_ultrasonic.h"
#include "marte_pistorms_brick.h"
#include "bcm2835.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define GYRO (BANK_B & PORT_1)
#define TOUCH (BANK_A & PORT_1)
#define ULTRASONIC (BANK_B & PORT_1)
#define LED_A BANK_A
#define LED_B BANK_B

int main(int argc, char **argv) {
  
    pistorms_init();
    
    
    pistorms_brick_led_On(LED_A,255,0,0);
    printf("Led Red ON");
    pistorms_brick_led_On(LED_B,0,255,0);
    printf("Led Green ON");
 /*
    pistorms_port_set_type_sensor(GYRO,EV3_TYPE);
    char *GYRO_id;
    GYRO_id = pistorms_get_device_id(GYRO);
    
    if(strcmp(GYRO_id, GYRO_SENSOR_ID) != 0){
	
	printf("Error ID:%s",GYRO_id);
  
    }else{
    
	printf("ID Correcto:%s", GYRO_id);
  
    }
    
    //GYRO_id = pistorms_get_device_id(GYRO);
    int GYRO_mode;
    GYRO_mode = pistorms_sensor_get_mode(GYRO);
    printf("Gyro Mode:%d\n", GYRO_mode);
    
    char *GYRO_data;
    char *GYRO_data2;
    while(1){
      
    GYRO_data = pistorms_gyroAngleEV3(GYRO);
    printf("Gyro Data Angle:%d,%d,%d,%d \n", GYRO_data[0],GYRO_data[1],GYRO_data[2],GYRO_data[3]);
     unsigned short data_final = GYRO_data[0] + (GYRO_data[1] << 8);
     short df = (short)data_final;
     //printf("Valor Final: %d \n", data_final);
     printf("Valor Final Short: %d \n", df);
     
     int z;
     int c;
     for (z=0; z<1000; z++){
       for (c=0; c<10000; c++){
	 
      }
      c=0;
       
      }
    //GYRO_mode = pistorms_sensor_get_mode(GYRO);
    //printf("Gyro Mode 1:%d\n", GYRO_mode);
    GYRO_data2 = pistorms_gyroRateEV3(GYRO);
    //GYRO_mode = pistorms_sensor_get_mode(GYRO);
    //printf("Gyro Mode 2:%d\n", GYRO_mode);
    
    //printf("Gyro Data:%ld,%ld,%ld,%ld \n", GYRO_data[0],GYRO_data[1],GYRO_data[2],GYRO_data[3]);
    //GYRO_data = pistorms_gyroAngleEV3(GYRO);
    //printf("Gyro Data:%x,%x,%x \n", GYRO_data[0],GYRO_data[1],GYRO_data[2],GYRO_data[3]);
   // GYRO_data = pistorms_gyroAngleEV3(GYRO);
   // printf("Gyro Data Angle:%d,%d,%d,%d \n", GYRO_data[0],GYRO_data[1],GYRO_data[2],GYRO_data[3]);
    printf("Gyro Data Rate:%d,%d,%d,%d \n", GYRO_data2[0],GYRO_data2[1],GYRO_data2[2],GYRO_data2[3]);

    /* unsigned short data_final = GYRO_data[0] + (GYRO_data[1] << 8);
     short df = (short)data_final;
     //printf("Valor Final: %d \n", data_final);
     printf("Valor Final Short: %d \n", df);*/
    /* unsigned short data_final2 = GYRO_data2[0] + (GYRO_data2[1] << 8);
     short df2 = (short)data_final2;
    // printf("Valor Final 2: %d \n", data_final2);
     printf("Valor Final 2 Short: %d \n", df2);
     

     int x;
     int y;
     for (x=0; x<1000; x++){
       for (y=0; y<10000; y++){
	 
      }
      y=0;
       
    }
    }
    */
    
   /* printf("--------------------------------------------\n");
    pistorms_sensor_set_mode(GYRO,RATE);
    GYRO_mode = pistorms_sensor_get_mode(GYRO);
    printf("Gyro Mode:%d\n", GYRO_mode);
    
    char *GYRO_rate;
    GYRO_rate = pistorms_sensor_read(GYRO);
    printf("Gyro Data2:%ld,%ld \n", GYRO_rate[0],GYRO_rate[1]);
    GYRO_rate= pistorms_sensor_read(GYRO);
    printf("Gyro Data2:%x,%x \n", GYRO_rate[0],GYRO_rate[1]);
    GYRO_rate = pistorms_sensor_read(GYRO);
    printf("Gyro Data2:%d,%d,%d,%d \n", GYRO_rate[0],GYRO_rate[1],GYRO_rate[2],GYRO_rate[3]);
    
     unsigned short data_final2 = GYRO_rate[0] + (GYRO_rate[1] << 8);
     short df2 = (short)data_final2;
     printf("Valor Final2: %d \n", data_final2);
     printf("Valor Final Short2: %d \n", df2);
     
     unsigned short data_finalbig = (GYRO_rate[0] << 8) + GYRO_rate[1];
     short df3 = (short)data_finalbig;
     printf("Valor FinalBigEndian: %d \n", data_finalbig);
     printf("Valor Final ShortBIGENDIAN: %d \n", df3);*/
   /* char *TOUCH_id;
    pistorms_port_set_type_sensor(TOUCH,TOUCH_TYPE);
    
    TOUCH_id = pistorms_get_device_id(TOUCH);
    
    if(strcmp(TOUCH_id, TOUCH_SENSOR_ID) != 0){
	
	printf("Error ID:%s",TOUCH_id);
  
    }else{
    
	printf("ID Correcto:%s", TOUCH_id);
  
    }
    
    char *TOUCH_data;*/
   /* while(1){
    
    //TOUCH_data = pistorms_sensor_read(TOUCH);
   // printf("Touch Data:%d,%d \n",TOUCH_data[0],TOUCH_data[1]);
    
    int value;
    value = pistorms_isTouchedEV3(TOUCH);
    printf("Is Touched:%d \n", value);
    
    int num;
    num = pistorms_numTouchesEV3(TOUCH);
    printf("Num touches:%d \n", num);
    
    pistorms_resetTouchesEV3(TOUCH);
    int num2;
     int x;
     int y;
     for (x=0; x<1000; x++){
       for (y=0; y<10000; y++){
	 
      }
      y=0;
       
      }
    num2 = pistorms_numTouchesEV3(TOUCH);
    printf("Num2 touches:%d \n", num2);
    }
    
     */
   
 /*   pistorms_port_set_type_sensor(ULTRASONIC,19);
   // pistorms_sensor_set_mode(ULTRASONIC,0);
    char *ULTRASONIC_data;
    char *ULTRASONIC_data_IN;
    char *ULTRASONIC_id;
    int presence;
    ULTRASONIC_id = pistorms_get_device_id(ULTRASONIC);
    
    if(strcmp(ULTRASONIC_id, "US-DIST-CM") != 0){
	
	printf("Error ID:%s",ULTRASONIC_id);
  
    }else{
    
	printf("ID Correcto:%s", ULTRASONIC_id);
  
    }
    
    int ULTRASONIC_mode;
    ULTRASONIC_mode = pistorms_sensor_get_mode(ULTRASONIC);
    printf("ULTRASONIC_mode:%d\n", ULTRASONIC_mode);
  
   
    while(1){
    
    ULTRASONIC_data = pistorms_ultrasonicDistanceCM(ULTRASONIC);
    /* int z;
     int c;
     for (z=0; z<1000; z++){
       for (c=0; c<10000; c++){
	 
      }
      c=0;
       
      }*/
  /*  printf("ULTRASONIC Data:%x,%x,%x \n",ULTRASONIC_data[0],ULTRASONIC_data[1],ULTRASONIC_data[2]);
    printf("ULTRASONIC Data:%d,%d,%d \n",ULTRASONIC_data[0],ULTRASONIC_data[1],ULTRASONIC_data[2]);
    // unsigned short data_final = ULTRASONIC_data[0] + (ULTRASONIC_data[1] << 8);
   //  printf("ULTRASONIC Data:%d \n",data_final);
     int z;
     int c;
     for (z=0; z<1000; z++){
       for (c=0; c<10000; c++){
	 
      }
      c=0;
       
      }
    ULTRASONIC_data_IN = pistorms_ultrasonicDistanceIN(ULTRASONIC);
    printf("ULTRASONIC Data2:%x,%x,%x \n",ULTRASONIC_data_IN[0],ULTRASONIC_data_IN[1],ULTRASONIC_data_IN[2]);
    printf("ULTRASONIC Data2:%d,%d,%d \n",ULTRASONIC_data_IN[0],ULTRASONIC_data_IN[1],ULTRASONIC_data_IN[2]);
    //ULTRASONIC_mode = pistorms_sensor_get_mode(ULTRASONIC);
   // printf("ULTRASONIC_mode2:%d\n", ULTRASONIC_mode);
    
    //presence = pistorms_ultrasonicPresence(ULTRASONIC);
    //printf("Presence:%d\n", presence);
    int x;
    int y;
     for (x=0; x<1000; x++){
       for (y=0; y<10000; y++){
	 
      }
      y=0;
       
      }
    
  }*/
}
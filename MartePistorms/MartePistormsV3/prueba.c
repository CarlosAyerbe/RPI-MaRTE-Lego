//#include "marte_pistorms_sensor_touch.h"
//#include "marte_pistorms_sensor_ultrasonic.h"
//#include "marte_pistorms_sensor_gyro.h"
#include "marte_pistorms_sensor_color.h"
#include "marte_pistorms_brick.h"
#include "marte_pistorms_motors.h"
#include "marte_pistorms.h"
//#include "bcm2835.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>


#define ULTRASONIC_ADDR BANK_B_PORT_1 
#define GYRO_ADDR BANK_B_PORT_1
#define TOUCH_ADDR BANK_B_PORT_1
#define COLOR_ADDR BANK_B_PORT_1

#define LED_A BANK_A
//#define LED_B BANK_B

#define MOTOR_1 BANK_B_PORT_1
//#define MOTOR_2 BANK_B_PORT_2
#define BANK_A_ADR BANK_B




int main(int argc, char **argv) {
  
 
  pistorms_init();
  

   struct timespec start, end,start2,end2, resolution;
   unsigned long int nanos, res , mediaNanos;
   long buffer[5];
   //int i = 0;
   long media, p;
   short g;
   
  /* 
    clock_gettime(CLOCK_MONOTONIC, &start);
    // CODE GOES HERE
    
  pistorms_brick_touch_screen_Y_asis();
  
  
    
   
    clock_gettime(CLOCK_MONOTONIC, &end);
    /*clock_getres(CLOCK_MONOTONIC, &resolution);
   
    res = resolution.tv_sec*1000000000 + resolution.tv_nsec;
    printf("Resolution: %lu (ns)\n", res);*/
  /*  nanos = (end.tv_sec - start.tv_sec)*1000000000 + end.tv_nsec - start.tv_nsec;
    printf("Elapsed time: %lu (ns)\n", nanos);
    
    
  clock_gettime(CLOCK_MONOTONIC, &start2);

pistorms_brick_touch_screen_Y_asis();
pistorms_brick_touch_screen_Y_asis();
pistorms_brick_touch_screen_Y_asis();
pistorms_brick_touch_screen_Y_asis();
pistorms_brick_touch_screen_Y_asis();
 
    clock_gettime(CLOCK_MONOTONIC, &end2);
    
    res = (end2.tv_sec - start2.tv_sec)*1000000000 + end2.tv_nsec - start2.tv_nsec;
    printf("Total=%lu\n",res);
    mediaNanos = res/5;
    printf("Media=%lu\n",mediaNanos);
    
     pistorms_motor_set_speed(MOTOR_1,-50);
    
    
    pistorms_motor_go(MOTOR_1 ,SPEED_GO);
  
    while(1){
      
      p = pistorms_motor_get_pos(MOTOR_1);
      printf("Motor Pos =%ld\n",p);
      sleep(3);
    }
  
   // buffer[i] = nanos;
    //i++;
    
  // }
 // media = (buffer[0]+buffer[1]+buffer[2]+buffer[3]+buffer[4])/5;
  //printf("Media=%lu\n",media);
  
  
  */
  
  /*
  char s = 0x83;

  char bufS[10] = {0};
  
   pistorms_port_set_type_sensor(COLOR_ADDR, 19);
    sleep(1);
  
  char *ULTRASONIC_id;
  ULTRASONIC_id = pistorms_get_device_id(COLOR_ADDR);
  
  if(strcmp(ULTRASONIC_id, "COLOR") != 0){
    
    printf("Error ID:%s",ULTRASONIC_id);
    
    
  }else{
    
    printf("ID Correcto:%s", ULTRASONIC_id);
  }
    
  
 // pistorms_port_set_type_sensor(COLOR_ADDR, 19);
  
 // sleep(1);
  pistorms_sensor_set_mode(COLOR_ADDR,2);
  sleep(1);
  
  while(1){
   // sleep(3);
  bcm2835_i2c_read_register_rs(&s,bufS,1);
  printf("Sensor Color = %d",bufS[0]);
  sleep(3);
  
  */
  
  int light,i,reflected,color;
  
  pistorms_sensor_color_configure(COLOR_ADDR);
  sleep(1);
  i = 0;
  
  while(i<5){
    sleep(3);
    
    reflected = pistorms_color_read_light(COLOR_ADDR, REFLECTED);
    
    printf("REFLECTED =%d",reflected);
    
    i++;
  }
  
  i = 0;
  
  while(i<5){
    
    sleep(3);
    
    light = pistorms_color_read_light(COLOR_ADDR, AMBIENT);
    
    printf("AMBIENT =%d",light);
    
    i++;
  }
  
  i = 0;
  
  while(i<5){
    
    sleep(3);
    color =  pistorms_color_measure(COLOR_ADDR);
    
    printf("MEASURE=%d",color);
    
    i++;
  }
  i=0;
  while(i<5){
    sleep(3);
    
    reflected = pistorms_color_read_light(COLOR_ADDR, REFLECTED);
    
    printf("REFLECTED =%d",reflected);
    
    i++;
  }
  
  
  

}
    
    

  
#include "marte_pistorms.h"
#include "marte_pistorms_sensors.h"
#include "marte_pistorms_sensor_touch.h"
#include "marte_pistorms_sensor_gyro.h"
#include "marte_pistorms_sensor_ultrasonic.h"
#include "marte_pistorms_brick.h"
#include "marte_pistorms_motors.h"
#include "bcm2835.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//#define GYRO (BANK_B | PORT_2)
//#define TOUCH (BANK_A | PORT_1)
//#define ULTRASONIC (BANK_B | PORT_1)

#define ULTRASONIC BANK_B_PORT_1 
#define GYRO BANK_B_PORT_2
#define TOUCH BANK_A_PORT_2

#define LED_A BANK_A
#define LED_B BANK_B

#define MOTOR_1 BANK_B_PORT_1
#define MOTOR_2 BANK_A_PORT_2
//#define MOTOR_2 5

#define MOTORS_BANK_B BANK_B
#define MOTORS_BANK_A BANK_A

int main(int argc, char **argv) {
  
  int ultra,touch,count,presence,gyro;
  int motor1;
  int motor2;
  int motor3;
  int ledOn, ledOn2;
  float cm;
  float in;
  short g;
  pistorms_init();
  
  ///pistorms_port_set_type_sensor(ULTRASONIC,EV3_TYPE);
  ultra =  pistorms_sensor_ultrasonic_configure(ULTRASONIC);
  printf("Ultra =%d ",ultra);
  delay(1800);
  
  
  
  touch =  pistorms_sensor_touch_configure(TOUCH);
  printf("Touch =%d ",touch);
  delay(1800);
  
  
  gyro =  pistorms_sensor_gyro_configure(5);
  printf("Gyro =%d ",gyro);
  delay(1800);
  
  char s = 0x71;
  char bufS[16] ={0};
  /*
   bcm2835_i2c_read_register_rs(&s,bufS,16);
  printf("Ultra ReadID: %s\n",bufS);
   
   
   
   char s2 = 0xA5;
  char bufS2[16] ={0};
  
   bcm2835_i2c_read_register_rs(&s2,bufS2,16);
   printf("Gyro ReadID: %s\n",bufS2);
 /* 
  while(ultra !=1){
  
      //pistorms_init();
      //pistorms_port_set_type_sensor(ULTRASONIC,EV3_TYPE);
      ultra =  pistorms_sensor_ultrasonic_configure(ULTRASONIC);
      printf("Ultra =%d ",ultra);
  }*/
  
  
 /* ledOn=pistorms_brick_led_On(LED_A,0,255,0);
  delay(1500);
  printf("Led 1 =%d",ledOn);
  ledOn2=pistorms_brick_led_On(5,0,0,255);
  printf("Led 2 =%d",ledOn2);
  delay(1500);
  ledOn=pistorms_brick_led_On(LED_B,0,0,255);
  delay(1500);
  printf("Led 1 =%d",ledOn);
  ledOn2=pistorms_brick_led_On(LED_B,0,255,0);
  printf("Led 2 =%d",ledOn2);

  int p=  pistorms_motor_reset_all_parameters(MOTORS_BANK_B);
  delay(1000);
  printf("RESET B=%d",p);
  
   p=  pistorms_motor_reset_all_parameters(5);
  delay(1000);
  printf("RESET B=%d",p);
  
    p=  pistorms_motor_reset_all_parameters(MOTORS_BANK_A);
  delay(1000);
  printf("RESET A=%d",p);
  
    p=  pistorms_motor_reset_all_parameters(MOTORS_BANK_A);
  delay(1000);
  printf("RESET A=%d",p);
  */
  
  //pistorms_motor_reset_all_parameters(MOTORS_BANK_A);
 // delay(100);
  
  
 /* 
  while(pistorms_brick_get_key_press_value() != 1){
    
    motor1= pistorms_motor_set_speed(MOTOR_1,30);
    //motor2=pistorms_motor_set_speed(MOTOR_2,30);
   //motor3=pistorms_motor_set_speed(MOTOR_3,70);
    
    printf("Status Motor1 = %d", motor1);
    //printf("Status Motor2 = %d", motor2);
    //printf("Status Motor3 = %d", motor3);
    
    pistorms_motor_go(MOTOR_1 ,SPEED_GO);*/
   // pistorms_motor_go(MOTOR_2 ,SPEED_GO);
    //pistorms_motor_go(MOTOR_3 ,SPEED_GO);
   
   // g = pistorms_gyro_read(GYRO,ANGLE);
    //printf("ANGLE 1=%d",g);
   // delay(5000);
    
  //   g = pistorms_gyro_read(GYRO,ANGLE);
   // printf("ANGLE 2=%d",g);
   // delay(5000);
    
   // g = pistorms_gyro_read(GYRO,RATE);
   // printf("RATE 1=%d",g);
   // delay(5000);
    
 //  g = pistorms_gyro_read(GYRO,RATE);
  //  printf("RATE 2=%d",g);
   // delay(5000);
  /*
    cm = pistorms_ultrasonic_read_distance(ULTRASONIC,CENTIMETERS);
    printf("CM 3 = %.1f",cm);
    delay(5000);
    
    
    cm = pistorms_ultrasonic_read_distance(ULTRASONIC,CENTIMETERS);
    printf("CM 2 = %.1f",cm);
    
    delay(5000);
   in= pistorms_ultrasonic_read_distance(ULTRASONIC,INCHES);
    printf("IN= %.1f",in);
    delay(5000);
    
    in = pistorms_ultrasonic_read_distance(ULTRASONIC,INCHES);
    printf("IN 2 = %.1f",in);
   
    delay(5000);
    
    in = pistorms_ultrasonic_read_distance(ULTRASONIC,4);
    printf("IN 2 = %.1f",in);
    
    int t = pistorms_motor_break_sync(MOTORS_BANK_B);
    printf("BREAK SYNC=%d",t);
    
    presence = pistorms_ultrasonic_presence(ULTRASONIC);
    
    printf("PRESENCE = %d",presence);
    delay(5000);
    
     presence = pistorms_ultrasonic_presence(ULTRASONIC);
    
    printf("PRESENCE2 = %d",presence);
    delay(5000);
  */
   /* 
    cm = pistorms_ultrasonicDistanceCM(ULTRASONIC);
    printf("CM 3 = %.1f",cm);*/
    /*while(pistorms_ultrasonicDistanceCM(ULTRASONIC)<15.0){
      
	pistorms_motor_set_speed(MOTOR_1,50);
	pistorms_motor_set_speed(MOTOR_2,50);
      
	pistorms_motor_go(MOTOR_1 ,SPEED_GO);
	pistorms_motor_go(MOTOR_2 ,SPEED_GO);
	delay(100);*/
    /*
    if(pistorms_ultrasonicDistanceCM(ULTRASONIC)<7.0){
      
	pistorms_motor_break_sync(MOTORS_BANK_B);
	delay(100);
	
	pistorms_motor_reset_all_parameters(MOTORS_BANK_B);
	delay(100);
	
	pistorms_motor_set_speed(MOTOR_1,50);
	pistorms_motor_set_pos(MOTOR_1,-1080);
	pistorms_motor_set_speed(MOTOR_2,50);
	pistorms_motor_set_pos(MOTOR_2,-1440);
	  
	pistorms_motor_go(MOTOR_1 ,SPEED_GO | ENCODER_GO);
	pistorms_motor_go(MOTOR_2 ,SPEED_GO | ENCODER_GO);
	delay(100);
	
	while(pistorms_motor_get_pos(MOTOR_2) > -1400){
	 
	  pistorms_brick_led_On(LED_A,0,0,255);
	  delay(100);
	  pistorms_brick_led_On(LED_B,0,0,255);
	  delay(100);
	}
	//pistorms_motor_reset_all_parameters(MOTORS_BANK_B);
	delay(100);
      }*/
    
    //}
  }/*
  pistorms_brick_led_On(LED_A,255,0,0);
  delay(100);
  pistorms_brick_led_On(LED_B,255,0,0);
  
  pistorms_motor_break_sync(MOTORS_BANK_B);
	delay(100);
  pistorms_motor_reset_all_parameters(MOTORS_BANK_B);
  
  while(1){
    presence = pistorms_ultrasonic_presence(ULTRASONIC);
    
    printf("PRESENCE = %d",presence);
    delay(1000);
    
  }
  
  
  pistorms_close();
  
}
  */
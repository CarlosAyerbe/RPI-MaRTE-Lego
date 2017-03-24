#include "marte_pistorms_sensor_touch.h"
#include "marte_pistorms_sensor_ultrasonic.h"
#include "marte_pistorms_brick.h"
#include "marte_pistorms_motors.h"
#include "marte_pistorms.h"
#include "bcm2835.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


#define ULTRASONIC_ADDR BANK_B_PORT_1 
//#define GYRO_ADDR BANK_A_PORT_2
#define TOUCH_ADDR BANK_B_PORT_2

#define LED_A BANK_A
#define LED_B BANK_B

#define MOTOR_1 BANK_B_PORT_1
#define MOTOR_2 BANK_B_PORT_2

#define MOTORS_BANK_B BANK_B
#define MOTORS_BANK_A BANK_A

int main(int argc, char **argv) {
  
  int ultraID,touchID;
  long pos1,pos2,pos3,pos4;
  
  pistorms_init();
  
  ultraID =  pistorms_sensor_ultrasonic_configure(ULTRASONIC_ADDR );
  printf("Ultra =%d ",ultraID);
  
  touchID =  pistorms_sensor_touch_configure(TOUCH_ADDR );
  printf("Touch =%d ",touchID);
  
  pistorms_brick_led_On(LED_A,0,255,0); //Green Led
  pistorms_brick_led_On(LED_B,0,255,0);	//Green Led
  
  pistorms_motor_reset_all_parameters(MOTORS_BANK_B);
  
  
  while(!pistorms_brick_get_key_press_value()){
    
    pistorms_motor_set_speed(MOTOR_1,-50);
    pistorms_motor_set_speed(MOTOR_2,-50);
    
    pistorms_motor_go(MOTOR_1 ,SPEED_GO);
    pistorms_motor_go(MOTOR_2 ,SPEED_GO);
    
    if((pistorms_ultrasonic_read_distance(ULTRASONIC_ADDR ,CENTIMETERS) < 6.0) ||( pistorms_is_touched(TOUCH_ADDR ))){
      
      pistorms_motor_brake_sync(MOTORS_BANK_B);
      sleep(1);
      pistorms_motor_reset_pos(MOTOR_1);
      pistorms_motor_reset_pos(MOTOR_2);
      
      pos1 = pistorms_motor_get_pos(MOTOR_1);
      pos2 = pistorms_motor_get_pos(MOTOR_2);
      
      pistorms_motor_set_speed(MOTOR_1,40);
      pistorms_motor_set_speed(MOTOR_2,40);
      //pistorms_motor_set_pos(MOTOR_1,1000); /*<! Go back*/
      //pistorms_motor_set_pos(MOTOR_2,1000);/*<! Go back*/	
      
      pistorms_motor_go(MOTOR_1 ,SPEED_GO);
      pistorms_motor_go(MOTOR_2 ,SPEED_GO);
      
      while((pos1 < 800)||(pos2 < 800)){/*<! White until achieve the position*/
	
	pos1 = pistorms_motor_get_pos(MOTOR_1);
	pos2 = pistorms_motor_get_pos(MOTOR_2);
	
	
      }
      
      pistorms_motor_brake_sync(MOTORS_BANK_B);
      sleep(1);
      
      pos1=0;
      pos2=0;
      
      pistorms_motor_reset_pos(MOTOR_1);
      pistorms_motor_reset_pos(MOTOR_2);
      
      pistorms_motor_set_speed(MOTOR_1,-30);
      pistorms_motor_set_speed(MOTOR_2,30);
       //pistorms_motor_set_pos(MOTOR_1,-400);/*<! Negative Enoder*/
      //pistorms_motor_set_pos(MOTOR_2,400);/*<! Positive Enccoder*/
      
      pistorms_motor_go(MOTOR_1 ,SPEED_GO);
      pistorms_motor_go(MOTOR_2 ,SPEED_GO);
      
      pos3 = pistorms_motor_get_pos(MOTOR_1);
      pos4 = pistorms_motor_get_pos(MOTOR_2);
      
      while((pos3 > -360)||(pos4 < 360)){/*<! White until achieve the position*/
	
	pos3 = pistorms_motor_get_pos(MOTOR_1);
	pos4 = pistorms_motor_get_pos(MOTOR_2);
	
	
      }
      
      pos3=0;
      pos4=0;
      
      
    }
    
  }
  
  
  pistorms_brick_led_On(LED_A,255,0,0);//Red Led
  pistorms_brick_led_On(LED_B,255,0,0);//Red Led
  
  pistorms_motor_brake_sync(MOTORS_BANK_B);
  pistorms_motor_reset_all_parameters(MOTORS_BANK_B);
  
  
  pistorms_close();
  
}
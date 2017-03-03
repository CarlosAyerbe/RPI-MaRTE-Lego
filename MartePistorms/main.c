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

#define ULTRASONIC BANK_A_PORT_1 
#define GYRO BANK_B_PORT_2
//#define TOUCH BANK_B_PORT_2

#define LED_A BANK_A
#define LED_B BANK_B

#define MOTOR_1 BANK_A_PORT_1
#define MOTOR_2 BANK_B_PORT_2
#define MOTORS_BANK_B BANK_B
#define MOTORS_BANK_A BANK_A

int main(int argc, char **argv) {
  
  pistorms_init();
  short i = 0;
  int ultra,gyro,touch,count,istouched,buttonGo;
  
  float j;
  float h;
  
  pistorms_brick_led_On(LED_A,255,0,0);
  pistorms_motor_reset_all_parameters(MOTORS_BANK_A);
  //pistorms_motor_reset_all_parameters(MOTORS_BANK_B);
  delay(100);
  pistorms_brick_led_On(LED_B,255,0,0);
  pistorms_motor_reset_all_parameters(MOTORS_BANK_B);
  delay(100);
  // pistorms_motor_reset_all_parameters(MOTORS_BANK_B);
  pistorms_motor_set_speed(MOTOR_2,80);
  pistorms_motor_set_pos(MOTOR_2,1800);
  pistorms_motor_go(MOTOR_2 ,SPEED_GO | ENCODER_GO);
  
  //  pistorms_motor_reset_all_parameters(MOTORS_BANK_A);
  pistorms_motor_set_speed(MOTOR_1,90);
  pistorms_motor_set_secs(MOTOR_1,9);
  pistorms_motor_go(MOTOR_1,SPEED_GO | TIME_GO);
  
  pistorms_port_set_type_sensor(GYRO,EV3_TYPE);
  gyro =  pistorms_sensor_proof_gyro(GYRO);
  printf("GYRO = %d",gyro);
  //i=pistorms_gyroAngleEV3(GYRO);*/
  pistorms_port_set_type_sensor(ULTRASONIC,EV3_TYPE);
  ultra =  pistorms_sensor_proof_ultrasonic(ULTRASONIC);
  printf("ULTRA = %d\n",ultra);
  
  /* delay(100);
   *   pistorms_port_set_type_sensor(TOUCH,TOUCH_TYPE);
   *   delay(100);
   *   touch = pistorms_sensor_proof_touch(TOUCH);
   *   printf("TOUCH= %d\n",touch);*/
  pistorms_brick_reset_key_press_count();
  
  while(1){
    
    i=pistorms_gyroRateEV3(GYRO);
    printf("Rotational Speed = %d\n",i);
    
    delay(1000);
    
    buttonGo = pistorms_brick_get_key_press_count();
    pistorms_port_set_type_sensor(ULTRASONIC,EV3_TYPE);
    j=pistorms_ultrasonicDistanceCM(ULTRASONIC);
    printf("CM = %.1f\n",j);
    
    h= pistorms_ultrasonicDistanceIN(ULTRASONIC);
    printf("IN = %.1f\n",h);
    
    /* pistorms_port_set_type_sensor(TOUCH,TOUCH_TYPE);
     *  istouched = pistorms_isTouchedEV3(TOUCH);
     *  printf("Value TOUCH = %d ",istouched);
     *  
     *  delay(1000);
     *  
     *  count = pistorms_numTouchesEV3(TOUCH);
     *  printf("Count TOUCH = %d ",count);*/
    
    if(buttonGo != 0){
      pistorms_brick_led_On(LED_A,0,255,0);
      delay(100);
      pistorms_brick_led_On(LED_B,0,255,0);
      pistorms_brick_reset_key_press_count();
    }
  }
  /*
   * pistorms_motor_reset_all_parameters(MOTORS_BANK_B);
   *    
   *    
   * pistorms_motor_set_speed(MOTOR_2,100);
   * //pistorms_motor_set_secs(MOTOR_2,1);
   * pistorms_motor_set_pos(MOTOR_2,1800);
   *     
   * //pistorms_motor_set_speed(MOTOR_1,170);
   * //pistorms_motor_set_pos(MOTOR_1,500);
   * pistorms_motor_go(MOTOR_2 ,SPEED_GO | ENCODER_GO);
   * //pistorms_motor_go(MOTOR_2 ,SPEED_GO | TIME_GO);
   * 
   *   
   *    while(1){
   *       
   * t = pistorms_motor_get_pos(MOTOR_2);
   * printf("POS = %d\n",t);
   * 
   *  int a;
   *  int b;
   *  for (a=0; a<1000; a++){
   *    for (b=0; b<10000; b++){
   *      
}
b=0;

}


}    

*/    
  /* char writeReg[2];
   *   writeReg[0]= 0x41;
   *   writeReg[1]= 0x52;
   *   pistorms_motor_reset_pos(MOTOR_2);
   *   bcm2835_i2c_write(writeReg,2);*/
  /* pistorms_motor_set_speed(MOTOR_2,50);
   *   
   *   pistorms_motor_set_secs(MOTOR_2,5);
   *   
   *   
   *   pistorms_motor_go(MOTOR_2, SPEED_GO | TIME_GO);
   *   
   *   pistorms_motor_set_speed(MOTOR_1,70);
   *  
   *   pistorms_motor_set_pos(MOTOR_1,1080);
   *   
   *   
   *   pistorms_motor_go(MOTOR_1, SPEED_GO | ENCODER_GO);
   *   
   *   while(j<5){
   *     
   *     j++;
   *     printf("dentro del while %d",j);
   *     i = pistorms_motor_get_pos(MOTOR_2);
   *     
   *     t = pistorms_motor_get_pos(MOTOR_1);
   *     
   *     printf("POS M2 = %d\n",i);
   *     printf("POS M1 = %d\n",t);
   *  
   *  int a;
   *  int b;
   *  for (a=0; a<1000; a++){
   *    for (b=0; b<10000; b++){
   *      
}
b=0;

}
// pistorms_motors_reset_all_parameter(MOTORS_BANK_B);
}*/
  /*
   *   i = pistorms_motor_get_pos(MOTOR_2);
   *     
   *     t = pistorms_motor_get_pos(MOTOR_1);
   *     
   *       printf("POS M2 = %d\n",i);
   *     printf("POS M1 = %d\n",t);
   *   pistorms_motor_reset_all_parameters(MOTORS_BANK_B);
   *        int a;
   *  int b;
   *  for (a=0; a<1000; a++){
   *    for (b=0; b<10000; b++){
   *      
}
b=0;

}

i = pistorms_motor_get_pos(MOTOR_2);

t = pistorms_motor_get_pos(MOTOR_1);

printf("POS M2 = %d\n",i);
printf("POS M1 = %d\n",t);*/
  
  /* char *encoder;
   *   char *encoder2;
   *   
   *   char writeReg[2];
   *   writeReg[0]= 0x41;
   *   writeReg[1]= 0x52;
   *   //pistorms_motor_reset_pos(MOTOR_2);
   *  // bcm2835_i2c_setSlaveAddress(BANK_B_ADDR);
   *   
   *  pistorms_motor_reset_pos(MOTOR_1);
   *  pistorms_motor_reset_pos(MOTOR_2);
   *   
   *    bcm2835_i2c_write(writeReg,2);
   *    
   *    pistorms_motor_set_pos(MOTOR_1,1000);
   *    pistorms_motor_set_pos(MOTOR_2,1000);
   *    //pistorms_motor_set_speed(MOTOR_1,1);
   *    //pistorms_motor_set_speed(MOTOR_2,1);
   *    //pistorms_motor_run_secs(MOTOR_1,10);
   *    //pistorms_motor_run_secs(MOTOR_2,10);
   *    pistorms_motor_go2(MOTOR_1, ENCODER_GO);
   *    pistorms_motor_go2(MOTOR_2, ENCODER_GO);*/
  
  //pistorms_motor_go2(MOTOR_1, TIME_GO);
  // pistorms_motor_go2(MOTOR_2, TIME_GO);
  // pistorms_motor_float(MOTOR_1);
  
  
  /* int a;
   *  int b;
   *  for (a=0; a<1000; a++){
   *    for (b=0; b<10000; b++){
   *      
}
b=0;

}*/
  
  // pistorms_motor_float(MOTOR_2);
  /* char status1 = 0x5A;
   *   char status2 = 0x5B;
   *   
   *   char bufStatus1[10] = {0};
   *   char bufStatus2[10] = {0};*/
  
  /* while(1){
   *   bcm2835_i2c_read_register_rs(&status1, bufStatus1,1);
   *   bcm2835_i2c_read_register_rs(&status2, bufStatus2,1);
   *   
   *   //printf("Status 1 = %d",bufStatus1[0]);
   *   printf("Status 1 = %x\n",bufStatus1[0]);
   * //  printf("Status 2 = %d",bufStatus2[0]);
   *   printf("Status 2 = %x\n",bufStatus2[0]);
   *   
   *     int z;
   *  int c;
   *  for (z=0; z<1000; z++){
   *    for (c=0; c<10000; c++){
   *      
}
c=0;

}

}*/
  
  /*char writeReg[2];
   *   writeReg[0]= 0x51;
   *   writeReg[1] = 0x8D;*/
  //pistorms_motor_set_speed(MOTOR_2,50);
  // pistorms_motor_set_speed(MOTOR_1,150);
  //pistorms_motor_run_secs(MOTOR_1,150,6);
  
  //pistorms_motor_set_speed_sync(MOTORS_BANK_B,150);
  
  //  pistorms_motor_reset_pos(MOTOR_2);
  
  // encoder = pistorms_motor_get_pos(MOTOR_2);
  // printf("Encoder: %d,%d,%d,%d     ",encoder[0],encoder[1],encoder[2],encoder[3]);
  
  //pistorms_motor_set_up(MOTOR_2,1,0,1);
  // pistorms_motor_set_go(MOTOR_2, SPEED_GO | TIME_GO);
  
  //  pistorms_motor_set_speed(MOTOR_2,50);
  //pistorms_motor_run_secs(MOTOR_2,6);
  //  pistorms_motor_set_pos(MOTOR_2,5600);
  
  //   pistorms_motor_go2(MOTOR_2, SPEED_GO | ENCODER_GO);
  // pistorms_motor_go(MOTOR_2,1,1,0);
  
  //pistorms_motor_set_speed(MOTOR_2,80);
  
  // bcm2835_i2c_write(writeReg,2);
  /* 
   *   while(1){
   *     
   *    i++;
   *    encoder = pistorms_motor_get_pos(MOTOR_2);
   *    printf("Encoder: %d,%d,%d,%d     ",encoder[0],encoder[1],encoder[2],encoder[3]);
   *    unsigned long data_final = encoder[0] + (encoder[1] << 8) + (encoder[2] << 16) + (encoder[3] << 24);
   *    long d = (long)data_final;
   *    printf("Valor final %d\n",d);
   *    
   *  int z;
   *  int c;
   *  for (z=0; z<1000; z++){
   *    for (c=0; c<10000; c++){
   *      
}
c=0;

}

// pistorms_motor_set_speed(MOTOR_2,100);
// pistorms_motor_set_up(MOTOR_2,1,0,0);
//pistorms_motor_break(MOTOR_2);
//pistorms_motor_float(MOTOR_2);
//pistorms_motor_break_sync(MOTORS_BANK_B);
}*/
  //pistorms_motor_reset_pos(MOTOR_2);
  //pistorms_motor_set_speed(MOTOR_2,50);
  
  // pistorms_motor_set_pos_2(MOTOR_2,9560); 
  
  // pistorms_motor_set_up(MOTOR_2,1,0,1);
  
  // bcm2835_i2c_write(writeReg,2);
  /*  while(1){
   *     
   *    encoder = pistorms_motor_get_pos(MOTOR_2);
   *    printf("Encoder Segundo while: %d,%d,%d,%d     ",encoder[0],encoder[1],encoder[2],encoder[3]);
   *     unsigned short data_final2 = encoder[0] + (encoder[1] << 8) + (encoder[2] << 16) + (encoder[3] << 24);
   *    short d2 = (short)data_final2;
   *    printf("Valor final2 %d\n",d2);
   *  int v;
   *  int b;
   *  for (v=0; v<1000; v++){
   *    for (b=0; b<10000; b++){
   *      
}
b=0;

}

}*/
  /*
   *   pistorms_brick_led_On(LED_A,255,0,0);
   *   printf("Led Red ON");
   *   pistorms_brick_led_On(LED_B,0,255,0);
   *   printf("Led Green ON");*/
  
  // int gyro;
  // int touch;
  /* int ultrasonic;
   *   char *ULTRASONIC_data;
   *   
   *   ultrasonic =  pistorms_sensor_proof_ultrasonic(ULTRASONIC);
   *   printf("ULTRASONIC = %d",ultrasonic);
   *   
   *   
   *     int z;
   *     int c;
   *     for (z=0; z<1000; z++){
   * for (c=0; c<10000; c++){
   *  
}
c=0;

}
pistorms_port_set_type_sensor(ULTRASONIC,EV3_TYPE);
pistorms_sensor_set_mode(ULTRASONIC,PROXIMITY_CENTIMETERS);

while(1){
  
  ULTRASONIC_data = pistorms_ultrasonicDistanceCM(ULTRASONIC);
  int z;
  int c;
  for (z=0; z<1000; z++){
    for (c=0; c<10000; c++){
      
}
c=0;

}
printf("ULTRASONIC Data:%x,%x,%x \n",ULTRASONIC_data[0],ULTRASONIC_data[1],ULTRASONIC_data[2]);

}*/
  /*  printf("ULTRASONIC Data:%x,%x,%x \n",ULTRASONIC_data[0],ULTRASONIC_data[1],ULTRASONIC_data[2]);
   *   
   *  /* 
   *   touch =  pistorms_sensor_proof_touch(TOUCH);
   *   printf("TOUCH = %d",touch);
   *     int x;
   *     int y;
   *     for (x=0; x<1000; x++){
   * for (y=0; y<10000; y++){
   *  
}
y=0;

}

gyro =  pistorms_sensor_proof_gyro(GYRO);
printf("GYRO = %d",gyro);
/*
 *   int battery;
 *   char *firmware_version;
 *   char *vendor_id;
 *   char *device_id;
 * 
 * 
 *      
 *   battery = pistorms_brick_get_battery_voltage();
 *   printf("Battery = %d \n", battery);
 *   firmware_version = pistorms_brick_get_firmware_version(LED_A);
 *   printf("Firmware Version Bank_A %s \n", firmware_version);
 *   vendor_id =  pistorms_brick_get_vendor_id(LED_A);
 *   printf("Vendor ID Bank_A %s \n", vendor_id);
 *   device_id =  pistorms_brick_get_device_id(LED_A);
 *   printf("Device ID Bank_A %s \n", device_id);
 *   
 *   
 *   
 *   int battery2;
 *   char *firmware_version2;
 *   char *vendor_id2;
 *   char *device_id2;
 *   
 *   battery2 = pistorms_brick_get_battery_voltage();
 *   printf("Battery2 = %d \n", battery2);
 *   firmware_version2 = pistorms_brick_get_firmware_version(LED_B);
 *   printf("Firmware Version Bank_B %s \n", firmware_version2);
 *   vendor_id2 =  pistorms_brick_get_vendor_id(LED_B);
 *   printf("Vendor ID Bank_B %s \n", vendor_id2);
 *   device_id2 =  pistorms_brick_get_device_id(LED_B);
 *   printf("Device ID Bank_B %s \n", device_id2);*/
/* char *x;
 *   char *y;
 *   
 *   char asis_X = 0XE7;
 *   char asis_Y = 0XE9;
 *   char bufAsisX[10] = {0};
 *   char bufAsisY[10] = {0};*/

// int touch;

// while(1){

//touch = pistorms_brick_screen_is_touched();
//printf("TOUCH = %d",touch);
// bcm2835_i2c_write(bufX,2);

//x = pistorms_brick_touch_screen_X_asis();
// y = pistorms_brick_touch_screen_Y_asis();
// bcm2835_i2c_read_register_rs(&asis_X,bufAsisX,1);
// bcm2835_i2c_read_register_rs(&asis_Y,bufAsisY,1);

// printf(" RAW X  = %x",bufAsisX[0]);
//  printf(" RAW Y  = %x\n",bufAsisY[0]);

/* unsigned short data_final = x[0] + (x[1] << 8);
 *     short ejex = (short)data_final;
 *     
 *     printf("X short %d\n",ejex);
 *    
 *    printf(" X = %d , %d  \n",x[0],x[1]);
 *    printf(" Y = %d , %d  \n",y[0],y[1]);*/
/*
 *     int z;
 *     int c;
 *     for (z=0; z<1000; z++){
 * for (c=0; c<10000; c++){
 *  
}
c=0;

}

}
*/
/*
 *   pistorms_port_set_type_sensor(GYRO,EV3_TYPE);
 *   char *GYRO_id;
 *   GYRO_id = pistorms_get_device_id(GYRO);
 *   
 *   if(strcmp(GYRO_id, GYRO_SENSOR_ID) != 0){
 * 
 * printf("Error ID:%s",GYRO_id);
 * 
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
 *    short df = (short)data_final;
 *    //printf("Valor Final: %d \n", data_final);
 *    printf("Valor Final Short: %d \n", df);*/
/* unsigned short data_final2 = GYRO_data2[0] + (GYRO_data2[1] << 8);
 *    short df2 = (short)data_final2;
 *   // printf("Valor Final 2: %d \n", data_final2);
 *    printf("Valor Final 2 Short: %d \n", df2);
 *    
 * 
 *    int x;
 *    int y;
 *    for (x=0; x<1000; x++){
 *      for (y=0; y<10000; y++){
 * 
}
y=0;

}
}
*/

/* printf("--------------------------------------------\n");
 *   pistorms_sensor_set_mode(GYRO,RATE);
 *   GYRO_mode = pistorms_sensor_get_mode(GYRO);
 *   printf("Gyro Mode:%d\n", GYRO_mode);
 *   
 *   char *GYRO_rate;
 *   GYRO_rate = pistorms_sensor_read(GYRO);
 *   printf("Gyro Data2:%ld,%ld \n", GYRO_rate[0],GYRO_rate[1]);
 *   GYRO_rate= pistorms_sensor_read(GYRO);
 *   printf("Gyro Data2:%x,%x \n", GYRO_rate[0],GYRO_rate[1]);
 *   GYRO_rate = pistorms_sensor_read(GYRO);
 *   printf("Gyro Data2:%d,%d,%d,%d \n", GYRO_rate[0],GYRO_rate[1],GYRO_rate[2],GYRO_rate[3]);
 *   
 *    unsigned short data_final2 = GYRO_rate[0] + (GYRO_rate[1] << 8);
 *    short df2 = (short)data_final2;
 *    printf("Valor Final2: %d \n", data_final2);
 *    printf("Valor Final Short2: %d \n", df2);
 *    
 *    unsigned short data_finalbig = (GYRO_rate[0] << 8) + GYRO_rate[1];
 *    short df3 = (short)data_finalbig;
 *    printf("Valor FinalBigEndian: %d \n", data_finalbig);
 *    printf("Valor Final ShortBIGENDIAN: %d \n", df3);*/
/* char *TOUCH_id;
 *   pistorms_port_set_type_sensor(TOUCH,TOUCH_TYPE);
 *   
 *   TOUCH_id = pistorms_get_device_id(TOUCH);
 *   
 *   if(strcmp(TOUCH_id, TOUCH_SENSOR_ID) != 0){
 * 
 * printf("Error ID:%s",TOUCH_id);
 * 
}else{
  
  printf("ID Correcto:%s", TOUCH_id);
  
}

char *TOUCH_data;*/
/* while(1){
 *   
 *   //TOUCH_data = pistorms_sensor_read(TOUCH);
 *  // printf("Touch Data:%d,%d \n",TOUCH_data[0],TOUCH_data[1]);
 *   
 *   int value;
 *   value = pistorms_isTouchedEV3(TOUCH);
 *   printf("Is Touched:%d \n", value);
 *   
 *   int num;
 *   num = pistorms_numTouchesEV3(TOUCH);
 *   printf("Num touches:%d \n", num);
 *   
 *   pistorms_resetTouchesEV3(TOUCH);
 *   int num2;
 *    int x;
 *    int y;
 *    for (x=0; x<1000; x++){
 *      for (y=0; y<10000; y++){
 * 
}
y=0;

}
num2 = pistorms_numTouchesEV3(TOUCH);
printf("Num2 touches:%d \n", num2);
}

*/

/*   pistorms_port_set_type_sensor(ULTRASONIC,19);
 *  // pistorms_sensor_set_mode(ULTRASONIC,0);
 *   char *ULTRASONIC_data;
 *   char *ULTRASONIC_data_IN;
 *   char *ULTRASONIC_id;
 *   int presence;
 *   ULTRASONIC_id = pistorms_get_device_id(ULTRASONIC);
 *   
 *   if(strcmp(ULTRASONIC_id, "US-DIST-CM") != 0){
 * 
 * printf("Error ID:%s",ULTRASONIC_id);
 * 
}else{
  
  printf("ID Correcto:%s", ULTRASONIC_id);
  
}

int ULTRASONIC_mode;
ULTRASONIC_mode = pistorms_sensor_get_mode(ULTRASONIC);
printf("ULTRASONIC_mode:%d\n", ULTRASONIC_mode);


while(1){
  
  ULTRASONIC_data = pistorms_ultrasonicDistanceCM(ULTRASONIC);
  /* int z;
   *    int c;
   *    for (z=0; z<1000; z++){
   *      for (c=0; c<10000; c++){
   * 
}
c=0;

}*/
  /*  printf("ULTRASONIC Data:%x,%x,%x \n",ULTRASONIC_data[0],ULTRASONIC_data[1],ULTRASONIC_data[2]);
   *   printf("ULTRASONIC Data:%d,%d,%d \n",ULTRASONIC_data[0],ULTRASONIC_data[1],ULTRASONIC_data[2]);
   *   // unsigned short data_final = ULTRASONIC_data[0] + (ULTRASONIC_data[1] << 8);
   *  //  printf("ULTRASONIC Data:%d \n",data_final);
   *    int z;
   *    int c;
   *    for (z=0; z<1000; z++){
   *      for (c=0; c<10000; c++){
   * 
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
// blink.c
//
// Example program for bcm2835 library
// Blinks a pin on an off every 0.5 secs
//
// After installing bcm2835, you can build this 
// with something like:
// gcc -o blink blink.c -l bcm2835
// sudo ./blink
//
// Or you can test it before installing with:
// gcc -o blink -I ../../src ../../src/bcm2835.c blink.c
// sudo ./blink
//
// Author: Mike McCauley
// Copyright (C) 2011 Mike McCauley
// $Id: RF22.h,v 1.21 2012/05/30 01:51:25 mikem Exp $

#include "bcm2835.h"
#include <stdio.h>

// Blinks on RPi Plug P1 pin 11 (which is GPIO pin 17)
#define PIN RPI_GPIO_P1_11

int main(int argc, char **argv)
{
    // If you call this, it will not actually access the GPIO
    // Use for testing
    //bcm2835_set_debug(1);

    if (!bcm2835_init())
      return 1;

    // Set the pin to be an output
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);
	

    // Blink
    while (1)
    {
	// Turn it on
	bcm2835_gpio_write(PIN, HIGH);

	uint8_t value = bcm2835_gpio_lev(PIN);
	printf("read from pin 11: %d\n", value);
	// wait a bit
	//bcm2835_delay(500);
	int i;
	int j;
	for (i=0; i<1000; i++){
		for (j=0; j<10000; j++){
		}
		j=0;
	}
	// turn it off
	bcm2835_gpio_write(PIN, LOW);

	uint8_t value2 = bcm2835_gpio_lev(PIN);
	printf("read from pin 11: %d\n", value2);
	//printf("read from pin 11: %d\n", value);
	
	// wait a bit
	//bcm2835_delay(500);

	int x;
	int y;
	for (x=0; x<1000; x++){
		for (y=0; y<10000; y++){
		}
		y=0;
	}
    }
    bcm2835_close();
    return 0;
}


/************************************
 * Author: C2C Caleb Ziegler
 * Date: 07 DEC 13
 * Description: Presence of wall near
 * left sensor turns on LED1 and
 * presence of wall near right sensor
 * turns on LED2. Uses sensor.h and
 * sensor.c to interact with sensors.
 ***********************************/

#include <msp430.h> 
#include "sensor.h"

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
    initSensors();
	P1DIR |= BIT0;  // Set P1.0 as output for left LED
	P1DIR |= BIT6;  // Set P1.6 as output for right LED
    while (1)
    {
    	// Turn on left LED on if after ADC, left sensor returns a value greater than 2FE, and if not, turn LED off
    	if (getLeftSensor() < 0x3EA)
    	{
    		P1OUT &= ~BIT0; // turn left LED off
    	}
    	else
    	{
    		P1OUT |= BIT0; // turn left LED on
    	}

    	// Turn on right LED if after ADC, right sensor returns a value greater than 1FF, and if not, turn LED off
    	if (getRightSensor() < 0x0E8)
    	{
    		P1OUT &= ~BIT6; // turn right LED off
    	}
    	else
    	{
    		P1OUT |= BIT6; // turn right LED on
    	}

    }
}

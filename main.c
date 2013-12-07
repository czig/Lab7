#include <msp430.h> 
#include "sensor.h"

/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
    initSensors();
	P1DIR |= BIT0;
	P1DIR |= BIT6;
    while (1)
    {

    	if (getLeftSensor() < 0x2FE)
    	{
    		P1OUT &= ~BIT0;
    	}
    	else
    	{
    		P1OUT |= BIT0;
    	}

    	if (getRightSensor() < 0x1FF)
    	{
    		P1OUT &= ~BIT6;
    	}
    	else
    	{
    		P1OUT |= BIT6;
    	}

    }
}

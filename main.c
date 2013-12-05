#include <msp430.h> 

/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
    initSensors();
    while (1)
    {
    	P1DIR |= BIT0;
    	if (getLeftSensor() < 0x1FF)
    	{
    		P1OUT &= ~BIT0;
    	}
    	else
    	{
    		P1OUT |= BIT0;
    	}
    	P1DIR |= BIT6;
    	if (getRightSensor() < 0x1FF)
    	{
    		P1OUT &= ~BIT6;
    	}
    	else
    	{
    		P1OUT |= BIT6;
    	}
    	P1DIR |= BIT0|BIT6;
    	if (getCenterSensor() < 0x1FF)
    	{
    		P1OUT &= ~(BIT0|BIT6);
    	}
    	else
    	{
    		P1OUT |= (BIT0|BIT6);
    	}
    }
}

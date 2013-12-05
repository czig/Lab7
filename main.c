#include <msp430.h> 

/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	

    while (1)
    {
    	getLeftSensor();
    	getRightSensor();
    	getCenterSensor();

    }
}

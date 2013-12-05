/************************************
 * Author: C2C Caleb Ziegler
 * Date: 21 NOV 13
 * Description: Implementation file for
 * operating sensor on robot.
 ***********************************/
#include <msp430.h>
#include "sensor.h"


unsigned int getLeftSensor()
{
	 ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	 ADC10CTL1 = INCH_3;                       // input A4
	 ADC10AE0 |= BIT3;                         // PA.1 ADC option select
	 ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK
	 P1DIR |= 0x01;                            // Set P1.0 to output direction

	 ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	 __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit

	 if (ADC10MEM < 0x1FF)
	 {
	      P1OUT &= ~0x01;
	 }                         // Clear P1.0 LED off
	 else
	 {
	      P1OUT |= 0x01;                        // Set P1.0 LED on
	 }

	 return 0;
}

unsigned int getRightSensor()
{
	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	ADC10CTL1 = INCH_4;                       // input A4
	ADC10AE0 |= BIT4;                         // PA.1 ADC option select
	ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK
	P1DIR |= 0x06;                            // Set P1.0 to output direction

	ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	__bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit

	if (ADC10MEM < 0x1FF)
		 {
		      P1OUT &= ~0x01;
		 }                         // Clear P1.0 LED off
	else
		 {
		      P1OUT |= 0x01;                        // Set P1.0 LED on
		 }

	return 0;
	}
}

unsigned int getCenterSensor()
{
	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	ADC10CTL1 = INCH_5;                       // input A4
	ADC10AE0 |= BIT5;                         // PA.1 ADC option select
	ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK
	P1DIR |= 0x03;                             // Do something

	ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	__bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit

	if (ADC10MEM < 0x1FF)
		 {
		      P1OUT &= ~0x01;
		 }                         // Clear P1.0 LED off
	else
		 {
		      P1OUT |= 0x01;                        // Set P1.0 LED on
		 }

	return 0;
	}
}
}

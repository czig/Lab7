/************************************
 * Author: C2C Caleb Ziegler
 * Date: 21 NOV 13
 * Description: Implementation file for
 * operating sensor on robot.
 ***********************************/
#include <msp430.h>
#include "sensor.h"

void initSensors(void)
{
	ADC10CTL0 &= ~ENC;
	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	ADC10AE0 |= BIT3|BIT4|BIT5;                         // PA.1 ADC option select
	ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK
	ADC10CTL1 |= BIT7|BIT6|BIT5;
}

unsigned int getLeftSensor()
{
	 ADC10CTL0 &= ~ENC;
	 ADC10CTL1 &= ~(INCH_15);
	 ADC10CTL1 |= INCH_3;                       // input A4
	 ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	 __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit

	 return ADC10MEM;
}

unsigned int getRightSensor()
{
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 &= ~(INCH_15);
	ADC10CTL1 |= INCH_4;                       // input A4
	ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	__bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit

	return ADC10MEM;

}

unsigned int getCenterSensor()
{
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 &= ~(INCH_15);
	ADC10CTL1 |= INCH_5;                       // input A4
	ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	__bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit

	return ADC10MEM;

}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}

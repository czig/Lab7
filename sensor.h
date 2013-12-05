/************************************
 * Author: C2C Caleb Ziegler
 * Date: 21 NOV 13
 * Description: Header file for
 * operating sensors on robot.
 ***********************************/

#include <msp430.h>
#ifndef SENSOR_H_
#define SENSOR_H_

unsigned int getLeftSensor();
unsigned int getRightSensor();
unsigned int getCenterSensor();

#endif /* SENSOR_H_ */

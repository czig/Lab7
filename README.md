Lab7
====

A/D Conversion - "Robot Sensing"

This repository includes the files main.c, sensor.h, and sensor.c, which allow the MSP430 to interface with the left and right sensors on the robot to light up the left and right LEDs on the MSP430, respectively. Sensor.h provides the functions required to interface with left, right, and center sensors, while sensor.c contains the implementations of those functions. 

NOTE: Numerous comments in sensor.c because after the code for one sensor was nailed down, this code was copied and pasted to be used with the other sensors (only the numbers needed to be changed at this point). 

##Grading

 - Prelab....................... 8.5
 - Required Functionality....... 35
 - B-Functionality.............. 10
 - A-Functionality.............. 10

##Hardware Needed:

 - MSP430
 - Robot issued by United States Air Force Academy Department of Electrical and Computer Engineering
 - LDV33 3.3V Regulator
 - 100 Micro Farad Capacitor

##Operation: 

 - This repository uses the code provided along with the MSP430 and the robot to operate the sensors on the robot. The code uses the MSP430 to perform analong-to-digital conversion on the analog signals received from the sensors, which produces a digital signal that can be used in various functions. In this case, main.c uses those digital signals to light up LED1 and LED2 on the MSP430 Launchpad board.  The pins on the MSP430 used to perform the ADC are P1.3 for the left sensor, P1.4 for the right sensor, and P1.5 for the center sensor. Note: depending on the robot used, there may be problems with loading for either of the sensors. To fix this problem, adjust the potentiometer for each sensor, make the clock as slow as possible (clock divider), and if these changes don't work, move the sensors themselves to have a less direct line of sight. 

 - Required Functionality - The presence of a wall next to the left sensor lights up LED1 on the MSP430 Launchpad board, and the presense of a wall next to the right sensor lights up LED2 on the MSP430 Launchpad board. The left and right directions are relative to standing behind the robot. The distance that causes the robot to register the wall and turn either LED on is defined in the conditional statements (of the if statements) in main.c. 
 - B-Functionality - release a sensor library. View the Sensor library in the repositories.
 - A-Functionality - Characterize the sensors with tables and graphs. See the tables and graphs included in this repository for the demonstration of A-functionality.

##Functions: 

All functions pertaining to the operation of the motor and movement of the robot are shown below.

```
void initSensors(void);
```
 - Initializes the sensors on the robot to allow sensing for the left, right, and center sensors. The left sensor uses A3 (P1.3), the right sensor uses A4 (P1.4), and the center sensor uses A5 (P1.5) to perform ADC on the sensor analog signals in the MSP430.

```
unsigned int getLeftSensor();
```
 - Returns the reading from the left sensor after the analog output signal from the left sensor is passed through the ADC. Again uses A3 (P1.3).

```
unsigned int getRightSensor();
```
 - Returns the reading from the right sensor after the analog output signal from the right sensor is passed through the ADC. Again uses A4 (P1.4).

```
unsigned int getCenterSensor();
```
 - Returns the reading from the center sensor after the analog output signal from the center sensor is passed through the ADC. Again uses A5 (P1.5).


##Documentation
 
 - C2C Jason Mossing helped me get voltage readings from my sensors and troubleshoot loading problems.

 - Captain Branchflower helped me toubleshoot problems with my code. He told me that I needed to disable the ENC bit (disable the core) in order to make changes to the ADC. Also, he showed me how to clear the input channel with INCH_15. Moreover, he recommended making an initSensors() function to make my code more modular. Additionally, he recommended having my getLeftSensor(), getRightSensor(), and getCenterSensor() functions return ADC10MEM in order to make the code function better as a library. Furthermore, he suggested putting the LED operation in main.c to make sensor.c function better as a library. 

##Licensing

 - Anyone is free to use and modify this code for any reason as long as it is documented. 

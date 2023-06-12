// buggy_driver.h

#ifndef BUGGY_DRIVER_H // Include guard start
#define BUGGY_DRIVER_H

#include "adafruitmotorhat.h"
#include "mpu6050_driver.h"
#include <iostream>
#include <wiringPi.h>

// Funktionen der Motoren
void driveForward(int speed);
void driveBackward(int speed);
void turnLeft(int speed);
void turnRight(int speed);
void stopMotors();

void driveStraight(MPU6050 *device, const float gy_start, int speed);
void rotate90(MPU6050 *device, const float gy_start, int speed, bool toLeft);

// Funktionen der LED
void turnLEDON(int led);
void turnLEDOFF(int led);

// Funktionen des HC-SR04 Sensors
double measureDistance(int trigger, int echo);
bool checkForObstacle(int distance, int trigger, int echo, int led);
void avoidObstacle(double distance, int trigger, int echo, int led);

#endif // Include guard end

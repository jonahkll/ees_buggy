#pragma once

#include "adafruitmotorhat.h"
#include <iostream>
#include <wiringPi.h>

// Funktionen der Motoren
void driveForward(int speed);
void driveBackward(int speed);
void turnLeft(int speed);
void turnRight(int speed);
void stopMotors();

// Funktionen der LED
void turnLEDON(int led);
void turnLEDOFF(int led);

// Funktionen des HC-SR04 Sensors
double measureDistance(int trigger, int echo);
bool checkForObstacle(int distance, int trigger, int echo, int led);
void avoidObstacle(double distance, int trigger, int echo, int led);

// Funktionen des MPU6050

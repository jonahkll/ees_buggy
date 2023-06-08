/*
Compile:
g++ -o test test.cpp buggy_driver.cpp source/adafruitmotorhat.cpp
source/adafruitdcmotor.cpp source/pwm.cpp source/i2cdevice.cpp -lwiringPi
*/

#include "buggy_driver.h"
#include "source/adafruitmotorhat.h"
#include <iostream>
#include <signal.h>

const int RED_LED = 4;     // GPIO-Pin für die LED
const int TRIGGER_PIN = 5; // GPIO-Pin für den Trigger
const int ECHO_PIN = 6;    // GPIO-Pin für den Echo

/// Interrupt Routine for STRG-C
void signalHandler(int signum) {
    std::cout << "Strg-C Programmende" << std::endl;
    // Beenden Sie hier bitte alle Verbindung zu den Sensoren etc.
    stopMotors();
    turnLEDOFF(RED_LED);
    exit(signum);
}

int main() {
    // Csignal für Abbruch über STRG-C
    signal(SIGINT, signalHandler);

    // Setup von WiringPi
    wiringPiSetup();

    // LED auf PIN 4 des Raspberry Pis beim Motor HAT PIN #23
    pinMode(RED_LED, OUTPUT);
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    while (1) {
        double distance = measureDistance(TRIGGER_PIN, ECHO_PIN);
        std::cout << "Entfernung: " << distance << " cm" << std::endl;

        // LED geht an, wenn die Distanz kleiner oder gleich 5cm ist (Test für
        // späteres Bremslicht)
        if (distance <= 5.0) {
            turnLEDON(RED_LED);
        } else {
            turnLEDOFF(RED_LED);
        }

        delay(500);
    }

    return 0;
}
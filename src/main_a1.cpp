///
/// Project main_a1
///

/*
Compile:
g++ -o main_a1.exe main_a1.cpp buggy_driver.cpp source/adafruitmotorhat.cpp
source/adafruitdcmotor.cpp source/pwm.cpp source/i2cdevice.cpp -lwiringPi
*/

#include "buggy_driver.h"
#include <signal.h>

const int RED_LED = 4;

/// Interrupt Routine for STRG-C
void signalHandler(int signum) {
    std::cout << "Strg-C Programmende" << std::endl;
    // Beenden Sie hier bitte alle Verbindung zu den Sensoren etc.
    digitalWrite(RED_LED, LOW);
    stopMotors();
    exit(signum);
}

int main() {
    // Csignal für Abbruch über STRG-C
    signal(SIGINT, signalHandler);

    // Setup von WiringPi
    wiringPiSetup();

    // LED auf PIN 4 des Raspberry Pis beim Motor HAT PIN #23
    pinMode(RED_LED, OUTPUT);

    // Buggy Fährt ungefähr im Rechteck
    while (1) {
        driveForward(100);
        delay(3000);
        stopMotors();
        // Die LED leuchtet, während der Buggy eine Kurve fährt
        turnLEDON(RED_LED);
        turnRight(100);
        delay(1500);
        stopMotors();
        turnLEDOFF(RED_LED);
    }

    return 0;
}
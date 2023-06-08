#include "buggy_driver.h"
#include <signal.h>

// Initialisierung der nötigen GPIO-Pins
const int RED_LED = 4;     // GPIO-Pin für die LED
const int TRIGGER_PIN = 5; // GPIO-Pin für den Trigger
const int ECHO_PIN = 6;    // GPIO-Pin für den Echo

/// Interrupt Routine for STRG-C
void signalHandler(int signum) {
    std::cout << "Strg-C Programmende" << std::endl;
    // Beenden Sie hier bitte alle Verbindung zu den Sensoren etc.
    digitalWrite(TRIGGER_PIN, LOW);
    digitalWrite(ECHO_PIN, LOW);
    digitalWrite(RED_LED, LOW);
    stopMotors();
    exit(signum);
}

int main() {
    // Csignal für Abbruch über STRG-C
    signal(SIGINT, signalHandler);

    // Setup von WiringPi
    wiringPiSetup();

    // Setze PinModes
    pinMode(RED_LED, OUTPUT);
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    // Initialisierung der Start-Distanz
    double distance = measureDistance(TRIGGER_PIN, ECHO_PIN);

    // Buggy fährt so lange gerade aus bis ein Obstacle erkannt wird und weicht
    // diesem dann aus
    while (1) {
        bool obstacle = false;
        driveForward(100);
        while (1) {
            obstacle =
                checkForObstacle(distance, TRIGGER_PIN, ECHO_PIN, RED_LED);
            if (obstacle) {
                avoidObstacle(distance, TRIGGER_PIN, ECHO_PIN, RED_LED);
                break;
            }
            delay(10);
        }
    }

    return 0;
}
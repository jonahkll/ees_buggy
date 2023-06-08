///
/// Project main_a3
///

/*
Compile:
g++ -o main_a3.exe main_a3.cpp buggy_driver.cpp mpu6050_driver.cpp
source/adafruitmotorhat.cpp source/adafruitdcmotor.cpp source/pwm.cpp
source/i2cdevice.cpp -lwiringPi
*/

#include "buggy_driver.h"
#include "mpu6050_driver.h"
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

    MPU6050Driver mpu6050;

    float accelX = 0, accelY = 0, accelZ = 0, gyroX = 0, gyroY = 0, gyroZ = 0;
    float ax_off, ay_off, az_off, gr_off, gp_off, gy_off;
    float angleX, angleY, angleZ;

    // Buggy fährt so lange gerade aus bis ein Obstacle erkannt wird und weicht
    // diesem dann aus
    while (1) {
        mpu6050.getOffsets(&ax_off, &ay_off, &az_off, &gr_off, &gp_off,
                           &gy_off);
        printf(
            "ax_off: %.4f, ay_off: %.4f, az_off: %.4f, gr_off: %.4f, gp_off: "
            "%.4f, gy_off: %.4f\n",
            ax_off, ay_off, az_off, gr_off, gp_off, gy_off);

        // driveForward(100);
        while (1) {
            // Auslesen der Beschleunigungswerte
            mpu6050.getAccel(&accelX, &accelY, &accelZ);
            printf("Beschleunigung X: %.4f, Y: %.4f, Z: %.4f\n", accelX, accelY,
                   accelZ);

            // Read the gyroscope values
            mpu6050.getGyro(&gyroX, &gyroY, &gyroZ);
            printf("Gyroscope X: %.4f, Y: %.4f, Z: %.4f\n", gyroX, gyroY,
                   gyroZ);

            mpu6050.getAngle(0, &angleX);
            mpu6050.getAngle(1, &angleY);
            mpu6050.getAngle(2, &angleZ);
            printf("Angle X: %.4f, Y: %.4f, Z: %.4f\n", angleX, angleY, angleZ);

            delay(1000);
        }
    }

    return 0;
}
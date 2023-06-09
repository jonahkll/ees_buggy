//-------------------------------MPU6050 Accelerometer and Gyroscope C++
// library----------------------------- Copyright (c) 2019, Alex Mous Licensed
// under the CC BY-NC SA 4.0

// Example code

#include "buggy_driver.h"
#include "mpu6050_driver.h"
#include <signal.h>

MPU6050 device(0x68, true);

// Initialisierung der nötigen GPIO-Pins
const int RED_LED = 4;     // GPIO-Pin für die LED
const int TRIGGER_PIN = 5; // GPIO-Pin für den Trigger
const int ECHO_PIN = 6;    // GPIO-Pin für den Echo

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

    float ax, ay, az, gr, gp,
        gy; // Variables to store the accel, gyro and angle values

    sleep(1); // Wait for the MPU6050 to stabilize

    // Calculate the offsets
    // std::cout << "Calculating the offsets...\n    Please keep the
    // accelerometer level and still\n    This could take a couple of
    // minutes..."; device.getOffsets(&ax, &ay, &az, &gr, &gp, &gy); std::cout
    // << "Gyroscope R,P,Y: " << gr << "," << gp << "," << gy <<
    // "\nAccelerometer X,Y,Z: " << ax << "," << ay << "," << az << "\n";

    // Read the current yaw angle
    device.calc_yaw = true;

    while (1) {
        driveForward(100);
        while (1) {
            // Get the current accelerometer values
            device.getAccel(&ax, &ay, &az);
            std::cout << "Accelerometer Readings: X: " << ax << ", Y: " << ay
                      << ", Z: " << az << "\n";

            // Get the current gyroscope values
            device.getGyro(&gr, &gp, &gy);
            std::cout << "Gyroscope Readings: X: " << gr << ", Y: " << gp
                      << ", Z: " << gy << "\n";

            device.getAngle(0, &gr);
            device.getAngle(1, &gp);
            device.getAngle(2, &gy);
            std::cout << "Current angle around the roll axis: " << gr << "\n";
            std::cout << "Current angle around the pitch axis: " << gp << "\n";
            std::cout << "Current angle around the yaw axis: " << gy << "\n";
            usleep(250000); // 0.25sec

            delay(1000);
        }
    }

    return 0;
}

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

MPU6050 device(0x68, true);

void calculateOffset(float *ax, float *ay, float *az, float *gr, float *gp,
                     float *gy) {
    // Calculate the offsets
    std::cout
        << "Calculating the offsets...\n    Please keep the accelerometer "
           "level and still\n    This could take a couple ofminutes...";
    device.getOffsets(ax, ay, az, gr, gp, gy);
    std::cout << "Gyroscope R,P,Y: " << *gr << "," << *gp << "," << *gy
              << "\nAccelerometer X,Y,Z: " << *ax << "," << *ay << "," << *az
              << "\n";
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

    float ax, ay, az, gr, gp,
        gy; // Variables to store the accel, gyro and angle values

    sleep(1); // Wait for the MPU6050 to stabilize

    // calculateOffset(&ax, &ay, &az, &gr, &gp, &gy);

    // Read the current yaw angle
    device.calc_yaw = true;
    float gy_start = 0.00;
    device.getAngle(2, &gy_start);

    bool toLeft = 0;
    while (1) {
        // driveForward(1);
        device.getAngle(2, &gy_start);
        driveStraight(&device, gy_start, 100);
        delay(350);
        stopMotors();
        rotate90(&device, gy_start, 100, toLeft);
        // while (1) {
        //     // Get the current accelerometer values
        //     device.getAccel(&ax, &ay, &az);
        //     std::cout << "Accelerometer Readings: X: " << ax << ", Y: " << ay
        //               << ", Z: " << az << "\n";

        //     // Get the current gyroscope values
        //     device.getGyro(&gr, &gp, &gy);
        //     std::cout << "Gyroscope Readings: X: " << gr << ", Y: " << gp
        //               << ", Z: " << gy << "\n";

        //     device.getAngle(0, &gr);
        //     device.getAngle(1, &gp);
        //     device.getAngle(2, &gy);
        //     std::cout << "Current angle around the roll axis: " << gr <<
        //     "\n"; std::cout << "Current angle around the pitch axis: " << gp
        //     << "\n"; std::cout << "Current angle around the yaw axis: " << gy
        //     << "\n"; usleep(250000); // 0.25sec

        //     delay(1000);
        // }
    }

    return 0;
}
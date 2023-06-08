#pragma once

//-----------------------MODIFY THESE PARAMETERS-----------------------

#define GYRO_RANGE                                                             \
    0 // Select which gyroscope range to use (see the table below) - Default is
      // 0
//	Gyroscope Range
//	0	+/- 250 degrees/second
//	1	+/- 500 degrees/second
//	2	+/- 1000 degrees/second
//	3	+/- 2000 degrees/second
// See the MPU6000 Register Map for more information

#define ACCEL_RANGE                                                            \
    0 // Select which accelerometer range to use (see the table below) - Default
      // is 0
//	Accelerometer Range
//	0	+/- 2g
//	1	+/- 4g
//	2	+/- 8g
//	3	+/- 16g
// See the MPU6000 Register Map for more information

// Offsets - supply your own here (calculate offsets with getOffsets function)
//     Accelerometer
#define A_OFF_X 30053.2324
#define A_OFF_Y 25106.2598
#define A_OFF_Z 18357.0547
//    Gyroscope
#define G_OFF_X 39441.2109
#define G_OFF_Y 26320.0508
#define G_OFF_Z 43069.8477

#define TAU 0.05                 // Complementary filter percentage
#define RAD_T_DEG 57.29577951308 // Radians to degrees (180/PI)

// Select the appropriate settings
#if GYRO_RANGE == 1
#define GYRO_SENS 65.5
#define GYRO_CONFIG 0b00001000
#elif GYRO_RANGE == 2
#define GYRO_SENS 32.8
#define GYRO_CONFIG 0b00010000
#elif GYRO_RANGE == 3
#define GYRO_SENS 16.4
#define GYRO_CONFIG 0b00011000
#else // Otherwise, default to 0
#define GYRO_SENS 131.0
#define GYRO_CONFIG 0b00000000
#endif
#undef GYRO_RANGE

#if ACCEL_RANGE == 1
#define ACCEL_SENS 8192.0
#define ACCEL_CONFIG 0b00001000
#elif ACCEL_RANGE == 2
#define ACCEL_SENS 4096.0
#define ACCEL_CONFIG 0b00010000
#elif ACCEL_RANGE == 3
#define ACCEL_SENS 2048.0
#define ACCEL_CONFIG 0b00011000
#else // Otherwise, default to 0
#define ACCEL_SENS 16384.0
#define ACCEL_CONFIG 0b00000000
#endif
#undef ACCEL_RANGE

#include <cmath>
#include <iostream>
#include <thread>
#include <wiringPiI2C.h>

// I2C-Adresse des MPU6050
#define MPU6050_ADDR 0x68

// MPU6050-Register für Beschleunigungswerte
#define MPU6050_ACCEL_XOUT_H 0x3B
#define MPU6050_ACCEL_XOUT_L 0x3C
#define MPU6050_ACCEL_YOUT_H 0x3D
#define MPU6050_ACCEL_YOUT_L 0x3E
#define MPU6050_ACCEL_ZOUT_H 0x3F
#define MPU6050_ACCEL_ZOUT_L 0x40

#define MPU6050_GYRO_XOUT_H 0x43
#define MPU6050_GYRO_XOUT_L 0x44
#define MPU6050_GYRO_YOUT_H 0x45
#define MPU6050_GYRO_YOUT_L 0x46
#define MPU6050_GYRO_ZOUT_H 0x47
#define MPU6050_GYRO_ZOUT_L 0x48

// MPU6050 register addresses for configuration
#define MPU6050_PWR_MGMT_1 0x6B
#define MPU6050_CONFIG 0x1A
#define MPU6050_GYRO_CONFIG 0x1B
#define MPU6050_ACCEL_CONFIG 0x1C

class MPU6050Driver {
  private:
    void _update();

    int _i2c_fd;
    float _accel_angle[3];
    float _gyro_angle[3];
    float _angle[3]; // Store all angles (accel roll, accel pitch, accel yaw,
                     // gyro roll, gyro pitch, gyro yaw, comb roll, comb pitch
                     // comb yaw)

    float ax, ay, az, gr, gp,
        gy; // Temporary storage variables used in _update()

    float dt; // Loop time (recalculated with each loop)

    struct timespec start, end; // Create a time structure

    bool _first_run = 1; // Variable for whether to set gyro angle to
                         // acceleration angle in compFilter

  public:
    MPU6050Driver() {
        // Initialisierung der I2C-Verbindung zum MPU6050
        _i2c_fd = wiringPiI2CSetup(MPU6050_ADDR);
        // Configure power management
        wiringPiI2CWriteReg8(_i2c_fd, MPU6050_PWR_MGMT_1, 0x00);

        // Configure gyro and accelerometer settings
        wiringPiI2CWriteReg8(_i2c_fd, MPU6050_CONFIG, 0x00);

        wiringPiI2CWriteReg8(_i2c_fd, MPU6050_GYRO_CONFIG, GYRO_CONFIG);
        wiringPiI2CWriteReg8(_i2c_fd, MPU6050_ACCEL_CONFIG, ACCEL_CONFIG);

        dt = 0.009;     // Loop time (recalculated with each loop)
        _first_run = 1; // Variable for whether to set gyro angle to
                        // acceleration angle in compFilter
        calc_yaw = false;

        bool run_update_thread = true;
        if (run_update_thread) {
            std::thread(&MPU6050Driver::_update, this)
                .detach(); // Create a seperate thread, for the update routine
                           // to run in the background, and detach it, allowing
                           // the program to continue
        }
    }
    void getAccelRaw(float *x, float *y, float *z);
    void getGyroRaw(float *roll, float *pitch, float *yaw);
    void getAccel(float *x, float *y, float *z);
    void getGyro(float *roll, float *pitch, float *yaw);
    void getOffsets(float *ax_off, float *ay_off, float *az_off, float *gr_off,
                    float *gp_off, float *gy_off);
    int getAngle(int axis, float *result);

    bool calc_yaw;
};

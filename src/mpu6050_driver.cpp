//-------------------------------MPU6050Driver Accelerometer and Gyroscope C++
// library----------------------------- Copyright (c) 2019, Alex Mous Licensed
// under the CC BY-NC SA 4.0

// Include the header file for this class
#include "mpu6050_driver.h"

void MPU6050Driver::getGyroRaw(float *roll, float *pitch, float *yaw) {
    int gyroX = wiringPiI2CReadReg16(_i2c_fd, MPU6050_GYRO_XOUT_H);
    int gyroY = wiringPiI2CReadReg16(_i2c_fd, MPU6050_GYRO_YOUT_H);
    int gyroZ = wiringPiI2CReadReg16(_i2c_fd, MPU6050_GYRO_ZOUT_H);
    *roll = (float)gyroX;  // Roll on X axis
    *pitch = (float)gyroY; // Pitch on Y axis
    *yaw = (float)gyroZ;   // Yaw on Z axis
}

void MPU6050Driver::getGyro(float *roll, float *pitch, float *yaw) {
    getGyroRaw(roll, pitch, yaw); // Store raw values into variables
    *roll = round((*roll - G_OFF_X) * 1000.0 / GYRO_SENS) /
            1000.0; // Remove the offset and divide by the gyroscope sensetivity
                    // (use 1000 and round() to round the value to three decimal
                    // places)
    *pitch = round((*pitch - G_OFF_Y) * 1000.0 / GYRO_SENS) / 1000.0;
    *yaw = round((*yaw - G_OFF_Z) * 1000.0 / GYRO_SENS) / 1000.0;
}

void MPU6050Driver::getAccelRaw(float *x, float *y, float *z) {
    int accelX = wiringPiI2CReadReg16(_i2c_fd, MPU6050_ACCEL_XOUT_H);
    int accelY = wiringPiI2CReadReg16(_i2c_fd, MPU6050_ACCEL_YOUT_H);
    int accelZ = wiringPiI2CReadReg16(_i2c_fd, MPU6050_ACCEL_ZOUT_H);
    *x = (float)accelX;
    *y = (float)accelY;
    *z = (float)accelZ;
}

void MPU6050Driver::getAccel(float *x, float *y, float *z) {
    getAccelRaw(x, y, z); // Store raw values into variables
    *x = round((*x - A_OFF_X) * 1000.0 / ACCEL_SENS) /
         1000.0; // Remove the offset and divide by the accelerometer
                 // sensetivity (use 1000 and round() to round the value to
                 // three decimal places)
    *y = round((*y - A_OFF_Y) * 1000.0 / ACCEL_SENS) / 1000.0;
    *z = round((*z - A_OFF_Z) * 1000.0 / ACCEL_SENS) / 1000.0;
}

void MPU6050Driver::getOffsets(float *ax_off, float *ay_off, float *az_off,
                               float *gr_off, float *gp_off, float *gy_off) {
    float gyro_off[3]; // Temporary storage
    float accel_off[3];

    *gr_off = 0, *gp_off = 0, *gy_off = 0; // Initialize the offsets to zero
    *ax_off = 0, *ay_off = 0, *az_off = 0; // Initialize the offsets to zero

    for (int i = 0; i < 10000; i++) { // Use loop to average offsets
        getGyroRaw(&gyro_off[0], &gyro_off[1], &gyro_off[2]); // Raw gyroscope
                                                              // values
        *gr_off = *gr_off + gyro_off[0], *gp_off = *gp_off + gyro_off[1],
        *gy_off = *gy_off + gyro_off[2]; // Add to sum

        getAccelRaw(&accel_off[0], &accel_off[1],
                    &accel_off[2]); // Raw accelerometer values
        *ax_off = *ax_off + accel_off[0], *ay_off = *ay_off + accel_off[1],
        *az_off = *az_off + accel_off[2]; // Add to sum
    }

    *gr_off = *gr_off / 10000, *gp_off = *gp_off / 10000,
    *gy_off = *gy_off / 10000; // Divide by number of loops (to average)
    *ax_off = *ax_off / 10000, *ay_off = *ay_off / 10000,
    *az_off = *az_off / 10000;

    *az_off = *az_off - ACCEL_SENS; // Remove 1g from the value calculated to
                                    // compensate for gravity)
}

int MPU6050Driver::getAngle(int axis, float *result) {
    if (axis >= 0 && axis <= 2) { // Check that the axis is in the valid range
        *result = _angle[axis];   // Get the result
        return 0;
    } else {
        std::cout
            << "ERR (MPU6050Driver.cpp:getAngle()): 'axis' must be between 0 "
               "and 2 (for roll, pitch or yaw)\n"; // Print error message
        *result = 0;                               // Set result to zero
        return 1;
    }
}

void MPU6050Driver::_update() { // Main update function - runs continuously
    clock_gettime(CLOCK_REALTIME, &start); // Read current time into start
                                           // variable

    while (1) {                 // Loop forever haha
        getGyro(&gr, &gp, &gy); // Get the data from the sensors
        getAccel(&ax, &ay, &az);

        // X (roll) axis
        _accel_angle[0] = atan2(az, ay) * RAD_T_DEG -
                          90.0; // Calculate the angle with z and y convert to
                                // degrees and subtract 90 degrees to rotate
        _gyro_angle[0] = _angle[0] + gr * dt; // Use roll axis (X axis)

        // Y (pitch) axis
        _accel_angle[1] = atan2(az, ax) * RAD_T_DEG -
                          90.0; // Calculate the angle with z and x convert to
                                // degrees and subtract 90 degrees to rotate
        _gyro_angle[1] = _angle[1] + gp * dt; // Use pitch axis (Y axis)

        // Z (yaw) axis
        if (calc_yaw) {
            _gyro_angle[2] = _angle[2] + gy * dt; // Use yaw axis (Z axis)
        }

        if (_first_run) { // Set the gyroscope angle reference point if this is
                          // the first function run
            for (int i = 0; i <= 1; i++) {
                _gyro_angle[i] =
                    _accel_angle[i]; // Start off with angle from accelerometer
                                     // (absolute angle since gyroscope is
                                     // relative)
            }
            _gyro_angle[2] =
                0; // Set the yaw axis to zero (because the angle cannot
                   // be calculated with the accelerometer when vertical)
            _first_run = 0;
        }

        float asum = abs(ax) + abs(ay) +
                     abs(az); // Calculate the sum of the accelerations
        float gsum = abs(gr) + abs(gp) +
                     abs(gy); // Calculate the sum of the gyro readings

        for (int i = 0; i <= 1; i++) { // Loop through roll and pitch axes
            if (abs(_gyro_angle[i] - _accel_angle[i]) >
                5) { // Correct for very large drift (or incorrect measurment of
                     // gyroscope by longer loop time)
                _gyro_angle[i] = _accel_angle[i];
            }

            // Create result from either complementary filter or directly from
            // gyroscope or accelerometer depending on conditions
            if (asum > 0.1 && asum < 3 &&
                gsum > 0.3) { // Check that th movement is not very high
                              // (therefore providing inacurate angles)
                _angle[i] =
                    (1 - TAU) * (_gyro_angle[i]) +
                    (TAU) * (_accel_angle[i]); // Calculate the angle using a
                                               // complementary filter
            } else if (gsum > 0.3) {           // Use the gyroscope angle if the
                                               // acceleration is high
                _angle[i] = _gyro_angle[i];
            } else if (gsum <=
                       0.3) { // Use accelerometer angle if not much movement
                _angle[i] = _accel_angle[i];
            }
        }

        // The yaw axis will not work with the accelerometer angle, so only use
        // gyroscope angle
        if (calc_yaw) { // Only calculate the angle when we want it to prevent
                        // large drift
            _angle[2] = _gyro_angle[2];
        } else {
            _angle[2] = 0;
            _gyro_angle[2] = 0;
        }

        clock_gettime(CLOCK_REALTIME, &end); // Save time to end clock
        dt = (end.tv_sec - start.tv_sec) +
             (end.tv_nsec - start.tv_nsec) / 1e9; // Calculate new dt
        clock_gettime(CLOCK_REALTIME, &start);    // Save time to start clock
    }
}
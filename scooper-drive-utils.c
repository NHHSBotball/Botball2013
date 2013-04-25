
#include "drive-utils.h"
#include "scooper-constants.h"

void drive_at_velocity(int port, int vel);
void drive_off(int port);

void drive_straight(int duration, int distance) {
    double speed = distance * 1000.0 / duration;
    drive_at_velocity(kMotorPortDriveLeft, (int) (speed * kCalibrationFactorDrive * kCalibrationFactorDriveLeft + kCalibrationConstantDrive + kCalibrationConstantDriveLeft));
    drive_at_velocity(kMotorPortDriveRight, (int) (speed * kCalibrationFactorDrive * kCalibrationFactorDriveRight + kCalibrationConstantDrive + kCalibrationConstantDriveRight));
    msleep(duration);
    drive_off(kMotorPortDriveLeft);
    drive_off(kMotorPortDriveRight);
}

void drive_arc(int duration, int radius, int angle) {
    double angular_velocity = angle * 1000.0 / duration;
    if (angle < 0) {
        drive_at_velocity(kMotorPortDriveLeft, (int) (angular_velocity * (radius - SCOOPER_RADIUS) * kCalibrationFactorDrive * kCalibrationFactorDriveLeft + kCalibrationConstantDrive + kCalibrationConstantDriveLeft));
        drive_at_velocity(kMotorPortDriveRight, (int) (angular_velocity * (radius + SCOOPER_RADIUS) * kCalibrationFactorDrive * kCalibrationFactorDriveRight + kCalibrationConstantDrive + kCalibrationConstantDriveRight));
    } else {
        drive_at_velocity(kMotorPortDriveLeft, (int) (angular_velocity * (radius + SCOOPER_RADIUS) * kCalibrationFactorDrive * kCalibrationFactorDriveLeft + kCalibrationConstantDrive + kCalibrationConstantDriveLeft));
        drive_at_velocity(kMotorPortDriveRight, (int) (angular_velocity * (radius - SCOOPER_RADIUS) * kCalibrationFactorDrive * kCalibrationFactorDriveRight + kCalibrationConstantDrive + kCalibrationConstantDriveRight));
    }
    msleep(duration);
    drive_off(kMotorPortDriveLeft);
    drive_off(kMotorPortDriveRight);
}

void drive_spin(int duration, int angle) {
    double angular_velocity = angle * 1000.0 / duration;
    drive_at_velocity(kMotorPortDriveLeft, (int) (angular_velocity * -SCOOPER_RADIUS) * kCalibrationFactorDrive * kCalibrationFactorDriveLeft + kCalibrationConstantDrive + kCalibrationConstantDriveLeft);
    drive_at_velocity(kMotorPortDriveRight, (int) (angular_velocity * SCOOPER_RADIUS) * kCalibrationFactorDrive * kCalibrationFactorDriveRight + kCalibrationConstantDrive + kCalibrationConstantDriveRight);
    msleep(duration);
    drive_off(kMotorPortDriveLeft);
    drive_off(kMotorPortDriveRight);
}

void drive_at_velocity(int port, int vel) {
    motor(port, (int) (vel * kCalibrationFactorPower));
    printf("driving m%i at %i mm/s (pwm: %i)\n", port, vel, (int) (vel * kCalibrationFactorPower));
}

void drive_off(int port) {
    motor(port, 0);
}

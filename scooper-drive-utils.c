
#include "drive-utils.h"
#include "scooper-constants.h"

void drive_straight(int duration, int distance) {
    double speed = distance / 1000.0 / duration;
    move_at_velocity(kMotorPortDriveLeft, (int) (speed * kCalibrationFactorDrive * kCalibrationFactorDriveLeft + kCalibrationConstantDrive + kCalibrationConstantDriveLeft));
    move_at_velocity(kMotorPortDriveRight, (int) (speed * kCalibrationFactorDrive * kCalibrationFactorDriveRight + kCalibrationConstantDrive + kCalibrationConstantDriveRight));
    msleep(duration);
    off(kMotorPortDriveLeft);
    off(kMotorPortDriveRight);
}

void drive_arc(int duration, int radius, int angle) {
    double angular_velocity = angle * 1000.0 / duration;
    if (angle < 0) {
        move_at_velocity(kMotorPortDriveLeft, (int) (angular_velocity * (radius - SCOOPER_RADIUS) * kCalibrationFactorDrive * kCalibrationFactorDriveLeft + kCalibrationConstantDrive + kCalibrationConstantDriveLeft));
        move_at_velocity(kMotorPortDriveRight, (int) (angular_velocity * (radius + SCOOPER_RADIUS) * kCalibrationFactorDrive * kCalibrationFactorDriveRight + kCalibrationConstantDrive + kCalibrationConstantDriveRight));
    } else {
        move_at_velocity(kMotorPortDriveLeft, (int) (angular_velocity * (radius + SCOOPER_RADIUS) * kCalibrationFactorDrive * kCalibrationFactorDriveLeft + kCalibrationConstantDrive + kCalibrationConstantDriveLeft));
        move_at_velocity(kMotorPortDriveRight, (int) (angular_velocity * (radius - SCOOPER_RADIUS) * kCalibrationFactorDrive * kCalibrationFactorDriveRight + kCalibrationConstantDrive + kCalibrationConstantDriveRight));
    }
    msleep(duration);
    off(kMotorPortDriveLeft);
    off(kMotorPortDriveRight);
}

void drive_spin(int duration, int angle) {
    double angular_velocity = angle * 1000.0 / duration;
    move_at_velocity(kMotorPortDriveLeft, (int) (angular_velocity * -SCOOPER_RADIUS) * kCalibrationFactorDrive * kCalibrationFactorDriveLeft + kCalibrationConstantDrive + kCalibrationConstantDriveLeft);
    move_at_velocity(kMotorPortDriveRight, (int) (angular_velocity * SCOOPER_RADIUS) * kCalibrationFactorDrive * kCalibrationFactorDriveRight + kCalibrationConstantDrive + kCalibrationConstantDriveRight);
    msleep(duration);
    off(kMotorPortDriveLeft);
    off(kMotorPortDriveRight);
}

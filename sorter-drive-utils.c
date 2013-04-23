
#include "drive-utils.h"
#include "sorter-constants.h"

void drive_straight(int duration, int distance) {
    create_drive_direct((int) ((double) distance / duration * kCalibrationFactorDrive * kCalibrationFactorDriveLeft + kCalibrationConstantDrive + kCalibrationConstantDriveLeft),
                        (int) ((double) distance / duration * kCalibrationFactorDrive * kCalibrationFactorDriveRight + kCalibrationConstantDrive + kCalibrationConstantDriveRight));
    msleep(duration * 1000 / distance);
    create_stop();
}

void drive_arc(int duration, int radius, int angle) {
    double angular_velocity = angle * 1000.0 / duration;
    if (angle < 0) {
        create_drive_direct((int) (angular_velocity * (radius - CREATE_RADIUS)),
                            (int) (angular_velocity * (radius + CREATE_RADIUS)));
    } else {
        create_drive_direct((int) (angular_velocity * (radius + CREATE_RADIUS)),
                            (int) (angular_velocity * (radius - CREATE_RADIUS)));
    }
    msleep(duration);
    create_stop();
}

void drive_spin(int duration, int angle) {
    double angular_velocity = angle * 1000.0 / duration;
    create_spin_CW((int) (angular_velocity * CREATE_RADIUS * kCalibrationFactorSpin + kCalibrationConstantSpin));
    msleep(duration);
    create_stop();
}

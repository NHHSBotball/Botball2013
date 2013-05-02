
#include <stdbool.h>
#include <math.h>
#include "drive-utils.h"
#include "scooper-constants.h"

// void drive_at_velocity(int port, int vel);
void drive_off(int port);
void turn_ticks(int power, int ticks) {
    
    if (ticks > 0) {
        clear_motor_position_counter(kMotorPortDriveLeft);
        motor(kMotorPortDriveLeft, power);
        while (get_motor_position_counter(kMotorPortDriveLeft) < ticks) {}
        motor(kMotorPortDriveLeft, 0);
    }
    else if (ticks < 0) {
        clear_motor_position_counter(kMotorPortDriveRight);
        motor(kMotorPortDriveRight, power);
        while (get_motor_position_counter(kMotorPortDriveRight) < -ticks) {}
        motor(kMotorPortDriveRight, 0);
    }
    
}

void drive_straight(int distance) {
    double target_left = distance * kCalibrationFactorTicks * kCalibrationFactorTicksLeft + kCalibrationConstantTicks + kCalibrationConstantTicksLeft;
    //double target_right = distance * kCalibrationFactorTicks * kCalibrationFactorTicksRight + kCalibrationConstantTicks + kCalibrationConstantTicksRight;
    clear_motor_position_counter(kMotorPortDriveLeft);
    clear_motor_position_counter(kMotorPortDriveRight);
    motor(kMotorPortDriveLeft, (int) (100 * (distance < 0 ? -1 : 1) * kCalibrationFactorDrive * kCalibrationFactorDriveLeft));
    motor(kMotorPortDriveRight, (int) (100 * (distance < 0 ? -1 : 1) * kCalibrationFactorDrive * kCalibrationFactorDriveRight));
    bool done_left = false;
    //bool done_right = false;
    while(!done_left) {
        if (!done_left && get_motor_position_counter(kMotorPortDriveLeft) / (double) target_left >= 1.0) {
            done_left = true;
            drive_off(kMotorPortDriveLeft);
            drive_off(kMotorPortDriveRight);
        }
    }
}

void drive_arc(int radius, double angle) {
    double distance_left = (fabs(angle) * (radius + (angle < 0 ? -1 : 1) * SCOOPER_RADIUS));
    double distance_right = (fabs(angle) * (radius + (angle < 0 ? 1 : -1) * SCOOPER_RADIUS));
    double target_left = distance_left * kCalibrationFactorTicks * kCalibrationFactorTicksLeft + kCalibrationConstantTicks + kCalibrationConstantTicksLeft;
    double target_right = distance_right * kCalibrationFactorTicks * kCalibrationFactorTicksRight + kCalibrationConstantTicks + kCalibrationConstantTicksRight;
    clear_motor_position_counter(kMotorPortDriveLeft);
    clear_motor_position_counter(kMotorPortDriveRight);
    double power_left = angle < 0 ? (100.0 * radius / (radius + SCOOPER_RADIUS)) : 100.0;
    double power_right = angle < 0 ? 100.0 : (100.0 * radius / (radius + SCOOPER_RADIUS));
    printf("running motor L at %f mm/s for %f mm (%f ticks)\n", power_left, target_left, distance_left);
    printf("running motor R at %f mm/s for %f mm (%f ticks)\n", power_right, target_right, distance_right);
    motor(kMotorPortDriveLeft, (int) ((power_left - ((100 - power_left) * kCalibrationFactorPower)) * (radius < 0 ? -1 : 1) * kCalibrationFactorDrive * kCalibrationFactorDriveLeft));
    motor(kMotorPortDriveRight, (int) ((power_right - ((100 - power_right) * kCalibrationFactorPower)) * (radius < 0 ? -1 : 1) * kCalibrationFactorDrive * kCalibrationFactorDriveRight));
    while(true) {
        if (get_motor_position_counter(kMotorPortDriveLeft) / (double) target_left >= 1.0
         || get_motor_position_counter(kMotorPortDriveRight) / (double) target_right >= 1.0) {
            drive_off(kMotorPortDriveLeft);
            drive_off(kMotorPortDriveRight);
            break;
        }
    }
}

void drive_spin(double angle) {
    /*double angular_velocity = angle * 1000.0 / duration;
    drive_at_velocity(kMotorPortDriveLeft, (int) (angular_velocity * -SCOOPER_RADIUS) * kCalibrationFactorDrive * kCalibrationFactorDriveLeft + kCalibrationConstantDrive + kCalibrationConstantDriveLeft);
    drive_at_velocity(kMotorPortDriveRight, (int) (angular_velocity * SCOOPER_RADIUS) * kCalibrationFactorDrive * kCalibrationFactorDriveRight + kCalibrationConstantDrive + kCalibrationConstantDriveRight);
    msleep(duration);
    drive_off(kMotorPortDriveLeft);
    drive_off(kMotorPortDriveRight);*/
}

/*void drive_at_velocity(int port, int vel) {
    motor(port, (int) (vel * kCalibrationFactorPower));
    printf("driving m%i at %i mm/s (pwm: %i)\n", port, vel, (int) (vel * kCalibrationFactorPower));
}*/

void drive_off(int port) {
    motor(port, 0);
}

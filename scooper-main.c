
#include <stdio.h>
#include <stdlib.h>
#include <kovan/kovan.h>
#include <math.h>
#include "scooper-constants.h"
#include "scoop-utils.h"
#include "drive-utils.h"

void startup_servos(void);

int main(int argc, char** argv) {
    startup_servos();
    drive_straight(340);
    
    motor(kMotorPortDriveLeft, 100);
    motor(kMotorPortDriveRight, 5);
    msleep(2200);
    motor(kMotorPortDriveLeft, 0);
    motor(kMotorPortDriveRight, 0);
    
    // pile 1
    open_scoop_doors();
    lower_scoop();
    tilt_scoop_low();
    drive_straight(250);
    close_scoop_doors();
    tilt_scoop_high();
    
    // cube
    drive_straight(50);
    open_scoop_doors();
    tilt_scoop_low();
    motor(kMotorPortDriveLeft, 50);
    motor(kMotorPortDriveRight, -50);
    msleep(500);
    motor(kMotorPortDriveLeft, 0);
    motor(kMotorPortDriveRight, 0);
    close_scoop_doors();
    motor(kMotorPortDriveLeft, 50);
    motor(kMotorPortDriveRight, -50);
    msleep(500);
    motor(kMotorPortDriveLeft, 0);
    motor(kMotorPortDriveRight, 0);
    return 0;
    
    // pile 2
    drive_straight(275);
    open_scoop_doors();
    tilt_scoop_low();
    drive_straight(250);
    close_scoop_doors();
    tilt_scoop_high();
    
    drive_straight(-750);
    
    motor(kMotorPortDriveLeft, -100);
    motor(kMotorPortDriveRight, -5);
    msleep(2300);
    motor(kMotorPortDriveLeft, 0);
    motor(kMotorPortDriveRight, 0);
    
    drive_straight(-400);
    
    motor(kMotorPortDriveLeft, 100);
    motor(kMotorPortDriveRight, -50);
    msleep(1000);
    motor(kMotorPortDriveLeft, 0);
    motor(kMotorPortDriveRight, 0);
    
    return 0;
}

void startup_servos(void) {
    enable_servos();
    raise_scoop();
    tilt_scoop_low();
    msleep(500);
}



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
    drive_straight(440);//old value 320
    /*//to be replaced with tick thing
    motor(kMotorPortDriveLeft, 100);
    motor(kMotorPortDriveRight, 5);
    msleep(2430);
    motor(kMotorPortDriveLeft, 0);
    motor(kMotorPortDriveRight, 0);*/
    
    turn_ticks(50, 1280);
    
    // pile 1
    open_scoop_doors();
    lower_scoop();
    tilt_scoop_low();
    drive_straight(260);
    close_scoop_doors();
    raise_scoop_level();
    
    
    
    //Reverse to pile 2
    
    
    drive_straight(-240);
    turn_ticks(50, -700);
    drive_straight(-310);
    
    turn_ticks(50, 740);
    lower_scoop_level();
    open_scoop_doors();
    
    //pick up pile 2
    
    //lower_scoop();
    //tilt_scoop_low();
    drive_straight(145);
    close_scoop_doors();
    raise_scoop_level(); 
    drive_straight(250);
    
    raise_scoop_very_high();
    open_doors_wide();
    
    turn_ticks(50, 500);
    drive_straight(-50);

    //set_servo_position(kServoPortScoopTiltLeft, kServoPositionScoopTiltHigh - 300);
    //set_servo_position(kServoPortScoopTiltLeft, (2047 - kServoPositionScoopTiltHigh) + 300);
    turn_ticks(50, 555);
    
    
    // drive_straight(50);
    
    dump();
    msleep(500);
    dump_shake();
    dump();
    dump_shake();
    dump();
    return 0;
    
    //raise_scoop();
    raise_scoop_very_high();
    drive_straight(-100);
    turn_ticks(50, -800);
    lower_scoop_level();
    drive_straight(1000);
    turn_ticks(100, -1000);
    turn_ticks(100, 1000);
}

void startup_servos(void) {
    enable_servos();
    raise_scoop();
    tilt_scoop_low();
    msleep(500);
}


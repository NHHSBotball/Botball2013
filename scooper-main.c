
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
    open_doors_wide();
    drive_straight(-50);
    
    lower_scoop_level();
    
    drive_straight(300);
    //close_scoop_doors();
    raise_scoop_very_high();
    drive_straight(185);//old value 320
    /*//to be replaced with tick thing
    motor(kMotorPortDriveLeft, 100);
    motor(kMotorPortDriveRight, 5);
    msleep(2430);
    motor(kMotorPortDriveLeft, 0);
    motor(kMotorPortDriveRight, 0);*/
    //dump();
    //close_scoop_doors();
    //open_scoop_doors();
    //dump();
    //msleep(800);
    raise_scoop_level();
    close_doors_wide();
    turn_ticks(50, 1058);
    
    // pile 1
    open_scoop_doors();
    lower_scoop_time(2000);
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
    drive_straight(155);
    close_scoop_doors();
    raise_scoop_level(); 
    drive_straight(250);
    
    raise_scoop_very_high();
    
    turn_ticks(50, 500);
    drive_straight(-60);

    //set_servo_position(kServoPortScoopTiltLeft, kServoPositionScoopTiltHigh - 300);
    //set_servo_position(kServoPortScoopTiltLeft, (2047 - kServoPositionScoopTiltHigh) + 300);
    turn_ticks(50, 555);
    
    
    // drive_straight(50);
    
    open_doors_wide();
    dump();
    msleep(500);
    dump_shake();
    dump();
    dump_shake();
    dump();
    
    //raise_scoop();
    raise_scoop_very_high();
    
    drive_straight(-300);
    close_doors_wide();
    turn_ticks_in_place(50, -1050);
    
    
    //drive to pile 3
    lower_scoop_level();
    open_scoop_doors();
    drive_straight(500);
    
    //pick up pile 3
    close_scoop_doors();
    raise_scoop_level();
    drive_straight(-500);
    return 0;
    
    turn_ticks_in_place(50, -475);
    drive_straight(-200);
    turn_ticks_in_place(50, 475);
    drive_straight(400);
    //pick up pile 4
    lower_scoop_level();
    
    drive_straight(500);
    open_scoop_doors();
    
}

void startup_servos(void) {
    enable_servos();
    set_servo_position(kServoPortScoopLeft, 2047 - 1706);
    set_servo_position(kServoPortScoopRight, 1706);
    set_servo_position(kServoPortScoopTiltLeft, 360);
    set_servo_position(kServoPortScoopTiltRight, 2047 - 360);
    scanf("%s", NULL);
}


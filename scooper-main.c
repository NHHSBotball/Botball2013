
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
    
    raise_scoop_level();
    
    drive_straight(900);
    drive_straight(-50);//old value 320
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
    turn_ticks_in_place(50, 750);
    
    // pile 1
    open_doors_narrow();
    lower_scoop_level();
    drive_straight(370);
    close_scoop_doors();
    raise_scoop_level();
    
    
    
    //Reverse to pile 2
    
    
    drive_straight(-290);
    turn_ticks(50, -700);
    drive_straight(-250);
    set_servo_position(kServoPortScoopTiltLeft, kServoPositionScoopTiltHighBack);
    set_servo_position(kServoPortScoopTiltRight, 2047 - kServoPositionScoopTiltHighBack);
    turn_ticks(50, 770);//this value
    lower_scoop_level();
    open_scoop_doors();
    
    //pick up pile 2
    drive_straight(320);
    close_scoop_doors();
    raise_scoop_level(); 
    drive_straight(80);
    
    raise_scoop_very_high();
    
    drive_straight(170);
    turn_ticks(50, 500);
    drive_straight(-90);
    turn_ticks_in_place(50, 650);
    drive_straight(100);

    //set_servo_position(kServoPortScoopTiltLeft, kServoPositionScoopTiltHigh - 300);
    //set_servo_position(kServoPortScoopTiltLeft, (2047 - kServoPositionScoopTiltHigh) + 300);
    // turn_ticks(50, 555);
    
    
    // drive_straight(50);
    
    //set_servo_position(kServoPortScoopTiltLeft, 1000);
    //set_servo_position(kServoPortScoopTiltRight, 2047 - 1000);
    msleep(200);
    open_doors_wide();
    dump();
    msleep(500);
    dump_shake();
    dump();
    dump_shake();
    dump();
    
    //raise_scoop();
    drive_straight(-400);
    raise_scoop_level();
    close_doors_wide();
    raise_scoop_very_high();
    turn_ticks_in_place(50, -1350);
    drive_straight(100);
    
    //drive to pile 3
    raise_scoop_level();
    turn_ticks_in_place(50, 700);
    turn_ticks_in_place(50, -400);
    lower_scoop_level();
    turn_ticks_in_place(50, -300);
    drive_straight(100);
    
    //pick up pile 3
    open_scoop_doors();
    drive_straight(400);
    close_scoop_doors();
    turn_ticks_in_place(50, -100);
    drive_straight(-400);
    raise_scoop_level();
    turn_ticks_in_place(50, -100);
    drive_straight(-400);
    turn_ticks_in_place(50, -200);
    drive_straight(-290);
    lower_scoop_level();
    turn_ticks_in_place(50, 1150);
    turn_ticks_in_place(50, -100);
    raise_scoop_level();
    
    // drive to/pick up pile 4
    drive_straight(500);
    turn_ticks_in_place(50, 400);
    mid_scoop_level();
    turn_ticks_in_place(50, -900);
    raise_scoop_level();
    turn_ticks_in_place(50, 400);
    lower_scoop_level();
    turn_ticks_in_place(50, 500);
    turn_ticks_in_place(50, -50);
    open_scoop_doors();
    drive_straight(230);
    close_scoop_doors();
    raise_scoop_level();
    
    // dump other load
    turn_ticks_inverse(50, 500);
    drive_straight(-100);
    turn_ticks_in_place(50, -100);
    drive_straight(-150);
    raise_scoop_very_high();
    turn_ticks_in_place(50, 700);
    drive_straight(200);
    
    set_servo_position(kServoPortScoopTiltLeft, 1000);
    set_servo_position(kServoPortScoopTiltRight, 2047 - 1000);
    msleep(200);
    open_doors_wide();
    dump();
    msleep(500);
    dump_shake();
    dump();
    dump_shake();
    dump();
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
    set_servo_position(kServoPortScoopTiltLeft, 800);
    set_servo_position(kServoPortScoopTiltLeft, 2047 - 800);
    scanf("%s", NULL);
}


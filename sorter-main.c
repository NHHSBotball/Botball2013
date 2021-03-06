
#include <stdio.h>
#include <stdlib.h>
#include <kovan/kovan.h>
#include <stdbool.h>
#include <unistd.h>
#include "sorter-constants.h"
#include "utils.h"

void raise_bay(void);
void lower_bay(void);
void start_spinner(void);
void stop_spinner(void);
void sort_balls(void);
void jiggle_create(void);
void wait_for_kill(void);

int main(int argc, char** argv) {
    enable_servo(kServoPortSorter);
    set_servo_position(kServoPortSorter, kServoPositionSorterCenter);
    clear_motor_position_counter(kMotorPortBayLeft);
    clear_motor_position_counter(kMotorPortBayRight);
    create_connect();
    camera_open(LOW_RES);
    
    scanf("%s", NULL);
    printf("waiting for light\n");
    while (analog(0) > 200) {}
    
    shut_down_in(700000);
    
    motor(kMotorPortBayLeft, 10);
    motor(kMotorPortBayRight, 10);
    while (get_motor_position_counter(kMotorPortBayLeft) < 230 || get_motor_position_counter(kMotorPortBayRight) < 230) {
        printf("pos: %i/%i\n", get_motor_position_counter(kMotorPortBayLeft), get_motor_position_counter(kMotorPortBayRight));
    }
    motor(kMotorPortBayLeft, 0);
    motor(kMotorPortBayLeft, 0);
    // wait_for_side_button();
    
    msleep(6000);
    
    create_drive_straight(200);
    msleep(1850);
    create_spin_CCW(200);
    msleep(750);
    create_drive_straight(-200);
    msleep(1500);
    create_spin_CW(200);
    msleep(1750);
    create_drive_straight(200);
    while (!get_create_lbump() && !get_create_rbump()) {}
    create_drive_straight(-150);
    msleep(900);
    create_spin_CCW(200);
    msleep(950);
    create_drive_straight(150);
    while (!get_create_lbump() && !get_create_rbump()) {}
    create_stop();
    
    msleep(10000);
    
    thread all_off = thread_create(wait_for_kill);
    thread_start(all_off);
    
    raise_bay();
    create_spin_CW(100);
    msleep(500);
    create_drive_straight(-100);
    msleep(1000);
    create_stop();
    
    thread jiggle_c = thread_create(jiggle_create);
    thread_start(jiggle_c);
    thread sort_b = thread_create(sort_balls);
    thread_start(sort_b);
    
    msleep(33000);
    
    while (true) {}
    
    /*thread_destroy(jiggle_c);
    create_stop();
    lower_bay();
    create_drive_straight(100);
    while (!get_create_lbump() && !get_create_rbump()) {}
    create_stop();
    
    msleep(10000);
    
    raise_bay();
    create_spin_CW(100);
    msleep(500);
    create_drive_straight(-100);
    msleep(1000);
    create_stop();
    
    thread_create(jiggle_create);
    thread_start(jiggle_c);
    thread_create(sort_balls);
    
    while (true) {}
    
    camera_close();*/
    return 0;
}

void raise_bay(void) {
    while (get_motor_position_counter(kMotorPortBayLeft) > 30 || get_motor_position_counter(kMotorPortBayRight) > 30) {
        motor(kMotorPortBayLeft, -50);
        motor(kMotorPortBayRight, -50);
        msleep(200);
        //motor(kMotorPortBayLeft, 0);
        //motor(kMotorPortBayRight, 0);
        //msleep(200);
        printf("pos: %i/%i\n", get_motor_position_counter(kMotorPortBayLeft), get_motor_position_counter(kMotorPortBayRight));
    }
    motor(kMotorPortBayLeft, 0);
    motor(kMotorPortBayLeft, 0);
}

void lower_bay(void) {
    motor(kMotorPortBayLeft, 10);
    motor(kMotorPortBayRight, 10);
    while (get_motor_position_counter(kMotorPortBayLeft) < 230 || get_motor_position_counter(kMotorPortBayRight) < 230) {
        printf("pos: %i/%i\n", get_motor_position_counter(kMotorPortBayLeft), get_motor_position_counter(kMotorPortBayRight));
    }
    motor(kMotorPortBayLeft, 0);
    motor(kMotorPortBayLeft, 0);
}

void start_spinner(void) {
    mav(kMotorPortSpinner, 500);
}

void stop_spinner(void) {
    off(kMotorPortSpinner);
}

void sort_balls(void) {
    start_spinner();
    
    while (!side_button()) {
        msleep(50);
        camera_update(); camera_update();
        if (get_object_count(kCameraChannelOrange) > 0 && get_object_confidence(kCameraChannelOrange, 0) >= 0.95 && get_object_area(kCameraChannelOrange, 0) > 500) {
            stop_spinner();
            set_servo_position(kServoPortSorter, kServoPositionSorterOrange);
            msleep(200);
            set_servo_position(kServoPortSorter, kServoPositionSorterCenter);
            msleep(200);
            start_spinner();
        } else if (get_object_count(kCameraChannelGreen) > 0  && get_object_confidence(kCameraChannelGreen, 0) >= 0.95 && get_object_area(kCameraChannelGreen, 0) > 500) {
            stop_spinner();
            set_servo_position(kServoPortSorter, kServoPositionSorterGreen);
            msleep(200);
            set_servo_position(kServoPortSorter, kServoPositionSorterCenter);
            msleep(200);
            start_spinner();
        }
    }
    
    alloff();
}

void jiggle_create(void) {
    while (true) {
        create_drive_direct(180, -180);
        msleep(5);
        create_drive_direct(-180, 180);
        msleep(5);
    }
}

void wait_for_kill(void) {
    while (!side_button()) {}
    alloff();
    motor(0, 0);
    motor(1, 0);
    motor(2, 0);
    motor(3, 0);
    alloff();
    disable_servos();
    create_drive_direct(0, 0);
    create_stop();
    create_disconnect();
    exit(0);
}


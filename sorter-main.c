
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
    enable_servo(kServoPortBayLeft);
    enable_servo(kServoPortBayRight);
    set_servo_position(kServoPortSorter, kServoPositionSorterCenter);
    create_connect();
    camera_open(LOW_RES);
    
    pthread_t left = set_servo_pos_millis_async(kServoPortBayLeft, kServoPositionBayLeftHorizontal, 2000);
    pthread_t right = set_servo_pos_millis_async(kServoPortBayRight, kServoPositionBayRightHorizontal, 2000);
    pthread_join(left, NULL);
    pthread_join(right, NULL);
    wait_for_side_button();
    
    thread all_off = thread_create(wait_for_kill);
    thread_start(all_off);
    
    raise_bay();
    thread jiggle_c = thread_create(jiggle_create);
    thread_start(jiggle_c);
    sort_balls();
    lower_bay();
    
    camera_close();
    return 0;
}

void raise_bay(void) {
    pthread_t left = set_servo_pos_millis_async(kServoPortBayLeft, kServoPositionBayLeftVertical, 2500);
    pthread_t right = set_servo_pos_millis_async(kServoPortBayRight, kServoPositionBayRightVertical, 2500);
    pthread_join(left, NULL);
    pthread_join(right, NULL);
}

void lower_bay(void) {
    pthread_t left = set_servo_pos_millis_async(kServoPortBayLeft, kServoPositionBayLeftHorizontal, 2500);
    pthread_t right = set_servo_pos_millis_async(kServoPortBayRight, kServoPositionBayRightHorizontal, 2500);
    pthread_join(left, NULL);
    pthread_join(right, NULL);
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
        create_drive_direct(150, -150);
        msleep(5);
        create_drive_direct(-150, 150);
        msleep(5);
    }
}

void wait_for_kill(void) {
    while (!side_button()) {}
    alloff();
    disable_servos();
    create_drive_direct(0, 0);
    create_stop();
    create_disconnect();
    exit(0);
}


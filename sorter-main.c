
#include <stdio.h>
#include <stdlib.h>
#include <kovan/kovan.h>
#include <stdbool.h>
#include "sorter-constants.h"
#include "utils.h"

void raise_bay(void);
void lower_bay(void);
void sort_balls(void);

int main(int argc, char** argv) {
    enable_servo(kServoPortSorter);
    enable_servo(kServoPortBayLeft);
    enable_servo(kServoPortBayRight);
    set_servo_position(kServoPortSorter, kServoPositionSorterCenter);
    set_servo_pos_millis(kServoPortSorter, kServoPositionSorterCenter, 1000);
    camera_open(LOW_RES);
    
    set_servo_position(kServoPortBayLeft, kServoPositionBayLeftHorizontal);
    set_servo_position(kServoPortBayRight, kServoPositionBayRightHorizontal);
    wait_for_side_button();
    
    raise_bay();
    sort_balls();
    lower_bay();
    
    camera_close();
    return 0;
}

void raise_bay(void) {
    pthread_t left = set_servo_pos_millis_async(kServoPortBayLeft, kServoPositionBayLeftVertical, 1000);
    pthread_t right = set_servo_pos_millis_async(kServoPortBayRight, kServoPositionBayRightVertical, 1000);
    pthread_join(left, NULL);
    pthread_join(right, NULL);
}

void lower_bay(void) {
    pthread_t left = set_servo_pos_millis_async(kServoPortBayLeft, kServoPositionBayLeftHorizontal, 1000);
    pthread_t right = set_servo_pos_millis_async(kServoPortBayRight, kServoPositionBayRightHorizontal, 1000);
    pthread_join(left, NULL);
    pthread_join(right, NULL);
}

void sort_balls(void) {
    fd(kMotorPortSpinner);
    
    while (!side_button()) {
        msleep(50);
        camera_update(); camera_update();
        if (get_object_count(kCameraChannelOrange) > 0 && get_object_confidence(kCameraChannelOrange, 0) >= 0.95 && get_object_area(kCameraChannelOrange, 0) > 500) {
            printf("area: %d\n", get_object_area(kCameraChannelOrange, 0));
            set_servo_position(kServoPortSorter, kServoPositionSorterOrange);
            msleep(200);
            set_servo_position(kServoPortSorter, kServoPositionSorterCenter);
            msleep(200);
        } else if (get_object_count(kCameraChannelGreen) > 0  && get_object_confidence(kCameraChannelGreen, 0) >= 0.95 && get_object_area(kCameraChannelGreen, 0) > 500) {
            set_servo_position(kServoPortSorter, kServoPositionSorterGreen);
            msleep(200);
            set_servo_position(kServoPortSorter, kServoPositionSorterCenter);
            msleep(200);
        }
    }
    
    alloff();
}


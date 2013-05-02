
#include <kovan/kovan.h>
#include "drive-utils.h"
#include "scooper-constants.h"
#include "utils.h"
#include "scoop-utils.h"

void open_doors_wide() {
    clear_motor_position_counter(kMotorPortScoopDoor);
    msleep(50);
    motor(kMotorPortScoopDoor, 100);
    while (get_motor_position_counter(kMotorPortScoopDoor) < kMotorPositionScoopDoorWide) {} //500
    motor(kMotorPortScoopDoor, 0);
}

void raise_scoop_very_high() {
    int time = 800;
    pthread_t threadLeft = set_servo_pos_millis_async(kServoPortScoopLeft, kServoPositionScoopMaxLeft, time);
    pthread_t threadRight = set_servo_pos_millis_async(kServoPortScoopRight, kServoPositionScoopMaxRight, time);
    
    pthread_t tiltThreadLeft = set_servo_pos_millis_async(kServoPortScoopTiltLeft, kServoPositionScoopTiltVeryHigh, time);
    pthread_t tiltThreadRight = set_servo_pos_millis_async(kServoPortScoopTiltRight, 2047 - kServoPositionScoopTiltVeryHigh, time);
    
    msleep(time);
    pthread_cancel(tiltThreadLeft);
    pthread_cancel(tiltThreadRight);
    pthread_cancel(threadLeft);
    pthread_cancel(threadRight);
}

void dump() {
    set_servo_position(kServoPortScoopTiltLeft, kServoPositionScoopTiltDump);
    set_servo_position(kServoPortScoopTiltRight, 2047 - kServoPositionScoopTiltDump);
    msleep(200);
}

void dump_shake() {
    pthread_t threadLeaft = set_servo_pos_millis_async(kServoPortScoopTiltLeft, kServoPositionScoopTiltDumpLow, 300);
    pthread_t threadRight = set_servo_pos_millis_async(kServoPortScoopTiltRight, 2047 - kServoPositionScoopTiltDumpLow, 300);
    msleep(300);
    pthread_cancel(threadLeaft);
    pthread_cancel(threadRight);
}

void lower_scoop() {
    int time = 800;
    pthread_t threadLeft = set_servo_pos_millis_async(kServoPortScoopLeft, kServoPositionScoopBottomLeft, time);
    pthread_t threadRight = set_servo_pos_millis_async(kServoPortScoopRight, kServoPositionScoopBottomRight, time);
    msleep(time);
    pthread_cancel(threadLeft);
    pthread_cancel(threadRight);
    
    //set_servo_position(kServoPortScoopLeft, kServoPositionScoopBottomLeft);
    //set_servo_position(kServoPortScoopRight, kServoPositionScoopBottomRight);
}

void raise_scoop() {
    int time = 800;
    pthread_t threadLeft = set_servo_pos_millis_async(kServoPortScoopLeft, kServoPositionScoopTopLeft, time);
    pthread_t threadRight = set_servo_pos_millis_async(kServoPortScoopRight, kServoPositionScoopTopRight, time);
    msleep(time);
    pthread_cancel(threadLeft);
    pthread_cancel(threadRight);
}

void raise_scoop_level() {
    int time = 800;
    pthread_t threadLeft = set_servo_pos_millis_async(kServoPortScoopLeft, kServoPositionScoopTopLeft, time);
    pthread_t threadRight = set_servo_pos_millis_async(kServoPortScoopRight, kServoPositionScoopTopRight, time);
    
    pthread_t tiltThreadLeft = set_servo_pos_millis_async(kServoPortScoopTiltLeft, kServoPositionScoopTiltHigh, time);
    pthread_t tiltThreadRight = set_servo_pos_millis_async(kServoPortScoopTiltRight, 2047 - kServoPositionScoopTiltHigh, time);
    
    msleep(time);
    pthread_cancel(tiltThreadLeft);
    pthread_cancel(tiltThreadRight);
    pthread_cancel(threadLeft);
    pthread_cancel(threadRight);
}

void lower_scoop_level() {
    int time = 800;
    pthread_t threadLeft = set_servo_pos_millis_async(kServoPortScoopLeft, kServoPositionScoopBottomLeft, time);
    pthread_t threadRight = set_servo_pos_millis_async(kServoPortScoopRight, kServoPositionScoopBottomRight, time);
    
    pthread_t tiltThreadLeft = set_servo_pos_millis_async(kServoPortScoopTiltLeft, kServoPositionScoopTiltLow, time);
    pthread_t tiltThreadRight = set_servo_pos_millis_async(kServoPortScoopTiltRight, 2047 - kServoPositionScoopTiltLow, time);
    
    msleep(time);
    pthread_cancel(tiltThreadLeft);
    pthread_cancel(tiltThreadRight);
    pthread_cancel(threadLeft);
    pthread_cancel(threadRight);
}

void tilt_scoop_low() {
    set_servo_position(kServoPortScoopTiltLeft, kServoPositionScoopTiltLow);
    set_servo_position(kServoPortScoopTiltRight, 2047 - kServoPositionScoopTiltLow);
}

void tilt_scoop_high() {
    set_servo_position(kServoPortScoopTiltLeft, kServoPositionScoopTiltHigh);
    set_servo_position(kServoPortScoopTiltRight, 2047 - kServoPositionScoopTiltHigh);
}

void tilt_scoop_dump() {
    set_servo_position(kServoPortScoopTiltLeft, kServoPositionScoopTiltDump);
    set_servo_position(kServoPortScoopTiltRight, 2047 - kServoPositionScoopTiltDump);
}

void open_scoop_doors() {
    clear_motor_position_counter(kMotorPortScoopDoor);
    msleep(50);
    motor(kMotorPortScoopDoor, 100);
    while (get_motor_position_counter(kMotorPortScoopDoor) < kMotorPositionScoopDoor) {} //500
    motor(kMotorPortScoopDoor, 0);
}

void close_scoop_doors() {
    clear_motor_position_counter(kMotorPortScoopDoor);
    msleep(50);
    motor(kMotorPortScoopDoor, -100);
    while (get_motor_position_counter(kMotorPortScoopDoor) >  -kMotorPositionScoopDoor) {} //700
    motor(kMotorPortScoopDoor, 0);
}

void scoop() {
    open_scoop_doors();
    lower_scoop();
    motor(0, 100);
    motor(2, 100);
    msleep(1000);
    motor(0, 0);
    motor(2, 0);
    close_scoop_doors();
    raise_scoop();
}


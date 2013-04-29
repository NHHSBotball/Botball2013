
#include <kovan/kovan.h>
#include "drive-utils.h"
#include "scooper-constants.h"
#include "utils.h"
#include "scoop-utils.h"

void lower_scoop() {
    set_servo_position(kServoPortScoopLeft, kServoPositionScoopBottomLeft);
    set_servo_position(kServoPortScoopRight, kServoPositionScoopBottomRight);
}

void raise_scoop() {
    set_servo_position(kServoPortScoopLeft, kServoPositionScoopTopLeft);
    set_servo_position(kServoPortScoopRight, kServoPositionScoopTopRight);
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
    while (get_motor_position_counter(kMotorPortScoopDoor) < 600) {}
    motor(kMotorPortScoopDoor, 0);
}

void close_scoop_doors() {
    clear_motor_position_counter(kMotorPortScoopDoor);
    msleep(50);
    motor(kMotorPortScoopDoor, -100);
    while (get_motor_position_counter(kMotorPortScoopDoor) >  -700) {}
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


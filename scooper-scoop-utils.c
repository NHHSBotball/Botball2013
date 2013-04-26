
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
    set_servo_position(kServoPortScoopTilt, 475);
    
}

void tilt_scoop_high() {
    set_servo_position(kServoPortScoopTilt, 1475);
    
}


void open_scoop_doors() {
    set_servo_position(kServoPortScoopDoor, kServoPositionScoopDoorOpen);
    
}

void close_scoop_doors() {
    set_servo_position(kServoPortScoopDoor, kServoPositionScoopDoorClosed);
    
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


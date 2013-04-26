
#ifndef SCOOPER_CONSTANTS_H
#define	SCOOPER_CONSTANTS_H

#include "constants.h"

#define SCOOPER_RADIUS 42.0

#define kCalibrationFactorDrive          1.0
#define kCalibrationFactorDriveLeft      1.0
#define kCalibrationFactorDriveRight     1.0
#define kCalibrationConstantDrive        0.0
#define kCalibrationConstantDriveLeft    0.0
#define kCalibrationConstantDriveRight   0.0

#define kServoPortScoopLeft 0
#define kServoPortScoopRight 1
#define kServoPortScoopTilt 2
#define kServoPortScoopDoor 3
#define kMotorPortDriveLeft 0
#define kMotorPortDriveRight 2

#define kServoPositionScoopBottomLeft 1000
#define kServoPositionScoopBottomRight (2047 - kServoPositionScoopLeft)
#define kServoPositionScoopTopLeft 168
#define kServoPositionScoopTopRight (2047 - kServoPositionScoopTopLeft)

#define kServoPositionScoopTiltLow 475
#define kServoPositionScoopTiltHigh 1475

#define kServoPositionScoopDoorOpen 0
#define kServoPositionScoopDoorClosed 2047


#endif	/* SCOOPER_CONSTANTS_H */



#ifndef SCOOPER_CONSTANTS_H
#define	SCOOPER_CONSTANTS_H

#include "constants.h"

#define SCOOPER_RADIUS 37.5

#define kCalibrationFactorDrive          1.0
#define kCalibrationFactorDriveLeft      1.0
#define kCalibrationFactorDriveRight     0.973
#define kCalibrationFactorTicks          5.28
#define kCalibrationFactorTicksLeft      1.0
#define kCalibrationFactorTicksRight     0.975
#define kCalibrationConstantTicks        0.0
#define kCalibrationConstantTicksLeft    0.0
#define kCalibrationConstantTicksRight   0.0
#define kCalibrationFactorPower          5.20

#define kServoPortScoopLeft 2
#define kServoPortScoopRight 0
#define kServoPortScoopTiltLeft 3
#define kServoPortScoopTiltRight 1

#define kMotorPortScoopDoor 3
#define kMotorPortDriveLeft 2
#define kMotorPortDriveRight 0

#define kServoPositionScoopBottomLeft 1527
#define kServoPositionScoopBottomRight (2047 - kServoPositionScoopBottomLeft)
#define kServoPositionScoopTopLeft 930
#define kServoPositionScoopTopRight (2047 - kServoPositionScoopTopLeft)
#define kServoPositionScoopMaxLeft 444
#define kServoPositionScoopMaxRight (2047 - kServoPositionScoopMaxLeft)

#define kServoPositionScoopTiltLow 300
#define kServoPositionScoopTiltHigh 600
#define kServoPositionScoopTiltVeryHigh 1200
#define kServoPositionScoopTiltDump 1410
#define kServoPositionScoopTiltDumpLow 900

#define kMotorPositionScoopDoor 560
#define kMotorPositionScoopDoorWide 1060


#endif	/* SCOOPER_CONSTANTS_H */



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

#define kServoPositionScoopBottomLeft 1591
#define kServoPositionScoopBottomRight (2047 - kServoPositionScoopBottomLeft)
#define kServoPositionScoopMidLeft 1400
#define kServoPositionScoopMidRight (2047 - kServoPositionScoopMidLeft)
#define kServoPositionScoopTopLeft 850
#define kServoPositionScoopTopRight (2047 - kServoPositionScoopTopLeft)
#define kServoPositionScoopMaxLeft 444
#define kServoPositionScoopMaxRight (2047 - kServoPositionScoopMaxLeft)

#define kServoPositionScoopTiltOffset 400
#define kServoPositionScoopTiltLow 323
#define kServoPositionScoopTiltHigh (600 + kServoPositionScoopTiltOffset)
#define kServoPositionScoopTiltHighBack (400 + kServoPositionScoopTiltOffset)
#define kServoPositionScoopTiltVeryHigh 1347
#define kServoPositionScoopTiltDump (1410 + kServoPositionScoopTiltOffset)
#define kServoPositionScoopTiltDumpLow (900 + kServoPositionScoopTiltOffset)

#define kMotorPositionScoopDoor 530
#define kMotorPositionScoopDoorWide 1060


#endif	/* SCOOPER_CONSTANTS_H */


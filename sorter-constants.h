
#ifndef SORTER_CONSTANTS_H
#define	SORTER_CONSTANTS_H

#include "constants.h"

#define kCalibrationFactorDrive          1.0
#define kCalibrationFactorDriveLeft      1.0
#define kCalibrationFactorDriveRight     1.0
#define kCalibrationFactorSpin           1.0
#define kCalibrationConstantDrive        0.0
#define kCalibrationConstantDriveLeft    0.0
#define kCalibrationConstantDriveRight   0.0
#define kCalibrationConstantSpin         0.0

#define kServoPortSorter 0
#define kServoPortBayLeft 1
#define kServoPortBayRight 2
#define kMotorPortSpinner 0

#define kServoPositionSorterCenter 945
#define kServoPositionSorterGreen 510
#define kServoPositionSorterOrange 1450

#define kServoPositionBayLeftHorizontal 350
#define kServoPositionBayLeftVertical 1110
#define kServoPositionBayRightHorizontal (2047 - kServoPositionBayLeftHorizontal)
#define kServoPositionBayRightVertical (2047 - kServoPositionBayLeftVertical)

#define kCameraChannelGreen 0
#define kCameraChannelOrange 1

#endif	/* SORTER_CONSTANTS_H */



#ifndef DRIVE_UTILS_H
#define	DRIVE_UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <kovan/kovan.h>

/**
 * Calibratable Movement Utils Functions
 * Units:
 *   duration : milliseconds
 *   distance : millimeters
 *   angle    : radians
 * To calibrate, change the preprocessor definitions at the top
 * of the respective constants files.
 */

void drive_straight(int duration, int distance);
void drive_arc(int duration, int radius, int angle);
void drive_spin(int duration, int angle);

#endif	/* DRIVE_UTILS_H */



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
 *   distance : millimeters
 *   angle    : radians
 * To calibrate, change the preprocessor definitions at the top
 * of the respective constants files.
 */

void drive_straight(int distance);
void drive_arc(int radius, double angle);
void drive_spin(double angle);

#endif	/* DRIVE_UTILS_H */


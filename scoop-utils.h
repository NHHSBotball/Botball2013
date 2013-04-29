/* 
 * File:   scoop-utils.h
 * Author: Henry
 *
 * Created on April 25, 2013, 4:32 PM
 */

#ifndef SCOOP_UTILS_H
#define	SCOOP_UTILS_H

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

void lower_scoop();
void raise_scoop();
void tilt_scoop_low();
void tilt_scoop_high();
void tilt_scoop_dump();
void open_scoop_doors();
void close_scoop_doors();
void scoop();

#endif	/* DRIVE_UTILS_H */


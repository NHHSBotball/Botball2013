
#ifndef UTILS_H
#define	UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <kovan/kovan.h>

void wait_for_a_button(void);
void wait_for_side_button(void);

void set_servo_pos_millis(int port, int pos, int millis);
pthread_t set_servo_pos_millis_async(int port, int pos, int millis);

#endif	/* UTILS_H */


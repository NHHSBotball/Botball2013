
#ifndef UTILS_H
#define	UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <kovan/kovan.h>

void wait_for_a_button(void);
void wait_for_side_button(void);

/**
 * Sets a servo position over a number of milliseconds. By default, this
 * function blocks. For an async version, you can use the
 * set_servo_pos_millis_async() function instead.
 * @param port servo port
 * @param pos target servo position
 * @param millis milliseconds to run for
 */
void set_servo_pos_millis(int port, int pos, int millis);

/**
 * Sets a servo position over a number of milliseconds asynchronously. It
 * automatically creates and runs a thread which itself calls the
 * set_servo_pos_millis() function. If you don't need non-blocking functionality
 * use that function instead. This function returns a pthread object, which
 * may be used by the caller to synchronize or wait for thread completion.
 * @param port servo port
 * @param pos target servo position
 * @param millis milliseconds to run for
 * @return thread object
 */
pthread_t set_servo_pos_millis_async(int port, int pos, int millis);

#endif	/* UTILS_H */


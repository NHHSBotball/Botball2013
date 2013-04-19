
#include "utils.h"

void wait_for_a_button(void) {
    while (!a_button()) {}
    while (a_button()) {}
}

void wait_for_side_button(void) {
    while (!side_button()) {}
    while (side_button()) {}
}

void set_servo_pos_millis(int port, int target, int millis) {
    int pos = get_servo_position(port);
    if (target == pos) return;
    int dx = pos < target ? 5 : -5;
    int dt = millis * 5 / abs(pos - target);
    do {
        pos += dx;
        set_servo_position(port, pos);
        msleep(dt);
    } while (abs(pos - target) > 5);
    set_servo_position(port, target);
}

struct set_servo_pos_millis_data {
    int port;
    int target;
    int millis;
};
static void* set_servo_pos_millis_thread(void* data) {
    struct set_servo_pos_millis_data* s_data = (struct set_servo_pos_millis_data*) data;
    set_servo_pos_millis(s_data->port, s_data->target, s_data->millis);
    free(data);
    return NULL;
}
pthread_t set_servo_pos_millis_async(int port, int target, int millis) {
    pthread_t t;
    struct set_servo_pos_millis_data* data = malloc(sizeof(*data));
    data->port = port;
    data->target = target;
    data->millis = millis;
    if (pthread_create(&t, NULL, set_servo_pos_millis_thread, data) != 0) {
        fprintf(stderr, "utils: fatal error: error creating pthread object\n");
        exit(EXIT_FAILURE);
    }
    return t;
}

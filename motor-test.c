
#include <stdio.h>
#include <stdlib.h>
#include <kovan/kovan.h>
#include <stdbool.h>
#include <unistd.h>

int main(int argc, char** argv) {
    clear_motor_position_counter(1);
    clear_motor_position_counter(2);
    motor(1, 30);
    motor(2, 30);
    while (!side_button()) {
        printf("pos: %i/%i\n", get_motor_position_counter(1), get_motor_position_counter(2));
        msleep(10);
    }
    alloff();
    return 0;
}

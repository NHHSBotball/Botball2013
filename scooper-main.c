
#include <stdio.h>
#include <stdlib.h>
#include <kovan/kovan.h>
#include "scooper-constants.h"
#include "scoop-utils.h"
#include "drive-utils.h"

int main(int argc, char** argv) {
    enable_servos();
    scoop();
    return 0;
}


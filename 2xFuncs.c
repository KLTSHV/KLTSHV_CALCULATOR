#include <stdio.h>
#include <string.h>

int determineNumberSystem(char* number) {
    if (strncmp(number, "0x", 2) == 0) {
        return 16;
    } else if (number[0] == '0') {
        return 8;
    } else {
        return 2;
    }
}


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>
#include <math.h>

int octalToDecimal(char octalNumber[]) {
    int decimalNumber = 0;
    int length = strlen(octalNumber);
    int power = length - 1;

    for (int i = 0; i < length; i++) {
        int digit = octalNumber[i] - '0';
        decimalNumber += digit * pow(8, power);
        power--;
    }

    return decimalNumber;
}

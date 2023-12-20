#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int hexToDecimal(char* hexString){

    int length = strlen(hexString);
    int decimal = 0;
    int base = 1;

    for (int i = length - 1; i >= 0; i--) {
        if (hexString[i] >= '0' && hexString[i] <= '9') {
            decimal += (hexString[i] - '0') * base;
        } else if (hexString[i] >= 'A' && hexString[i] <= 'F') {
            decimal += (hexString[i] - 'A' + 10) * base;
        } else if (hexString[i] >= 'a' && hexString[i] <= 'f') {
            decimal += (hexString[i] - 'a' + 10) * base;
        } else {
            printf("Некорректный ввод\n");
            return -1;
        }
        base = base * 16;
    }

    return decimal;
}


}
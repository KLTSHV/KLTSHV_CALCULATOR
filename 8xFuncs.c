#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int isOctalNumber(const char* input) {
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] < '0' || input[i] > '7') {
            return 0;  
        }
    }
    return 1; 
}

int octalToDecimal(char *octalNumber) {
    int decimalNumber = 0;
    int length = strlen(octalNumber);

    int isNegative = 0;
    int startIndex = 0;

    if (octalNumber[0] == '-') {
        isNegative = 1;
        startIndex = 1;
    }


    for (int i = startIndex; i < length; i++) {
        decimalNumber += (octalNumber[i] - '0') * pow(8, length - 1 - i);
    }


    if (isNegative) {
        decimalNumber = -decimalNumber;
    }

    return decimalNumber;
}


char* decimalToOctal(int num) {
    char octalString[20]; 
    int isNegative = 0;

    if (num < 0) {
        isNegative = 1;
        num = -num; 
    }

    sprintf(octalString, "%s%o", (isNegative ? "-0" : "0"), num); 

    char* result = (char*)malloc((sizeof(octalString) + 1) * sizeof(char)); 
    sprintf(result, "%s", octalString); 
    return result;
}


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int binaryToDecimal(char* binary) {
    int length = strlen(binary);
    int decimal = 0;
    int i;

    for (i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, length - 1 - i);
        } else if (binary[i] != '0') {
            printf("Invalid binary number\n");
            return -1;
        }
    }

    return decimal;
}


int determineNumberSystem(char* number) {
    if (strncmp(number, "0x", 2) == 0) {
        return 16;
    } else if (number[0] == '0') {
        return 8;
    } else {
        return 2;
    }
}


int determineOperation(char* op) {
    if (strcmp(op, "+") == 0){
        return 1;    
    }
    else if (strcmp(op, "-") == 0){
        return 2;    
    }
    else if (strcmp(op, "*") == 0){
        return 3;    
    }
    else if (strcmp(op, "%") == 0){
        return 4;    
    }
    else if (strcmp(op, "&") == 0){
        return 5;    
    }
    else if (strcmp(op, "|") == 0){
        return 6;    
    }
    else if (strcmp(op, "^") == 0){
        return 7;
    }
    else{
        return 0; // возврат значения по умолчанию, если операция не распознана
    }
}



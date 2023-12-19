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


int determineOperation(char* op) {
    if (strcmp(op, "+") == 0){
        return 1;    
    }
    else if (strcmp(op, "-") == 0){
        return 2;    
    }
    else if (strcmp(op, "&") == 0){
        return 3;    
    }
    else if (strcmp(op, "%") == 0){
        return 4;    
    }
    else if (strcmp(op, "*") == 0){
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



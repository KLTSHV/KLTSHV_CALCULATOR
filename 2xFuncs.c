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
#include <stdio.h>

int determineOperation(char op) {
    if (strcmp(op, "+")==0){
        return 1;    
    }
    if (strcmp(op, "-")==0){
        return 2;    
    }
    if (strcmp(op, "&")==0){
        return 3;    
    }
    if (strcmp(op, "%%")==0){
        return 4;    
    }
    if (strcmp(op, "*")==0){
        return 5;    
    }
    if (strcmp(op, "|")==0){
        return 6;    
    }
    if (strcmp(op, "^")==0){
        return 7;
    }
    return 0;
}


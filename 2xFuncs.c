#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int binaryToDecimal(char* binaryNumber) {
    int decimalNumber = 0;
    int length = strlen(binaryNumber);
    int isNegative = 0;
    
 
    if (binaryNumber[0] == '-') {
        isNegative = 1;
    }

    for (int i = length - 1; i >= isNegative; i--) {
        if (binaryNumber[i] == '1') {
            decimalNumber += pow(2, length - 1 - i);
        }
    }


    if (isNegative) {
        decimalNumber = -decimalNumber;
    }

    return decimalNumber;
}

char* decimalToBinary(int num) {
    char binaryString[33]; 
    int i = 0;
    int isNegative = 0;

    if (num < 0) {
        isNegative = 1;
        num = -num; 
    }

    if (num == 0) {
        binaryString[i++] = '0';
    } else {
        while (num > 0) {
            binaryString[i++] = (num % 2) + '0';
            num = num / 2; 
        }
    }
    binaryString[i] = '\0'; 

 
    int start = 0;
    int end = i - 1;

    while (start < end) {
        char temp = binaryString[start];
        binaryString[start] = binaryString[end];
        binaryString[end] = temp;
        start++;
        end--;
    }

    if (isNegative) {
       
        char* result = malloc(i + 2);
        result[0] = '-';
        for (int j = 0; j < i; j++) {
            result[j + 1] = binaryString[j];
        }
        result[i + 1] = '\0'; 
        return result;
    } else {
        
        char* result = malloc(i + 1);
        for (int j = 0; j < i; j++) {
            result[j] = binaryString[j];
        }
        result[i] = '\0'; 
        return result;
    }}





int determineNumberSystem(char* number) {
    if (strncmp(number, "0x", 2) == 0) {
        return 16;
    } else if (number[0] == '0' ) {
        return 8;
    } else if (strncmp(number, "-0x", 3) == 0){
        return 16;
    } else if (number[0] == '-' && number[1] == '0'){

        return 8;
    } else{

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
        return 0; 
    }
}


char* removeFirstChar(const char* input) {
    if (input == NULL || input[0] == '\0') {
        return NULL;
    }

    char* result = (char*)malloc(strlen(input)); 
    strcpy(result, input + 1);  
    
    return result;
}
int isBinaryNumber(const char* input) {
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] != '0' && input[i] != '1') {
            return 0;  
        }
    }
    return 1; 
}



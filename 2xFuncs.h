#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#ifndef _F2_
#define _F2_



int determineNumberSystem(char* number);

int determineOperation(char* op);

int binaryToDecimal(char* binary);

char* decimalToBinary(int num);

char* removeFirstChar(const char* input);

int isBinaryNumber(const char* input);

#endif
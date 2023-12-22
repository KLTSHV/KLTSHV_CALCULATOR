#include <stdio.h>
#include <string.h>
#include <math.h>

#ifndef _F8_
#define _F8_

int octalToDecimal(char octalNumber[]);

char* decimalToOctal(int num);

int isOctalNumber(const char* input);

#endif
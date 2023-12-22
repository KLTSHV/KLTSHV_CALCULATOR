#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef _F16_
#define _F16_

int hexToDecimal(char* hexstr);

char* decimalToHex(int num); 

char* negativeDecimalToHex(int num);

int isHexadecimalNumber(const char* input);

#endif 
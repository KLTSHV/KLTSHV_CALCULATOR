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

    // Проверяем, является ли число отрицательным
    if (octalNumber[0] == '-') {
        isNegative = 1;
        startIndex = 1;
    }

    // Преобразуем в десятичное число
    for (int i = startIndex; i < length; i++) {
        decimalNumber += (octalNumber[i] - '0') * pow(8, length - 1 - i);
    }

    // Учитываем знак числа
    if (isNegative) {
        decimalNumber = -decimalNumber;
    }

    return decimalNumber;
}


char* decimalToOctal(int num) {
    char octalString[20]; // Выделяем память под строку
    int isNegative = 0;

    if (num < 0) {
        isNegative = 1;
        num = -num; // Преобразуем отрицательное число в положительное для удобства
    }

    sprintf(octalString, "%s%o", (isNegative ? "-0" : "0"), num); // Форматируем число в восьмеричную систему

    char* result = (char*)malloc((sizeof(octalString) + 1) * sizeof(char)); // Выделяем память для строки octalString + '\0'
    sprintf(result, "%s", octalString); // Копируем значение из octalString в result
    return result;
}


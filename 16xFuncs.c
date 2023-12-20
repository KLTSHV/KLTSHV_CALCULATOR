#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int hexToDecimal(char *hexNumber) {
    int decimalNumber = 0;
    int length = strlen(hexNumber);

    int isNegative = 0;
    int startIndex = 0;

    // Проверяем, является ли число отрицательным
    if (hexNumber[0] == '-') {
        isNegative = 1;
        startIndex = 1;
    }

    // Преобразуем в десятичное число
    for (int i = startIndex + 2; i < length; i++) {
        int digitValue;
        if (hexNumber[i] >= '0' && hexNumber[i] <= '9') {
            digitValue = hexNumber[i] - '0';
        } else if (hexNumber[i] >= 'A' && hexNumber[i] <= 'F') {
            digitValue = hexNumber[i] - 'A' + 10;
        } else if (hexNumber[i] >= 'a' && hexNumber[i] <= 'f') {
            digitValue = hexNumber[i] - 'a' + 10;
        } else {
            printf("Некорректный символ в шестнадцатеричном числе: %c\n", hexNumber[i]);
            return 0;  // Возврат, если обнаружен некорректный символ
        }
        decimalNumber += digitValue * pow(16, length - 1 - i);
    }

    // Учитываем знак числа
    if (isNegative) {
        decimalNumber = -decimalNumber;
    }

    return decimalNumber;
}


// Функция для перевода положительного десятичного числа в шестнадцатиричную систему
char* decimalToHex(int num) {
    char* hexString = (char*)malloc(20 * sizeof(char)); // Выделяем память под строку
    sprintf(hexString, "0x%X", num); // Используем функцию sprintf для форматированной записи числа в шестнадцатиричной системе
    return hexString;
}

// Функция для перевода отрицательного десятичного числа в шестнадцатиричную систему
char* negativeDecimalToHex(int num) {
    char* hexString = (char*)malloc(20 * sizeof(char)); // Выделяем память под строку
    sprintf(hexString, "-0x%X", abs(num)); // Используем функцию sprintf для форматированной записи числа в шестнадцатиричной системе с учетом знака
    return hexString;
}


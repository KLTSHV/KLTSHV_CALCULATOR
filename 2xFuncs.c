#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int binaryToDecimal(char* binaryNumber) {
    int decimalNumber = 0;
    int length = strlen(binaryNumber);
    int isNegative = 0;
    
    // Определение, является ли число отрицательным
    if (binaryNumber[0] == '-') {
        isNegative = 1;
    }

    for (int i = length - 1; i >= isNegative; i--) {
        if (binaryNumber[i] == '1') {
            decimalNumber += pow(2, length - 1 - i);
        }
    }

    // Обработка отрицательных чисел
    if (isNegative) {
        decimalNumber = -decimalNumber;
    }

    return decimalNumber;
}

char* decimalToBinary(int num) {
    char binaryString[33]; // Выделяем память под строку (32 символа для двоичного представления и 1 символ для завершающего нуля)

    int i = 0;
    int isNegative = 0;

    if (num < 0) {
        isNegative = 1;
        num = -num; // Преобразуем отрицательное число в положительное
    }

    if (num == 0) {
        binaryString[i++] = '0';
    } else {
        while (num > 0) {
            binaryString[i++] = (num % 2) + '0'; // Преобразуем остаток от деления в символ и добавляем его к строке
            num = num / 2; // Делаем целочисленное деление
        }
    }
    binaryString[i] = '\0'; // Добавляем завершающий нуль

    // Реверсируем строку, чтобы получить правильный порядок битов
    int start = 0;
    int end = i - 1;

    // for(int pl = 0; pl < strlen(num); pl++){

    //     if (strcmp(num[pl], '1') != 0 && strcmp(num[pl], '0') != 0){

    //     }
    // }
    while (start < end) {
        char temp = binaryString[start];
        binaryString[start] = binaryString[end];
        binaryString[end] = temp;
        start++;
        end--;
    }

    if (isNegative) {
        // Выделяем память под строку с учетом знака минуса и завершающего нуля
        char* result = malloc(i + 2);
        result[0] = '-';
        for (int j = 0; j < i; j++) {
            result[j + 1] = binaryString[j];
        }
        result[i + 1] = '\0'; // Добавляем завершающий нуль
        return result;
    } else {
        // Если число положительное, выделяем память под строку и копируем в нее двоичное представление
        char* result = malloc(i + 1);
        for (int j = 0; j < i; j++) {
            result[j] = binaryString[j];
        }
        result[i] = '\0'; // Добавляем завершающий нуль
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
        return 0; // возврат значения по умолчанию, если операция не распознана
    }
}


char* removeFirstChar(const char* input) {
    if (input == NULL || input[0] == '\0') {
        return NULL;
    }

    char* result = (char*)malloc(strlen(input));  // Выделяем память для новой строки
    strcpy(result, input + 1);  // Копируем исходную строку без первого символа
    
    return result;
}



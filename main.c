#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "2xFuncs.h"
#include "8xFuncs.h"
#include "16xFuncs.h"


int main() {

    char input[1000];

    fgets(input, 1000, stdin);

    char *variables[100]; 

    char *token = strtok(input, " "); 
    
    int i = 0;

    char operation[10];

    while (token != NULL) {

        if(isdigit(token[0]) == 0){

            strcpy(operation, token);
        }

        variables[i++] = token; 

        token = strtok(NULL, " "); 

    }

    

    if(i >= 4 || i == 2){

        printf("Unknown operation\n");

        return -1;

    }

    if(i == 1){

        if(variables[0][0] == 126 && variables[0][1] != 45){
            
            
            
        }


    }

    if(i == 3){

        int var1 = determineNumberSystem(variables[0]);

        int var2 = determineNumberSystem(variables[2]);

        int op = determineOperation(variables[1]);

        if(var1 != var2){

            printf("Different systems");

            return -1;

        }else{

            variables[2][strlen(variables[2])-1] = '\0';

            int var1InDec;

            int var2InDec;

            if(var1 == 2){
                
                var1InDec = binaryToDecimal(variables[0]);

                var2InDec = binaryToDecimal(variables[2]);

                
            }else if(var1 == 8){

                var1InDec = octalToDecimal(variables[0]);

                var2InDec = octalToDecimal(variables[2]);

            }else if(var1 == 16){

                var1InDec = hexToDecimal(variables[0]);

                var2InDec = hexToDecimal(variables[2]);


            }

            if( (op == 4 || op == 5 || op == 6 || op == 7) && (var1InDec < 0 || var2InDec < 0)){
                
                printf("Numbers must be greater than zero!");

                return -1;

            }

            int result;

            if(op == 1){
                
                result = var1InDec + var2InDec;

            }else if(op == 2){

                result = var1InDec - var2InDec;

            }else if(op == 3){

                result = var1InDec * var2InDec;

            }else if(op == 4){

                result = var1InDec % var2InDec;

            }else if(op == 5){

                result = var1InDec & var2InDec;

            }else if(op == 6){

                result = var1InDec | var2InDec;
            }else if(op == 7){

                result = var1InDec ^ var2InDec;
            }
            if (var1 == 2){
                
                printf("%s", decimalToBinary(result));

            }  
            if (var1 == 8){

                printf("%s, %d", decimalToOctal(result), result);
            }  
            if (var2 == 16){
                if(result >= 0){
                printf("%s, %d", decimalToHex(result), result);

                }
                else if(result < 0){

                    printf("%s", negativeDecimalToHex(result));
                }
            }
        }

        
    }
}


    

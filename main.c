#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "2xFuncs.h"
#include "8xFuncs.h"
#include "16xFuncs.h"


int main() {

    char input[100];

    fgets(input, 100, stdin);

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
            
            //special func for TILDE

        }


    }

    if(i == 3){

        int var1 = determineNumberSystem(variables[0]);

        int var2 = determineNumberSystem(variables[2]);

        int op = determineOperation(operation);

        if(var1 != var2){

            printf("Different systems");

            return -1;

        }else{

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
            printf("%d", result);
        }

        
    }
}


    

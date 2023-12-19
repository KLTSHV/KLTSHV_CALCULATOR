#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "2xFuncs.h"


int main() {

    char input[100];

    fgets(input, 100, stdin);

    char *variables[100]; 

    char *token = strtok(input, " "); 
    
    int i = 0;

    char operation[5];

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

         

        printf("%d, %s, %d", var1, variables[1][0], var2);

        
    }
}


    

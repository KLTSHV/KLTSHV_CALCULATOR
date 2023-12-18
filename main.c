#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main() {

    char input[100];

    fgets(input, 100, stdin);

    char *variables[100]; 

    char *token = strtok(input, " "); 
    
    int i = 0;

    while (token != NULL) {

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

        
    }
}


    

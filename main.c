#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



#include <stdio.h>
#include <string.h>

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

    if(i >= 4 or i == 2){

        printf("Unknown operation\n");

        return -1;

    }

    if(i == 1){

        printf("%s\n", variables[0]);
        
    }
}


    

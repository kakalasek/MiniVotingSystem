#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUT_BUFFER 200

int main();

void stringLengthValidation(int maxLength, char *string);
int stringExistenceValidation(char *filePath, char *string);

int main(){

    stringExistenceValidation("Resources/People", "string");

    // char validationNumber[30];
    // char candidateNumber[10];

    // printf("Enter your validation number:\n");
    // fgets(validationNumber, sizeof(validationNumber), stdin);

    // if(validationNumber[strlen(validationNumber)] == '\n'){
    //     getchar();
    // }
    // stringLengthValidation(14, validationNumber);

    // printf("\nEnter the number of your candidate:\n");
    // fgets(candidateNumber, sizeof(candidateNumber), stdin);

    // if(candidateNumber[strlen(candidateNumber)] == '\n'){
    //     getchar();
    // }
    // stringLengthValidation(3, candidateNumber);

    exit(EXIT_SUCCESS);
}

void stringLengthValidation(int maxLength, char *string){
    if(strlen(string) > maxLength){
        fprintf(stderr, "Input too long...\n");
        exit(EXIT_FAILURE);
    }
}

int stringExistenceValidation(char *filePath, char *string){
    FILE *file;
    file = fopen(filePath, "r");
    if(file == NULL){
        fprintf(stderr, "File not found...\n");
        exit(EXIT_FAILURE);
    }
    
    char *token;
    char *data[3];
    int i;
    char buffer[INPUT_BUFFER];

    while(fgets(buffer, INPUT_BUFFER, file)){
        i = 0;
        token = strtok(buffer, ",");
        
        while(token != NULL){
            data[i] = token;
            printf("%s\n", token);
            token = strtok(NULL, ",");
            i++;
        }
    }
}
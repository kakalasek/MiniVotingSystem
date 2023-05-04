#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUT_BUFFER 200

int main();

void stringLengthValidation(int maxLength, char *string);
int stringExistenceValidation(char *filePath, char *string, int charToCompare);

int main(){

    char validationNumber[INPUT_BUFFER];
    char candidateNumber[INPUT_BUFFER];

    printf("Enter your validation number:\n");
    fgets(validationNumber, sizeof(validationNumber), stdin);

    if(validationNumber[strlen(validationNumber)] == '\n'){
        getchar();
    }
    stringLengthValidation(14, validationNumber);

    if(stringExistenceValidation("Resources/People", validationNumber, 13) != 0){
        fprintf(stderr, "ID not found...\n");
        exit(EXIT_FAILURE);
    }

    printf("\nEnter the number of your candidate:\n");
    fgets(candidateNumber, sizeof(candidateNumber), stdin);

    if(candidateNumber[strlen(candidateNumber)] == '\n'){
        getchar();
    }
    stringLengthValidation(5, candidateNumber);

    if(stringExistenceValidation("Resources/Candidates", candidateNumber, 4) != 0){
        fprintf(stderr, "Candidate not found...\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}

void stringLengthValidation(int maxLength, char *string){
    if(strlen(string) > maxLength){
        fprintf(stderr, "Input too long...\n");
        exit(EXIT_FAILURE);
    }
}

int stringExistenceValidation(char *filePath, char *string, int charToCompare){
    FILE *file;
    file = fopen(filePath, "r");
    if(file == NULL){
        fprintf(stderr, "File not found...\n");
        exit(EXIT_FAILURE);
    }
    
    char *token;
    char *data[4];
    int i;
    char buffer[INPUT_BUFFER];

    while(fgets(buffer, INPUT_BUFFER, file)){
        i = 0;
        token = strtok(buffer, ",");
        
        while(token != NULL){
            data[i] = token;
            token = strtok(NULL, ",");
            i++;
        }
        if(strncmp(data[2], string, charToCompare) == 0){
            return 0;
        }
    }

    return 1;
}
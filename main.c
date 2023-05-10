#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUT_BUFFER 200

int main();

void stringLengthValidation(int maxLength, char *string);
int stringExistenceValidation(char *filePath, char *string, int charToCompare);
void vote(char *validationNumber, char *candidateNumber);

int main(){

    char validationNumber[INPUT_BUFFER];
    char candidateNumber[INPUT_BUFFER];

    vote("14051985/8934", "32");

    // printf("Enter your validation number:\n");
    // fgets(validationNumber, sizeof(validationNumber), stdin);

    // if(validationNumber[strlen(validationNumber)] == '\n'){
    //     getchar();
    // }
    // stringLengthValidation(14, validationNumber);

    // if(stringExistenceValidation("Resources/People", validationNumber, 13) != 0){
    //     fprintf(stderr, "ID not found...\n");
    //     exit(EXIT_FAILURE);
    // }

    // printf("\nEnter the number of your candidate:\n");
    // fgets(candidateNumber, sizeof(candidateNumber), stdin);

    // if(candidateNumber[strlen(candidateNumber)] == '\n'){
    //     getchar();
    // }
    // stringLengthValidation(5, candidateNumber);

    // if(stringExistenceValidation("Resources/Candidates", candidateNumber, 4) != 0){
    //     fprintf(stderr, "Candidate not found...\n");
    //     exit(EXIT_FAILURE);
    // }

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
            fclose(file);
            return 0;
        }
    }

    fclose(file);
    return 1;
}

void vote(char *validationNumber, char *candidateNumber){
    FILE *people;
    FILE *candidates;
    FILE *foo;

    people = fopen("Resources/People", "r");
    foo = fopen("Resources/foo", "w");

    char *data[INPUT_BUFFER];
    char buffer[INPUT_BUFFER];
    int lineTracker = 0;
    int dataTracker;
    char *token;
    char *tempData[4];

    while(fgets(buffer, INPUT_BUFFER, people)){
        dataTracker = 0;
        data[lineTracker] = buffer;

        token = strtok(data[lineTracker], ",");
        while(token != NULL){
            tempData[dataTracker] = token;
            token = strtok(NULL, ",");
            dataTracker++;
        }
        if(strncmp(tempData[2], validationNumber, 13) == 0){
            strcpy(tempData[3], "1\n");
        }
            
        fprintf(foo, "%s,%s,%s,%s", tempData[0], tempData[1], tempData[2], tempData[3]);
        lineTracker++;
    }
    fclose(foo);
    fclose(people);

    fopen(foo, "r");
    fopen(people, "w");
    
}
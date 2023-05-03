#include <stdio.h>
#include <string.h>

void stringValidation(int maxLength, char *string);

int main(){
    char validationNumber[30];
    char candidateNumber[10];

    printf("Enter your validation number:\n");
    fgets(validationNumber, sizeof(validationNumber), stdin);
    if(validationNumber[strlen(validationNumber)] == '\n'){
        getchar();
    }
    stringValidation(14, validationNumber);
    printf("\nEnter the number of your candidate:\n");
    fgets(candidateNumber, sizeof(candidateNumber), stdin);
    if(candidateNumber[strlen(candidateNumber)] == '\n'){
        getchar();
    }
    stringValidation(3, candidateNumber);

    return 0;
}

void stringValidation(int maxLength, char *string){
    if(strlen(string) > maxLength){
        printf("Your input is invalid!\n");
        exit(1);
    }
}
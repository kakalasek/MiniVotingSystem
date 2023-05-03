#include <stdio.h>
#include <string.h>

int main(){
    char validationNumber[14];
    char candidateNumber[3];

    printf("Enter your validation number:\n");
    scanf("%13s", validationNumber);
    printf("\nEnter the number of your candidate:\n");
    scanf("%2s", candidateNumber);

    return 0;
}
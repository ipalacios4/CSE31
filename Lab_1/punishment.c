#include <stdio.h>
#include <stdlib.h>
int main(){
    char str[] = "C programming language is the best!";
    int iteration;
    int counter;
    int typo;

    printf("Enter the number of lines for the punishment: ");
    scanf("%d", &iteration);

     if (iteration <= 0){
        printf("You entered an incorrect value for the number of lines!");
        exit(0);
    }

    printf("Enter the line for which we want to make a typo: ");
    scanf("%d", &typo);

    if (typo < 0 || typo > iteration){
        printf("You entered an incorrect value for the number of lines!");
        exit(0);
    }

    for(counter = 1; counter < iteration; counter++){
        if(counter == typo){
            printf("C programming language is the bet!");
        }
        printf("C programming language is the best!");
    }

    return 0;
}
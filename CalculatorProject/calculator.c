#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 1000

void askN(int *count, float arr[MAX]){

    char line[50];
    *count = 0;  

    printf("Insert numbers (enter '#' to stop insert): ");
    while (fgets(line, 50, stdin))
    {
        if (line[0] == '#')
        {
            break;
        }

        if (sscanf(line, "%f", &arr[*count]) == 1)
        {
            // increment the counter each time a valid number is entered
            (*count)++;
        }
        else
        {
            printf("Please enter a valid number. ");
        }         
    }      
}

float add(int *count, float arr[MAX]){  

    float sum = 0;
    for (int i = 0; i < *count; i++)
    {
        sum += arr[i];
    }
      
    return sum;
}

float sub(int *count, float arr[MAX]){
    float subt = arr[0];
    for (int i = 1; i < *count; i++){
        subt -= arr[i];
    }
    return subt;
}

float mult(int *count, float arr[MAX]){

    float mul = arr[0];  // initialize with the first element of array
    for (int i = 1; i < *count; i++)  
    {
        mul *= arr[i];
    }
    return mul;
}

float division(int *count, float arr[MAX]){
    float divi = arr[0];
    for (int i = 1; i < *count; i++){
        if(arr[i] != 0.0) // Add a condition to prevent division by zero
            divi /= arr[i];
        else {
            printf("Error: Division by zero is not allowed!\n");
            return 0;
        }
    }
    return divi;
}

int main(){

    int opcao = -1, numIn;//opcao and  amount of numbers the user want to countert;
    int *count = &numIn;
    float arr[MAX];
    float sum = 0;
    float accumulator = 0.0f; // this will hold our result between operations
    int hasAccumulator = 0;  // this will track if we have a result to use

    printf("----Calculator----\n");
    
    while (opcao != 0)
    {
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n");
        printf("4. Division\n5. Reset data\n0. Exit\n");
        printf("Choose one option: ");
        scanf("%d", &opcao);
        while((getchar()) != '\n'); //clear buffer
        switch (opcao) {
            case 1:  // addition
                askN(count, arr);
                if (hasAccumulator) {
                    // if we have a result from a previous operation, add the new total to it
                    accumulator += add(count, arr);
                } else {
                    // if we don't have a result from a previous operation, just use the new total
                    accumulator = add(count, arr);
                    hasAccumulator = 1;
                }
                printf("Total sum: %.2f\n", accumulator);
                break;

            case 2:  // subtraction
                askN(count, arr);
                if (hasAccumulator) {
                    accumulator -= sub(count, arr);
                } else {
                    accumulator = sub(count, arr);
                    hasAccumulator = 1;
                }
                printf("Total Sub: %.2f\n", accumulator);
                break;

            case 3:  // multiplication
                askN(count, arr);
                if (hasAccumulator) {
                    accumulator *= mult(count, arr);
                } else {
                    accumulator = mult(count, arr);
                    hasAccumulator = 1;
                }
                printf("Total Multiplication: %.2f\n", accumulator);
                break;

            case 4:  // division
                askN(count, arr);
                if (hasAccumulator && accumulator != 0.0f) {
                    accumulator /= division(count, arr);
                } else {
                    float divi = division(count, arr);
                    if (divi != 0.0f) {
                        accumulator = divi;
                        hasAccumulator = 1;
                    } else {
                        printf("Error: Division by zero is not allowed!\n");
                        accumulator = 0.0f;
                        hasAccumulator = 0;
                    }
                }
                printf("Total Division: %.2f\n", accumulator);
                break;

            case 5:  // clear accumulator
                accumulator = 0.0f;
                hasAccumulator = 0;
                printf("Accumulator cleared.\n");
                break;

            case 0:  // exit
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}











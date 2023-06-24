#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 1000

void askN(int *count, float arr[MAX]){

    char line[50];
    *count = 0;  

    printf("countert numbers (enter '#' to stop): ");
    while (fgets(line, 50, stdin) && line[0] != '#')
    {

        if (sscanf(line, "%f", &arr[*count]) == 1)
        {
            // increment the counter each time a valid number is entered
            (*count)++;
        }
        else
        {
            printf("Invalid input, try again: ");
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

    printf("----Calculator----\n");
    
    while (opcao != 0)
    {
        printf("1. Addition\n2. Subtraction\n");
        printf("3. Multiplication\n4. Division\n0. Exit\n");
        printf("Choose one option: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            askN(count, arr);
            sum = add(count, arr);
            printf("Total sum: %.2f\n", sum);            
            break;
        case 2:  
            askN(count, arr);
            float subt = sub(count, arr);
            printf("Total Sub: %.2f\n", subt);            
            break;
        case 3:
            askN(count, arr);
            float mul = mult(count, arr);
            printf("Total Multiplication: %.2f\n", mul);            
            break;
        case 4:
            askN(count, arr);
            float divi = division(count, arr);
            printf("Total Division: %.2f\n", divi);  
            break;          
        case 0:
            break;
        }
    }
    free(arr);
}





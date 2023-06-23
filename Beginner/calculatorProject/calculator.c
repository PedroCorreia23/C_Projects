#include <stdio.h>
#include <stdlib.h>

void numberInsert(int *ins){
    printf("How many numbers do want to insert? ");
    scanf("%d", ins);
}
void askN(int *ins, float *arr){


    printf("Insert numbers: ");
    for (int i = 0; i < *ins; i++)
    {
        scanf("%f", &arr[i]);
    }    
}

float add(int *ins, float *arr){

    float sum = 0;
    for (int i = 0; i < *ins; i++)
    {
        sum += arr[i];
    }
      
    return sum;
}

float sub(int *ins, float *arr){
    float subt = arr[0];
    for (int i = 1; i < *ins; i++){
        subt -= arr[i];
    }
    return subt;
}

float mult(int *ins, float *arr){

    float mul = arr[0];  // initialize with the first element of array
    for (int i = 1; i < *ins; i++)  
    {
        mul *= arr[i];
    }
    return mul;
}

float division(int *ins, float *arr){
    float divi = arr[0];
    for (int i = 1; i < *ins; i++){
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

    int opcao = -1, numIn;//opcao and  amount of numbers the user want to insert;
    int *ins = &numIn; 
    float *arr;
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
            numberInsert(ins);
            arr = (float*) malloc(*ins * sizeof(float));  // Allocate memory for array
            askN(ins, arr);
            sum = add(ins, arr);
            printf("Total sum: %.2f\n", sum);
            free(arr);            
            break;
        case 2:
            numberInsert(ins);
            arr = (float*) malloc(*ins * sizeof(float));  
            askN(ins, arr);
            float subt = sub(ins, arr);
            printf("Total Sub: %.2f\n", subt);
            free(arr);            
            break;
        case 3:
            numberInsert(ins);
            arr = (float*) malloc(*ins * sizeof(float));  
            askN(ins, arr);
            float mul = mult(ins, arr);
            printf("Total Multiplication: %.2f\n", mul);
            free(arr);            
            break;
        case 4:
            numberInsert(ins);
            arr = (float*) malloc(*ins * sizeof(float));  
            askN(ins, arr);
            float divi = division(ins, arr);
            printf("Total Division: %.2f\n", divi);
            free(arr);  
            break;          
        case 0:
            break;
        }
    }

}





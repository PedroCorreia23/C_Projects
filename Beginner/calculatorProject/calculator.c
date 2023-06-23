#include <stdio.h>

int numberInsert(int *ins){
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

int main(){

    int opcao = -1, numIn;//opcao and  amount of numbers the user want to insert;
    int *ins = &numIn; 
    float arr[*ins];
    float sum = 0;

    printf("----Calculator----\n");
    
    while (opcao != 0)
    {
        printf("1. Addition\n2. Subtraction\n");
        printf("3. Multiplication\n4. Division\n");
        printf("Choose one option: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            numberInsert(ins);
            askN(ins, arr);
            sum = add(ins, arr);
            printf("Total sum: %.2f\n", sum);
            break;
        
        case 0:
            break;
        }
    }


    printf("quantidade: %d", *ins);
}





#include <stdio.h>

void numberInsert(int *ins){
    printf("How many numbers do you want to insert? ");
    scanf("%d", ins);
}

void askN(float *num1, float *num2){
    printf("Insert N");
}

float add(){
    // You need to add code here
    return 0.0f; // Placeholder
}

int main(){

    int opcao = -1, numIn; // Initialize opcao to prevent undefined behavior
    int *ins = &numIn; 
    float n1, n2;
    float *num1 = &n1, *num2 = &n2;

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
            add();
            break;
        
        case 0:
            break;
        }
    }

    printf("Quantity: %d\n", *ins); // Use *ins to dereference the pointer

    return 0;
}

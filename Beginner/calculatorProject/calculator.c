#include <stdio.h>

int numberInsert(int *ins){
    printf("How many numbers do want to insert? ");
    scanf("%d", ins);
}
void askN(float *num1, float *num2){

    printf("Insert N");
}
float add(){
    int a;
    int B;
    int C;
}

int main(){

    int opcao = -1, numIn;//opcao and  amount of numbers the user want to insert;
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

    printf("quantidade: %d", *ins);

    
}
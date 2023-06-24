#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CATEGORIES 6

void randWord(){

    char *word;
    srand(time(NULL));
    word = animals[rand() % 3];
    printf("%s", word);
}

void waitForEnter() {
    char ch = getchar();
    if(ch != '\n') {
        while(getchar() != '\n');
        waitForEnter();
    }
}

int main() {

    char *animals[] = {"dog", "cat", "penguin"};
    char *countries[] = {"USA", "France", "Brazil"};
    char *car_brands[] = {"Tesla", "BMW", "Toyota"};
    char *colors[] = {"Red", "Green", "Blue"};
    char *names[] = {"Alice", "Bob", "Charlie"};

    char **all_categories[NUM_CATEGORIES] = {animals, countries, car_brands, colors, names, NULL};

    char word;
    int cat;
    printf("Press Enter to start...\n");
    waitForEnter();

    printf("Categories:\n ");
    printf("1. Animals\n2. Countries\n3. Car Brands\n4. Colors\n5. Names\n6. Mix Of All\n");
    printf("Choose one: ");
    scanf("%d", &cat);
    getchar();  // Consume the '\n' character left by scanf
    switch (cat)
    {
    case 1:
        /* code */
        break;
    
    default:
        break;
    }

    printf("Game started!\n\n");

    printf("Choosing word....");
    randWord();

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CATEGORIES 6
#define NUM_WORDS_IN_CATEGORY 3

char* randWord(char *words[]) {
    srand(time(NULL));
    return words[rand() % NUM_WORDS_IN_CATEGORY];
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

    printf("Press Enter to start...\n");
    waitForEnter();

    printf("Categories:\n ");
    printf("1. Animals\n2. Countries\n3. Car Brands\n4. Colors\n5. Names\n6. Random\n");
    printf("Choose one: ");
    int cat;
    scanf("%d", &cat);
    getchar();  // Consume the '\n' character left by scanf

    if (cat >= 1 && cat <= NUM_CATEGORIES) {
        printf("Game started!\n\n");
        printf("Choosing word....\n");
        char* chosenWord;
        if (cat == NUM_CATEGORIES) {
            // Random category
            chosenWord = randWord(all_categories[rand() % (NUM_CATEGORIES - 1)]);
        } else {
            chosenWord = randWord(all_categories[cat - 1]);
        }
        printf("%s\n", chosenWord);  // Print the chosen word
    } else {
        printf("Invalid category number. Please run the program again.\n");
    }

    return 0;
}

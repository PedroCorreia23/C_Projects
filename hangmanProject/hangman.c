#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define NUM_CATEGORIES 6
#define NUM_WORDS_IN_CATEGORY 3

const char *hangman[] = {
" ________\n |      |\n |      O\n |     /|\\\n |     / \\\n |\n |\n_|_\n", // Stage 6: gallows + head + body + both arms + both legs
" ________\n |      |\n |      O\n |     /|\\\n |     /\n |\n |\n_|_\n", // Stage 5: gallows + head + body + both arms + one leg
" ________\n |      |\n |      O\n |     /|\\\n |\n |\n |\n_|_\n", // Stage 4: gallows + head + body + both arms
" ________\n |      |\n |      O\n |     /|\n |\n |\n |\n_|_\n", // Stage 3: gallows + head + body + one arm
" ________\n |      |\n |      O\n |      |\n |\n |\n |\n_|_\n", // Stage 2: gallows + head + body
" ________\n |      |\n |      O\n |\n |\n |\n |\n_|_\n", // Stage 1: gallows + head
" ________\n |      |\n |\n |\n |\n |\n |\n_|_\n" // Stage 0: just the gallows
};

void toLowerCase(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void printHangman(int incorrectGuesses) {
    if (incorrectGuesses < 0 || incorrectGuesses >= sizeof(hangman) / sizeof(hangman[0])) {
        printf("Hangman image not found.\n");
    } else {
        printf("%s", hangman[incorrectGuesses]);
    }
}

void updateWord(char *chosenWordLower, char *chosenWord, char *revealedWord, char guess) {
    char *p = strchr(chosenWordLower, guess);
    while(p != NULL) {
        int position = p - chosenWordLower;
        revealedWord[position] = chosenWord[position];
        p = strchr(p + 1, guess);
    }

    printf("Current word: %s\n\n", revealedWord);
}

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

void game() {
    char *animals[] = {"dog", "cat", "penguin"};
    char *countries[] = {"USA", "France", "Brazil"};
    char *car_brands[] = {"Tesla", "BMW", "Toyota"};
    char *colors[] = {"Red", "Green", "Blue"};
    char *names[] = {"Alice", "Bob", "Charlie"};

    char **all_categories[NUM_CATEGORIES] = {animals, countries, car_brands, colors, names, NULL};

    int cat, want, lives = 6; //is as carater IS in that word
    char word[20], c, *is;
    char *chosenWord = NULL;
    char wrongletters[100];
    int l = 0;
    char chosenWordLower[20];


    printf("Press Enter to start...\n");
    waitForEnter();
    
    while(1) {
        printf("Categories:\n");
        printf("1. Animals\n2. Countries\n3. Car Brands\n4. Colors\n5. Names\n6. Random\n");
        printf("Choose one: ");
        int result = scanf("%d", &cat);
        while(getchar() != '\n');  // Consume the '\n' character left by scanf and clear the buffer

        if(result != 1) {
            printf("Invalid input. Please enter a number.\n\n");
            continue;
        }
        if (cat >= 1 && cat <= NUM_CATEGORIES) {
            printf("\nGame started!\n\n");
            printf("Choosing word....\n");
            if (cat == NUM_CATEGORIES) {
                // Random category
                chosenWord = randWord(all_categories[rand() % (NUM_CATEGORIES - 1)]);
            } else {
                chosenWord = randWord(all_categories[cat - 1]);
            }
            printf("Word choosen: %s\n", chosenWord);  // Print the chosen word
            strcpy(chosenWordLower, chosenWord);  
            toLowerCase(chosenWordLower);
            break;
        } else {
            printf("Invalid category number. Please enter a number between 1 and 6.\n\n");
        }
    }

    char revealedWord[20];
    for(int i = 0; i < strlen(chosenWord); i++) {
        revealedWord[i] = '_';
    }
    revealedWord[strlen(chosenWord)] = '\0';

    printf("Word choosen: %s\n\n", revealedWord);  // Print the chosen word (hidden)

    while (lives > 0)
    {
        printf("What do you want to do?\n");
        printf("1. Guess a letter\n2. Guess the word\n");
        printf("Insert Option: ");
        scanf("%d", &want);
        getchar();  // Consume the '\n' character left by scanf
        switch (want)
        {
        case 1:
            printf("Insert caracter: ");
            scanf("%c", &c);
            printf("\n");
            getchar();  // Consume the '\n' character left by scanf
            c = tolower(c);  // Convert the input character to lower case
            is = strchr(chosenWordLower, c);
            updateWord(chosenWordLower, chosenWord, revealedWord, c);
            // Check if the revealed word matches the chosen word
            char revealedWordLower[20];  // Copy of revealed word to be converted to lower case
            strcpy(revealedWordLower, revealedWord);  // Copy the revealed word
            toLowerCase(revealedWordLower);  // Convert revealed word to lower case for comparison
            if (strcmp(chosenWordLower, revealedWordLower) == 0) {
                printf("Congratulations! You guessed all the letters. You win!\n");
                return;
            }
            if (is != NULL)
            {
                printf("The letter %c is present in the word.\n\n", c);
            }else{
                wrongletters[l] = c;
                l++;
                printf("The letter %c is NOT present in the word.\n", c);
                lives--;
                printHangman(lives);
                printf("Wrong letters: ");
                for (int i = 0; i < l; i++)
                {
                    printf("%c ", wrongletters[i]);
                }
                printf("\n");
            }
            break;
        case 2:
            printf("Insert word: ");
            fgets(word, 20, stdin);
            word[strcspn(word, "\n")] = 0;  // Remove the newline character
            toLowerCase(word);
            if (strcmp(chosenWordLower, word) != 0)
            {
                printf("Wrong Word!\n");
                lives--;
                printHangman(lives);
                printf("\n");
            }
            else{
                printf("Congratulations! You Win!\n");
                return;   
            }
            break;
        default:
            printf("Invalid Option.\n");
            break;
        }
    }
    printf("Game over! You have lost all your lives.\n");
}

int main(){

    char playAgain = 'y';
    while(playAgain == 'y' || playAgain == 'Y') {
        game();
        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);
        printf("\n");
    }
    printf("Thanks for playing :)\nBye...");
    return 0;
}





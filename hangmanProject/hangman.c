#include <stdio.h>

void waitForEnter() {
    char ch = getchar();
    if(ch != '\n') {
        while(getchar() != '\n');
        waitForEnter();
    }
}

int main() {

    printf("Press Enter to start the game...\n");
    waitForEnter();
    printf("Game started!\n");



    return 0;
}

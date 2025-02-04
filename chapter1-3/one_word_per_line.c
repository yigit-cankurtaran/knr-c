#include <stdio.h>

int main() {
    int input;

    while ((input = getchar()) != EOF){
        if (input != ' '){
            putchar(input);
        } else{
            putchar('\n');
        }
    }
}

#include <stdio.h>

void exercise18(){
    int input;
    int tabs = 0, spaces = 0, newlines = 0;

    while ((input = getchar()) != EOF){
        if (input == '\t') ++tabs; // '' = char constant "" = string literal
                                   // we need char constants here bc we want 1 char
        else if (input == '\n') ++newlines;
        else if (input == ' ') ++spaces;
    }

    printf("tabs: %d, spaces: %d, newlines: %d\n", tabs, spaces, newlines);
}

int main(){
    exercise18();
    return 1;
}

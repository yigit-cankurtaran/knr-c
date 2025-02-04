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

    // press ctrl+d to reach EOF
    // exercise done
}

void exercise19(){
    int input;
    int last_was_space = 0; // tracking var
                            // 1  = true 0 = false

    while((input = getchar()) != EOF){ // open the input
        if (input == ' '){ // if input is space
            if (!last_was_space){
                putchar(input);
                // only printing the first space in a sequence
                last_was_space = 1;
            } 
        } else {
            putchar(input); 
            // reseting the flag when non-blank char
            last_was_space = 0;
        }
    }
    // exercise working
}

void exercise110(){
    int input;
    
    while ((input = getchar()) != EOF){
        if (input == '\t'){
            putchar('\\'); // putchar can only print 1 char
                           // first we print the backslash
                           // we also escape it with another backslash
            putchar('t'); // then we print the other char
        }
        if (input == '\b'){
            putchar('\\');
            putchar('b');
        }
        if (input == '\\'){ // we also can't check for it directly
                            // so we also need to escape it here
            putchar('\\');
        }
        putchar(input);
    }
    // exercise working
}

int main(){
    exercise110();
    return 1;
}

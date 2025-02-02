#include <stdio.h>
#include <string.h>

char* remove_whitespace(char* c){
    if (c[strlen(c) - 1] == '\n') c[strlen(c) - 1] = '\0'; // remove newline
    int j = 0; // index var
    printf("this is the whitespace remove function\n");
    for (int i = 0; c[i] != '\0'; i++){
        // i is the counter j is the value we'll use
        if (c[i] != ' '){ // if char i currently points at is whitespace
            c[j] = c[i]; // shift it to where j is in
            j++; // move j to the right
        }
    }
    c[j] = '\0'; // terminating the string
    // the j and i is us moving the chars we want to the left
    // after we're done with the loop we need to end it so we only have non-whitespace
    // if we don't terminate they're still in the string just on the right
    return c;
}


int main() {
    int a = 0;
    int is_negative = 0;
    int digit;
    char input[64];
    printf("enter the number you want to convert\n");
    fgets(input, sizeof(input), stdin);
    remove_whitespace(input); // call function directly after creating the string
    if (input[0] == '-') is_negative = 1; // check if number is negative
    int start = is_negative ? 1 : 0; // if the start is a -, start the loop from 1

    for (int i = start; input[i] != '\0'; i++){
        if (input[i] >= '0' && input[i] <= '9'){
            a *= 10; // shifting digits left whenever a new digit comes
            digit = input[i] - '0'; // this is how you turn strings to numbers
            a += digit; // add the new digit to the right
        } else {
            printf("not a number");
            return 1;
        }
    }
    if (is_negative) a = -a;
    printf("the integer val is %d\n", a);
    return 0;
}

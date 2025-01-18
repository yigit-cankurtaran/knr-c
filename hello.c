#include <stdio.h> // include the standard input/output library

// a C program consists of functions and variables
int sub(){ // function
           // expects no arguments, empty parentheses
    return 5;
}

int main(){ // main function
            // the program begins executing at the beginning of main
    printf("hello world!\n"); // another function, this time from stdio.h
    int i = sub(); // variable
                   // i is an int, is the result of sub()
    printf("result of sub is %d\n", i);
    return 0;
}

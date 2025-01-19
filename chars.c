#include <stdio.h>

void chars() { // void = doesn't return anything
    int c, d;
    printf("getting char\n");
    c = getchar(); // gets the first char from whatever we type in
    printf("the char we got is: ");
    d = putchar(c); // prints what getchar gets. e.g. "h" from "hello"
    printf("\nthe ascii value is: %d\n", d);
    // prints the ASCII value of "h" from "hello" (104)
}

void input_copy(){
    int input; // creating an input var here
               // we need it as an int bc EOF = -1
               // and getchar() returns an int
               // if we declared this as a char it couldn't handle EOF

    //input = getchar(); // get the first char
                       // not really necessary in this context
                       // but it's good practice to initialize the loop with the first input

    // we can also initialize in the while statement itself
    // while (input != EOF){ // while we don't hit EOF
                          // e.g. before we hit enter
    while ((input = getchar()) != EOF){
        putchar(input); // print the input
                        // prints when we press enter due to terminal buffering
                        // enter flushes the line buffer and makes the input available
                        // until then the program doesn't know we typed anything
        // input = getchar(); // keep reading the next char until we signal EOF
        // commenting out since we already have it in the loop statement
    }
}

void eof_val(){ // exercise 1-7
    int end;

    end = EOF;

    printf("value of EOF is: %d\n", end);
}

int main(){
    printf("chars function, chapter 1.5 start\n");
    chars();
    eof_val();
    printf("input copy function, chapter 1.5.1\n");
    input_copy();
}

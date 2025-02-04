#include <stdio.h>

#define N 4

/*

Exercise 1-20. Write a program detab that replaces tabs in the input with the
proper number of blanks to space to the next tab stop. Assume a fixed set of
tab stops, say every n columns. Should n be a variable or a symbolic parameter?

*/

int main(){
    int i, c;
    while ((c = getchar()) != EOF){ // open input
        if (c == '\t') { // if c is a tab
            for (int i = 0; i < N; i++){
                putchar(' '); // run loop 4 times, replace tab with space
            }
        } else putchar(c); // otherwise just print the char
    }
    return 0;
}

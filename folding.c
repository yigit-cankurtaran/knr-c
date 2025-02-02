#include <stdio.h>
#define N 50

/*
   Exercise 1-22. Write a program to "fold" long input lines into two or more
   shorter lines after the last non-blank character that occurs before the n-th
   column of input. Make sure your program does something intelligent with very
   long lines, and if there are no blanks or tabs before the specified column. 
*/

// simple solution, might write a better one
// more complicated one is in folding_buffer but i like this one better
int main(){
    int c, len = 0, pos = 0; // i can use pos to write one that only breaks on spaces and tabs

    while((c = getchar()) != EOF){
        if (c != '\n' && c != '\0'){
            len++;
        }
        if (len > N){
            c = '\n';
            len = 0; // resetting len because len needs to update after every wrap
                     // or we get a newline for every char instead of the chars themselves.
            pos = 0; // reset position
        }
        putchar(c);
    }
}

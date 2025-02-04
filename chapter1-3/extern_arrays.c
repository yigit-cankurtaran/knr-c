#include <stdio.h>
#define MAXLINE 1000

// inferior version of char_arrays.c
// less maintainable due to reliance on external scope
// use the previous code whenever possible
// section 1.10 external variables and scope

// these are declarations. we state the nature of the vars but no storage is allocated
int max; // max length
char line[MAXLINE]; // current input
char longest[MAXLINE]; // longest line saved

int getthis(void); // (void) = func takes no parameters
// explicitly empty. otherwise it might read as it takes all sorts of parameters and whatnot
void copy(void);

int main(){
    int len;
    extern int max; // using max from outside of the function body
    extern char longest[];

    max = 0; // this holds the length of the longest char
    // in the declaration-definition dichotomy this is a definition.
    // we take the max and we give it a value so it now exists in memory.
    while ((len = getthis()) > 0){
        if (len > max) { // if current line is longer than max
            max = len; // make current line max
            copy(); // copy current line into the longest
        }
    }
    if (max > 0) printf("longest string is %s, its size is %d", longest, max);
    return 0;
}

int getthis(void){
    int c, i;
    extern char line[]; // using line[] from outside the function

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) 
        line[i] = c;
    // for loop opens up the input, appends stuff until the newline or EOF hits
    if (c == '\n'){
        line[i] = c;
        ++i;
        // appends to the count until we hit a newline
    }
    line[i] = '\0'; // terminate the string
    return i;
}

void copy(void){
    int i = 0;
    extern char line[], longest[];

    while ((longest[i] = line[i]) != '\0') ++i;
}

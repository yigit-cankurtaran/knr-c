#include <stdio.h>
#define MAXLINE 1000

int getthis(char line[], int maxline); // function prototype
                                      // technically we're declaring here so we can use it in main
                                      // but we'll fill it out later
void copy(char to[], char from[]);

// printing longest input line
int main() {
    int len; // current line length
    int max; // max length so far

    char line[MAXLINE];    // current input line
    char longest[MAXLINE]; // longest line saved here

    max = 0;
    while ((len = getthis(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) printf("longest string is %s, its size is %d", longest, max);
    return 0;
}

int getthis(char s[], int lim){ // s[] = input line, lim = limit
    int c, i; // i = index counter, c = holds characters from input
    // c is int to correctly hold values like EOF
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) s[i] = c;
    // read one character at a time with getchar
    // until we reach max limit or get to end of file or get to a new line
        if (c == '\n') {
            s[i] = c;
            ++i; // this is how we get the line length
        }
        s[i] = '\0';
        return i;
}

void copy(char to[], char from[]){
    int i = 0;
    while ((to[i] = from[i]) != '\0'){ // when you do assignment and then a check
        // it assigns first and then it runs the check
        // this first runs to[i] = from[i] and then checks if either of them are the end of a string
        i++; // go to the next char
    }
}

/* basically what this does is we have a longest line and its length in the main function.
   getthis opens up an input for the user, checks the length and the chars of every line.
   this is why newlines end the counting for i. and i returns an integer because we want the length
   we compare the length of every line to the longest line, if our current line is longer we
   copy that into longest and update the longest value.  */

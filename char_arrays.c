#include <stdio.h>
#define MAXLINE 1000

int getline(char line[] int maxline); // function prototype
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
    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) printf("%s", longest);
    return 0;
}

int getline(char s[], int lim){ // s[] = input line, lim = limit
    int c, i; // i = index counter, c = holds characters from input
    // c is int to correctly hold values like EOF
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) s[i] = c;
        if (c == '\n') {
            s[i] = c;
            ++i;
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

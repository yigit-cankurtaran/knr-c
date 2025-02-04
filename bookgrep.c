#include <stdio.h>
#define MAXLINE 1000

int getstring(char line[], int max); // this is so that we can use the function in main
// before we write it out
int strindex(char source[], char searchfor[]);
char pattern[] = "ould"; // we don't enter the pattern ourselves for now hmm

int main() {
    char line[MAXLINE];
    int found = 0;
    while (getstring(line, MAXLINE) > 0){ // while getline runs (input is open)
        // getline copies the input into "line" so we can use it for strindex
        if (strindex(line, pattern) >= 0) { // run strindex on line
            // if there is a match (if -1 isn't returned) print the line then print the count
            // this logic works because the index of the similarity will be 0 minimum (string start)
            printf("%s", line);
            found++;
        }
    }
    return found;
}

// get line into s, return length
int getstring(char s[], int lim) { // different parameter names??
    int c, i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') s[i++] = c;
    // while we haven't reached end of line yet, put c as the next char of s
    if (c == '\n') s[i++] = c; // we exit the input loop if we encounter a newline
    // but we still add the newline to the array to handle it gracefully
    // to preserve the line format and to display other lines as well.
    s[i] = '\0'; // end string
    return i;
}

// strindex: return index of t in s, -1 if none
int strindex(char s[], char t[]) {
    // searches for t[] in s[]
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) { // iterate through s[]
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) ;
            // empty statement. the for loop does nothing.
            // doesn't need to do anything. we just advance j and k while the condition holds
        // iterate through t, if s[j(i)] and t[k] are the same and t isn't ended, advance positions
    if (k > 0 && t[k] == '\0') return i; // return the index where similarities start
    }
    return -1; // impossible for string index to be negative, no match
}

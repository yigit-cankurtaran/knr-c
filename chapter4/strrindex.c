/* Exercise 4-1. Write the function strrindex(s,t), which returns the position
   of the rightmost occurrence of t in s, or - 1 if there is none.
*/

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

// get the rightmost occurence of t in s
int strrindex(char* s, char* t){
    int stringlen = strlen(s);
    int patternlen = strlen(t);
    int i, j;

    if (stringlen <= 0 || patternlen <= 0) { // if either are blank
        return -1;
    }

    for (i = stringlen - patternlen; i >= 0; i--){ // looking at s from the right side
        // start i at the last index where we can fit t into s.
        // e.g. s has 10 chars t has 3 and we start at 9 we overshoot and we can't find it
        for (j = 0; j < patternlen; j++) { // looking at t from the left side
            if (s[i + j] != t[j]) break; // we need to compare every char in t with the corresponding char in s
            // i is the starting point. then for every char in i we compare it with the next char
            // e.g. t[0] with s[i] that's s[i + 0] then t[1] is compared with s[i + 1]
            // until we hit t[patternlen - 1] and compare it to s[i + patternlen - 1]
            // this is why we start from stringlen - patternlen
            // we break out of this loop if this isn't satisfied so i increments, then for the next i we check it against j again etc.
        }
        if (j == patternlen) return i; // j tracks the pattern string.
        // if the pattern string is fully in the string return its index
    }
    return -1; // if it's not return -1
}

int main(){
    char my_string[MAXLINE] = "peter piper picked a peck of pickled peppers";
    char pattern1[MAXLINE] = "pe";
    char pattern2[MAXLINE] = "pi";
    printf("last %s in: %d\n", pattern1, strrindex(my_string, pattern1));
    printf("last %s in: %d\n", pattern2, strrindex(my_string, pattern2));
    return 0;
}


#include <stdio.h>

#define MAXLINE 1000

// checks if character is a letter
int is_letter(char c) {
    // checking for both lower and upper cases
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// checks if character is a digit
int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

// expands shorthand notations like a-z in s1 into equivalent complete list abc...xyz in s2
void expand(char s1[], char s2[]) {
    int i, j;
    i = j = 0;

    while (s1[i] != '\0') { // before we reach the end of string
        // look for pattern: char-char
        if (s1[i + 1] == '-' && s1[i + 2] != '\0') {
            char start = s1[i];
            char end = s1[i + 2];

            // check if both chars are letters or both are digits
            if ((is_letter(start) && is_letter(end)) || (is_digit(start) && is_digit(end))) {
                // expand range (both ascending and descending)
                if (start <= end) {
                    while (start <= end) s2[j++] = start++;
                }
                else {
                    while (start >= end) s2[j++] = start--;
                }
                i += 3; // skip the processed range
            }
            else {
                // not a valid range, copy character as-is
                s2[j++] = s1[i++];
            }
        } else {
            // no range pattern, copy character as-is
            s2[j++] = s1[i++];
        }
    }
    s2[j] = '\0'; // null-terminate the result string
}

int main()
{
    char s1[MAXLINE] = "a-z0-9"; // test case 1: letters and numbers
    char s2[MAXLINE];
    char s3[MAXLINE] = "a-b-c"; // test case 2: multiple ranges
    char s4[MAXLINE];
    char s5[MAXLINE] = "z-a"; // test case 3: descending range
    char s6[MAXLINE];

    expand(s1, s2);
    expand(s3, s4);
    expand(s5, s6);

    printf("a-z0-9 expands to: %s\n", s2);
    printf("a-b-c expands to: %s\n", s4);
    printf("z-a expands to: %s\n", s6);

    return 0;
}

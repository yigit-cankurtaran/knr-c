#include <stdio.h>

int main(){
    int c, i, nwhite, nother;
    int ndigit[10]; // array init

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i){ // iterating over the array
        ndigit[i] = 0; // every value on the array is now 0
                       // a number for every digit
                       // current starting point is 0 0 0 0 0... 10 0s
    }

    while ((c = getchar()) != EOF){ // c = current char
        if (c >= '0' && c <= '9') ++ndigit[c-'0']; // we're checking the input char by char
                                                   // if it's a digit, convert it to an int and add 1 to its value
                                                   // the int conversion works due to ASCII stuff
                                                   // e.g. '1' - '0' maps to 1 as an int
                                                   // bc the ascii of '0' is 48 and '1' is 49
                                                   // so '1' - '0' = 49 - 48 = 1
                                                   // so we can print how many digits we have
                                                   // clever!
        else if (c == ' ' || c == '\n' || c == '\t') ++nwhite; // if there's whitespace
        else ++nother; // the count of the other stuff
    }

    printf("digits = ");
    for (i = 0; i < 10; ++i) printf(" %d", ndigit[i]);
    printf(", whitespace = %d, other = %d\n", nwhite, nother);
}

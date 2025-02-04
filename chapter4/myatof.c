// Exercise 4-2. Extend atof to handle scientific notation of the form 123.45e-6 where a floating-point number may be followed by e or E and an optionally signed exponent.

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double my_atof(char s[]){
    double val, power;
    int i, sign, exponent;
    double scientific = 1.0;

    for (i = 0; isspace(s[i]); i++) ;
            // skip whitespace, empty for loop
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') i++; // after the sign, ignore any other signs. skip w i++

    for (val = 0.0; isdigit(s[i]); i++) val = 10.0 * val + (s[i] - '0');
    // update val for each digit. 10.0 * val shifts it left to make room for the new value
    // integer part of the number
    if (s[i] == '.') i++; // if next char is ., move past it
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0; // we get power so we can divide it to get fractional
    }

    for (i = 0; i < strlen(s); i++){
        if (s[i] == 'e' || s[i] == 'E') {
            if (s[i + 1] == '-') {
                scientific *= -1; // take the negative into account
                i += 2; // skip over the negative and the -
            } else {
                i++; // skip over the -
            }
            exponent = strtol(&s[i], NULL, 10); // start from s[i] and convert to int
            // send the leftover non-digits to NULL, base 10 numbers
        }
    }
    scientific = pow(10, exponent);

    return (sign * val / power) * scientific; // positive/negative times the total number divided by what we got from the fractional calculation 
}

int main() {
    char hi[] = "2.55555123";
    printf("the result of hi is %f\n", atof(hi));
    char hello[] = "2321.123";
    printf("the result of hello is %f\n", atof(hello));
    char negativescientific[] = "123.45e-2";
    printf("the result of negativescientific is %f\n", atof(negativescientific));
    char positivescientific[] = "123.45e6";
    printf("the result of positivescientific is %f\n", atof(positivescientific));
}

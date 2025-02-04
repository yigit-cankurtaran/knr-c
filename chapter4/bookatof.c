#include <ctype.h>
#include <stdio.h>

double atof(char s[]){
    double val, power;
    int i, sign;

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
    return sign * val / power; // positive/negative times the total number divided by what we got from the fractional calculation
}

int main(){
    char hi[] = "2.55555123";
    printf("the result of hi is %f", atof(hi));
    char hello[] = "2321.123";
    printf("the result of hello is %f", atof(hello));
}

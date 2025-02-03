#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// a=10 b=11 c=12 d=13 e=14 f=15
// will use ascii arithmetic to handle this

int main() {
    char test_string[] = "1A3F"; // random hexadecimal string
    int a = strlen(test_string); // number which we will use for the loop
    int i = 0; // loop variable
    int final_num = 0;

    if (test_string[0] == '0' && test_string[1] == 'x'){
        i = 2; // if the first 2 chars are 0x start from the actual number
    }

    for (; i < a; i++){
        if (test_string[i] <= '9' && test_string[i] >= '0') { // if test_string is a digit
            test_string[i] -= '0'; // turn char into int
            final_num += test_string[i] * pow(16, a - i - 1); // add the value to the final number
            // a - i - 1 counting from the right, get the value we're at
            // pow comes from math.h
        } else { // if we hit a-f
            if (test_string[i] == toupper(test_string[i])){ // if uppercase
                test_string[i] = test_string[i] - 'A' + 10;
                // characters are back to back in alphabetical order
                // a is 10 in hexadecimal
            } else { // if lowercase
                test_string[i] = test_string[i] - 'a' + 10;
            }
            final_num += test_string[i] * pow(16, a - i - 1); // add the value to the final number
        }
    }
    printf("final number is %d.", final_num);
}

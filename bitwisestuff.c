#include <stdio.h>

int main(){
    int n = 150; // 10010110
    // & = bitwise and, used to set bits to zero
    int b = n & 0177; // keep only the lowest 7 bits
    // the 0177 and 0167 stuff are octals. you can change the octals to binaries to get how they move
    // to change octals to binaries p much just look at the digits and take the digits to their binaries
    // octal digits are 3 bits each
    // n becomes 00010110, the 1 in the start is gone
    printf("n's value after bitwise and is %d\n", b); // prints 22

    // | = bitwise or, used to set bits to one
    int c = n | 0167; // turns all the lower bits to 1
    printf("n's value after bitwise or is %d\n", c); // prints 255

    int d = n | 0b01101111; // binary instead of octal
    // binaries are used with 0b prefix
    printf("let's see if this works, %d\n", d); // it does. prints 255
}

// let it marinate for a bit then do exercises 2-6 2-7 2-8

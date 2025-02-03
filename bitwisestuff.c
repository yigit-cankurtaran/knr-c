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

    int e = n & ~077; // 077 is 111111 in octals
    // ~077 is 000000
    // taking an and of anything 0 is 0
    printf("setting last 6 bits of n to 0, %d\n", e); // prints 128

    int x = 5; // had to make it an int bc bit shifting doesn't work on floats.
    int y = x << 2; // shifting to left = 1s move left 0s are 0s
    // used for fast multiplication (powers of 2) or setting bits
    // e.g. moving 2 bits to the left = x * 2^2 1 bit to the left would be x * 2^1
    printf("x shifted 2 bits to the left: %d\n", y); // prints 20
    int z = x >> 2; // shifting to the right
    // used for fast division or setting bits
    // e.g. moving 2 bits to the right = x / 2^2 1 bit to the left would be x / 2^1
    printf("x shifted 2 bits to the right: %d\n", z); // prints 1
}

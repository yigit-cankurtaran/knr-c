/* Exercise 2-6. Write a function setbits (x,p,n,y) that returns x with the n
   bits that begin at position p set to the rightmost n bits of y, leaving the other
   bits unchanged.
   */

#include <stdio.h>

int setbits(int x, int p, int n, int y){
    int y_mask = (1 << n) - 1; // last n bits are now 1
    // we can use this with a bitwise and to grab the last n bits
    int y_bits = y & y_mask; // if everything is 1 and we run and, 1s will return 1 and 0s will return 0
    y_bits = y_bits << (p - n + 1); // shift left p bits
    int x_mask = ~(((1 << n) - 1) << (p - n + 1)); // n bits from p is 0
    int x_bits = x & x_mask; // running and here makes it so that the p-n is always 0
    return x_bits | y_bits; // we have to use or bc bitwise operation
    // combine bits, do NOT add them
}

int main(){
    printf("the result is %d\n", setbits(172, 4, 3, 231));
}

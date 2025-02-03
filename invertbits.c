/*
Exercise 2-7. Write a function invert (x,p,n) that returns x with the n bits
that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving
the others unchanged.
*/

#include <stdio.h>

int invertbits(int x, int p, int n){
    int x_mask = ((1 << n) - 1) << (p - n + 1);
    // i want n 1's, 1 << n - 1 gives me these 1s
    // then i want to shift it to the position of p
    // we shift it p - n + 1
    // p is the highest bit i can touch, i need n bits total
    // counting down n bits, the last one lands at p - n + 1 so we shift it that much

    x = x ^ x_mask; // xor bc if we xor something with 1 we get the opposite of it
    return x;
}

int main(){
    printf("the result is %d", invertbits(127, 6, 2));
}

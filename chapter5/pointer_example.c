#include <stdio.h>

int main() {
    int x = 42; // regular integer
    int *ptr = &x; // *ptr points to the address of x

    printf("value of x = %d\n", x);
    printf("value of x by dereferencing = %d\n", *ptr);
    printf("\n");

    printf("value of pointer from ptr is = %p\n", ptr); // we use %p to print addresses
    printf("value of pointer from x is = %p\n", &x);
    // prints 0x16ddc6fb8 as address
    printf("\n");

    printf("pointer + 10 is %d\n", *ptr + 10);
    // pointer arithmetic, we can use *ptr wherever x can appear
    *ptr = 100;
    printf("pointer now points to %d\n", *ptr);
    printf("value of x is %d\n", x);
    // both print the value as 100
    printf("\n");

    // DON'T DO THIS
    *ptr++; // this increments the "ptr" instead of "*ptr", a.k.a. what it points to
    // pointer precedence. ptr++ is evaluated first
    printf("testing this %d\n", *ptr); // prints "testing this 0"
    // undefined behavior, might crash or print something else
    printf("current address of ptr is %p\n", ptr);
    // prints current address of ptr is 0x16ddc6fbc
    // the last digit moves to c from 8 bc ints are 4 bits. 8 + 4 = 12 = b. we increment it by 1
    *ptr--; // moving the pointer back to where it should be
    // also bad practice but just to see how bits move
    printf("i think it's fixed now %d\n", *ptr); // it is, prints 100

    // to properly increment a pointer variable you do it like this
    (*ptr)++;
    printf("the good ending %d\n", *ptr); // prints 101

    return 0;
}

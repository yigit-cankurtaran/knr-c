#include <stdio.h>

int main() {
    int x = 42; // regular integer
    int *ptr = &x; // *ptr points to the address of x

    printf("value of x = %d\n", x);
    printf("value of x by dereferencing = %d\n", *ptr);
    printf("value of pointer from ptr is = %p\n", ptr); // we use %p to print addresses
    printf("value of pointer from x is = %p\n", &x);

    return 0;
}

#include <stdio.h>

int main(){
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int* pa;
    pa = &a[0];
    int x = *pa;

    *pa += 20; // adding 20 to the value of 0th element of a
    x += 50; // this doesn't do anything because it's just the value of pa. not a pointer
    for (int i = 0; i < 10; i++){
        printf("element %d of a is %d\n", i, a[i]);
        // using the pointer, we change it regardless of what we use it with.
        // it changes the value in the memory
        printf("if we access it with pointer %d of a is %d\n", i, *(pa + i));
        // we iterate through it with *(pa + i)
        // we tell c to move the pointer forward by i elements
        // the language adjusts the pointer based on the size of the data type
        // due to pointer to an array pointing to the start of an array
            // we can also write a[i] as *(a+i)
    }
    printf("we can do ++a as %d\n", *(++pa)); // points to index 1
    // *(++pa) = *(pa + 1) = a[1]
    return 0;
}

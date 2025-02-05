// attempting to find an easy way to create slices

#include <stdio.h>

void print_slice(int *x, int size){
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", x[i]);
        // prints x[0] to x[size - 1]
        printf("\nwith a pointer this is %d\n", *(x + i));
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    print_slice(arr, 3);
}

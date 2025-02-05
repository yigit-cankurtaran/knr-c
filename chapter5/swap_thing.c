#include <stdio.h>

void swap(int x, int y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void working_swap(int *px, int *py){
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

void modify_array(int arr[]){
    arr[0] = 100;
}

int main(){
    int a = 1;
    int b = 2;
    swap(a, b);
    printf("a on first swap is %d\t b is %d\n", a, b);
    // doesn't work when dealing with individual numbers
    // pass by value, we only change the copies of stuff without pointers
    // array examples worked because arrays decay into pointers.

    int nums[3] = {1, 2, 3};
    modify_array(nums);
    for (int i = 0; i < 3; i++){
        printf("index %d on nums is %d\n", i, nums[i]);
        // index 0 is 100. it worked because these work with pointers under the hood
    }
    printf("\n");

    working_swap(&a, &b); // this is how we pass in pointers
    // while passing them into a function we get their addresses
    // and we dereference them in the function declaration to directly access the variables
    // pass by reference, this works
    printf("a on second swap is %d\t b is %d\n", a, b);

    // px is address of a, py is address of b
    // *px and *py give access to a and b directly
    // values are swapped in main()'s memory
}

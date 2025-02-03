#include <stdio.h>

// find x in v...v[n-1]
int binsearch(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n - 1; // creating the upper and lower limits
    while (low <= high) {
        mid = (low + high) / 2; // mid = the average of the 2 values if odd it truncates
        if (x < v[mid]) high = mid - 1; // if num we're looking for is smaller than the middle element, lower the upper limit
        else if (x > v[mid]) low = mid + 1; // if num we're looking for is larger than the middle element, raise the upper limit
        else return mid; // if the numbers are the same return the mid
    }
    return -1; // no match, the element we're looking for isn't in the array
}

int main(){
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(array) / sizeof(array[0]);
    int find_me = 7;

    printf("the result of the search is: %d\n", binsearch(find_me, array, length));
}

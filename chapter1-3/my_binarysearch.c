#include <stdio.h>

int binsearch(int x, int v[], int n){
    int low = 0, high = n; // high is one past the end
    while (low < high) { // low is lower than high
        int mid = (low + high) / 2; // the center is the average of the 2
        if (v[mid] < x) low = mid + 1; // if the center is lower than the number we're looking for increment mid
        else high = mid; // if the center is higher than the number we're looking for drop the ceiling to half
    }
    return (low < n && v[low] == x) ? low : -1; // if low is lower than the length and the low is the index we're looking for return low, else -1 bc we couldn't find it.
}

int main{
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(array) / sizeof(array[0]);
    int find_me = 7;

    printf("the result of the search is: %d\n", binsearch(find_me, array, length));
}

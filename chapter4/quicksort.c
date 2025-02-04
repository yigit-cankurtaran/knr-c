#include <stdio.h>

void swap(int v[], int i, int j);
void qsort(int v[], int left, int right);
// left and right are the indexes we want

int main(void) {
    int nums[] = { 5, 12, 7, 546, 345, 4253, 43, 126 };
    int numslength = sizeof(nums) / sizeof(nums[0]);
    printf("the array is:\n");
    for (int i; i < numslength; i++){
        printf("%d ", nums[i]);
    }
    qsort(nums, 0, numslength - 1); // it's void, so doesn't return anything
    // we run it on our nums array starting from index 0 to the last index
    // it modifies it in place
    printf("\nthe array sorted is:\n");
    for (int i; i < numslength; i++){
        printf("%d ", nums[i]);
    }
}

// sort v[left]...v[right] into increasing order
void qsort(int v[], int left, int right){
    int i, last; // i = loop counter last = pivot tracker
    void swap(int v[], int i, int j);

    if (left >= right) return; // if the subarray has 0 or 1 element it's alr sorted
    swap(v, left, (left + right) / 2); // pick the middle element as pivot, move it to start by swapping
    last = left; // keep track of the boundary between elements
    for (i = left + 1; i <= right; i++) { // iterate over the array
        if (v[i] < v[left]) swap (v, ++last, i); // if an element is smaller than the pivot it gets swapped with the next position in the smaller section
    }
    swap(v, left, last); // move the pivot to its final position (last)
    // it's now where its left is all smaller than it and its right are all larger
    qsort(v, left, last - 1); // recursion, the function calling itself
    // this sorts the left part
    qsort(v, last + 1, right); // this sorts the right part
}

// interchange v[i] and v[j]
void swap(int v[], int i, int j){
    int temp;
    // we're only using temp here so the values don't disappear

    temp = v[i];
    v[i] = v[j];
    v[j] = temp; // switch places, move temp again
}

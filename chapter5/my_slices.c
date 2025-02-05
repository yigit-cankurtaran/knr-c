#include <stdio.h>
#include <stdlib.h>

int *create_int_slice(int *x, int start, int end) { // takes int pointer, start, end ints
// returning an int* bc we're returning an array
    int slice_size = end - start; // size
    int *slice = (int *) malloc(slice_size * sizeof(int)); // type of memory to allocate malloc(size)
    if (slice == NULL) {
    printf("memory allocation for int slice failed");
    return NULL;
    }
    for (int i = 0; i < slice_size; i++) {
        slice[i] = x[start + i];
    }
    return slice;
}

char *create_char_slice(char* string, int start, int end){
    int slice_size = end - start;
    char *slice = (char *) malloc((slice_size * sizeof(char)) + 1); // + 1 bc we want a null char
    if (slice == NULL) {
        printf("memory allocation for char slice failed");
    }
    for (int i = 0; i < slice_size; i++){
        slice[i] = string[start + i];
    }
    return slice;
}

int main(void) {
    int my_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    char my_string[] = "hello world";
    int start = 2, end = 5;
    int slice_size = end - start;
    int* slice_from_array; // declaring as a pointer bc an array needs a fixed size
    char* slice_from_string;
    slice_from_array = create_int_slice(my_array, start, end); // passing in my_array
    // bc it's a pointer to the first element. &my_array points to the entire array
    slice_from_string = create_char_slice(my_string, start, end);

    if (slice_from_array == NULL) { // if memory allocation fails
        return 1; // terminate
    }

    for (int i = 0; i < slice_size; i++) {
        printf("element %d of int slice is %d\n", i, slice_from_array[i]);
        // prints elements 3 and 4 and 5 in indexes 2, 3, 4
        printf("element %d of char slice is %c\n", i, slice_from_string[i]); // c bc we print char
    }

    printf("full string slice is %s\n", slice_from_string);

    free(slice_from_array); // slice_from_array is a pointer so we can just pass it here
    // if we don't free this after we're done with it we get a memory leak
    free(slice_from_string);
    return 0;
}


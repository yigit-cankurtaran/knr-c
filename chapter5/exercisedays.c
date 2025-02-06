/* Exercise 5-9. Rewrite the routines day_of_year and month_day with
pointers instead of indexing. */

#include <stdio.h>
#include <stdlib.h>

// static char* daytab[13] = {
static char (*daytab[2])[13] = {
    // declaring daytab as an array of 2 elements
    // each element of this array is a pointer of an array of 13 chars
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // ordinary year
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} // leap year
};

int main(void){
    for (int i = 0; i < 10; i++){
        printf("%d\n", daytab[i][i]);
    }
}

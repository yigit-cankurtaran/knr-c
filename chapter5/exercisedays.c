/* Exercise 5-9. Rewrite the routines day_of_year and month_day with
pointers instead of indexing. */

#include <stdio.h>
#include <stdlib.h>

static char (*daytab[2])[13] = {
    // declaring daytab as an array of 2 elements
    // each element of this array is a pointer of an array of 13 chars
    // daytab = var name, daytab[2] means daytab is an array of 2 elements
    // (*daytab[2]) means each element in daytab is a pointer
    // (*daytab[2])[13] = this pointer points to an array of 13 chars
    &(char[13]){0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // ordinary year
    &(char[13]){0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} // leap year
    // these elements are compound literals
    // create an array of 13 chars, return that array. use & to turn it to a pointer
    // inside functions these return pointers, but not inside file scope so we need &
    // this pointer is stored inside daytab. there are 2 of these pointers
};

int day_of_year(int year, int *monthptr, int *dayptr) {
    // error handling
    if (*monthptr <= 0 || *dayptr <= 0){
        printf("please enter valid values (positive integers)");
        exit(-1);
    }

    int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0; 
    char *ptrs = (char *) *(daytab + leap); // get pointer to the correct array
    // we need to cast bc the type is actually 'char (*)[13]'

    // add up the days from previous months
    // go through months before the given month and add their days
    for(; *monthptr > 1; (*monthptr)--) *dayptr += *(ptrs + (*monthptr - 1));
    // we only need to get the days of the past months bc dayptr is already
    // the current day on the current month

    return *dayptr; // return the value of dayptr
}

void month_day(int year, int *yeardayptr, int *pmonth, int *pday) {
    if (pmonth == NULL || pday == NULL){
        printf("please enter non-null addresses.");
        exit(-1);
    }

    int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    char *ptrs = (char *) *(daytab + leap); // pick the correct array
    int total_days = *yeardayptr; // the value of yeardayptr

    // subtract days of each month from total until we can't subtract anymore
    while (total_days > *(ptrs + *pmonth)) { // while total days is longer than the month
        total_days -= *(ptrs + *pmonth); // subtract days in the month
        (*pmonth)++; // add 1 to the month
    }

    // whatever is left is the day of the month
    *pday = total_days;
}

int main(void) {
    int month = 3;
    int day = 4;
    int year = 2025;
    int function_result = day_of_year(year, &month, &day);
    printf("march 4 2025 is day %d of the year\n", function_result);

    int yearday = function_result;
    int calculated_month, calculated_day;

    month_day(year, &yearday, &calculated_month, &calculated_day);
    printf("day %d of 2025 is %d/%d\n", function_result, calculated_day, calculated_month);

    return 0;
}

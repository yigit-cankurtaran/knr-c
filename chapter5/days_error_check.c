/*Exercise 5-8. There is no error checking in day_of_year or month_day.
  Remedy this defect.*/

#include <stdio.h>
#include <stdlib.h>

static char daytab[2][13] =  {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // ordinary year
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} // leap year
    // this starts with a 0 bc we want the months to be in proper indexes
};
// 2 dimensional array. 2 different arrays inside a single daytab array

int day_of_year(int year, int month, int day){
    // negative or 0 months, negative or 0 days give this an error

    if (month <= 0 || day <= 0){
        printf("please enter valid values (positive integers)");
        exit(-1);
    }

    int i, leap;
    
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0; 
    // if the year is a multiple of 4 or a multiple of 400 and not a multiple of 100
    for (i = 1; i < month; i++) day += daytab[leap][i]; // go to leap or ordinary year
    // get the month, add the number of the past months on the day we pass
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {

    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0; // leap year calc again
    for (i = 1; yearday > daytab[leap][i]; i++) yearday -= daytab [leap][i];
    // start from the first month, leap = which array we check, i = our index in that array
    // while yearday is larger than the month we're on, lower yearday by whatever our current month is

    if (pmonth == NULL || pday == NULL){
        printf("please enter non-null addresses.");
        exit(-1);
    }

    *pmonth = i; // post-loop amount of i will be the number of months
    *pday = yearday; // the remainder from yearday will be our days
    // the pointers here are solely to return multiple vars
    // we create some ints in the function we call this in
    // then we pass in their addresses to this function
    // and this puts the values we want in their addresses.
}

int main(void) {
    int day = day_of_year(2025, 3, 1);
    printf("march 1 2025 is day %d of the year\n", day);

    // convert day 61 of 2024 back to month
    int month, day2;
    month_day(2024, 61, &month, &day2); // remember, pointers bc we want 2 diff values
    // &month and &day2 are because we're sending the address of the variables.
    // we put the values we get into these addresses so we can return them
    // we change it in the memory bc we cant return 2 different values normally
    printf("day 61 of 2024 is month %d, day %d\n", month, day2);

    return 0;
}

#include <stdio.h>

int main() {
    double sum, v;
    sum = 0;
    while (scanf("%lf", &v) == 1) printf("\t%.2f\n", sum += v);
    // scan the string according to format, store the result in value
    // here we pass in the address of v
    // it prints a tab, the float with 2 of the chars after . , and then a newline

    char date[] = "5 Dec 2001";
    int day, year;
    char month[4]; // enough for month name + null terminator
    sscanf(date, "%d %s %d", &day, month, &year);
    // the string to parse, the pattern to pass it with, the pointers to the new vars
    // we don't need to pass a pointer to month bc array vars decay to pointers
    printf("day: %d, month: %s, year: %d\n", day, month, year);
    return 0;
}

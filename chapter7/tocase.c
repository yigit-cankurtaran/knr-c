/* Exercise 7-1. Write a program that converts upper case to lower or lower case
to upper, depending on the name it is invoked with, as found in argv[0]. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char** argv){
    if (argc != 2) {
        printf("usage: %s <lower|upper>\n", argv[0]);
        return 1;
    }
    // argv[0] is always the program name itself
    // e.g. if it's just a.out it prints "usage: a.out"
    char str[] = "Hello World";
    
    if (strcmp(argv[1], "lower") == 0) {
        for (int i = 0; str[i]; i++) str[i] = tolower(str[i]);
        // we can iterate directly here bc strings are null terminated
    } else if (strcmp(argv[1], "upper") == 0) {
        for (int i = 0; str[i]; i++) str[i] = toupper(str[i]);
    } else {
        printf("invalid option, use 'lower' or 'upper'\n");
        return 1;
    }

    printf("%s\n", str);
    return 0;
}

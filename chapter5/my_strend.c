/* Exercise 5-4. Write the function strend(s, t), which returns 1 if the string
t occurs at the end of the string s, and zero otherwise. */

#include <stdio.h>
#include <string.h>

int my_strend(char* s, char* t){
    int s_length = strlen(s);
    int t_length = strlen(t);

    if (t_length > s_length) return 0;
    // a longer string cannot appear at the end of a shorter string

    // moving s to the position where the comparison starts
    s = s + s_length - t_length;

    while (*t != '\0') { // while we haven't reached t's end yet
        if (*s++ != *t++) return 0;
        // pointer arithmetic. if the value of the char isn't the same return 0, increment chars
    }
    return 1;
}

int main(void){
    char first[] = "hello";
    char second[] = "ello";

    char third[] = "yellow";
    char fourth[] = "low";

    char fifth[] = "sh";

    printf("first and second is %d\n", my_strend(first, second));
    printf("third and fourth is %d\n", my_strend(third, fourth));
    printf("fourth and fifth is %d\n", my_strend(fourth, fifth));
}

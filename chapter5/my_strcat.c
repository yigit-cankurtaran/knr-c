/* Exercise 5-3. Write a pointer version of the function strcat that we showed
in Chapter 2: strcat(s, t) copies the string t to the end of s. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_strcat(char* s, char* t){
    int s_length = strlen(s);
    int t_length = strlen(t);
    int length = s_length + t_length;
    char* new_string = (char*) malloc((length * sizeof(char)) + 1);
    // +1 bc we want a /0 at the end of string

    int i;

    // add s to new string
    for (i = 0; i < s_length; i++) {
        *(new_string + i) = *(s + i);
    }

    // add t to new string
    for (int j = 0; j < t_length; j++) {
        *(new_string + s_length + j) = *(t + j);
    }
    new_string[length] = '\0';

    return new_string;
}

int main(void){
    char hello[] = "hello";
    char world[] = "world";

    char* combined_string = my_strcat(hello, world);
    if (combined_string == NULL) {
        printf("malloc failed on main");
        return 1;
    }

    printf("new string is %s\n", combined_string);

    free(combined_string);

    return 0;
}

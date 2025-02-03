/*
   Exercise 2-5. Write the function any (s 1, s2), which returns the first location
   in the string s1 where any character from the string s2 occurs, or - 1 if s1
   contains no characters from s2. (The standard library function strpbrk does
   the same job but returns a pointer to the location.)
*/

#include <stdio.h>
#include <string.h>

int any(char* s1, char* s2){
    int i, k;
    for (i = 0; i < strlen(s1); i++){
        for (k = 0; k < strlen(s2); k++){
            if (s1[i] == s2[k]) return i;
        }
    }
    return -1;
}

int main(){
    char hello[] = "hello";
    char sleep[] = "sleep";
    char nap[] = "nap";

    printf("result of hello and sleep is %d\n", any(hello, sleep));
    printf("result of hello and nap is %d\n", any(hello, nap));
    printf("result of sleep and nap is %d\n", any(sleep, nap));
}

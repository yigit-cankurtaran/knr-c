#include <stdio.h>

int my_strlen(char* s){
    int n; // we need to declare it up here bc we want to return it
    // it can't be stuck on the for loop's scope
    for (n = 0; *s != '\0'; s++, n++) ; // empty for loop
    // incrementing s pretty much is s[i] i++
    return n;
}

int main(void){
    char hi[] = "test";
    char hello[] = "greetings";
    printf("first string %d\n", my_strlen(hi));
    printf("second string %d\n", my_strlen(hello));
}

#include <stdio.h>

int main() {
    int c, d;
    printf("getting char\n");
    c = getchar(); // gets the first char from whatever we type in
    d = putchar(c); // prints what getchar gets. e.g. "h" from "hello"
    printf("%d\n",d); // prints the ASCII value of "h" from "hello"
    return 0;
}

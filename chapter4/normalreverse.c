#include <stdio.h>
#include <string.h>

// take the string, move the last char in the place of the first char
// move the first char in place of the last char
// i++ and do the same again
// do this until you hit the middle of the string
void reverse (char* s){
    int string_length = strlen(s);
    int i, j;
    char temp;

    for (i = 0; i < string_length / 2; i++) { // string_length / 2 bc we need to hit the middle
        temp = s[i];
        s[i] = s[string_length - i - 1]; // we have to use i - 1 bc of indexing
        // the final element is s[string_length - 1] so we have to be within that limit
        s[string_length - i - 1] = temp;
    }
}

int main(void) {
    char test[] = "reverse me";
    char test2[] = "reverse me but with odd number of chars";
    printf("even before reversal: %s\n", test);
    reverse(test);
    printf("even after reversal: %s\n", test); // works for even length strings

    printf("odd before reversal: %s\n", test2);
    reverse(test2);
    printf("odd after reversal: %s\n", test2); // works for odd as well
}

/* Exercise 4-13. Write a recursive version of the function reverse(s), which
   reverses the string s in place.
*/

#include <stdio.h>
#include <string.h>

// take the string, move the last char in the place of the first char
// move the first char in place of the last char
// i++ and do the same again
// do this until you hit the middle of the string

void helper(char* s, int left, int right){
    if (left >= right) return;
    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;

    helper(s, left + 1, right - 1);
    // instead of writing a for loop with an i+1 and i-1 we decrement it this way
    // we do both because we want to reach half. they'll meet in the middle
}

void reverse(char* s) {
    int length = strlen(s);
    helper(s, 0, length - 1);
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

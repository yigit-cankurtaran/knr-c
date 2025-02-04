/*
   Exercise 2-4. Write an alternate version of squeeze(s1,2) that deletes
   each character in s 1 that matches any character in the string s 2
*/

#include <stdio.h>
#include <string.h>

void squeeze(char* s1, char* s2){
    int i, j; // i is for s1 j is for s2
    for (i = 0; s1[i] != '\0'; i++){
        for (j = 0; s2[j] != '\0'; j++){ // check every char in s1 against every char in s2
            if (s1[i] == s2[j]){
                for (int k = i; s1[k] != '\0'; k++){ // create a new var
                    s1[k] = s1[k + 1];
                }
                // we need a new var bc we'll need to decrement i to check if back to back chars are the same
                // and if we decrement then increment it's stuck on an endless loop
                i--;
                break;
            }
        }
    }

    printf("s1 is now %s, s2 is now %s", s1, s2);
}

int main(){
    char hello[] = "hello";
    char hey[] = "hey";

    squeeze(hello, hey);
    
    return 0;
}

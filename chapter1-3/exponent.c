#include <stdio.h>

int power(int base, int n) { // inputs also need their type
                             // int function() = returns int
    int i, p;
    p = 1;

    for (i = 1; i <= n; ++i) p *= base; // multiply p by base until we reach n
    return p; // returns 1 for 0 bc the for loop doesn't fire
              // i <= isn't true
}

int value_power(int base, int n) {

    int p;
    
    for (p = 1; n > 0; --n) p *= base;
    // multiply p by base, decrement n, multiply again until n hits 1
    return p;
}
                          
int main() {
    int i;
    for (i = 0; i < 10; ++i) printf("old power: %d %d %d\n", i, power(2, i), power(-3, i));
    for (i = 0; i < 10; ++i) printf("new power: %d %d %d\n", i, value_power(2, i), value_power(-3, i));
    return 0;
}

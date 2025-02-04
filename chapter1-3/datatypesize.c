#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
    int max_int = INT_MAX;
    printf("max int is: %d \n", max_int);
    short int short_int = SHRT_MAX;
    printf("short max int is: %hu \n", short_int);
    long int long_int = LONG_MAX;
    printf("long max int is: %ld \n", long_int);
    long long int longest_int = LLONG_MAX;
    printf("long long max int is: %lld \n", longest_int);
    float max_float = FLT_MAX;
    printf("max float is: %f \n", max_float);
}

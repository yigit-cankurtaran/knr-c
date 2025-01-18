#include <stdio.h>

int main(){
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 100;
    step = 1;

    celsius = lower;
    while(celsius <= upper){
        //celsius = 5 * (fahr - 32) / 9;
        fahr = (9 * celsius / 5) + 32;
        printf("%d\t%d\n", celsius, fahr);
        celsius = celsius + step;
    }
}


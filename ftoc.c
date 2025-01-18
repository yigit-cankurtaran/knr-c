#include <stdio.h>

int main(){
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    // heading for exercise 1.3
    printf("FAHRENHEIT\tCELSIUS\n");
    while(fahr <= upper){
        celsius = 5 * (fahr - 32) / 9;
        printf("%3d\t%12d\n", fahr, celsius); //little bit of styling
                                              //right center, first is 3, 2nd is 12 digits long
        fahr = fahr + step;
    }
}


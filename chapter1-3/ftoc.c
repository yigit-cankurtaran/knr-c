#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(){
    int fahr, celsius;

    fahr = LOWER;
    // heading for exercise 1.3
    printf("FAHRENHEIT\tCELSIUS\n");
    while(fahr <= UPPER){
        celsius = 5 * (fahr - 32) / 9;
        printf("%3d\t%12d\n", fahr, celsius); //little bit of styling
                                              //right center, first is 3, 2nd is 12 digits long
        fahr += STEP;
    }
}


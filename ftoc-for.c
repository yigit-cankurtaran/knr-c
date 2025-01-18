#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(){
    int fahr, celsius;

    printf("FAHRENHEIT\tCELSIUS\n");
    for(fahr = UPPER; fahr >= LOWER; fahr -= STEP){
        // fahr = upper, check if fahr >= lower, if so run fahr -= step, run it again
        // if fahr !>= lower, stop
        celsius = 5 * (fahr - 32) / 9;
        printf("%3d\t%12d\n", fahr, celsius); //little bit of styling
                                              //right center, first is 3, 2nd is 12 digits long
    }
}


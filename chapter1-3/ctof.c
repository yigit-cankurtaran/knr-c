#include <stdio.h>

#define LOWER 0 //freezing
#define UPPER 100 //boiling
#define STEP 1 //1 degree each time
               //no = or ; or anything just define the thing
               //this is a macro not a statement

int main(){
    float fahr, celsius; //units, doing them as float
    celsius = LOWER;

    printf("FAHRENHEIT\tCELSIUS\n");
    while(celsius <= UPPER){ //while we're below freezing
        //celsius = 5 * (fahr - 32) / 9;
        fahr = (9 * celsius / 5) + 32; //p much just reversed the formula
        printf("%3.2f\t%6.f\n", celsius, fahr); //both floats, c only has the last 2 digits
        celsius = celsius + STEP; //raise the number
    }
}

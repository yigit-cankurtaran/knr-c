#include <stdio.h>

int main(){
    float fahr, celsius; //units, doing them as float
    int lower, upper, step; //limits + how much we're gonna raise

    lower = 0; //freezing
    upper = 100; //boiling
    step = 1; //1 degree each time

    celsius = lower;
    while(celsius <= upper){ //while we're below freezing
        //celsius = 5 * (fahr - 32) / 9;
        fahr = (9 * celsius / 5) + 32; //p much just reversed the formula
        printf("%3.2f\t%6.f\n", celsius, fahr); //both floats, c only has the last 2 digits
        celsius = celsius + step; //raise the number
    }
}

// my own exercise for pointing at a function with pointers
// choosing a math operation dynamically

#include <stdio.h>

int add (int a, int b) {
    return a + b;
}
int subtract (int a, int b) {
    return a - b;
}
int multiply (int a, int b) {
    return a * b;
}
int divide (int a, int b) {
    return a / b;
}

int calculate(int x, int y, int(*operation)(int,int)) {
    return operation(x, y); // call the function pointer on the values passed
}

int main(void){
    int a = 10, b = 5;

    int(*op)(int, int); // declaring a function pointer
    // we use function pointers to handle functions generically
    // without having to know which functions we'll call
    // we can decide at runtime which function to call based on conditions
    // this basically means "op is a pointer to a function that takes 2 ints as input"

    op = add; // in this, we mean that "op now points to the add function"
    printf("addition is %d\n", calculate(a,b,op));
    op = subtract;
    printf("subtraction is %d\n", calculate(a,b,op));
    op = multiply;
    printf("multiplication is %d\n", calculate(a,b,op));
    op = divide;
    printf("division is %d\n", calculate(a,b,op));

    printf("\nfinal situation of nums a: %d b:%d", a, b);
    // these stay the same bc we didnt use pointers for them
    return 0;
}

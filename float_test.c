/*
This file is mainly to test the c type float and there are many interesting things happened.
when we need to compare a float varible to zero, we need set a precision value, here is a 
example:
    const float PRECISION = 0.000001
    if((x >= -PRECISION) && (x <= PRECISION)) //This line is equal to x == 0 in integer type

--------------------------------
S(1bit)|  E(8bit)   |   M(23bit)
--------------------------------
10.25 = 1*10^1 + 0*10^2 + 2*10^(-1) + 5*10(-2)
101.1 = 1*2^2 + 0*2^1 + 1*2^0 + 1*2^(-1)
there is a example to clear the concept:
123.456D = 1111011.01110100101111001b
= 1.11101101110100101111001*2^6
so
S = 0
E = 00000110
M = 11101101110100101111001
summary:
we can express 6bit significant digits after point and partly express 7bit significant digits.
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    float a = 10.2;
    float b = 9;
    printf("a-b=%f\n", a-b);
    printf("a-b=%.8f\n", a-b);
    exit(0);    
}

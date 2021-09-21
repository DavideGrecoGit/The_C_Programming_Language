#include <stdio.h>

// Print Fahrenheit-Celsius table
int main(int argc, char const *argv[])
{
    float fahr, celsius, step;
    int lower, upper;

    lower = -20;
    upper = 60;
    step = 2.5;

    celsius = lower;
    printf("%7s\t%6s\n\n", "celsius", "fahr");

    while (celsius <= upper)
    {
        fahr = 9.0 / 5.0 * celsius + 32.0;
        printf("%6.1f\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}

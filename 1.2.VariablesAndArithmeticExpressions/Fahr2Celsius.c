#include <stdio.h>

// Print Fahrenheit-Celsius table
int main(int argc, char const *argv[])
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -5;
    upper = 140;
    step = 5;

    fahr = lower;

    printf("%4s\t%7s\n\n", "fahr", "celsius");

    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}

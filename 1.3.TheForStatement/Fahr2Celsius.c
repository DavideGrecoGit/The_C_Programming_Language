#include <stdio.h>

// Print Fahrenheit-Celsius table
int main(int argc, char const *argv[])
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -5;
    upper = 140;
    step = 5;

    printf("%6s\t%6s\n\n", "fahr", "celsius");

    for (fahr = lower; fahr <= upper; fahr = fahr + step)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
    }

    return 0;
}

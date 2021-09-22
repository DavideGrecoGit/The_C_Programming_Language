#include <stdio.h>

#define LOWER -5
#define UPPER 140
#define STEP 5

// Print Fahrenheit-Celsius table
int main(int argc, char const *argv[])
{
    float fahr, celsius;

    printf("%4s\t%6s\n\n", "fahr", "celsius");

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
    }

    return 0;
}

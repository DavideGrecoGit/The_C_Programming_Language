#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]);

int main(int argc, char const *argv[])
{
    char s[] = "12314e-2";
    printf("%f\n", atof(s));
    return 0;
}

double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
    {
        ;
    }

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.')
    {
        i++;
    }

    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    if (s[i++] == 'e' && s[i++] == '-')
    {
        double temp = 0.0;
        for (; isdigit(s[i]); i++)
        {
            temp = 10.0 * temp + (s[i] - '0');
        }
        for (int k = 0; k < temp; k++)
        {
            power *= 10;
        }
    }

    return sign * val / power;
}

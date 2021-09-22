#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c, i, nwhite, nother;
    nwhite = nother = 0;

    int ndigit[10];
    for (i = 0; i < 10; ++i)
    {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
        {
            ++ndigit[c - '0'];
        }
        else if (c == ' ' || c == '\n' || c == '\t')
        {
            ++nwhite;
        }
        else
        {
            ++nother;
        }
    }

    printf("digits = ");
    for (i = 0; i < sizeof(ndigit) / sizeof(ndigit[0]); ++i)
    {
        printf(" %d", ndigit[i]);
    }
    printf(", white spaces = %d, other = %d\n", nwhite, nother);

    return 0;
}

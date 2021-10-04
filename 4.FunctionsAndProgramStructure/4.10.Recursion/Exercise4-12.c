#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char s[]);
int itoaRecursion(int n, char s[], int i);

int main(int argc, char const *argv[])
{
    char s[1000];
    char t[1000];
    int n = -12035;

    itoa(n, t);
    printf("No recursion:   %s\n", t);

    itoaRecursion(n, s, 0);
    printf("With recursion: %s\n", s);

    return 0;
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)
    {
        n = -n;
    }

    i = 0;
    do
    {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
    {
        s[i++] = '-';
    }

    s[i] = '\0';
    reverse(s);
}

int itoaRecursion(int n, char s[], int i)
{
    if (n < 0)
    {
        s[i++] = '-';
        n = -n;
    }

    if (n / 10)
    {
        i = itoaRecursion(n / 10, s, i);
    }

    s[i++] = n % 10 + '0';
    s[i] = '\0';

    return i;
}
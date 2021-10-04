#include <stdio.h>

#define MAX_LINE 1000

int getlines(char s[], int lim);
int strrindex(char s[], char t[]);

int main(int argc, char const *argv[])
{
    char s[MAX_LINE], t[MAX_LINE];

    printf("Insert a string: \n");
    getlines(s, MAX_LINE);

    printf("Search in string: \n");
    getlines(t, MAX_LINE);

    printf("Rightmost occurence: %d\n\n", strrindex(s, t));

    return 0;
}

int getlines(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }

    s[i] = '\0';

    return i;
}

int strrindex(char s[], char t[])
{
    int i, j, k, max_i = -1;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
        {
            ;
        }
        if (t[k] == '\0')
        {
            max_i = i;
        }
    }

    return max_i;
}
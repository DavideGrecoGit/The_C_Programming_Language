#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[]);

int main(int argc, char const *argv[])
{
    char s1[] = "---a-z0-9--";
    char s2[1000];

    expand(s1, s2);
    printf("%s", s2);

    return 0;
}

void expand(char s1[], char s2[])
{
    int i = 0;

    // Trim
    while (s1[i] == '-')
    {
        i++;
    }

    int j = strlen(s1) - 1;
    while (s1[j] == '-')
    {
        j--;
    }
    s1[j + 1] = '\0';

    char start = '\0';
    char end = '\0';
    j = 0;
    for (; s1[i] != '\0'; i++)
    {
        if (s1[i] != '-')
        {
            if (start == '\0')
            {
                start = s1[i];
            }
            else
            {
                end = s1[i];
                char c = start;
                while (c != end)
                {
                    s2[j++] = c;
                    c++;
                }
                s2[j++] = end;

                start = '\0';
                end = '\0';
            }
        }
    }
    s2[j] = '\0';
}

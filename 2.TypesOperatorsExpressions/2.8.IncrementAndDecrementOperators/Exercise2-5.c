#include <stdio.h>

int any(char s1[], char s2[], int len);

int main(int argc, char const *argv[])
{
    char s[] = "abcdefgcdef";
    char c[] = "ecb";
    int min = any(s, c, sizeof(s) / sizeof(s[0]));
    printf("%d\n", min);
    return 0;
}

int any(char s1[], char s2[], int len)
{
    int i, j, min;
    min = len;

    for (i = 0; s2[i] != '\0'; i++)
    {
        for (j = 0; s1[j] != '\0'; j++)
        {
            if (s1[j] == s2[i])
            {
                if (min > j)
                {
                    min = j;
                }
                break;
            }
        }
    }

    if (min == len)
    {
        min = -1;
    }

    return min;
}
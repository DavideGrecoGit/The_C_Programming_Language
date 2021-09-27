#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(int argc, char const *argv[])
{
    char s[] = "test string";
    char c[] = "ti";
    squeeze(s, c);
    printf("%s", s);
    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, y;

    int flag = 0;

    for (i = y = 0; s1[i] != '\0'; i++)
    {
        flag = 0;

        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            s1[y++] = s1[i];
        }
    }

    s1[y] = '\0';
}

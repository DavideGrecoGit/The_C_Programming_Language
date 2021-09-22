#include <stdio.h>

#define MAXLINE 1000

int getlineOldSchool(char s[]);
void reverse(char s[]);

int main(int argc, char const *argv[])
{
    int c, i, len;
    char line[MAXLINE];

    while ((len = getlineOldSchool(line)) > 0)
    {
        for (i = len; i >= 0; --i)
        {
            printf("%c", line[i]);
        }
        printf("\n");
    }

    return 0;
}

// getline: read a line into s, return its lenght
int getlineOldSchool(char s[])
{
    int c, i;

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }

    return i - 1;
}
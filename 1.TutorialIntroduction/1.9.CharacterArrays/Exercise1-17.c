#include <stdio.h>
#define MAXLINE 1000       //max input line size
#define PRINT_THRESHOLD 80 //minimum size required to print

int getlineOldSchool(char s[], int lim);

// print longest input line
int main(int argc, char const *argv[])
{
    int len;            //current line lenght
    char line[MAXLINE]; //current input line

    while ((len = getlineOldSchool(line, MAXLINE)) > 0)
    {
        if (len > PRINT_THRESHOLD)
        {
            printf("%s", line);
        }
    }

    return 0;
}

// getline: read a line into s, return its lenght
int getlineOldSchool(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

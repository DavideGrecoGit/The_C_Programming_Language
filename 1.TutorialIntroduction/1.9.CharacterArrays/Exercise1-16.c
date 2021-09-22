#include <stdio.h>
#define MAXLINE 10 //max input line size

int getlineOldSchool(char s[], int lim);
void copy(char to[], char from[]);

// print longest input line
int main(int argc, char const *argv[])
{
    int len;               //current line lenght
    int max;               //max lenght so far
    char line[MAXLINE];    //current input line
    char longest[MAXLINE]; //longest line saved here

    max = 0;
    while ((len = getlineOldSchool(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
    {
        printf("%s", longest);
    }

    return 0;
}

// getline: read a line into s, return its lenght
int getlineOldSchool(char s[], int lim)
{
    int c, i, j;

    i = 0;
    for (j = 0; (c = getchar()) != EOF && c != '\n'; ++j)
    {
        if (j < lim - 2)
        {
            s[i] = c;
            ++i;
        }
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return j;
}

//copy: copy "from" into "to"; assumes "to" is big enough
void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0' && i < MAXLINE)
    {
        i++;
    }
}
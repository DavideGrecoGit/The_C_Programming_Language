#include <stdio.h>
#define MAXLINE 1000 //max input line size

int getlineOldSchool(char s[], int lim);
void copy(char to[], char from[]);

// print longest input line
int main(int argc, char const *argv[])
{
    int len;               //current line lenght
    int max;               //max lenght so far
    char line[MAXLINE];    //current input line
    char longest[MAXLINE]; //longest line saved here

    /* Test comment
    Multiline */
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

    /* Test */
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

//copy: copy "from" into "to"; assumes "to" is big enough
void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        i++;
    }
}
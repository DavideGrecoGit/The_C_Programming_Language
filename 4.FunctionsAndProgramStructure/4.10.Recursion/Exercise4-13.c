#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void reverseRecursion(char s[], int i, int j);

int main(int argc, char const *argv[])
{
    char s[] = "Hello World!";
    char t[] = "Hello World!";
    int n = -12035;

    reverse(t);
    printf("No recursion:   %s\n", t);

    // printf("%d %d", 0, strlen(s) - 1);

    reverseRecursion(s, 0, (strlen(s) - 1));
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

void reverseRecursion(char s[], int i, int j)
{
    if (i < j)
    {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;

        reverseRecursion(s, ++i, --j);
    }
}
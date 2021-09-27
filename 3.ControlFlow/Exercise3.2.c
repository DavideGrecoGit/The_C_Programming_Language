#include <stdio.h>

void escape(char s[], char t[]);
void notEscape(char s[], char t[]);

int main(int argc, char const *argv[])
{
    char t[] = "sadv sa as\n asdas\t\n\td \t dsa";
    int maxLen = (sizeof(t) / sizeof(t[0])) * 2;
    char s[maxLen];
    char d[maxLen / 2];

    escape(s, t);
    printf("T:\n%s\n", t);
    printf("S:\n%s\n", s);

    printf("\n\n");

    notEscape(d, s);
    printf("S:\n%s\n", s);
    printf("D:\n%s\n", d);

    return 0;
}

void escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;

        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;

        default:
            s[j++] = t[i];
            break;
        }
    }

    s[j] = '\0';
}

void notEscape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
        case '\\':
            if (t[i + 1] == 'n')
            {
                i++;
                s[j++] = '\n';
            }

            if (t[i + 1] == 't')
            {
                i++;
                s[j++] = '\t';
            }

            break;

        default:
            s[j++] = t[i];
            break;
        }
    }

    s[j] = '\0';
}
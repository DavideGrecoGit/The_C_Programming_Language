#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Write a program to check a C program for rudimentary syntax erorrs like unbalanced parentheses, brackets and braces. */
int main(int argc, char const *argv[])
{
    char filePath[] = "INSERT TEST FILE";

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    size_t read;

    printf("%s\n\n", filePath);

    fp = fopen(filePath, "r");
    if (fp == NULL)
    {
        printf("\nERROR\n");
        return 1;
    }

    int i;

    int oParenthesis, cParenthesis, oBraces, oBrackets, cBraces, cBrackets, SQuotes, DQuotes;
    oParenthesis = cParenthesis = oBraces = oBrackets = cBraces = cBrackets = SQuotes = DQuotes = 0;

    int isCommented = 0;
    int hasErrors = 0;

    while ((read = getline(&line, &len, fp)) != -1)
    {
        //printf("%s", line);
        for (i = 0; i < strlen(line); i++)
        {
            // Do not check if char is in a comment

            if (line[i] == '/' && line[i + 1] == '/')
            {
                break;
            }

            if (line[i] == '/' && line[i + 1] == '*')
            {
                isCommented = 1;
            }

            if (line[i] == '*' && line[i + 1] == '/')
            {
                isCommented = 0;
                i = i + 2;
            }

            if (isCommented == 0)
            {
                //If char are not commented out, count them
                if (line[i] == '(')
                {
                    ++oParenthesis;
                }
                if (line[i] == ')')
                {
                    ++cParenthesis;
                }

                if (line[i] == '[')
                {
                    ++oBrackets;
                }
                if (line[i] == ']')
                {
                    ++cBrackets;
                }

                if (line[i] == '{')
                {
                    ++oBraces;
                }
                if (line[i] == '}')
                {
                    ++cBraces;
                }

                if (line[i] == '\'')
                {
                    ++SQuotes;
                }
                if (line[i] == '"')
                {
                    ++DQuotes;
                }
            }
        }
    }

    if (oParenthesis != cParenthesis)
    {
        printf("ERROR: () mismatch\n");
        hasErrors = 1;
    }

    if (oBrackets != cBrackets)
    {
        printf("ERROR: [] mismatch\n");
        hasErrors = 1;
    }

    if (oBraces != cBraces)
    {
        printf("ERROR: {} mismatch\n");
        hasErrors = 1;
    }

    if (SQuotes % 2 != 0)
    {
        printf("ERROR: '' mismatch\n");
        hasErrors = 1;
    }

    if (DQuotes % 2 != 0)
    {
        printf("ERROR: \" \" mismatch\n");
        hasErrors = 1;
    }

    if (hasErrors == 0)
    {
        printf("Code WITHOUT mismatch!\n");
    }

    printf("\n\n");

    fclose(fp);
    if (line)
        free(line);
    return 0;
}
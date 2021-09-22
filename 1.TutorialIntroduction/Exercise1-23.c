#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    int i, j;

    int isCommented = 0;

    while ((read = getline(&line, &len, fp)) != -1)
    {
        //printf("%s", line);
        for (i = 0; i < strlen(line); i++)
        {
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
                printf("%c", line[i]);
            }
        }
    }

    printf("\n\n");

    fclose(fp);
    if (line)
        free(line);
    return 0;
}

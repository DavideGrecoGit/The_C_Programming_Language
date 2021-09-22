#include <stdio.h>

#define FIRST_VALID_CHAR 32
#define ASCII (127 - FIRST_VALID_CHAR)

int main(int argc, char const *argv[])
{
    int c, i, j, wl;
    wl = 0;

    int nchar[ASCII];

    for (i = 0; i < ASCII; ++i)
    {
        nchar[i] = 0;
    }

    printf("Write something! (press ctrl+d to count to exit)\n");

    while ((c = getchar()) != EOF)
    {
        ++nchar[c - FIRST_VALID_CHAR];
    }

    for (i = 0; i < ASCII; ++i)
    {
        printf(" %c| ", i + FIRST_VALID_CHAR);

        for (j = 0; j < nchar[i]; ++j)
        {
            printf("|");
        }
        printf("\n");
    }

    return 0;
}
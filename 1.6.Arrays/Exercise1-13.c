#include <stdio.h>

#define MAX_WORD_LENGHT 10

int main(int argc, char const *argv[])
{
    int c, i, j, wl;
    wl = 0;

    int nwords[MAX_WORD_LENGHT];

    for (i = 0; i < MAX_WORD_LENGHT; ++i)
    {
        nwords[i] = 0;
    }

    printf("Write something! (press ctrl+d to count to exit)\n");

    while ((c = getchar()) != EOF)
    {
        if (c == '\n' || c == '\t' || c == ' ')
        {
            if (wl >= MAX_WORD_LENGHT)
            {
                wl = MAX_WORD_LENGHT - 1;
            }

            if (wl != 0)
            {
                ++nwords[wl];
                wl = 0;
            }
        }
        else
        {
            ++wl;
        }
    }

    // for (i = 0; i < MAX_WORD_LENGHT; ++i)
    // {
    //     if (i == MAX_WORD_LENGHT - 1)
    //     {
    //         printf(" %2d+ ", i);
    //     }
    //     else
    //     {
    //         printf(" %2d  ", i);
    //     }
    //     for (j = 0; j < nwords[i]; ++j)
    //     {
    //         printf("|");
    //     }
    //     printf("\n");
    // }

    int max = 0;
    for (i = 0; i < MAX_WORD_LENGHT; ++i)
    {
        if (nwords[i] > max)
        {
            max = nwords[i];
        }
    }

    printf("\n");

    j = max;

    while (j > 0)
    {
        for (i = 0; i < MAX_WORD_LENGHT; ++i)
        {
            if (nwords[i] >= j)
            {
                printf("  -  ");
            }
            else
            {
                printf("     ");
            }
        }
        --j;
        printf("\n");
    }

    for (i = 0; i < MAX_WORD_LENGHT; ++i)
    {
        if (i == MAX_WORD_LENGHT - 1)
        {
            printf(" %2d+ ", i);
        }
        else
        {
            printf(" %2d  ", i);
        }
    }
    printf("\n");
    printf("\n");

    return 0;
}

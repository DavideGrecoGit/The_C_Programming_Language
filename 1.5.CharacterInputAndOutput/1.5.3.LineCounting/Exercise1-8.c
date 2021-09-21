#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c, nl, nt, nb;

    nl = 0;
    nt = 0;
    nb = 0;

    printf("Write something! (press ctrl+d to count to exit)\n");

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            ++nl;
        }

        if (c == '\t')
        {
            ++nt;
        }

        if (c == ' ')
        {
            ++nb;
        }
    }
    printf("Total newlines: %d\n", nl);
    printf("Total tabs: %d\n", nt);
    printf("Total blanks: %d\n", nb);
    return 0;
}
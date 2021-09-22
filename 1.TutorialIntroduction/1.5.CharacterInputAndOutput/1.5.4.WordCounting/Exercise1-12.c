#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c, f;
    f = 0;

    printf("Write something! (press ctrl+d to count to exit)\n");

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            ++f;
            if (f <= 1)
            {
                printf("\n");
            }
        }
        else
        {
            putchar(c);
            f = 0;
        }
    }

    return 0;
}
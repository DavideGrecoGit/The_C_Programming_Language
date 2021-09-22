#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c, nb;

    printf("Write something! (press ctrl+d to count to exit)\n");

    nb = 0;

    while ((c = getchar()) != EOF)
    {

        if (c == ' ')
        {
            ++nb;
        }
        else
        {
            nb = 0;
        }

        if (nb <= 1)
        {
            putchar(c);
        }
    }

    return 0;
}

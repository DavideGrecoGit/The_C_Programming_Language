#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c;

    printf("Write something! (press ctrl+d to count to exit)\n");

    while ((c = getchar()) != EOF)
    {

        if (c == '\t')
        {
            printf("\\t");
        }
        else if (c == '\b')
        {
            printf("\\b");
        }
        else if (c == '\\')
        {
            printf("\\");
            printf("\\");
        }
        else
        {
            putchar(c);
        }
    }

    return 0;
}
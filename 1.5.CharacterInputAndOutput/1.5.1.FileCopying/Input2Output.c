#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c;
    printf("EOF: %d\n", EOF);
    printf("Write something and press Enter! (press ctrl+d to exit)\n");

    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
    return 0;
}

#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("Press a letter and then Enter: ");
    char c = getchar();
    printf("You pressed: %c\n", c);

    printf("I obtained: ");
    putchar(c);
    printf("\n");

    return 0;
}

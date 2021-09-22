#include <stdio.h>

int main(int argc, char const *argv[])
{
    long nc = 0;

    printf("Write something! (press ctrl+d to count to exit)\n");

    while (getchar() != 'q')
    {
        ++nc;
    }

    printf("Total chars: %ld\n", nc);

    return 0;
}

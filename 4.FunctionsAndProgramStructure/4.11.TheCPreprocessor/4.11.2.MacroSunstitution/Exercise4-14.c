#include <stdio.h>

#define swap(t, x, y) \
    {                 \
        t temp;       \
        temp = x;     \
        x = y;        \
        y = temp;     \
    }

int main(int argc, char const *argv[])
{
    int x, y;

    x = 10;
    y = 5;

    printf("x: %d y: %d\n", x, y);
    swap(int, x, y);
    printf("x: %d y: %d\n", x, y);

    return 0;
}

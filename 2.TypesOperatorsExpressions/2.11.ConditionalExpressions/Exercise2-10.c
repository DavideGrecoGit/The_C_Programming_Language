#include <stdio.h>

int lower(int c);

int main(int argc, char const *argv[])
{
    printf("%c", lower('D'));
    return 0;
}

int lower(int c)
{
    (c >= 'A' && c <= 'Z') ? c = c + 'a' - 'A' : c;
    return c;
}
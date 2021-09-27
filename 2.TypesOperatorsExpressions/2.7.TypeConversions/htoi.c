#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int htoi(char s[]);

int main(int argc, char const *argv[])
{
    char hex[] = "ab2d44f";
    printf("Hex: %s to Int: %d\n\n", hex, htoi(hex));
    return 0;
}

int htoi(char s[])
{
    //No need to reinvent the wheel :D
    return (int)strtol(s, NULL, 16);
}

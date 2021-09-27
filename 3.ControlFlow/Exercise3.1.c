#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n);
int binsearchRefactored(int x, int v[], int n);

int main(int argc, char const *argv[])
{
    int len = 100;
    int i, toSearch = 28;
    int v[len];

    for (i = 0; i < len; i++)
    {
        v[i] = i * 2;
    }
    printf("\n");

    clock_t begin = clock();
    int index = binsearch(toSearch, v, len);
    clock_t end = clock();
    double time_spent = (double)(end - begin);
    printf("BINARYSEARCH: index %d time: %f\n", index, time_spent);

    begin = clock();
    index = binsearchRefactored(toSearch, v, len);
    end = clock();
    time_spent = (double)(end - begin);
    printf("BINARYSEARCH2: index %d time: %f\n", index, time_spent);
    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (x < v[mid])
        {
            high = mid - 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

int binsearchRefactored(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (x < v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (v[mid - 1] == x)
    {
        return mid - 1;
    }
    else
    {
        return -1;
    }
}
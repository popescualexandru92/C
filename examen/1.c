#include <stdio.h>

void Test(int i, int n)
{
    printf("*");
    if (i < n)
        Test(i + 1, n);
    printf("+");
}

void main()
{
    Test(1,5);
}